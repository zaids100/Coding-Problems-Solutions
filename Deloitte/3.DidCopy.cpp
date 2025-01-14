#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{   
    string adj,rahul;
    cin>>adj;
    cin>>rahul;

    unordered_map<int,int> aMap,rMap;

    for(auto c : adj)aMap[c]++;
    for(auto c : rahul)rMap[c]++;

    cout<<(aMap==rMap);
    
    return 0;
}