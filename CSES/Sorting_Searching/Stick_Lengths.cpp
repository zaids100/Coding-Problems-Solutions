#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> sticks(n);
    for(int i=0;i<n;i++)cin>>sticks[i];

    sort(sticks.begin(),sticks.end());

    int medianInd=(n%2==0)?(n/2)-1:n/2;
    long long res=0;
    for(int i=0;i<n;i++){
        res=res+(long long)abs(sticks[i]-sticks[medianInd]);
    }
    cout<<res<<endl;
}