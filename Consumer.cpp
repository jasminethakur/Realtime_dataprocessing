   #include "Consumer.h"
   #include <iostream>
   #include <chrono>

   void Consumer::consume(std::queue<DataPacket>& queue, std::mutex& mtx) {
       Transformer transformer; 
       while (true) {
           DataPacket packet;
           {
               std::lock_guard<std::mutex> lock(mtx);
               if (!queue.empty()) {
                   packet = queue.front();
                   queue.pop();
               } else {
                   continue; 
               }
           }
           
           DataPacket transformedPacket = transformer.transform(packet);
           std::cout << "Consumed: " << transformedPacket.data << std::endl;
           std::this_thread::sleep_for(std::chrono::milliseconds(1000)); 
       }
   }
   