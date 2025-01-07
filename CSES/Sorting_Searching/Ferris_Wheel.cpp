#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,x;
    cin>>n>>x;

    vector<int> w(n);

    for(int i=0;i<n;i++)cin>>w[i];

    sort(w.begin(),w.end());

    int cnt=0;

    int i=0;
    int j=n-1;

    while(i<=j)
    {  
       if(i==j)
       {
          cout<<cnt+1;
          exit(0);
       }
       else if(w[i]+w[j]<=x)
       {
          i++;
          j--;
       }
       else{
          j--;
       }
       cnt++;
    }
    
    cout<<cnt<<endl;

    return 0;
}