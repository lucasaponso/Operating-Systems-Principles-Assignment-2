#ifndef SJF_FUNCTIONS_H
#define SJF_FUNCTIONS_H
//includes local & system files
#include "pcb.h"
#include <queue>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream> 
//other libs
using std::cout;
using std::endl;
using std::queue;
using std::endl;

//method to run the simulator
void run(std::queue<pcb>& processes);

#endif // SJF_FUNCTIONS_H
