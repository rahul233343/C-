#include <chrono>
#include <iostream>

class Timer{
    public:
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
      
    explicit Timer(){
        start = std::chrono::high_resolution_clock::now();
    }
    
    ~Timer(){
       end = std::chrono::high_resolution_clock::now();
       auto diff = end - start;
       std::cout<<std::chrono::duration<double,std::milli>(diff).count()<<" millis \t"<< std::chrono::duration<double,std::nano>(diff).count()<<" nanos"<<std::endl;
    
    }

};
