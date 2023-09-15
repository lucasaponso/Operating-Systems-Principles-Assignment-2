#ifndef FIFO_FUNCTIONS_H
#define FIFO_FUNCTIONS_H
//includes local & system files
#include "pcb.h"
#include <queue>
#include <iostream>
//other libs
using std::cout;
using std::endl;
using std::queue;
using std::endl;

//method to run the simulator
void run(std::queue<pcb>& processes);

#endif // FIFO_FUNCTIONS_H
