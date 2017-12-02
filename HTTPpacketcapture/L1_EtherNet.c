#include "L1_EtherNet.h"


const void * L1_EtherNet(const void *vpData , unsigned int *UIP_NEXT)
{
	const struct ether_header *stp_eth = vpData;
	/* eth_shost */
	printf("[%02X:%02X:%02X:%02X:%02X:%02X] -> "
		  "[%02X:%02X:%02X:%02X:%02X:%02X]\n"
	,stp_eth -> ether_shost[0]
	,stp_eth -> ether_shost[1]
	,stp_eth -> ether_shost[2]
	,stp_eth -> ether_shost[3]
	,stp_eth -> ether_shost[4]
	,stp_eth -> ether_shost[5]
	/*ether_dhost */
	,stp_eth -> ether_dhost[0]
	,stp_eth -> ether_dhost[1]
	,stp_eth -> ether_dhost[2]
	,stp_eth -> ether_dhost[3]
	,stp_eth -> ether_dhost[4]
	,stp_eth -> ether_dhost[5]);

	printf("-------------------------------------------\n");		
	printf(" --------  Ether Net Adderss  --------\n");
	printf("-------------------------------------------\n\n");
	printf("Destination Address = [%02X:%02X:%02X:%02X:%02X:%02X]\n"
		,stp_eth -> ether_dhost[0]
		,stp_eth -> ether_dhost[1]
		,stp_eth -> ether_dhost[2]
		,stp_eth -> ether_dhost[3]
		,stp_eth -> ether_dhost[4]
		,stp_eth -> ether_dhost[5]);
	printf("Source Address      = [%02X:%02X:%02X:%02X:%02X:%02X]\n"
		,stp_eth -> ether_shost[0]
		,stp_eth -> ether_shost[1]
		,stp_eth -> ether_shost[2]
		,stp_eth -> ether_shost[3]
		,stp_eth -> ether_shost[4]
		,stp_eth -> ether_shost[5]);
	
	//printf("%04X\n",ntohs(stp_eth -> ether_type)); //확인 코드 
	switch(ntohs(stp_eth -> ether_type))
	{
	
		case ETHERTYPE_PUP:
			printf("Packet Type = Xerox PUP\n");
			
			break;

		case ETHERTYPE_IP:
			printf("Packet Type = IP \n");
			
			break;

		case ETHERTYPE_ARP:
			printf("Packet Type = Address Resoluation\n");
			
			break;

		case ETHERTYPE_REVARP:
			printf("Packet Type = Reverse ARP\n");
			
			break;
			
		default :
			printf(" Packet  :  UnKnwon \n");
		
			
	}
	*UIP_NEXT = ntohs(stp_eth -> ether_type);
	vpData = stp_eth + 1; //주소가 14byte 만큼 이동 
	return vpData;
}



