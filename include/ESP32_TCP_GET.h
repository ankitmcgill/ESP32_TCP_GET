//////////////////////////////////////////////////////////////////
// ESP32 - TCP -GET
//
// ESP32 LIBRARY FOR TCP GET REQUESTS
//
// REFERENCE:
//	
//	(1) NEIL KOLBAN ESP32 EBOOK
//	(2) https://github.com/espressif/esp-idf/tree/master/examples
//  (3) https://github.com/espressif/esp-idf/blob/master/examples/protocols/http_request/main/http_request_example_main.c
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

#define ESP32_TCP_GET_TAG		            "ESP32:TCP_GET"

#define ESP32_TCP_GET_RETRY_COUNT           (3)
#define ESP32_TCP_GET_REPLY_TIMEOUT_SEC     (5)

#define ESP8266_TCP_GET_GET_REQUEST_STRING "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n"

void ESP32_TCP_GET_SNTP_SetDebug(bool enable);
void ESP32_TCP_GET_Initialize(ip_addr_t* dns1,
								ip_addr_t* dns2,
                                void (*user_cb)(char*));

bool ESP32_TCP_GET_RunGetRequest(char* hostname,
                                    char* path,
                                    char* port,
									char* response,
									uint16_t response_len);

#endif
