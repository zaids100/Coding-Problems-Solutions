#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Input
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // DP arrays
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    // Initialization for the first element
    if (x[0] == 0) {
        for (int v = 1; v <= m; v++) {
            prev[v] = 1;
        }
    } else {
        prev[x[0]] = 1;
    }

    // DP transitions
    for (int i = 1; i < n; i++) {
        fill(cur.begin(), cur.end(), 0); // Reset current DP array

        for (int v = 1; v <= m; v++) {
            if (prev[v] == 0) continue;

            if (x[i] == 0 || x[i] == v) {
                cur[v] = (cur[v] + prev[v]) % MOD;
                if (v > 1) cur[v] = (cur[v] + prev[v - 1]) % MOD;
                if (v < m) cur[v] = (cur[v] + prev[v + 1]) % MOD;
            }
        }

        swap(prev, cur); // Move to the next step
    }

    // Calculate the result
    int result = 0;
    for (int v = 1; v <= m; v++) {
        result = (result + prev[v]) % MOD;
    }

    // Output the result
    cout << result << "\n";

    return 0;
}
