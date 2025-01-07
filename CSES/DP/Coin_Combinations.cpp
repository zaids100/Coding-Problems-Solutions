#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int main() {   
    int n;
    ll x;
    cin >> n >> x;

    vector<ll> dp(x + 1, 0);
    vector<ll> coins(n);

    // Read the coin values
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Base case: There is 1 way to make a sum of 0 (using no coins)
    dp[0] = 1;

    // Loop over all sums from 1 to x
    for (ll i = 1; i <= x; i++) {
        // For each coin, try to form the sum i
        for (ll coin : coins) {
            if (i - coin >= 0) {
                dp[i] = (dp[i] + dp[i - coin]) % MOD;  // Add ways to form sum (i - coin)
            }
        }
    }
    // Output the number of ways to make sum x
    cout << dp[x] << endl;

    return 0;
}
