#include "L2_IP.h"

const void * L2_IP(const void *vpData , unsigned int * UIP_NEXT , unsigned int *IP_HD)
{
	const struct ip *stp_IP = vpData;
//	unsigned int A = 0x00FF00FF;
	printf("-------------------------------------------\n");
	printf("-------------------------------------------\n");
	printf("     --------  IP Header  --------\n");
	printf("-------------------------------------------\n\n");
	printf("IP_Version : %d\n",stp_IP -> ip_v);
	printf("-------------------------------------------\n");
	printf("IP_Header Length : %d , SIZE : %d Byte\n",stp_IP->ip_hl, ((stp_IP->ip_hl) * 4) );
	printf("-------------------------------------------\n");		
	

	switch(IPTOS_TOS(stp_IP->ip_tos))
	{
		case  IPTOS_LOWDELAY:
			printf("Type of Service     : LOWDEALY\n");
			break;
		case IPTOS_THROUGHPUT :
			printf("Type of Service     : THROUGHPUT\n");
			break;
		case IPTOS_RELIABILITY :
			printf("Type of Service     : RELIABILITY\n");
			break;
		case IPTOS_LOWCOST :
			printf("Type of Service     : LOWCOST\n");
			break;
		default :
		printf("Type of Service     : UnKnown\n");
			break;
		

	}
	printf("-------------------------------------------\n");
	printf("IP_TOTAL_Length     : %d\n",ntohs(stp_IP -> ip_len));
	printf("-------------------------------------------\n");
	printf("IP_IDENTIFICATION   : %d\n",ntohs(stp_IP -> ip_id));
	printf("-------------------------------------------\n");
	
	printf("Don't Fragment Flag : %s\n",(ntohs(stp_IP -> ip_off)& IP_DF)? "YES":"NO");
	printf("-------------------------------------------\n");
	printf("More Fragment Flag  : %s\n",(ntohs(stp_IP -> ip_off)& IP_MF)? "YES":"NO");
	
	printf("-------------------------------------------\n");
	
	printf("Time To Live        : %d\n",stp_IP -> ip_ttl);
	printf("-------------------------------------------\n");		
	switch(stp_IP -> ip_p)
	{
	/*
		case  IPPROTO_IP :
		printf("Dummy protocol for TCP \n");
		break;
*/
		case  IPPROTO_HOPOPTS :
		printf("PROTOCOL  : IPv6 Hop_by_Hop options\n");				
		break;

		case  IPPROTO_ICMP :
		printf("PROTOCOL : Internet Control Message Protocol\n");
		break;

		case  IPPROTO_IGMP:
		printf("PROTOCOL  : Internet Group Message Protocol\n");
		break;

		case  IPPROTO_IPIP :
		printf("PROTOCOL  : IPIP tunnels (older KA9Q tunnerls use 94)\n");
		break;

		case  IPPROTO_TCP :
		printf("PROTOCOL  : Transmission Control Protocol \n");
		break;

		case  IPPROTO_EGP :
		printf("PROTOCOL  : Exterior Gateway Protocol\n");
		break;

		case  IPPROTO_PUP :
		printf("PROTOCOL  : PUP Protocol \n"); 
		break;

		case  IPPROTO_UDP :
		printf("PROTOCOL  : User Datagram Protocol\n");
		break;

		case  IPPROTO_IDP :
		printf("PROTOCOL  : XNS IDP protocol\n");
		break;

		case  IPPROTO_TP :
		printf("PROTOCOL  : SO Transport Class 4\n"); 
		break;

		case  IPPROTO_IPV6 :
		printf("PROTOCOL  : IPv6 header\n");
		break;

		case  IPPROTO_ROUTING :
		printf("PROTOCOL  : IPv6 routing header\n");
		break;

		case  IPPROTO_FRAGMENT :
		printf("PROTOCOL  : IPv6 fragmentation header\n");
		break;

		case  IPPROTO_RSVP :
		printf("PROTOCOL  : Reservation Protocol\n"); 
		break;

		case  IPPROTO_GRE :
		printf("PROTOCOL  : General Routing Encapsulation\n");
		break;

		case  IPPROTO_ESP :
		printf("PROTOCOL  : encapsulating security payload \n"); 
		break;

		case  IPPROTO_AH :
		printf("PROTOCOL  : authentication header \n");
		break;

		case  IPPROTO_ICMPV6 :
		printf("PROTOCOL  : ICMPV6\n"); 
		break;

		case  IPPROTO_NONE :
		printf("PROTOCOL  : IPv6 no next header\n");
		break;

		case  IPPROTO_DSTOPTS :
		printf("PROTOCOL  : IPv6 destination options\n");
		break;

		case  IPPROTO_MTP :
		printf("PROTOCOL  : Multicase Transport Protocol \n");
		break;

		case IPPROTO_ENCAP :
		printf("PROTOCOL  : ENCAPSULATION HEader \n"); 
		break;

		case  IPPROTO_PIM :
		printf("PROTOCOL  : Protocol Independent Multicase \n");
		break;

		case  IPPROTO_COMP :
		printf("PROTOCOL  : Compression Header Protocol\n");
		break;

		case  IPPROTO_RAW :
		printf("PROTOCOL  : Raw IP packets \n");
		break;

		default : 
		printf("PROTOCOL  : Unknwon\n");
		break;
			
	}
	*UIP_NEXT = (stp_IP -> ip_p);
	printf("-------------------------------------------\n");
	printf("Check Sum : %d\n" ,ntohs(stp_IP -> ip_sum));
	printf("-------------------------------------------\n");
	printf("IP_ADDRESS Source      : %s \n",inet_ntoa(stp_IP -> ip_src));
	printf("IP_ADDRESS Destination : %s \n",inet_ntoa(stp_IP -> ip_dst));
	printf("-------------------------------------------\n");

	*IP_HD =((stp_IP->ip_hl) * 4) ;
//	printf("TEST IP   :   %s\n",inet_ntoa(*((struct in_addr *)&A)));
	vpData = (unsigned char *)vpData + ((stp_IP->ip_hl) * 4);
	return vpData;
}



