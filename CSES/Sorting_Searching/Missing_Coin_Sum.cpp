#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int rounds = 1;  // We start with the first round
    int max_collected = 0;  // This keeps track of the largest number we've collected so far

    // Process each element in the array
    for (int i = 0; i < n; ++i) {
        if (arr[i] == max_collected + 1) {
            max_collected++;  // Update the largest collected number
        } else if (arr[i] > max_collected + 1) {
            rounds++;  // If the number is larger than the next expected, we start a new round
            max_collected = arr[i];  // Reset the max_collected to the current number
        }
    }

    cout << rounds << endl;
    return 0;
}
