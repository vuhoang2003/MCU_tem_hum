#include <stdbool.h>
#include <stdint.h>
#include "driverlib/rom.h"
// #include "inc/hw_memmap.h"
#include "inc/hw_types.h"
// #include "driverlib/debug.h"
// #include "driverlib/gpio.h"
#include "driverlib/hibernate.h"
#include "driverlib/sysctl.h"
// #include "driverlib/systick.h"
// #include "utils/ustdlib.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"

#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/i2c.h"
#include "driverlib/timer.h"
#include "driverlib/watchdog.h"

#include "i2c_sensor.h"


// //*****************************************************************************
// //
// // The states in the interrupt handler state machine.
// //
// //*****************************************************************************
// #define I2C_SEN_MASTER_BASE         I2C1_BASE
// #define I2C_SEN_ADDR       0x03
// #define STATE_IDLE         0
// #define STATE_WRITE_NEXT   1
// #define STATE_WRITE_FINAL  2
// #define STATE_WAIT_ACK     3
// #define STATE_SEND_ACK     4
// #define STATE_READ_ONE     5
// #define STATE_READ_FIRST   6
// #define STATE_READ_NEXT    7
// #define STATE_READ_FINAL   8
// #define STATE_READ_WAIT    9

// //*****************************************************************************
// //
// // The variables that track the data to be transmitted or received.
// //
// //*****************************************************************************
// static unsigned char *g_pucData = 0;
// static unsigned long g_ulCount = 0;

// //*****************************************************************************
// //
// // The current state of the interrupt handler state machine.
// //
// //*****************************************************************************
// static volatile unsigned long g_ulState = STATE_IDLE;

// //*****************************************************************************
// //
// // The error routine that is called if the driver library encounters an error.
// //
// //*****************************************************************************
// // #ifdef DEBUG
// // void
// // __error__(char *pcFilename, unsigned long ulLine)
// // {
// // }
// // #endif

