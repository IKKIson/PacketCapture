#include "L2_ARP.h"

const void * L2_ARP(const void *vpData , unsigned int * UIP_NEXT)
{
	const struct ether_arp * stp_ARP = vpData;
	printf("-------------------------------------------\n");
	printf("     --------  ARP Header  --------\n");
	printf("-------------------------------------------\n\n");
	switch(ntohs(stp_ARP -> arp_hrd))
		{
				/* ARP protocol HARDWARE identifiers. */
				case ARPHRD_NETROM:
				printf("Hardware Type = from KA9Q: NET/ROM pseudo  \n");
				break;
				case ARPHRD_ETHER :
				printf("Hardware Type = Ethernet 10Mbps \n");
				break;
				case ARPHRD_EETHER:
				printf("Hardware Type = Experimental Ethernet \n");
				break;
				case ARPHRD_AX25 :
				printf("Hardware Type = AX.25 Level 2  \n");
				break;
				case ARPHRD_PRONET:
				printf("Hardware Type = PROnet token ring  \n");
				break;
				case ARPHRD_CHAOS:
				printf("Hardware Type =  Chaosnet  \n");
				break;
				case ARPHRD_IEEE802:
				printf("Hardware Type = IEEE 802.2 Ethernet/TR/TB  \n");
				break;

				case ARPHRD_ARCNET:
				printf("Hardware Type = ARCnet \n");
				break;
				case ARPHRD_APPLETLK:
				printf("Hardware Type =  APPLEtalk\n");
				break;
				
				case ARPHRD_DLCI :
				printf("Hardware Type = Frame Relay DLCI\n");
				break;
  				case ARPHRD_ATM :
				printf("Hardware Type = ATM  \n");
				break;
				case ARPHRD_METRICOM :          
				printf("Hardware Type = Metricom STRIP (new IANA id)\n");
				break;
  		}
		printf("-------------------------------------------\n");
		switch(ntohs(stp_ARP -> arp_pro))
		{
	
			case ETHERTYPE_PUP:
				printf("Protocol Type = Xerox PUP\n");
				
				break;

			case ETHERTYPE_IP:
				printf("Protocol  Type = IP \n");
				
				break;

			case ETHERTYPE_ARP:
				printf("Protocol  Type = Address Resoluation\n");
				
				break;

			case ETHERTYPE_REVARP:
				printf("Protocol  Type = Reverse ARP\n");
				
				break;
				
			default :
				printf("Protocol   =  UnKnwon \n");
			
			
		}		
		printf("-------------------------------------------\n");
		switch(ntohs(stp_ARP -> arp_op))
			{
				/* ARP Protocol opcodes.*/
				case ARPOP_REQUEST  :          
				printf("Protocol opcode = ARP request\n");
				break;
				case ARPOP_REPLY    :        
				printf("Protocol opcode = ARP reply                   \n");
				break;
				case ARPOP_RREQUEST  :         
				printf("Protocol opcode = RARP request                \n");
				break;
				case ARPOP_RREPLY    :          
				printf("Protocol opcode = RARP reply                  \n");
				break;
				case ARPOP_InREQUEST:           
				printf("Protocol opcode = InARP request               \n");
				break;
				case ARPOP_InREPLY   :            
				printf("Protocol opcode = InARP reply                 \n");
				break;
				case ARPOP_NAK   :           
				printf("Protocol opcode = (ATM)ARP NAK                \n");
				break;
			}	
		printf("-------------------------------------------\n");
		printf("Length of hardware address = %d\n",stp_ARP ->arp_hln);
		printf("-------------------------------------------\n");
		printf("Length of Protocol address = %d\n",stp_ARP ->arp_pln);
		printf("-------------------------------------------\n");
		
		printf("Sender H/W Address = [%02X:%02X:%02X:%02X:%02X:%02X]\n"
		,stp_ARP -> arp_sha[0]
		,stp_ARP -> arp_sha[1]
		,stp_ARP -> arp_sha[2]
		,stp_ARP -> arp_sha[3]
		,stp_ARP -> arp_sha[4]
		,stp_ARP -> arp_sha[5]);
		printf("-------------------------------------------\n");
		printf("Sender P/T Address = [%d.%d.%d.%d]\n"
		,stp_ARP -> arp_spa[0]
		,stp_ARP -> arp_spa[1]
		,stp_ARP -> arp_spa[2]
		,stp_ARP -> arp_spa[3]);
		
		printf("Sender P/T Address = %s \n",inet_ntoa(*((struct in_addr*)stp_ARP -> arp_spa)));
		printf("-------------------------------------------\n");
		
		printf("Target H/W Address = [%02X:%02X:%02X:%02X:%02X:%02X]\n"
		,stp_ARP -> arp_tha[0]
		,stp_ARP -> arp_tha[1]
		,stp_ARP -> arp_tha[2]
		,stp_ARP -> arp_tha[3]
		,stp_ARP -> arp_tha[4]
		,stp_ARP -> arp_tha[5]);
		printf("-------------------------------------------\n");
		printf("Target P/T Address = [%d.%d.%d.%d]\n"
		,stp_ARP -> arp_tpa[0]
		,stp_ARP -> arp_tpa[1]
		,stp_ARP -> arp_tpa[2]
		,stp_ARP -> arp_tpa[3]);

		printf("Target P/T Address = %s \n",inet_ntoa(*((struct in_addr*)stp_ARP -> arp_tpa)));
		
		printf("-------------------------------------------\n");
		
		
	vpData = ((unsigned char *)vpData + 28);
	return vpData;
}

