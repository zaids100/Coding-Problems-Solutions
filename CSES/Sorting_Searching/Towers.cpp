#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{   
    int n; cin>>n;
    vector<int> cubes(n,0);
    multiset<int> towers;
    ll res=0;
    for(int i=0;i<n;i++)
    {  
        cin>>cubes[i];
        
        auto ub=towers.upper_bound(cubes[i]);
        
        if(!towers.empty() && ub!=towers.end())
        {
           towers.erase(ub);
        }
        else{
            res++;
        }
        towers.insert(cubes[i]);
    }

    cout<<res;
    return 0;
}
