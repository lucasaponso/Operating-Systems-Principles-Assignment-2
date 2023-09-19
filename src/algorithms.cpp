#include "../includes/algorithms.h"

void run_fifo(queue<pcb>& processes) 
{
    int currentTime = 0;
    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;
    int totalResponseTime = 0;
    int numProcesses = processes.size(); 

    while (!processes.empty()) 
    {
        pcb& currentProcess = processes.front();
        processes.pop();

        cout << "PID " << currentProcess.id << ", Burst Time: " << currentProcess.burst_time;
        currentTime += currentProcess.burst_time;

        int turnaroundTime = currentTime;
        int waitingTime = turnaroundTime - currentProcess.burst_time;
        int responseTime = waitingTime;

        totalTurnaroundTime += turnaroundTime;
        totalWaitingTime += waitingTime;
        totalResponseTime += responseTime;

        cout << ", Response Time: " << responseTime << " Turnaround Time: " << turnaroundTime << " Waiting Time: " << waitingTime << endl;
    }

    double avgTurnaroundTime = static_cast<double>(totalTurnaroundTime) / numProcesses;
    double avgWaitingTime = static_cast<double>(totalWaitingTime) / numProcesses;
    double avgResponseTime = static_cast<double>(totalResponseTime) / numProcesses;

    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Response Time: " << avgResponseTime << endl;
}



void run_rr(std::queue<pcb>& processes, int timeQuantum) 
{
    std::queue<pcb> readyQueue = processes;
    int currentTime = 0;
    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;
    int totalResponseTime = 0;
    int numProcesses = readyQueue.size(); 

    while (!readyQueue.empty()) {
        pcb currentProcess = readyQueue.front();
        readyQueue.pop();

        int responseTime = currentTime;

        if (currentProcess.burst_time <= timeQuantum) {
            currentTime += currentProcess.burst_time;
            int turnaroundTime = currentTime;
            int waitingTime = turnaroundTime - currentProcess.burst_time;

            totalTurnaroundTime += turnaroundTime;
            totalWaitingTime += waitingTime;
            totalResponseTime += responseTime;

            std::cout << "PID " << currentProcess.id << ", Burst Time: " << currentProcess.burst_time;
            std::cout << ", Response Time: " << responseTime << " Turnaround Time: " << turnaroundTime << " Waiting Time: " << waitingTime << std::endl;
        } else {
            currentTime += timeQuantum;
            currentProcess.burst_time -= timeQuantum;
            readyQueue.push(currentProcess);
        }

        if (currentProcess.burst_time <= 0) {
            std::cout << "Process " << currentProcess.id << " completed." << std::endl;
        }
    }

    double avgTurnaroundTime = static_cast<double>(totalTurnaroundTime) / numProcesses;
    double avgWaitingTime = static_cast<double>(totalWaitingTime) / numProcesses;
    double avgResponseTime = static_cast<double>(totalResponseTime) / numProcesses;  

    std::cout << "Average Turnaround Time: " << avgTurnaroundTime << std::endl;
    std::cout << "Average Waiting Time: " << avgWaitingTime << std::endl;
    std::cout << "Average Response Time: " << avgResponseTime << std::endl;
}



bool compareByBurstTime(const pcb& a, const pcb& b) 
{
    return a.burst_time < b.burst_time;
}

void run_sjf(std::queue<pcb>& processes) 
{
    std::vector<pcb> processVector;
    int currentTime = 0;
    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;
    int totalResponseTime = 0;

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
        totalResponseTime += responseTime;  

        std::cout << "ID: " << p.id << ", Burst Time: " << p.burst_time;
        std::cout << " Response Time: " << responseTime << " Turnaround Time: " << turnaroundTime << " Waiting Time: " << waitingTime << std::endl;

        currentTime += p.burst_time;
    }

    double avgTurnaroundTime = static_cast<double>(totalTurnaroundTime) / processVector.size();
    double avgWaitingTime = static_cast<double>(totalWaitingTime) / processVector.size();
    double avgResponseTime = static_cast<double>(totalResponseTime) / processVector.size();  

    std::cout << "Average Turnaround Time: " << avgTurnaroundTime << std::endl;
    std::cout << "Average Waiting Time: " << avgWaitingTime << std::endl;
    std::cout << "Average Response Time: " << avgResponseTime << std::endl; 
}

