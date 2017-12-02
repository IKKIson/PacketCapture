#include "L3_ICMP.h"

const void* L3_ICMP(const void *vp_data , unsigned int * UIP_NEXT)
{
	const struct icmp* stp_ICMP = vp_data;
	printf("-------------------------------------------\n");
	printf("     --------  ICMP Header  --------\n");
	printf("-------------------------------------------\n\n");
	switch(stp_ICMP -> icmp_type)
		{
			case ICMP_ECHOREPLY :
				printf("Header Type : Echo Reply\n");
				printf("----------------------------------------\n");
				break;
			case ICMP_UNREACH :
				printf("Header Type : Destination Unreachable\n");
				printf("----------------------------------------\n");
				switch(stp_ICMP -> icmp_code)
					{
						case ICMP_UNREACH_NET :
							printf("Code : bad net\n");
							printf("-------------------------------------------\n");
							break;
						case ICMP_UNREACH_HOST :
							printf("Code : bad host\n");
							printf("-------------------------------------------\n");
							break;
						case ICMP_UNREACH_PROTOCOL :
							printf("Code : bad Protocol \n");
							printf("-------------------------------------------\n");
							break;
						case ICMP_UNREACH_PORT :
							printf("Code : bad port\n");
							printf("-------------------------------------------\n");
							break;
						case ICMP_UNREACH_NEEDFRAG :
							printf("Code : IP_DF caused drop\n");
							printf("-------------------------------------------\n");
							break;
						case ICMP_UNREACH_SRCFAIL :
							printf("Code : src rout failed\n");
							printf("-------------------------------------------\n");
							break;
						case ICMP_UNREACH_NET_UNKNOWN :
							printf("Code : unknown net\n");
							printf("-------------------------------------------\n");
							break;
						case ICMP_UNREACH_HOST_UNKNOWN :
							printf("Code : unknown host\n");
							printf("-------------------------------------------\n");
							break;
						case ICMP_UNREACH_ISOLATED :
							printf("Code : src host isolated\n");
							printf("-------------------------------------------\n");
							break;
						case ICMP_UNREACH_NET_PROHIB :
							printf("Code : net dinied\n");
							printf("-------------------------------------------\n");
							break;
						case ICMP_UNREACH_HOST_PROHIB :
							printf("Code : host denied\n");
							printf("-------------------------------------------\n");
							break;
						case ICMP_UNREACH_TOSNET :
							printf("Code : bad tos for net\n");
							printf("-------------------------------------------\n");
							break;
						case ICMP_UNREACH_TOSHOST :
							printf("Code : bad tos for host\n");
							printf("-------------------------------------------\n");
							break;
						case ICMP_UNREACH_FILTER_PROHIB :
							printf("Code : admin prohib\n");
							printf("-------------------------------------------\n");
							break;
						case ICMP_UNREACH_HOST_PRECEDENCE :
							printf("Code : host prec vio\n");
							printf("-------------------------------------------\n");
							break;
						case ICMP_UNREACH_PRECEDENCE_CUTOFF :
							printf("Code : Prec cutoff\n");
							printf("-------------------------------------------\n");
							break;
						default :
							printf("Unknown\n");
							printf("-------------------------------------------\n");
							break;
					}
				break;
			case ICMP_SOURCEQUENCH :
				printf("Header Type : Source Quench\n");
				printf("-------------------------------------------\n");
				break;
			case ICMP_ECHO :
				printf("Header Type : ECHO Request\n");
				printf("-------------------------------------------\n");
				break;
			case ICMP_TIMXCEED :
				printf("Header Type : TIME EXCEEDED\n");
				printf("-------------------------------------------\n");
				switch(stp_ICMP -> icmp_code)
					{
						case ICMP_TIMXCEED_INTRANS :
							printf("Code : TTL = 0 in transit\n");
							printf("-------------------------------------------\n");
							break;
						case ICMP_TIMXCEED_REASS :
							printf("Code : TTL = 0 in reass\n");
							printf("-------------------------------------------\n");
							break;
							
						default :
							printf("Code : Unknown\n");
							printf("-------------------------------------------\n");
							break;
					}
				break;
			default :
				printf("Unknown\n");
				printf("-------------------------------------------\n");
				break;

		}
	printf("Check Sum   : %d\n",ntohs(stp_ICMP -> icmp_cksum));
	printf("-------------------------------------------\n");
	//printf("ID1 = %d\n",ntohs(stp_ICMP-> icmp_id));
	printf("Identifier     : %d\n",(stp_ICMP-> icmp_hun.ih_idseq.icd_id));
	printf("-------------------------------------------\n");
	//printf("SQUNCE Number1 = %d\n",ntohs(stp_ICMP -> icmp_seq));
	printf("SQUNCE Number  : %d\n",(stp_ICMP -> icmp_hun.ih_idseq.icd_seq));
	printf("-------------------------------------------\n");

	//vpData = (unsigned char *)vpData + ((stp_IP->ip_hl) * 4);
	return vp_data;

}


