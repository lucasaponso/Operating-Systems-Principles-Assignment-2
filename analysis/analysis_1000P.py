import matplotlib.pyplot as plt

average_turnaround_time = [39718.4, 29955.8, 55366]
average_waiting_time = [39638.3, 29875.7, 55339.3]
average_response_time = [39638.3, 29875.7, 55339.3]

scheduling_algorithms = ['FIFO', 'SJF', 'RR']
bar_width = 0.2
x = range(len(scheduling_algorithms))
fig, ax = plt.subplots()
ax.bar(x, average_turnaround_time, width=bar_width, label='Turnaround Time')
ax.bar([i + bar_width for i in x], average_waiting_time, width=bar_width, label='Waiting Time')
ax.bar([i + bar_width * 2 for i in x], average_response_time, width=bar_width, label='Response Time')
ax.set_xlabel('Scheduling Algorithms')
ax.set_ylabel('Time (ms)')
ax.set_title('Average Times by Scheduling Algorithm')
ax.set_xticks([i + bar_width for i in x])
ax.set_xticklabels(scheduling_algorithms)
ax.legend()
plt.tight_layout()
plt.show()



parameters = [50, 100, 150, 200, 250, 300, 350]
avg_turnaround_time = [55366, 48854.9, 39718.4, 39718.4, 39718.4, 39718.4, 39718.4]
avg_waiting_time = [55339.3, 48807.2, 39638.3, 39638.3, 39638.3, 39638.3, 39638.3]
avg_response_time = [55339.3, 48807.2, 39638.3, 39638.3, 39638.3, 39638.3, 39638.3]

fig, ax = plt.subplots()
ax.plot(parameters, avg_turnaround_time, marker='o', label='Average Turnaround Time')
ax.plot(parameters, avg_waiting_time, marker='o', label='Average Waiting Time')
ax.plot(parameters, avg_response_time, marker='o', label='Average Response Time')
ax.set_xlabel('Parameter Value')
ax.set_ylabel('Time (ms)')
ax.set_title('Performance vs. Parameter Value')
ax.legend()
plt.grid(True)
plt.tight_layout()
plt.show()
