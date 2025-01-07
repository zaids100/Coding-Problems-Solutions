#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;
    vector<tuple<ll, ll, int>> customers; // {arrival, departure, index}

    // Read input
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        customers.push_back({a, b, i});
    }

    // Sort customers by arrival day
    sort(customers.begin(), customers.end());

    // Min-heap to track room availability: {departure, room_number}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    vector<ll> room_assignment(n);
    ll max_rooms = 0;

    for (auto &[arrival, departure, index] : customers) {
        // Check if any room is available
        if (!pq.empty() && pq.top().first < arrival) {
            // Reuse the room
            int room = pq.top().second;
            pq.pop();
            pq.push({departure, room});
            room_assignment[index] = room;
        } else {
            // Allocate a new room
            max_rooms++;
            pq.push({departure, max_rooms});
            room_assignment[index] = max_rooms;
        }
    }

    // Output results
    cout << max_rooms << endl;
    for (int room : room_assignment) {
        cout << room << " ";
    }
    cout << endl;

    return 0;
}
