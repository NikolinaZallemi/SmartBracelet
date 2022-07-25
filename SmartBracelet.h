#ifndef SMARTBRACELET_H
#define SMARTBRACELET_H

////////////////////////
//GLOBAL VARIABLES

//length of the keys
#define K_LEN 20

//Number of supported couples (N_max (total nodes) = Max number of couples *2)
#define C_MAX 2
#define N_MAX C_MAX*2

//timers values
#define T_1 15000 // Pairing
#define T_2 10000 // INFO
#define T_3 60000 // MISSING Alarm
//#define T_4 120000

//DATA TYPES

#define BROADCAST 0
#define UNICAST 1
#define INFO 2

//info datagram status code
#define STANDING 10
#define WALKING 20
#define RUNNING 30
#define FALLING 40


//DATA STRUCTURES

//pairing datagram (broadcast)
typedef nx_struct pairing_datagram{
	nx_uint8_t type; // Data type
	nx_uint8_t key[K_LEN]; //20 
	nx_uint16_t address;
	nx_uint8_t identifier; // 0 or 1
}pairing_datagram_t;

//informative datagram (unicast)
typedef nx_struct info_datagram{
	nx_uint8_t type; // Data type
	nx_uint16_t posX;
	nx_uint16_t posY;
	nx_uint8_t status;
	nx_uint16_t identifier;
} info_datagram_t;

//pairing acknowledgement datagram (unicast)
typedef nx_struct pairing_datagram_ack{
	nx_uint8_t type;
	nx_uint8_t acknowledgement;
}pairing_datagram_ack_t;

//Sender: Constants
enum{
	AM_DATAGRAM = N_MAX,
};



#endif
