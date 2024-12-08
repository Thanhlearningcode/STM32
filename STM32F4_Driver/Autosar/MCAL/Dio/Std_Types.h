/**********************************************************
 * @file Std_Types.h
 * @brief Defines standard data types for AUTOSAR
 * @details This file provides platform-independent data types 
 *          decoupled from hardware and compilers for basic 
 *          software modules in AUTOSAR.
 * @version 1.0
 * @date 2024-1-7
 * @author Nguyen Van Thanh
 **********************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

/**********************************************************
 *                     INCLUDE GUARD
 * Prevents multiple inclusions that cause compilation errors
 **********************************************************/

/* ===========================================
 *  Version Information
 * =========================================== */
/**********************************************************
 * @brief Version information of Std_Types.h
 * @details Version definitions to facilitate tracking of 
 *          changes and software compatibility.
 **********************************************************/
#define STD_TYPES_SW_MAJOR_VERSION  (1U)   /**< Major version number */
#define STD_TYPES_SW_MINOR_VERSION  (0U)   /**< Minor version number */
#define STD_TYPES_SW_PATCH_VERSION  (0U)   /**< Patch version number */

/* ===========================================
 *  Logical State Definitions
 * =========================================== */
/**********************************************************
 * @brief Definitions of high and low logical states
 * @details Used for input/output signals.
 **********************************************************/
#define STD_HIGH    0x01U   /**< High logical state */
#define STD_LOW     0x00U   /**< Low logical state */

/* ===========================================
 *  Null Pointer Definition
 * =========================================== */
/**********************************************************
 * @brief Defines the NULL pointer
 * @details The NULL pointer refers to address 0.
 **********************************************************/
#ifndef NULL
    #define NULL ((void*)0)  /**< NULL pointer definition */
#endif


/* ===========================================
 *  Platform Independent Data Types
 * =========================================== */
/**********************************************************
 * @brief Platform-independent data types
 * @details Explicit definitions of size and sign for data types.
 **********************************************************/
typedef unsigned char        uint8;    /**< 8-bit unsigned integer */
typedef signed char          sint8;    /**< 8-bit signed integer */
typedef unsigned short       uint16;   /**< 16-bit unsigned integer */
typedef signed short         sint16;   /**< 16-bit signed integer */
typedef unsigned long        uint32;   /**< 32-bit unsigned integer */
typedef signed long          sint32;   /**< 32-bit signed integer */
typedef unsigned long long   uint64;   /**< 64-bit unsigned integer */
typedef signed long long     sint64;   /**< 64-bit signed integer */


typedef float   float32;   /**< 32-bit floating-point number */
typedef double  float64;   /**< 64-bit floating-point number */

/* ===========================================
 *  Standard Return Type
 * =========================================== */
/**********************************************************
 * @typedef Std_ReturnType
 * @brief Standard return type
 * @details Used for API functions with predefined return values 
 *          such as E_OK and E_NOT_OK.
 **********************************************************/
typedef uint8 Std_ReturnType;
#define E_OK        0x00U   /**< Operation successful */
#define E_NOT_OK    0x01U   /**< Operation failed */

/* ===========================================
 *  Volatile Type Definitions
 * =========================================== */
/**********************************************************
 * @brief Volatile data types
 * @details Used for hardware registers or memory regions.
 **********************************************************/
typedef volatile uint8      vuint8;    /**< 8-bit unsigned volatile integer */
typedef volatile sint8      vsint8;    /**< 8-bit signed volatile integer */
typedef volatile uint16     vuint16;   /**< 16-bit unsigned volatile integer */
typedef volatile sint16     vsint16;   /**< 16-bit signed volatile integer */
typedef volatile uint32     vuint32;   /**< 32-bit unsigned volatile integer */
typedef volatile sint32     vsint32;   /**< 32-bit signed volatile integer */
typedef volatile uint64     vuint64;   /**< 64-bit unsigned volatile integer */
typedef volatile sint64     vsint64;   /**< 64-bit signed volatile integer */

/* ===========================================
 *  Boolean Type Definitions
 * =========================================== */
/**********************************************************
 * @typedef boolean
 * @brief Boolean data type
 * @details Used to represent true or false values.
 **********************************************************/
typedef uint8 boolean;

#ifndef TRUE
    #define TRUE    1U  /**< Boolean value TRUE */
#endif

#ifndef FALSE
    #define FALSE   0U  /**< Boolean value FALSE */
#endif

/* ===========================================
 *  Version Information Structure
 * =========================================== */
/**********************************************************
 * @typedef Std_VersionInfoType
 * @brief Version information structure
 * @details This structure stores version information 
 *          of a software module.
 **********************************************************/
typedef struct {
    uint16 vendorID;          /**< Vendor ID */
    uint16 moduleID;          /**< Module ID */
    uint8 sw_major_version;   /**< Major version of the software */
    uint8 sw_minor_version;   /**< Minor version of the software */
    uint8 sw_patch_version;   /**< Patch version of the software */
} Std_VersionInfoType;

/* ===========================================
 *  Development Error Tracer (DET) Report Error Macro
 * =========================================== */
/**********************************************************
 * @brief Macro to report errors to Development Error Tracer (DET)
 * @details Used to log development errors during execution.
 **********************************************************/
#define Det_ReportError(ModuleId, InstanceId, ApiId, ErrorId)  /* Report error to DET */

/* ===========================================
 *  Active/Idle State Definitions
 * =========================================== */
/**********************************************************
 * @brief Defines active/idle states
 * @details Used for system states.
 **********************************************************/
#define STD_ACTIVE   0x01U   /**< Active state */
#define STD_IDLE     0x00U   /**< Idle state */

/* ===========================================
 *  On/Off State Definitions
 * =========================================== */
/**********************************************************
 * @brief Defines on/off states
 * @details Used to control on/off states.
 **********************************************************/
#define STD_ON   0x01U   /**< ON state */
#define STD_OFF  0x00U   /**< OFF state */

#endif /* STD_TYPES_H */
