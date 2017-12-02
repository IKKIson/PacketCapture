#include <stdio.h>
#include <pcap/pcap.h>
#include "hex.h"
#include "L1_EtherNet.h"
#include "L2_IP.h"

int main()
{
	char errbuf[PCAP_ERRBUF_SIZE];
	char *cpNIC_Name;
	pcap_t *stp_NIC;
	const  u_char *ucp_DATA;
	struct pcap_pkthdr st_info;
	unsigned int UI_NEXT;
	unsigned int IP_HD;
	unsigned int TCP_HD;
	//패킷 캡쳐 절차 
	//함수 한번 호출에 에러처리 한번 

	cpNIC_Name = pcap_lookupdev(errbuf);
	if(cpNIC_Name == NULL)
	{
		printf(errbuf);
		putchar('\n');
		return 0;
	}
	printf(cpNIC_Name);
	putchar('\n');
	stp_NIC =pcap_open_live(cpNIC_Name,1500,1,0, errbuf);
	if(stp_NIC == NULL)
	{
		printf(errbuf);
		putchar('\n');
		return 0;
	}
	printf("패킷 캡쳐 오픈 successful\n");
	
	//에러 날때 마다 close 닫아 주어야한다.
	ucp_DATA = pcap_next(stp_NIC , &st_info);
	hex(ucp_DATA,10);
	ucp_DATA = L1_EtherNet(ucp_DATA , &UI_NEXT );
	switch(UI_NEXT)
	{
	
		case ETHERTYPE_PUP:
			
			break;

		

		case ETHERTYPE_IP:
			ucp_DATA = L2_IP(ucp_DATA , &UI_NEXT,&IP_HD);
			
		break;
		case ETHERTYPE_ARP:
		case ETHERTYPE_REVARP:
			ucp_DATA = L2_ARP(ucp_DATA , &UI_NEXT);
		break;
		
			
		default :
		break;	
		
			
	}
	switch(UI_NEXT)
	{
	/*
		case  IPPROTO_IP :
		
		break;
*/
		case  IPPROTO_HOPOPTS :
						
		break;

		case  IPPROTO_ICMP :
		ucp_DATA = L3_ICMP(ucp_DATA , &UI_NEXT);
		break;

		case  IPPROTO_IGMP:
		
		break;

		case  IPPROTO_IPIP :
		
		break;

		case  IPPROTO_TCP :
		ucp_DATA = L3_TCP(ucp_DATA , &UI_NEXT,&TCP_HD);
		if(UI_NEXT == 80)
		{
			UI_NEXT = st_info.caplen - 14 - IP_HD - TCP_HD;
			ucp_DATA = L4_HTTP(ucp_DATA , &UI_NEXT);
		}
		break;

		case  IPPROTO_EGP :
		
		break;

		case  IPPROTO_PUP :
		
		break;

		case  IPPROTO_UDP :
		
		break;

		case  IPPROTO_IDP :
		
		break;

		case  IPPROTO_TP :
		
		break;

		case  IPPROTO_IPV6 :
		
		break;

		case  IPPROTO_ROUTING :
		
		break;

		case  IPPROTO_FRAGMENT :
		
		break;

		case  IPPROTO_RSVP :
		
		break;

		case  IPPROTO_GRE :
		
		break;

		case  IPPROTO_ESP :
		
		break;

		case  IPPROTO_AH :
		
		break;

		case  IPPROTO_ICMPV6 :
		
		break;

		case  IPPROTO_NONE :
		
		break;

		case  IPPROTO_DSTOPTS :
		
		break;

		case  IPPROTO_MTP :
		
		break;

		case IPPROTO_ENCAP :
		
		break;

		case  IPPROTO_PIM :
		
		break;

		case  IPPROTO_COMP :
		
		break;

		case  IPPROTO_RAW :
	
		break;

		default : 
		
		break;
			
	}
	
	//L2_ARP(ucp_DATA);
	pcap_close(stp_NIC);
		
	
	return 0;
}
