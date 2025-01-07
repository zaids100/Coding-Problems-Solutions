#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    vector<vector<long long>> movies(n);

    for (long long i = 0; i < n; i++) 
    {
        long long startTime, endTime;
        cin >> startTime >> endTime;
        movies[i] = {startTime, endTime};
    }

    // Sort movies by their end time
    sort(movies.begin(), movies.end(), [](const vector<long long> &a, const vector<long long> &b)
         {
             return a[1] < b[1]; // ascending order according to end times
         });

    long long res = 0;
    long long lastEndTime = -1;

    for (long long i = 0; i < n; i++) 
    {
        if (movies[i][0] >= lastEndTime) 
        {
            res++;
            lastEndTime = movies[i][1];
        }
    }

    cout << res << endl;

    return 0;
}
