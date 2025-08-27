

					AREA RTOS_SYSTEM,CODE,READONLY
					ENTRY
					EXPORT ConfigurationStackPointer
					EXPORT PendSV_Handler
					IMPORT StoreCurrentStack
					IMPORT ContextSwitch
					IMPORT GetNextTask
					EXPORT Task1 [WEAK]
					EXPORT Task2 [WEAK]
						
ConfigurationStackPointer
		            MSR MSP,R1      
		            MSR PSP,R0
		            MRS R0,CONTROL 
		            ORR R0,R0,#(1<<1)
		            MSR CONTROL,R0
					BX LR
					
PendSV_Handler
					CPSID I
					MRS R0,PSP
					STMDB R0!,{R4-R11}
					PUSH {LR}
					BL StoreCurrentStack
					BL ContextSwitch
					BL GetNextTask
					POP {LR}
					LDMIA R0!,{R4-R11}
					MSR PSP,R0
					CPSIE I
					BX LR
					
Task1
					B Task1

Task2
					B Task2
					
					END