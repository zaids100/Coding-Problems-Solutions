// #include <iostream>
// #include <set>
// #include <vector>
// #include <algorithm>
// using namespace std;

//Accepted
// int main() {
//     int n;
//     cin >> n;
//     vector<int> coins(n);
//     for (int i = 0; i < n; i++) {
//         cin >> coins[i];
//     }

//     set<int> possible_sums;
//     possible_sums.insert(0); 
  
//     for (int coin : coins) {
//         set<int> new_sums = possible_sums;
//         for (int sum : possible_sums) {
//             new_sums.insert(sum + coin); 
//         }
//         possible_sums = new_sums; 
//     }

//     // Output the result
//     cout << possible_sums.size() - 1 << endl;
//     for (int sum : possible_sums) {
//         if (sum > 0) { 
//             cout << sum << " ";
//         }
//     }
//     cout << endl;

//     return 0;
// }

// TLE
// #include <iostream>
// #include <set>
// #include <vector>
// using namespace std;

// void findPossibleSums(int index, const vector<int>& coins, set<int>& possible_sums, int current_sum) {
//     // Base case: If we've considered all coins, return
//     if (index == coins.size()) {
//         return;
//     }

//     // Include the current coin in the sum
//     possible_sums.insert(current_sum + coins[index]);
    
//     // Explore the next coin without including the current coin (move to next index)
//     findPossibleSums(index + 1, coins, possible_sums, current_sum);

//     // Explore the next coin while including the current coin (update the current sum)
//     findPossibleSums(index + 1, coins, possible_sums, current_sum + coins[index]);
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<int> coins(n);
//     for (int i = 0; i < n; i++) {
//         cin >> coins[i];
//     }

//     // Set to store all distinct sums
//     set<int> possible_sums;
    
//     // Start the recursion with the first coin and current sum as 0
//     findPossibleSums(0, coins, possible_sums, 0);

//     // Output the number of distinct sums (excluding sum 0) and the sums themselves
//     cout << possible_sums.size() << endl; // Exclude the sum 0
//     for (int sum : possible_sums) {
//         if (sum > 0) { // We don't want to print sum 0
//             cout << sum << " ";
//         }
//     }
//     cout << endl;

//     return 0;
// }