// //*****************************************************************************
// //
// // The I2C interrupt handler.
// //
// //*****************************************************************************
// void I2C_Sen_IntHandler(void)
// {
    // //
    // // Clear the I2C interrupt.
    // //
    // ROM_I2CMasterIntClear(I2C_SEN_MASTER_BASE);

    // //
    // // Determine what to do based on the current state.
    // //
    // switch(g_ulState)
    // {
        // //
        // // The idle state.
        // //
        // case STATE_IDLE:
        // {
            // //
            // // There is nothing to be done.
            // //
            // break;
        // }

        // //
        // // The state for the middle of a burst write.
        // //
        // case STATE_WRITE_NEXT:
        // {
            // //
            // // Write the next byte to the data register.
            // //
            // ROM_I2CMasterDataPut(I2C_SEN_MASTER_BASE, *g_pucData++);
            // g_ulCount--;

            // //
            // // Continue the burst write.
            // //
            // ROM_I2CMasterControl(I2C_SEN_MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);

            // //
            // // If there is one byte left, set the next state to the final write
            // // state.
            // //
            // if(g_ulCount == 1)
            // {
                // g_ulState = STATE_WRITE_FINAL;
            // }

            // //
            // // This state is done.
            // //
            // break;
        // }

        // //
        // // The state for the final write of a burst sequence.
        // //
        // case STATE_WRITE_FINAL:
        // {
            // //
            // // Write the final byte to the data register.
            // //
            // ROM_I2CMasterDataPut(I2C_SEN_MASTER_BASE, *g_pucData++);
            // g_ulCount--;

            // //
            // // Finish the burst write.
            // //
            // ROM_I2CMasterControl(I2C_SEN_MASTER_BASE,
                             // I2C_MASTER_CMD_BURST_SEND_FINISH);

            // //
            // // The next state is to wait for the burst write to complete.
            // //
            // g_ulState = STATE_SEND_ACK;

            // //
            // // This state is done.
            // //
            // break;
        // }

        // //
        // // Wait for an ACK on the read after a write.
        // //
        // case STATE_WAIT_ACK:
        // {
            // //
            // // See if there was an error on the previously issued read.
            // //
            // if(ROM_I2CMasterErr(I2C_SEN_MASTER_BASE) == I2C_MASTER_ERR_NONE)
            // {
                // //
                // // Read the byte received.
                // //
                // ROM_I2CMasterDataGet(I2C_SEN_MASTER_BASE);

                // //
                // // There was no error, so the state machine is now idle.
                // //
                // g_ulState = STATE_IDLE;

                // //
                // // This state is done.
                // //
                // break;
            // }

            // //
            // // Fall through to STATE_SEND_ACK.
            // //
        // }

        // //
        // // Send a read request, looking for the ACK to indicate that the write
        // // is done.
        // //
        // case STATE_SEND_ACK:
        // {
            // //
            // // Put the I2C master into receive mode.
            // //
            // ROM_I2CMasterSlaveAddrSet(I2C_SEN_MASTER_BASE, I2C_SEN_ADDR, true);

            // //
            // // Perform a single byte read.
            // //
            // ROM_I2CMasterControl(I2C_SEN_MASTER_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);

            // //
            // // The next state is the wait for the ack.
            // //
            // g_ulState = STATE_WAIT_ACK;

            // //
            // // This state is done.
            // //
            // break;
        // }

        // //
        // // The state for a single byte read.
        // //
        // case STATE_READ_ONE:
        // {
            // //
            // // Put the I2C master into receive mode.
            // //
            // ROM_I2CMasterSlaveAddrSet(I2C_SEN_MASTER_BASE, I2C_SEN_ADDR, true);

            // //
            // // Perform a single byte read.
            // //
            // ROM_I2CMasterControl(I2C_SEN_MASTER_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);

            // //
            // // The next state is the wait for final read state.
            // //
            // g_ulState = STATE_READ_WAIT;

            // //
            // // This state is done.
            // //
            // break;
        // }

        // //
        // // The state for the start of a burst read.
        // //
        // case STATE_READ_FIRST:
        // {
            // //
            // // Put the I2C master into receive mode.
            // //
            // ROM_I2CMasterSlaveAddrSet(I2C_SEN_MASTER_BASE, I2C_SEN_ADDR, true);

            // //
            // // Start the burst receive.
            // //
            // ROM_I2CMasterControl(I2C_SEN_MASTER_BASE,
                             // I2C_MASTER_CMD_BURST_RECEIVE_START);

            // //
            // // The next state is the middle of the burst read.
            // //
            // g_ulState = STATE_READ_NEXT;

            // //
            // // This state is done.
            // //
            // break;
        // }

        // //
        // // The state for the middle of a burst read.
        // //
        // case STATE_READ_NEXT:
        // {
            // //
            // // Read the received character.
            // //
            // *g_pucData++ = ROM_I2CMasterDataGet(I2C_SEN_MASTER_BASE);
            // g_ulCount--;

            // //
            // // Continue the burst read.
            // //
            // ROM_I2CMasterControl(I2C_SEN_MASTER_BASE,
                             // I2C_MASTER_CMD_BURST_RECEIVE_CONT);

            // //
            // // If there are two characters left to be read, make the next
            // // state be the end of burst read state.
            // //
            // if(g_ulCount == 2)
            // {
                // g_ulState = STATE_READ_FINAL;
            // }

            // //
            // // This state is done.
            // //
            // break;
        // }

        // //
        // // The state for the end of a burst read.
        // //
        // case STATE_READ_FINAL:
        // {
            // //
            // // Read the received character.
            // //
            // *g_pucData++ = ROM_I2CMasterDataGet(I2C_SEN_MASTER_BASE);
            // g_ulCount--;

            // //
            // // Finish the burst read.
            // //
            // ROM_I2CMasterControl(I2C_SEN_MASTER_BASE,
                             // I2C_MASTER_CMD_BURST_RECEIVE_FINISH);

            // //
            // // The next state is the wait for final read state.
            // //
            // g_ulState = STATE_READ_WAIT;

            // //
            // // This state is done.
            // //
            // break;
        // }

        // //
        // // This state is for the final read of a single or burst read.
        // //
        // case STATE_READ_WAIT:
        // {
            // //
            // // Read the received character.
            // //
            // *g_pucData++  = ROM_I2CMasterDataGet(I2C_SEN_MASTER_BASE);
            // g_ulCount--;

            // //
            // // The state machine is now idle.
            // //
            // g_ulState = STATE_IDLE;

            // //
            // // This state is done.
            // //
            // break;
        // }
    // }
// }

// //*****************************************************************************
// //
// // Write to the RTC device.
// //
// //*****************************************************************************
// void I2C_Sen_Write(unsigned char *pucData, unsigned long ulOffset, unsigned long ulCount)
// {
    // //
    // // Save the data buffer to be written.
    // //
    // g_pucData = pucData;
    // g_ulCount = ulCount;

    // //
    // // Set the next state of the interrupt state machine based on the number of
    // // bytes to write.
    // //
    // if(ulCount != 1)
    // {
        // g_ulState = STATE_WRITE_NEXT;
    // }
    // else
    // {
        // g_ulState = STATE_WRITE_FINAL;
    // }

    // //
    // // Set the slave address and setup for a transmit operation.
    // //
    // ROM_I2CMasterSlaveAddrSet(I2C_SEN_MASTER_BASE, I2C_SEN_ADDR | (ulOffset >> 8), false);

    // //
    // // Place the address to be written in the data register.
    // //
    // ROM_I2CMasterDataPut(I2C_SEN_MASTER_BASE, ulOffset);

    // //
    // // Start the burst cycle, writing the address as the first byte.
    // //
    // ROM_I2CMasterControl(I2C_SEN_MASTER_BASE, I2C_MASTER_CMD_BURST_SEND_START);

    // //
    // // Wait until the I2C interrupt state machine is idle.
    // //
    // while(g_ulState != STATE_IDLE)
    // {
    // }
