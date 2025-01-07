#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long prev = 0;
    long long res = 0;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (prev > temp)
        {
            res = res + abs(temp - prev);
            temp=temp+abs(temp - prev);
        }
        prev = temp;
    }
    cout << res << endl;
    return 0;
}