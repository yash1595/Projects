#include "SPI_Driver.h"

/******************************************************************
******************* Initiliazses the UCA0CTLW0 register************
******************************************************************/
void SPI_Init(uint8_t ClockPhase,uint32_t ClockFreq,uint8_t MSB, uint8_t CharLen,uint16_t mode,uint16_t ClockSource,uint8_t DefinedClockSource)
{	
	/*Setting GPIO for the fucnctions*/
	GPIO_SPI_SET();
	/*Set up the the Bit values in SPI Control register*/
	_UCA0CTLW0_->ClockSource=ClockSource;
	_UCA0CTLW0_->Msb=Msb;
	_UCA0CTLW0_->CharLen=CharLen;
	_UCA0CTLW0_->mode=mode;
	_UCA0CTLW0_->ClockPhase=ClockPhase;
	_UCA0CTLW0_->reset = RESET;
	/*Use the CS_getSMCLK() for calculating the bits to be written to UCA0BRW(Bit Rate Control Register)*/
	_UCA0BRW_=CS_getSMCLK()/ClockFreq;		//Alt gt SMCLK frequency and check.

}
/********************************************************************
********************* Set the GPIO Pins to SPI Mode******************
********************************************************************/
void GPIO_SPI_SET()
{
		
	P1DIR |= GPIO_SPI;		//Set as input or output
	P1OUT |= GPIO_SPI;		//Set state to high
	P1SEL0 &= ~GPIO_SPI;	//Set the pins to SPI Mode
	P1SEL1 &= ~GPIO_SPI;	
}
/********************************************************************
*********************SPI Receive Function******************
********************************************************************/
uint8_t* SPI_Receive()
{
    while(_UCA0STATW_ & _UCBUSY_==1);
    uint8_t* Data = (uint8_t*)SPIReceiveBuff;
    return Data;
}
/********************************************************************
*********************SPI Transmit Function***************************
********************************************************************/
void SPI_Transmit(uint8_t* Data)
{
    while(_UCA0STATW_ & _UCBUSY_==1);
    SPITransmitBuff=*Data;
}