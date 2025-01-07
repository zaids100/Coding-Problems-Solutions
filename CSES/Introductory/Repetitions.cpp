#include<bits/stdc++.h>
using namespace std;
int main()
{   
    string s;
    cin>>s;

    long long maxi=0;
    long long cnt=1;

    for(int i=0;i<s.size();)
    {
        char c=s[i];                          //ATTCGGGA
        int j=i+1;
        while(j<s.size() && s[j]==c)
        {
            j++;
            cnt++;
        }
        maxi=max(maxi,cnt);
        i=j;
        cnt=1;
    }

    maxi=max(maxi,cnt);

    cout<<maxi;
    return 0;
}