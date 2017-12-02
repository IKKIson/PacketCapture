#include "L4_HTTP.h"

const void * L4_HTTP(const void *vpdata , unsigned int * UI_NEXT)
{
	const unsigned char *ucp_data = vpdata;
	printf("-------------------------------------------\n");		
	printf(" --------  HTTP  --------\n");
	printf("-------------------------------------------\n\n");
	while(0 != *UI_NEXT )
		{
			putchar(*ucp_data);
			++ucp_data;
			*UI_NEXT = *UI_NEXT - 1;
		}
	printf("-------------------------------------------\n\n");
	return vpdata;
}

