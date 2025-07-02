   #ifndef CONSUMER_H
   #define CONSUMER_H

   #include <queue>
   #include <mutex>
   #include <thread>
   #include "DataPacket.h"
   #include "Transformer.h" 

   class Consumer {
   public:
       void consume(std::queue<DataPacket>& queue, std::mutex& mtx);
   };

   #endif 
   