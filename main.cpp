#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include "Producer.h"
#include "Consumer.h"
#include "Transformer.h"

int main() {
    std::queue<DataPacket> queue;
    std::mutex mtx;

    Producer producer;
    Consumer consumer;

    std::thread producerThread(&Producer::produce, &producer, std::ref(queue), std::ref(mtx));
    std::thread consumerThread(&Consumer::consume, &consumer, std::ref(queue), std::ref(mtx));

    producerThread.join();
    consumerThread.detach(); 

    return 0;
}
