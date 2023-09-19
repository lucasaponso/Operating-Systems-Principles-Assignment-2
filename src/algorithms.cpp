#include "../includes/algorithms.h"

void run_fifo(queue<pcb>& processes) 
{
    int currentTime = 0;
    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;
    int totalResponseTime = 0;  // Initialize a variable to store the total response time
    int numProcesses = processes.size(); 

    while (!processes.empty()) 
    {
        pcb& currentProcess = processes.front(); // Use a reference instead of copying
        processes.pop();

        cout << "PID " << currentProcess.id << ", Burst Time: " << currentProcess.burst_time;
        currentTime += currentProcess.burst_time;

        int turnaroundTime = currentTime;
        int waitingTime = turnaroundTime - currentProcess.burst_time;
        int responseTime = waitingTime; // Calculate the correct response time

        totalTurnaroundTime += turnaroundTime;
        totalWaitingTime += waitingTime;
        totalResponseTime += responseTime;  // Update the total response time

        cout << ", Response Time: " << responseTime << " Turnaround Time: " << turnaroundTime << " Waiting Time: " << waitingTime << endl;
    }

    double avgTurnaroundTime = static_cast<double>(totalTurnaroundTime) / numProcesses;
    double avgWaitingTime = static_cast<double>(totalWaitingTime) / numProcesses;
    double avgResponseTime = static_cast<double>(totalResponseTime) / numProcesses;  // Calculate the average response time

    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Response Time: " << avgResponseTime << endl;  // Print the average response time
}



void run_rr(std::queue<pcb>& processes, int timeQuantum) 
{
    std::queue<pcb> readyQueue = processes;
    int currentTime = 0;
    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;
    int totalResponseTime = 0;  // Initialize a variable to store the total response time
    int numProcesses = readyQueue.size();  // Number of processes in the queue

    while (!readyQueue.empty()) {
        pcb currentProcess = readyQueue.front();
        readyQueue.pop();

        int responseTime = currentTime; // Calculate the response time

        if (currentProcess.burst_time <= timeQuantum) {
            currentTime += currentProcess.burst_time;
            int turnaroundTime = currentTime;
            int waitingTime = turnaroundTime - currentProcess.burst_time;

            totalTurnaroundTime += turnaroundTime;
            totalWaitingTime += waitingTime;
            totalResponseTime += responseTime;  // Update the total response time

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
    double avgResponseTime = static_cast<double>(totalResponseTime) / numProcesses;  // Calculate the average response time

    std::cout << "Average Turnaround Time: " << avgTurnaroundTime << std::endl;
    std::cout << "Average Waiting Time: " << avgWaitingTime << std::endl;
    std::cout << "Average Response Time: " << avgResponseTime << std::endl;  // Print the average response time
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
    int totalResponseTime = 0;  // Initialize a variable to store the total response time

    while (!processes.empty()) 
    {
        processVector.push_back(processes.front());
        processes.pop();
    }

    std::sort(processVector.begin(), processVector.end(), compareByBurstTime);

    std::cout << "Contents of the queue after SJF scheduling:" << std::endl;
    
    for (const auto& p : processVector) 
    {
        int responseTime = currentTime; // Calculate the response time
        int turnaroundTime = currentTime + p.burst_time;
        int waitingTime = currentTime;

        totalTurnaroundTime += turnaroundTime;
        totalWaitingTime += waitingTime;
        totalResponseTime += responseTime;  // Update the total response time

        std::cout << "ID: " << p.id << ", Burst Time: " << p.burst_time;
        std::cout << " Response Time: " << responseTime << " Turnaround Time: " << turnaroundTime << " Waiting Time: " << waitingTime << std::endl;

        currentTime += p.burst_time;
    }

    double avgTurnaroundTime = static_cast<double>(totalTurnaroundTime) / processVector.size();
    double avgWaitingTime = static_cast<double>(totalWaitingTime) / processVector.size();
    double avgResponseTime = static_cast<double>(totalResponseTime) / processVector.size();  // Calculate the average response time

    std::cout << "Average Turnaround Time: " << avgTurnaroundTime << std::endl;
    std::cout << "Average Waiting Time: " << avgWaitingTime << std::endl;
    std::cout << "Average Response Time: " << avgResponseTime << std::endl;  // Print the average response time
}

