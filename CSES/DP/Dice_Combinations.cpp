#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll MOD=1e9+7;
// int ways(ll n,vector<ll> &memo){
//     if(n==0)return 1;
//     if(n<0)return 0;
//     if(memo[n]!=-1)return memo[n];
//     int currWays=0;

//     for(int i=1;i<=6;i++)
//     {
//         currWays=(currWays+ways(n-i,memo))%MOD;
//     }

//     return memo[n]=currWays;
// }

int main()
{   
    ll n;
    cin>>n;
    vector<ll> memo(n+1,0);
    memo[0]=1;
    memo[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            if(i-j>=0)
            {
                memo[i]=(memo[i]+memo[i-j])%MOD;
            }
        }
    }
    
    cout<<memo[n];

    return 0;
}