#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{   
    ll n; cin>>n;
    // unordered_set<ll> st;
    vector<ll> nums(n,0);
    for(int i=0;i<n;i++)
    {   
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    int cnt=0;
    for(int i=0;i<n;)
    {
        int num=nums[i];
        int j=i+1;
        while(j<n && nums[j]==num)
        {
            j++;
        }
        cnt+=1;
        i=j;
    }
    
    // 1 1 1 1 2 2 2 3 

    cout<<cnt<<endl;
    return 0;
}