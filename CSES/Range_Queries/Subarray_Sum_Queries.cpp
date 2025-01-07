#include <bits/stdc++.h>
using namespace std;


//Brute for technique process each query with kadane's algo LEADING TO A QUADRATIC TIME COMPLEXITY O(N * Q);
int maxSubArrSum(int arr[], int n) {
    int res = INT_MIN; // Maximum subarray sum
    int currSum = 0;   // Current subarray sum

    for (int i = 0; i < n; i++) {
        currSum += arr[i];
        res = max(res, currSum); // Update the result with the current maximum sum
        if (currSum < 0) {       // Reset the current sum if it becomes negative
            currSum = 0;
        }
    }

    return max(res, 0); // Allow empty subarrays by ensuring the result is non-negative
}

int main() {   
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++) {
        int k, x;
        cin >> k >> x;
        arr[k - 1] = x; // Update the array value
        cout << maxSubArrSum(arr, n) << endl;
    }

    return 0;
}
