#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    string s;
    getline(cin, s);
    vector<string> allWords;
    stringstream ss(s);
    string word;

    while (ss >> word) {
        allWords.push_back(word);
    }

    sort(allWords.begin(), allWords.end());

    for (int i = 0; i < allWords.size(); i++) {
        if (isVowel(allWords[i][0])) {
            cout << allWords[i] << " " << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
