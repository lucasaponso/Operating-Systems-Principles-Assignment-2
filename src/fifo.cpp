#include "../includes/pcb.h"
#include "../includes/fifo.h"

void run(queue<pcb>& processes) 
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
