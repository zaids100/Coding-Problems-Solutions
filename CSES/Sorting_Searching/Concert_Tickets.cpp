#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{    
    int n,m;
    cin>>n>>m;
    multiset<ll> list;

    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        list.insert(temp);
    }

    for(int i=0;i<m;i++)
    {
        ll custPrice;
        cin>>custPrice;

        auto paidPrice=list.upper_bound(custPrice);

        if(paidPrice==list.begin())
        {
            cout<<-1<<endl;
            continue;
        }
        else{
            cout<<*(--paidPrice)<<endl;
            list.erase(paidPrice); // remove one occurence
        }
    }

    return 0;
}