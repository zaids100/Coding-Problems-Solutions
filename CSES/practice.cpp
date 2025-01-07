#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    long long calculateScore(string s)
    {
        vector<int> reverseMappingArr(26, 0);
        unordered_map<char, stack<int>> mp;
        int score = 0;
        char c = 'z';
        for (int i = 0; i < 26; i++)
        {
            reverseMappingArr[i] = c;
            c--;
        }
        
        for(auto c : reverseMappingArr)cout<<c<<endl;

        for (int i = 0; i < s.size(); i++)
        {
            char c = reverseMappingArr[s[i] - 'a'];
            auto itr = mp.find(c);

            if (itr != mp.end())
            {
                if (!itr->second.empty())
                {
                    score = score + i - itr->second.top();
                    itr->second.pop();

                    if (itr->second.empty())
                    {
                        mp.erase(itr);
                    }
                }
            }
            mp[s[i]].push(i);
        }

        return score;
    }
};

int main()
{
    Solution sol;
    string s="eockppxdqclkhjgvnw";
    sol.calculateScore(s);
    return 0;
}