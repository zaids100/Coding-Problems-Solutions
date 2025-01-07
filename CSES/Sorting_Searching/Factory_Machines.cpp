#include <bits/stdc++.h>
using namespace std;


bool canMakeProducts(vector<long long> &time,long long t,long long k)
{
       int pCnt=0;

       for(int i=0;i<time.size();i++)
       {
           pCnt+=t/time[i];
           if(pCnt>=k)return true;
       }
       return false;
}


int main() {
    long long n,t;
    cin>>n>>t;
    vector<long long> time(n);
    long long maxTime=INT_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>time[i];
        maxTime=min(maxTime,time[i]);
    }

    long long low=1;
    long long high=t*maxTime;

    while(low<=high)
    {
        long long mid=low+(high-low)/2;
        if(canMakeProducts(time,mid,t))
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    cout<<low<<endl;


    return 0;
}
