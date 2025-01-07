#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int n,m;
    cin>>n>>m;

    long long pref[n];
    // int currSum=0;
    for(int i=0;i<n;i++)
    {   
       int temp;
       cin>>temp;
       if(i==0)
       {
          pref[i]=temp;
       }
       else{
          pref[i]=pref[i-1]+temp;
       }
    }

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a-=1;
        b-=1;
        if(a==0)
        {
            cout<<pref[b]<<endl;
        }
        else{
            cout<<pref[b]-pref[a-1]<<endl;
        }
    }

    return 0;
}