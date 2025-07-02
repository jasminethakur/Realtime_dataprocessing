   #ifndef TRANSFORMER_H
   #define TRANSFORMER_H

   #include "DataPacket.h"

   class Transformer {
   public:
       DataPacket transform(const DataPacket& packet);
   };

   #endif 
   