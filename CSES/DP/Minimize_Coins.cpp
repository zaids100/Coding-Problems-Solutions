#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n, 0);
    vector<int> dp(x + 1, 1e9);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        for (auto coins : coins)
        {
            if (i - coins >= 0)
            {
                dp[i] = min(dp[i], dp[i - coins] + 1);
            }
        }
    }

    if (dp[x] == 1e9)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[x] << endl;
    }
}