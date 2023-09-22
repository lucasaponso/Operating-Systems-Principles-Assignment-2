import matplotlib.pyplot as plt

# Data for small input size (50 processes)
scheduling_algorithms = ['FIFO', 'SJF', 'RR (20)', 'RR (80)', 'RR (120)']
avg_tt_small = [1819.24, 1328.92, 2555.88, 2229.06, 2055]
avg_wt_small = [1747.64, 1257.32, 2545.88, 2187.86, 2000.2]
avg_rt_small = [1747.64, 1257.32, 2545.88, 2187.86, 2000.2]

# Data for medium input size (150 processes)
avg_tt_medium = [6343.02, 4891.86, 9606.59, 8437.65, 7395.32]
avg_wt_medium = [6258.17, 4807.01, 9596, 8395.99, 7334.47]
avg_rt_medium = [6258.17, 4807.01, 9596, 8395.99, 7334.47]

# Data for large input size (500 processes)
avg_tt_large = [19855.7, 15006.7, 29607.7, 26182.1, 22477.8]
avg_wt_large = [19775.8, 14926.9, 29597.3, 26142.8, 22416.6]
avg_rt_large = [19775.8, 14926.9, 29597.3, 26142.8, 22416.6]

# Data for the effect of different time quantum values on RR for small input size
time_quantums = ['20', '80', '120']
avg_tt_rr_small = [2555.88, 2229.06, 2055]
avg_wt_rr_small = [2545.88, 2187.86, 2000.2]
avg_rt_rr_small = [2545.88, 2187.86, 2000.2]

# Data for the effect of different time quantum values on RR for medium input size
avg_tt_rr_medium = [9606.59, 8437.65, 7395.32]
avg_wt_rr_medium = [9596, 8395.99, 7334.47]
avg_rt_rr_medium = [9596, 8395.99, 7334.47]

# Data for the effect of different time quantum values on RR for large input size
avg_tt_rr_large = [29607.7, 26182.1, 22477.8]
avg_wt_rr_large = [29597.3, 26142.8, 22416.6]
avg_rt_rr_large = [29597.3, 26142.8, 22416.6]

# Create subplots for AVG TT, AVG WT, and AVG RT for each input size
fig, axes = plt.subplots(3, 1, figsize=(10, 18))

# Plot AVG TT
axes[0].plot(scheduling_algorithms, avg_tt_small, marker='o', linestyle='-', label='Small Input Size')
axes[0].plot(scheduling_algorithms, avg_tt_medium, marker='o', linestyle='-', label='Medium Input Size')
axes[0].plot(scheduling_algorithms, avg_tt_large, marker='o', linestyle='-', label='Large Input Size')
axes[0].set_title('Average Turnaround Time (AVG TT) for Different Input Sizes')
axes[0].set_xlabel('Scheduling Algorithm')
axes[0].set_ylabel('AVG TT (ms)')
axes[0].grid(True)
axes[0].legend()

# Plot AVG WT
axes[1].plot(scheduling_algorithms, avg_wt_small, marker='o', linestyle='-', label='Small Input Size')
axes[1].plot(scheduling_algorithms, avg_wt_medium, marker='o', linestyle='-', label='Medium Input Size')
axes[1].plot(scheduling_algorithms, avg_wt_large, marker='o', linestyle='-', label='Large Input Size')
axes[1].set_title('Average Waiting Time (AVG WT) for Different Input Sizes')
axes[1].set_xlabel('Scheduling Algorithm')
axes[1].set_ylabel('AVG WT (ms)')
axes[1].grid(True)
axes[1].legend()

# Plot AVG RT
axes[2].plot(scheduling_algorithms, avg_rt_small, marker='o', linestyle='-', label='Small Input Size')
axes[2].plot(scheduling_algorithms, avg_rt_medium, marker='o', linestyle='-', label='Medium Input Size')
axes[2].plot(scheduling_algorithms, avg_rt_large, marker='o', linestyle='-', label='Large Input Size')
axes[2].set_title('Average Response Time (AVG RT) for Different Input Sizes')
axes[2].set_xlabel('Scheduling Algorithm')
axes[2].set_ylabel('AVG RT (ms)')
axes[2].grid(True)
axes[2].legend()

# Show the subplots
plt.tight_layout()
plt.show()

# Create subplots for the effect of different time quantum values on RR
fig, axes = plt.subplots(3, 1, figsize=(10, 18))

# Plot AVG TT for RR with different time quantum values
axes[0].plot(time_quantums, avg_tt_rr_small, marker='o', linestyle='-', label='Small Input Size')
axes[0].plot(time_quantums, avg_tt_rr_medium, marker='o', linestyle='-', label='Medium Input Size')
axes[0].plot(time_quantums, avg_tt_rr_large, marker='o', linestyle='-', label='Large Input Size')
axes[0].set_title('Effect of Time Quantum on AVG TT for RR')
axes[0].set_xlabel('Time Quantum')
axes[0].set_ylabel('AVG TT (ms)')
axes[0].grid(True)
axes[0].legend()

# Plot AVG WT for RR with different time quantum values
axes[1].plot(time_quantums, avg_wt_rr_small, marker='o', linestyle='-', label='Small Input Size')
axes[1].plot(time_quantums, avg_wt_rr_medium, marker='o', linestyle='-', label='Medium Input Size')
axes[1].plot(time_quantums, avg_wt_rr_large, marker='o', linestyle='-', label='Large Input Size')
axes[1].set_title('Effect of Time Quantum on AVG WT for RR')
axes[1].set_xlabel('Time Quantum')
axes[1].set_ylabel('AVG WT (ms)')
axes[1].grid(True)
axes[1].legend()

# Plot AVG RT for RR with different time quantum values
axes[2].plot(time_quantums, avg_rt_rr_small, marker='o', linestyle='-', label='Small Input Size')
axes[2].plot(time_quantums, avg_rt_rr_medium, marker='o', linestyle='-', label='Medium Input Size')
axes[2].plot(time_quantums, avg_rt_rr_large, marker='o', linestyle='-', label='Large Input Size')
axes[2].set_title('Effect of Time Quantum on AVG RT for RR')
axes[2].set_xlabel('Time Quantum')
axes[2].set_ylabel('AVG RT (ms)')
axes[2].grid(True)
axes[2].legend()

# Show the subplots
plt.tight_layout()
plt.show()
