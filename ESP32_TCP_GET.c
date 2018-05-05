//////////////////////////////////////////////////////////////////
// ESP32 - TCP -GET
//
// ESP32 LIBRARY FOR TCP GET REQUESTS
//
// REFERENCE:
//
// MAY 05, 2018
//
// ANKIT BHATNAGAR
// ANKIT.BHATNAGARINDIA@GMAIL.COM
/////////////////////////////////////////////////////////////////

#include "ESP32_TCP_GET.h"

//INTERNAL VARIABLES
static bool s_debug;

//INTERNAL FUNCTIONS

void ESP32_TCP_GET_SNTP_SetDebug(bool enable)
{
	//SET THE DEBUG FLAG
	
	s_debug = enable;
}

void ESP32_TCP_GET_Initialize(void)
{
	//INITIALIZE MODULE
	
	ets_printf(ESP32_TCP_GET_TAG" : Initialized\n");
}


