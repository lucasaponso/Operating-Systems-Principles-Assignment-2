#include "../includes/algorithms.h"

void run_fifo(queue<pcb>& processes) 
{
    int currentTime = 0;
    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;
    int numProcesses = processes.size(); 

    while (!processes.empty()) 
    {
        pcb& currentProcess = processes.front(); // Use a reference instead of copying
        processes.pop();

        cout << "PID " << currentProcess.id << ", Burst Time: " << currentProcess.burst_time;
        currentTime += currentProcess.burst_time;

        int turnaroundTime = currentTime;
        int waitingTime = turnaroundTime - currentProcess.burst_time;
        int responseTime = waitingTime;

        totalTurnaroundTime += turnaroundTime;
        totalWaitingTime += waitingTime;

        cout << ", Response Time: " << responseTime << " Turnaround Time: " << turnaroundTime << " Waiting Time: " << waitingTime << endl;
    }

    double avgTurnaroundTime = static_cast<double>(totalTurnaroundTime) / numProcesses;
    double avgWaitingTime = static_cast<double>(totalWaitingTime) / numProcesses;

    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
    cout << "Average Waiting Time " << avgWaitingTime << endl;
}


void run_rr(std::queue<pcb>& processes, int timeQuantum) 
{
    std::queue<pcb> readyQueue = processes;
    int remainingTime = 0;

    while (!readyQueue.empty()) {
        pcb currentProcess = readyQueue.front();
        readyQueue.pop();

        if (currentProcess.burst_time <= timeQuantum) {
            remainingTime = currentProcess.burst_time;
        } else {
            remainingTime = timeQuantum;
        }

        currentProcess.burst_time -= remainingTime;

        if (currentProcess.burst_time <= 0) {
            std::cout << "Process " << currentProcess.id << " completed." << std::endl;
        } else {
            readyQueue.push(currentProcess);
        }
    }
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
