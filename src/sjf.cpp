#include "../includes/pcb.h"
#include "../includes/sjf.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

bool compareByBurstTime(const pcb& a, const pcb& b) 
{
    return a.burst_time < b.burst_time;
}

void run(std::queue<pcb>& processes) 
{
    std::vector<pcb> processVector;
    int currentTime = 0;
    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;

    while (!processes.empty()) 
    {
        processVector.push_back(processes.front());
        processes.pop();
    }

    std::sort(processVector.begin(), processVector.end(), compareByBurstTime);

    std::cout << "Contents of the queue after SJF scheduling:" << std::endl;
    
    for (const auto& p : processVector) 
    {
        int responseTime = currentTime;
        int turnaroundTime = currentTime + p.burst_time;
        int waitingTime = currentTime;

        totalTurnaroundTime += turnaroundTime;
        totalWaitingTime += waitingTime;

        std::cout << "ID: " << p.id << ", Burst Time: " << p.burst_time;
        std::cout << " Response Time: " << responseTime << " Turnaround Time: " << turnaroundTime << " Waiting Time: " << waitingTime << std::endl;

        currentTime += p.burst_time;
    }

    double avgTurnaroundTime = static_cast<double>(totalTurnaroundTime) / processVector.size();
    double avgWaitingTime = static_cast<double>(totalWaitingTime) / processVector.size();

    std::cout << "Average Turnaround Time: " << avgTurnaroundTime << std::endl;
    std::cout << "Average Waiting Time: " << avgWaitingTime << std::endl;
}
