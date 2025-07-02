   #include "Transformer.h"

   DataPacket Transformer::transform(const DataPacket& packet) {
       DataPacket transformedPacket;
       transformedPacket.data = "Transformed: " + packet.data; // Example transformation
       return transformedPacket;
   }
   