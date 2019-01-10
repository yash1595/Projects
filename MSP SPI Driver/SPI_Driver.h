#include <stdint.h>
#include <stdio.h>

#define SPI_BASE_ADD	((uint32_t*)0x40002000)
#define _UCA0BRW_     	((*(uint32_t*)0x40001006))
#define _UCA0STATW_   	((*(uint32_t*)0x4000100A))

#define SPI_RX_BUFF		((uint32_t)0x4000200C)
#define SPI_TX_BUFF		((uint32_t)0x4000200E)							
#define ACK 	 		((uint16_t)(0x0000))
#define SMCLK 	 		((uint16_t)(0x0001))
#define PIN3SPI  		((uint16_t)(0x0000))
#define PIN4SPI  		((uint16_t)(0x0001))
#define I2C  	 		((uint16_t)(0x0003))
#define _UCBUSY_   		((uint16_t)(0x0001))
#define RESET	 		((uint16_t)(0x0001))
#define GPIO_SPI 		((uint8_t)(0X0E)) 		// [0000 1110] ==> P1.5-P1.7

#define BYTES 		16
#define	MSB 		0
#define LSB 		1
#define BITS7 		1
#define	BITS8 		0

/******************************************************************
***************Structure storing Register UCAxCTLW0****************
*******************************************************************/
typedef struct{						
	uint8_t ClockPhase;
	uint8_t ClockPolarity;
	uint8_t Msb;
	uint8_t CharLen;
	uint8_t Master;
	uint16_t mode;
	uint8_t sync;
	uint16_t ClockSource;
	uint16_t Reserved;
	uint8_t stem;
	uint8_t reset;
}SPI_Configuration_Register;					//Structure to store the 16-bit register SPI Control Register UCAxCTLW0.
SPI_Configurations* _UCA0CTLW0_ = SPI_BASE_ADD; //Pointer to Memory locaiton where the structure is to be located in the Microcontroller.

/******************************************************************
***********************Function Declarations***********************
*******************************************************************/
void SPI_Init(uint8_t,uint32_t,uint8_t,uint8_t,uint16_t,uint16_t);
void GPIO_SPI_SET(void);
uint8_t* SPI_Receive(void);
void SPI_Transmit(uint8_t*);