#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int n,k;
    cin>>n>>k;

    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    
    unordered_map<int,int> window;
    int i=0;
    long long res=0;
    for(int j=0;j<n;j++)
    {    
        window[arr[j]]++;
        while(i<j && window.size()>k)
        {
            window[arr[i]]--;
            if(window[arr[i]]==0)window.erase(arr[i]);
            i++;
        }
        res+=j-i+1;
    }
    cout<<res<<endl;
    return 0;
}