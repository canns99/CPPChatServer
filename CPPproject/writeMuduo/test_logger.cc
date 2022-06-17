#include "logger.h"
#include <iostream>
#include "TimeStamp.h"



int main(){
    
    std::cout<<TimeStamp::now().timeToString()<<"\n";
    
}