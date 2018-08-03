#ifndef _ENB
#define _ENB

#include "Channel.h"
#include "PBCH.h"
#include <vector>

class eNodeB
{
    public:
        eNodeB();
        ~eNodeB();
        void start();

    private:
        std::vector<Channel*> channels;
        PBCH pbch;
};

#endif