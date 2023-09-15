#ifndef ALGO_FUNCTIONS_H
#define ALGO_FUNCTIONS_H
#include "pcb.h"
using std::cout;
using std::endl;
using std::queue;
using std::endl;

void run_fifo(queue<pcb>& processes);
void run_sjf(queue<pcb>& processes);
void run_rr(queue<pcb>& processes, int timeQuantum);

#endif //ALGO_FUNCTIONS_H