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

#ifndef _ESP32_TCP_GET_
#define _ESP32_TCP_GET_

#include <stdio.h>
#include <stdbool.h>
#include "esp_system.h"
#include "esp_err.h"
#include "esp_log.h"

#define ESP32_TCP_GET_TAG				"ESP32:TCP_GET"

void ESP32_TCP_GET_SNTP_SetDebug(bool enable);

void ESP32_TCP_GET_Initialize(void);

#endif
