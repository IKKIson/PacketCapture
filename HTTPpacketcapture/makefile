CCFLAGS = -lpcap
CC = gcc
OBJ = main.o hex.o L1_EtherNet.o L2_IP.o L2_ARP.o L3_ICMP.o L3_TCP.o L3_UDP.o L4_HTTP.o

all : $(OBJ)
	 $(CC)	-o	main $(OBJ) $(CCFLAGS)

clean : 
	rm -rf $(OBJ)
	rm -rf main

run : all
	./main
	
		
