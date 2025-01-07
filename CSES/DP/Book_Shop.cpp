#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll maxPages(int ind, ll sum, vector<int> &price, vector<int> &pages, vector<vector<int>> &memo) {

    // Base case: if we've processed all items
    if(ind >= price.size()) {
        return 0;  // No more items to select
    }

    // If we've already solved this subproblem, return the result
    if(memo[ind][sum] != -1) return memo[ind][sum];

    ll pick = 0;
    ll noPick = 0;

    // If we can pick the current item (i.e., if we have enough money left)
    if(sum - price[ind] >= 0) {
        pick = pages[ind] + maxPages(ind + 1, sum - price[ind], price, pages, memo);
    }

    // Skip the current item
    noPick = maxPages(ind + 1, sum, price, pages, memo);

    // Store and return the maximum of picking or not picking the current item
    return memo[ind][sum] = max(pick, noPick);
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> price(n, 0);
    for(int i = 0; i < n; i++) cin >> price[i];
    vector<int> pages(n, 0);
    for(int i = 0; i < n; i++) cin >> pages[i];

    // DP table: dp[i][j] will store the maximum pages we can get with the first i items and total sum j
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    // Fill the DP table
    for(int i = 1; i <= n; i++) {  // Iterate through each item
        for(int j = 0; j <= x; j++) {  // Iterate through each possible sum
            // If we can pick this item (i.e., sum is >= price[i-1])
            if(j >= price[i-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-price[i-1]] + pages[i-1]);
            }
            // Otherwise, we just skip this item
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }

    // The answer will be the maximum pages we can get with n items and sum x
    cout << dp[n][x] << endl;

    return 0;
}