#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> applicants(n);
    vector<int> apartments(m);

    // Input the desired apartment sizes of the applicants
    for (int i = 0; i < n; i++) {
        cin >> applicants[i];
    }

    // Input the sizes of the apartments
    for (int i = 0; i < m; i++) {
        cin >> apartments[i];
    }

    // Sort both the applicants' desired sizes and the apartments' sizes
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int matched = 0;
    int applicant_idx = 0;
    int apartment_idx = 0;

    // Use two-pointer technique to match applicants with apartments
    while (applicant_idx < n && apartment_idx < m) {
        if (apartments[apartment_idx] < applicants[applicant_idx] - k) {
            // Apartment is too small, move to the next apartment
            apartment_idx++;
        } else if (apartments[apartment_idx] > applicants[applicant_idx] + k) {
            // Apartment is too large, move to the next applicant
            applicant_idx++;
        } else {
            // Valid match, move both pointers
            matched++;
            applicant_idx++;
            apartment_idx++;
        }
    }

    // Output the number of matched applicants
    cout << matched << endl;

    return 0;
}
