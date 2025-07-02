#ifndef PRODUCER_H
#define PRODUCER_H

#include <queue>
#include <mutex>
#include <thread>
#include "DataPacket.h"

class Producer {
public:
    void produce(std::queue<DataPacket>& queue, std::mutex& mtx);
};

#endif 
