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


#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include "lwip/netdb.h"
#include "lwip/dns.h"
#include "ESP32_TCP_GET.h"

//INTERNAL VARIABLES
static bool s_debug;

//TCP REPLATED
static uint8_t s_esp32_tcp_get_attempt_count;

//BUFFERS
static char* s_esp32_tcp_get_buffer_request;
static char* s_esp32_tcp_get_buffer_response;

//CALLBACK FUNCTION VARIABLE
static void (*s_esp32_tcp_get_user_cb)(char*);

//INTERNAL FUNCTIONS

void ESP32_TCP_GET_SNTP_SetDebug(bool enable)
{
	//SET THE DEBUG FLAG
	
	s_debug = enable;
}

void ESP32_TCP_GET_Initialize(ip_addr_t* dns1,
								ip_addr_t* dns2,
                                void (*user_cb)(char*))
{
	//INITIALIZE MODULE
	
	s_esp32_tcp_get_attempt_count = 0;

	s_esp32_tcp_get_user_cb = user_cb;

	s_esp32_tcp_get_buffer_request = (char*)malloc(150);
	s_esp32_tcp_get_buffer_request = (char*)malloc(300);

	//SET DNS SERVER
	if(dns1 != NULL)
	{
		dns_setserver(1, dns1);
		ets_printf(ESP32_TCP_GET_TAG" : DNS 1 = %s\n", dns1);
	}

	if(dns2 != NULL)
	{
		dns_setserver(2, dns2);
		ets_printf(ESP32_TCP_GET_TAG" : DNS 2 = %s\n", dns2);
	}


	ets_printf(ESP32_TCP_GET_TAG" : Initialized\n");
}

bool ESP32_TCP_GET_RunGetRequest(char* hostname,
                                    char* path,
                                    char* port)
{
	//GENERATE GET STRING AND INITIATE TCP GET REQUEST

	//GENRATE GET STRING
	sprintf(s_esp32_tcp_get_buffer_request,
			ESP8266_TCP_GET_GET_REQUEST_STRING,
			hostname,
			path);
	
	if(s_debug)
	{
		ets_printf(ESP32_TCP_GET_TAG" : GET str = %s\n", s_esp32_tcp_get_buffer_request);
	}

	struct in_addr* address;
	struct addrinfo* resolved;
	struct addrinfo hints = {
							.ai_family = AF_INET,
							.ai_socktype = SOCK_STREAM
						};

	esp_err_t err;
	err = getaddrinfo(hostname, port, &hints, &resolved);

	if(err != ESP_OK || resolved == NULL)
	{
		ets_printf(ESP32_TCP_GET_TAG" : DNS resolve error. stopping !!!\n");
		return false;
	}

	//DNS RESOLVED. PRINT IP
	address = &((struct sockaddr_in*)resolved->ai_addr)->sin_addr;
	ets_printf(ESP32_TCP_GET_TAG" : DNS resolved = %s\n", inet_ntoa(*address));

	return true;
}

