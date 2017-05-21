#ifndef BBBIO_IT_CTRLR_H
#define BBBIO_IT_CTRLR_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <errno.h>
#include "BBBiolib.h"

/* IT controller Registers */

#define INTCPS_MMAP_ADDR	0x48200000
#define INTCPS_MMAP_LEN		0x1000

/* Register offset*/

#define INTC_SYSCONFIG	0x10
#define INTC_IDLE		0x50
#define INTC_MIR0		0x84
#define INTC_MIR_CLEAR0	0x88
#define INTC_MIR_SET0	0x8C
#define INTC_MIR1		0xA4
#define INTC_MIR_CLEAR1	0xA8
#define INTC_MIR_SET1	0xAC
#define INTC_MIR2		0xC4
#define INTC_MIR_CLEAR2	0xC8
#define INTC_MIR_SET2	0xCC
#define INTC_MIR3		0xE4
#define INTC_MIR_CLEAR3	0xE8
#define INTC_MIR_SET3	0xEC
#define INTC_ILR_start	0x100

/*Externs*/
extern int memh;
/* ---------------------------------------------------------------------------- */
/*Functions*/
int BBBIO_IT_CTRLR_Init();
void BBBIO_IT_CTRLR_Release();
int BBBIO_IT_CTRLR_Enable_GPIO_IT();
int BBBIO_IT_CTRLR_Disable_GPIO_IT();

#endif
