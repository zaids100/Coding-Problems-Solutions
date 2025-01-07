#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int max_customers(int n, vector<pair<int, int>>& customers) {
    vector<pair<int, char>> events;

    // Step 1: Create events for arrival and departure
    for (const auto& customer : customers) {
        events.push_back({customer.first, 'A'});  // 'A' for arrival
        events.push_back({customer.second, 'D'}); // 'D' for departure
    }

    // Step 2: Sort events: First by time, then 'D' before 'A' if same time
    sort(events.begin(), events.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
        if (a.first == b.first) return a.second == 'D'; // Departures before arrivals if same time
        return a.first < b.first;
    });

    priority_queue<int, vector<int>, greater<int>> heap; // Min-heap to track departures
    int max_customers = 0;
    int current_customers = 0;

    // Step 3: Process events
    for (const auto& event : events) {
        if (event.second == 'A') {
            heap.push(event.first);  // Customer arrives, push departure time
            current_customers++;
        } else {
            heap.pop();  // Customer departs, pop departure time
            current_customers--;
        }
        max_customers = max(max_customers, current_customers);  // Track maximum customers
    }

    return max_customers;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> customers(n);

    for (int i = 0; i < n; ++i) {
        cin >> customers[i].first >> customers[i].second;  // Read arrival and departure times
    }

    cout << max_customers(n, customers) << endl;

    return 0;
}
