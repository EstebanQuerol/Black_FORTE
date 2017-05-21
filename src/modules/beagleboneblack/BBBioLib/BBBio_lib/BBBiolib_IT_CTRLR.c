#include "BBBiolib_IT_CTRLR.h"


volatile unsigned int * itctrl_ptr = NULL;
/* Functions */

/* ----------------------------------------------------------------------------------------------- */
/* Interruption controller init
 *	iolib_init will run this function automatically
 *
 *      @return         : 1 for success , 0 for failed
 */

int BBBIO_IT_CTRLR_Init()
{

	if (memh == 0) {
#ifdef BBBIO_LIB_DBG
		printf("BBBIO_IT_CTRLR_Init: memory not mapped?\n");
#endif
		return 0;
    }

	/* Create Memory map */
	itctrl_ptr = mmap(0, INTCPS_MMAP_LEN, PROT_READ | PROT_WRITE, MAP_SHARED, memh, INTCPS_MMAP_ADDR);

	if(itctrl_ptr == MAP_FAILED) {
#ifdef BBBIO_LIB_DBG
			printf("BBBIO_IT_CTRLR_Init: IT controller mmap failure! ,error :%s\n" ,strerror(errno)));
#endif
			return 0;
	}
	if(0 != BBBIO_IT_CTRLR_Enable_GPIO_IT()){
#ifdef BBBIO_LIB_DBG
			printf("BBBIO_IT_CTRLR_Init: Error unmasking GPIO ITs! ,error :%s\n" ,strerror(errno)));
#endif
			return 0;
	}
	return 1;
}

/* ----------------------------------------------------------------------------------------------- */
/* Interruption controller release
 */
void BBBIO_IT_CTRLR_Release()
{
	if(itctrl_ptr != NULL) {
		munmap((void *)itctrl_ptr, INTCPS_MMAP_LEN);
		itctrl_ptr = NULL;
	}
}

//-----------------------------------------------------------------------------------------------
/*********************************
 Enable GPIO modules interruptions
 *******************************
 * Unmask GPIO0, GPIO1, GPIO2 and GPIO3 modules interruptions
 *	@return		: 1 for success , 0 for failed
 *
 *	Warning		: By default only "A" channel interruptions are unmasked
 */
int BBBIO_IT_CTRLR_Enable_GPIO_IT(){
	//TODO: Add priority as parameter?
	volatile unsigned int* reg;		//register

	// sanity checks
	if (itctrl_ptr==0) {
#ifdef BBBIO_LIB_DBG
		printf("BBBIO_IT_CTRLR_Enable_GPIO_IT: mmap error!\n");
#endif
		return 0;
	}

	//GPIO0
	reg = itctrl_ptr + INTC_MIR_CLEAR3;
	*reg = 1<<0;
	//GPIO1
	reg = itctrl_ptr + INTC_MIR_CLEAR3;
	*reg = 1<<2;
	//GPIO2
	reg = itctrl_ptr + INTC_MIR_CLEAR1;
	*reg = 1<<0;
	//GPIO3
	reg = itctrl_ptr + INTC_MIR_CLEAR1;
	*reg = 1<<30;
	return 1;
}

//-----------------------------------------------------------------------------------------------
/*********************************
 Disable GPIO modules interruptions
 *******************************
 * Mask GPIO0, GPIO1, GPIO2 and GPIO3 modules interruptions
 *	@return		: 1 for success , 0 for failed
 *
 *	Warning		: By default only "A" channel interruptions are masked
 */
int BBBIO_IT_CTRLR_Disable_GPIO_IT(){
	//TODO: Add priority as parameter?
	volatile unsigned int* reg;		//register

	// sanity checks
	if (itctrl_ptr==0) {
#ifdef BBBIO_LIB_DBG
		printf("BBBIO_IT_CTRLR_Disable_GPIO_IT: mmap error!\n");
#endif
		return 0;
	}

	//GPIO0
	reg = itctrl_ptr + INTC_MIR_SET3;
	*reg = 1<<0;
	//GPIO1
	reg = itctrl_ptr + INTC_MIR_SET3;
	*reg = 1<<2;
	//GPIO2
	reg = itctrl_ptr + INTC_MIR_SET1;
	*reg = 1<<0;
	//GPIO3
	reg = itctrl_ptr + INTC_MIR_SET1;
	*reg = 1<<30;
	return 1;
}
