#ifndef HEADER_H
#define HEADER_H

#include "../common_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/epoll.h>

#define BROADCAST_PORT 20700

//#define DEBUG 1

// States
// 0 - Before MIB_MESSAGE
// 1 - Sending PRACH
// 2 - awaiting prach response
// 3 - RRC connection request
// 4 - awaiting connection setup
// 5 - send rrc connection complete

struct conn_pair
{
    int sock;
    int port;
};

struct eNB_conn_info
{
    struct conn_pair broadcast;
    struct conn_pair prach;
    struct conn_pair dl_sch;
    struct conn_pair ul_sch;
    struct conn_pair pdcch;
    struct conn_pair pucch;
};


//uefuncs.c
int get_unique_name();
void handletraffic();
void setup_ue(struct UE_INFO *);
void init_channel(struct conn_pair *, struct epoll_event *, int *);
void setup_connection_information(struct eNB_conn_info *, struct MIB_MESSAGE);
void open_channels(struct eNB_conn_info *, struct epoll_event *, int *);
void print_cell();

//setup_socket.c
void setup_socket(int *, int);
int set_non_block();
void setup_broadcast_socket();
void add_socket_epoll(struct epoll_event *, int *, int *);

//messages.c
int receive_msg(int, void *, size_t);
int send_msg(struct conn_pair, void *, size_t);

void receive_broadcast(int, struct UE_INFO *, struct MIB_MESSAGE *);

void send_random_access_preamble(struct conn_pair, struct UE_INFO *);
void receive_random_access_response(int, struct UE_INFO *);

void send_uci(struct conn_pair, struct UE_INFO *);
void receive_dci(int, struct UE_INFO *);

void send_rrc_req(struct conn_pair, struct UE_INFO *);
void receive_rrc_setup(int, struct UE_INFO *);

#endif