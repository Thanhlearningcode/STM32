/*
* @file Can.c
* @brief CAN Driver implementation according to AUTOSAR Classic.
* @details This file contains the implementation of the CAN driver as per AUTOSAR specifications.
*          It includes functions for configuring the CAN controller, sending, and receiving messages.
*          GPIO Configuration:
*          - GPIOA PA11 -> CanRx (CAN Receive Pin)
*          - GPIOA PA12 -> CanTx (CAN Transmit Pin)
* @author Nguyen Van Thanh
* @date 10/15/2024
*/


#include "Can.h"
#define MAX_DATA_LENGTH 8 

void Can_Config(){
		// Rcc init
		RCC->APB2ENR|=( 1U << 2 );  	// Enable clock of GPIOA
		RCC->APB1ENR|=( 1U << 25 );    // Enable clock of CAN1
		// Configure GPIOA PA11 -> RX & PA12 -> TX
	
		GPIOA->CRH&=~ (0xFF << 12 );   // Clear bit
		GPIOA->CRH|=  ( 4U  << 12 );   // Floating input PA11
		GPIOA->CRH|=	(	0xB << 16 );   // AF output max speed 50mhz
		// Configure Can 
	
		CAN1->MCR&=~	(	1U	<< 8  );   // Time Triggered Communication mode disabled
		CAN1->MCR&=~  ( 1U  << 6  );   // Automatic bus-off management disabled
		CAN1->MCR&=~  ( 1U  << 5  );   // Automatic wake-up mode disabled
		CAN1->MCR&=~	( 1U  << 4  );   // No automatic retransmisson disabled
		CAN1->MCR&=~  ( 1U  << 3  );   // Received FIFO locked mode
		CAN1->MCR&=~  ( 1U  << 2  );   // Transmit FIFO priority
		CAN1->MCR&=~	( 1U  << 0  );   // Ensure that can is not in reset state and is normal mode
	// APB1 36mhz
	//fCan = 36000000/4 = 9 000 000.
	//1tq = 1/9000000.
	//Speed CAN = 1/(9tq) = 1Mb/s
	// -> Prescaler = 4, BS1 = 3tq, BS2 = 5tq, SJW = 1tq  682-683 pages 
		CAN1->BTR|=   ( 4U  << 0  );   // Prescaler 
		CAN1->BTR|=   ( 3U  << 16 );   // BS1 = 3tq
		CAN1->BTR|=   ( 5U  << 20 );   // BS2 = 5 tq 
	// Can filter
	  CAN1->FMR |=  ( 1U  << 0  );   // Filter Init Mode 
		CAN1->FM1R&=~ ( 1U  << 0  );   // IDmask number 0
		CAN1->FS1R|=  ( 1U  << 0  );   // 32bit-scaler 
	// Configure mask ID
		CAN1->FM1R&=! ( 1U  << 0  );
		CAN1->sFilterRegister[0].FR1 = 0xFFE0; // Mask ID High
    CAN1->sFilterRegister[0].FR2 = 0x0000; // Mask ID Low
	// Configure filter ID
    CAN1->sFilterRegister[0].FR1 = (0x123 << 5); // ID Filter High
    CAN1->sFilterRegister[0].FR2 = 0x0000; // ID Filter Low
		CAN1->FFA1R&=~( 1U << 0  );    // FIFO0
		
	  CAN1->FMR &= ~( 1U << 0  );    // Active filters mode.
				
}



uint32_t CAN_ReceiveData() {
    uint32_t messageID;  // Variable to store the received message ID
    uint32_t receivedData = 0;  // Variable to store received data as a 32-bit integer
    uint8_t TestArray[MAX_DATA_LENGTH];  // Array to store received data

    // Wait until there is a new message in FIFO0
    while (!(CAN1->RF0R & CAN_RF0R_FMP0)); 

    // Receive data from FIFO0
    messageID = CAN1->sFIFOMailBox[0].RDHR >> 21;  // Extract ID (21 bits from RDHR)

    // Extract data from the register
    for (int i = 0; i < (CAN1->sFIFOMailBox[0].RDHR & 0x0F); i++) {  // Get DLC from RDHR
        TestArray[i] = (CAN1->sFIFOMailBox[0].RDLR >> (i * 8)) & 0xFF;  // Get data byte by byte
        receivedData |= (TestArray[i] << (i * 8));  // Combine bytes into a single uint32_t
    }

    // Clear the message after processing
    CAN1->RF0R |= CAN_RF0R_RFOM0;  // Clear the message in FIFO0

    return receivedData;  // Return the combined received data
}
void CAN_TransmitData(uint8_t *data, uint8_t len, uint32_t id) {
    // Wait until the transmit mailbox is empty
    while (!(CAN1->TSR & CAN_TSR_TME0));  // Check if mailbox 0 is empty

    // Set the standard ID for the message
    CAN1->sTxMailBox[0].TIR = (id << 21);  // Shift ID to the left and store it in TIR
    CAN1->sTxMailBox[0].TIR &= ~(1U << 1) ; // Clear RTR bit for data frame

    // Set the data length code (
    CAN1->sTxMailBox[0].TDTR = len;  // Set the length of the data

    // Load data into the transmit data registers
    for (int i = 0; i < len; i++) {
        CAN1->sTxMailBox[0].TDLR = (data[i] << (i * 8));  // Load data into LSB first
    }

    // Request transmission of the message
    CAN1->sTxMailBox[0].TIR |= (1U << 0);  // Set the transmission request bit
}