// }

// //*****************************************************************************
// //
// // Read from the RTC device.
// //
// //*****************************************************************************
// void I2C_Sen_Read(unsigned char *pucData, unsigned long ulOffset, unsigned long ulCount)
// {
    // //
    // // Save the data buffer to be read.
    // //
    // g_pucData = pucData;
    // g_ulCount = ulCount;

    // //
    // // Set the next state of the interrupt state machine based on the number of
    // // bytes to read.
    // //
    // if(ulCount == 1)
    // {
        // g_ulState = STATE_READ_ONE;
    // }
    // else
    // {
        // g_ulState = STATE_READ_FIRST;
    // }

    // //
    // // Start with a dummy write to get the address set in the RTC.
    // //
    // ROM_I2CMasterSlaveAddrSet(I2C_SEN_MASTER_BASE, I2C_SEN_ADDR | (ulOffset >> 8), false);

    // //
    // // Place the address to be written in the data register.
    // //
    // ROM_I2CMasterDataPut(I2C_SEN_MASTER_BASE, ulOffset);

    // //
    // // Perform a single send, writing the address as the only byte.
    // //
    // ROM_I2CMasterControl(I2C_SEN_MASTER_BASE, I2C_MASTER_CMD_SINGLE_SEND);

    // //
    // // Wait until the I2C interrupt state machine is idle.
    // //
    // while(g_ulState != STATE_IDLE)
    // {
    // }
// }


// void I2C_Sen_Init(void)
// {
    // //SleepModeInit();
	// // Enable the peripheral
    // ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C1);    
    // ROM_SysCtlPeripheralSleepEnable(SYSCTL_PERIPH_I2C1);
    // ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);    
    // ROM_SysCtlPeripheralSleepEnable(SYSCTL_PERIPH_GPIOA);
	
    // // Enable processor interrupts.
    // ROM_IntMasterEnable();
	
    // // Configure the appropriate pins to be I2C instead of GPIO.
    // ROM_GPIOPinTypeI2C(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7);
	
    // // Initialize the I2C master at 400KHz.
    // ROM_I2CMasterInitExpClk(I2C_SEN_MASTER_BASE, SysCtlClockGet(), true);
	
    // // Enable the I2C interrupt.
    // ROM_IntEnable(INT_I2C1);
	
    // // Enable the I2C master interrupt.
    // ROM_I2CMasterIntEnable(I2C_SEN_MASTER_BASE);
	
// }

// void HibernateHandler(void)
// {
	// //unsigned long ulStatus;
    // // HibernateIntClear(HIBERNATE_INT_RTC_MATCH_0);

	// // HibernateRTCSet(0);
	// // HibernateRTCMatch0Set(1);
    // // ulNVData[0]+=1;
	// // ulNVData[1]+=2;
	
	
	
	
	
			
	
	// // ulStatus = HibernateIntStatus(1);
	// // HibernateIntClear(ulStatus);
	// ROM_HibernateIntClear(HIBERNATE_INT_RTC_MATCH_0);
	// //HibernateDataGet(ulNVData, 64);
	// // if(ulStatus & HIBERNATE_INT_RTC_MATCH_0){
		
	// //	HibernateRTCSet(0);
		// // HibernateRTCMatch0Set(1);
	// //	HibernateRTCMatch0Set(HibernateRTCGet() + 1);
	// // }
	// //UpdateTimeParameters();
	// //HibernateDataSet(ulNVData, 64);
	
// }

// void SleepModeInit(void){
    // ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_WDOG0);
    // ROM_SysCtlPeripheralSleepEnable(SYSCTL_PERIPH_WDOG0);
    // //SysCtlPeripheralClockGating(true);
    // ROM_IntMasterEnable();
    // ROM_IntPrioritySet(INT_WATCHDOG, 0x40);	
	
    // ROM_IntEnable(INT_WATCHDOG);
	
    // // Set the period of the watchdog timer.
    // ROM_WatchdogReloadSet(WATCHDOG0_BASE, SysCtlClockGet()/2);

    // // Enable reset generation from the watchdog timer.
    // ROM_WatchdogResetEnable(WATCHDOG0_BASE);

    // // Enable the watchdog timer.
    // ROM_WatchdogEnable(WATCHDOG0_BASE);
