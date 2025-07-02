#include "Producer.h"
#include <iostream>
#include <chrono>

void Producer::produce(std::queue<DataPacket>& queue, std::mutex& mtx) {
    int count = 0;
    while (count < 10) { // Produce 10 data packets
        DataPacket packet;
        packet.data = "Data " + std::to_string(count);
        
        {
            std::lock_guard<std::mutex> lock(mtx);
            queue.push(packet);
            std::cout << "Produced: " << packet.data << std::endl;
        }
        
        count++;
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate delay
    }
}
