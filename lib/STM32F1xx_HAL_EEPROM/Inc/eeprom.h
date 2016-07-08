/**
  ******************************************************************************
  * @file    EEPROM_Emulation/inc/eeprom.h
  * @author  MCD Application Team
  * @version V3.1.0
  * @date    07/27/2009
  * @brief   Contains all the functions prototypes for the EEPROM emulation
  *          firmware library.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2009 STMicroelectronics</center></h2>
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EEPROM_H
#define __EEPROM_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "application.h"

/* Exported constants --------------------------------------------------------*/
/* Define the STM32F1xxxx flash page size depending on the used STM32 device */
#if defined (STM32F100x4) || defined (STM32F100x6) || defined (STM32F100x8) || defined (STM32F100xB) || \
    defined (STM32F101x4) || defined (STM32F101x6) || defined (STM32F101x8) || defined (STM32F101xB) || \
    defined (STM32F102x4) || defined (STM32F102x6) || defined (STM32F102x8) || defined (STM32F102xB) || \
    defined (STM32F103x4) || defined (STM32F103x6) || defined (STM32F103x8) || defined (STM32F103xB) || \
    defined (STM32F105x8) || defined (STM32F105xB) || defined (STM32F107xB)
  #define PAGE_SIZE  (uint16_t)0x400  /* Page size = 1KByte */
#else
  #define PAGE_SIZE  (uint16_t)0x800  /* Page size = 2KByte */
  #warning Make sure that the flash page size of your device is 2kBytes.
#endif

/* EEPROM operation timeout */
#define EEPROM_ERASE_TIMEOUT    FLASH_TIMEOUT_VALUE

/* EEPROM start address in Flash */
#define EEPROM_START_ADDRESS    ((uint32_t)0x0800F800) /* EEPROM emulation start address:
                                                  after 62KByte of used Flash memory */

/* Pages 0 and 1 base and end addresses */
#define PAGE0_BASE_ADDRESS      ((uint32_t)(EEPROM_START_ADDRESS + 0x000))
#define PAGE0_END_ADDRESS       ((uint32_t)(EEPROM_START_ADDRESS + (PAGE_SIZE - 1)))

#define PAGE1_BASE_ADDRESS      ((uint32_t)(EEPROM_START_ADDRESS + PAGE_SIZE))
#define PAGE1_END_ADDRESS       ((uint32_t)(EEPROM_START_ADDRESS + (2 * PAGE_SIZE - 1)))

/* Used Flash pages for EEPROM emulation */
#define PAGE0                   ((uint16_t)0x0000)
#define PAGE1                   ((uint16_t)0x0001)

/* No valid page define */
#define NO_VALID_PAGE           ((uint16_t)0x00AB)

/* Page status definitions */
#define ERASED                  ((uint16_t)0xFFFF)     /* PAGE is empty */
#define RECEIVE_DATA            ((uint16_t)0xEEEE)     /* PAGE is marked to receive data */
#define VALID_PAGE              ((uint16_t)0x0000)     /* PAGE containing valid data */

/* Valid pages in read and write defines */
#define READ_FROM_VALID_PAGE    ((uint8_t)0x00)
#define WRITE_IN_VALID_PAGE     ((uint8_t)0x01)

/* Page full define */
#define PAGE_FULL               ((uint8_t)0x80)

/* Variables' number */
#define NUMBER_OF_VARIABLES     ((uint8_t)ADDRESS_LENGTH)

/* Exported types ------------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
uint16_t EE_Init(void);
HAL_StatusTypeDef EE_ReadVariable(uint16_t VirtAddress, uint16_t* Data);
uint16_t EE_WriteVariable(uint16_t VirtAddress, uint16_t Data);

#endif /* __EEPROM_H */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/