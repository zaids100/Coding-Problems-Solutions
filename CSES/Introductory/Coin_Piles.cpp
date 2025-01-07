#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;

        // Check the conditions
        if ((a + b) % 3 == 0 && a <= 2 * b && b <= 2 * a) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
