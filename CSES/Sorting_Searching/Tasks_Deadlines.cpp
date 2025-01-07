#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    int duration;
    int deadline;
};

bool compare(Task &a, Task &b) {
    // Sort by duration in ascending order
    return a.duration < b.duration;
}

int main() {
    int n;
    cin >> n;
    vector<Task> tasks(n);
    
    // Input task details (duration and deadline)
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].duration >> tasks[i].deadline;
    }

    // Sort tasks by duration in increasing order
    sort(tasks.begin(), tasks.end(), compare);

    long long current_time = 0;
    long long total_reward = 0;

    // Process tasks in sorted order
    for (int i = 0; i < n; i++) {
        long long finish_time = current_time + tasks[i].duration;
        long long reward = tasks[i].deadline - finish_time;
        total_reward += reward;

        // Update current time after finishing the task
        current_time = finish_time;
    }

    // Output the total reward
    cout << total_reward << endl;

    return 0;
}
