#include "L3_TCP.h"

const void * L3_TCP(const void * vpdata , unsigned int * UI_NEXT , unsigned int * TCP_HD)
{
	const struct tcphdr *stp_TCP = vpdata;
	printf("-------------------------------------------\n");
	printf("     --------  TCP Header  --------\n");
	printf("-------------------------------------------\n");
	
	printf("Source Port        :  %d\n",ntohs(stp_TCP -> source));
	printf("-------------------------------------------\n");
	printf("Destination Port   :  %d\n",ntohs(stp_TCP -> dest));
	printf("-------------------------------------------\n");
	printf("Squnce Number      :  %lu\n",ntohl(stp_TCP -> seq));
	printf("-------------------------------------------\n");
	printf("Ack_Squnce Number  :  %lu\n",ntohl(stp_TCP -> ack_seq));
	printf("-------------------------------------------\n");

	printf("TCP Header Size    :  %dByte\n",(stp_TCP -> doff)*4);
	printf("-------------------------------------------\n");
//	printf("res1 :  %d\n",(stp_TCP -> res1));
//	printf("res2 :  %d\n",(stp_TCP -> res2));
	printf("urg :  %s\n",((stp_TCP -> urg)&1)? "YES":"NO");
	printf("-------------------------------------------\n");
	printf("ack :  %s\n",((stp_TCP -> ack)&1)? "YES":"NO");
	printf("-------------------------------------------\n");
	printf("psh :  %s\n",((stp_TCP -> psh)&1)? "YES":"NO");
	printf("-------------------------------------------\n");
	printf("rst :  %s\n",((stp_TCP -> rst)&1)? "YES":"NO");
	printf("-------------------------------------------\n");
	printf("syn :  %s\n",((stp_TCP -> syn)&1)? "YES":"NO");
	printf("-------------------------------------------\n");
	printf("fin :  %s\n",((stp_TCP -> fin)&1)? "YES":"NO");
	printf("-------------------------------------------\n");
	printf("Window Size :  %d\n",ntohs(stp_TCP -> window));
	printf("-------------------------------------------\n");
	printf("Check Sum   :  %d\n",ntohs(stp_TCP -> check));
	printf("-------------------------------------------\n");
	printf("Urg_ptr     :  %d\n",ntohs(stp_TCP -> urg_ptr));
	printf("-------------------------------------------\n");

	//포트 두개 중 작은 값 찾기 
	*UI_NEXT = ( ((ntohs(stp_TCP -> source)) < (ntohs(stp_TCP -> dest)))? ntohs(stp_TCP -> source) : ntohs(stp_TCP -> dest));
	*TCP_HD = (stp_TCP -> doff)*4;
	return vpdata+((stp_TCP -> doff)*4);
}




























