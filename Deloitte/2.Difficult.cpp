#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{   
    int n,k;cin>>n>>k;
    vector<int> arr(n,0);for(int i=0;i<n;i++)cin>>arr[i];
    map<int,int> mp;
    
    int res=INT_MIN;
    int i=0;

    for(int j=0;j<n;j++){
        mp[arr[j]]++;
        if(j-i+1<k){
            continue;
        }
        else{
            // window hit find the minimum in the window
            int mini=mp.begin()->first;
            res=max(res,mini);
            mp[arr[i]]--;
            if(mp[arr[i]]==0)mp.erase(arr[i]);
            i++;
        }
    }

    cout<<res;

    return 0;
}