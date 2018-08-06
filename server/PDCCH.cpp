#include "PDCCH.h"
#include "channels_struct.h"
#include "Uplink_channel.h"

#include <iostream>

PDCCH::PDCCH(int port, size_t counter_reset) : Uplink_channel(port, counter_reset)
{
}

void PDCCH::send_dci(bool cqi_request)
{
    struct DCI_MESSAGE dci_message;
    dci_message.format0_a_flag = 1;
    dci_message.freqency_hooping = 0;
    dci_message.riv = 15;
    dci_message.mcs = 20;
    dci_message.ndi = 1;
    dci_message.tpc = 88;
    dci_message.cyclic_shift = 34;
    dci_message.cqi_request = static_cast<char>(cqi_request ? 1 : 0);

    send_message((void*) &dci_message, sizeof(struct DCI_MESSAGE));

    std::cout << "DCI sent" << std::endl;
}