// }

// void WatchdogIntHandler(void)
// {
    // //
    // // Clear the watchdog interrupt.
    // //
    // ROM_WatchdogIntClear(WATCHDOG0_BASE);
// }




#define SHT_DATA_OUT(x)				ROM_GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, x*GPIO_PIN_7)
#define SHT_DATA_IN					((ROM_GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_7)>>7)&1)
#define SHT_CLK(x)					ROM_GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, x*GPIO_PIN_6)
#define __delay_us(x)				ROM_SysCtlDelay(x*10)	// 1 cycle = 0.02 us

unsigned char SHT_Resolution= 0;
void SHT_ResetConection(void)
{
	unsigned char i;
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    ROM_GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_6|GPIO_PIN_7);//// CLK DATA la chan ra
	SHT_DATA_OUT(1);// kéo chân DATA lên m?c cao
	for (i=0; i<9; i++)// vòng l?p for t?o xung clock lên chân CLK d? reset c?m bi?n
	{
		SHT_CLK(1);
		SHT_CLK(0);
	}
	SHT_DATA_OUT(1);
	SHT_CLK(0);
	SHT_CLK(1);
	SHT_DATA_OUT(0);
	SHT_CLK(0);
	SHT_CLK(1);
	SHT_DATA_OUT(1);
	SHT_CLK(0);
}


void SHT_Init(unsigned char resolution)
{
	SHT_ResetConection();
	SHT_WriteByte(SHT_STATUS_REG_W);
	// __delay_ms(300);
	__delay_us(5);
	SHT_WriteByte(resolution);
	SHT_Resolution=resolution;
}

unsigned char SHT_WriteByte(unsigned char Data)
{
	unsigned char i, error = 0;
	ROM_GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_7);//// DATA la chan ra
	__delay_us(1);
	for(i = 0x80; i > 0; i /= 2)
	{
		SHT_CLK(0);
		if(i & Data) SHT_DATA_OUT(1);
		else SHT_DATA_OUT(0);
		__delay_us(1);
		SHT_CLK(1);
		__delay_us(1);
	}
	SHT_CLK(0);
	ROM_GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_7); // Data la chan vao
	__delay_us(1);
	SHT_CLK(1);
	__delay_us(1);
	error = SHT_DATA_IN;
	SHT_CLK(0);
        __delay_us(5);
	//__delay_ms(250);
	return(error);
}


unsigned char SHT_ReadByte(unsigned char ack)
{
	unsigned char i, val = 0;
	ROM_GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_7); // Data la chan vao
	for(i = 0x80; i > 0; i /= 2)
	{
		SHT_CLK(1);
		__delay_us(1);
		if(SHT_DATA_IN) val = val | i;
		__delay_us(1);
		SHT_CLK(0);
	}
	ROM_GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_7);//// DATA la chan ra
	__delay_us(1);
	SHT_DATA_OUT(!ack);
	SHT_CLK(1);
	__delay_us(1);
	SHT_CLK(0);
	return(val);
}


unsigned int SHT_ReadSenSor(unsigned char Command)
{
	unsigned char msb, lsb, crc;
	SHT_ResetConection();
	if(SHT_WriteByte(Command)) 
	{
		return 0xffff;
	}
	// SHT_WriteByte(Command);
	while(SHT_DATA_IN);
	msb = SHT_ReadByte(SHT_ACK);
	lsb = SHT_ReadByte(SHT_ACK);
	crc = SHT_ReadByte(SHT_NOACK);
	return(((unsigned int) msb << 8) | (unsigned int) lsb);
}

void SHT_ReadTemHumi(float *tem, float *humi)
{
	unsigned int SOT;
	unsigned int SORH;
	SOT=SHT_ReadSenSor(SHT_MEASURE_TEMP);
	SORH=SHT_ReadSenSor(SHT_MEASURE_HUMI);
	if((SOT!=0xffff) && (SORH!=0xffff))
	{
		if(SHT_Resolution==SHT_14_12_BIT)
		{
			*tem=(H_D1+H_D2*SOT);
			*humi= ((H_D1+H_D2*SOT-25)*(H_T1+H_T2*SORH)+H_C1+H_C2*SORH+H_C3*SORH*SORH);
		}
		else
		{
			*tem=(L_D1+L_D2*SOT);
			*humi= ((L_D1+L_D2*SOT- 25)*(L_T1+L_T2*SORH)+L_C1+L_C2*SORH+L_C3*SORH*SORH);
		}
	}
}
