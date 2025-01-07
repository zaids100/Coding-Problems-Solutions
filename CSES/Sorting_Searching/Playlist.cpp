#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    set<int> window;  // Set to store the unique elements in the window
    int i = 0;         // Left pointer of the sliding window
    int maxLen = 0;

    // Sliding window approach
    for (int j = 0; j < n; j++) {
        // Add the current element to the window set
        while (window.find(nums[j]) != window.end()) {
            // If the element is already in the set, shrink the window from the left
            window.erase(nums[i]);
            i++;  // Move the left pointer to the right
        }

        // Add the current element to the window
        window.insert(nums[j]);

        // Update the maximum length of the window
        maxLen = max(maxLen, j - i + 1);
    }

    cout << maxLen << endl;

    return 0;
}
