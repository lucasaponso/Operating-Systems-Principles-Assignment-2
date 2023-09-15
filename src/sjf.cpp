#include "../includes/pcb.h"
#include "../includes/sjf.h"

bool compareByBurstTime(const pcb& a, const pcb& b) 
{
    return a.burst_time < b.burst_time;
}

void run(std::queue<pcb>& processes) 
{
    std::vector<pcb> processVector;
    while (!processes.empty()) 
    {
        processVector.push_back(processes.front());
        processes.pop();
    }
    std::sort(processVector.begin(), processVector.end(), compareByBurstTime);
    for (const auto& p : processVector) 
    {
        processes.push(p);
    }
    std::cout << "Contents of the queue after SJF scheduling:" << std::endl;
    while (!processes.empty()) 
    {
        std::cout << "ID: " << processes.front().id << ", Burst Time: " << processes.front().burst_time << std::endl;
        processes.pop();
    }
}
