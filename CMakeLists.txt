cmake_minimum_required(VERSION 3.10)
project(RealTimeDataProcessing)

set(CMAKE_CXX_STANDARD 17)

add_executable(RealTimeDataProcessing main.cpp Producer.cpp Consumer.cpp Transformer.cpp)

target_link_libraries(RealTimeDataProcessing pthread)