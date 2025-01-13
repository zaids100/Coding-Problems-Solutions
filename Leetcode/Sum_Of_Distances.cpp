#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<long long> dist(n,0LL);
        
        // prefix=count(nums[i])*i-totalDistAccumulated
        // suffix=totalDistAccumulated-count(nums[i])*i
        
        // two pass O(2n) ~ O(n) --> time and space

        unordered_map<int,pair<int,long long>> pref;
        unordered_map<int,pair<int,long long>> suff;
       
        // first pass for prefix
        for(int i=0;i<n;i++){

            int count=pref[nums[i]].first;
            long long totalDist=pref[nums[i]].second;

            dist[i]+=(long long)count*i-totalDist;

            pref[nums[i]].first++;
            pref[nums[i]].second+=i;

        }
        
        // second pass for suffix
        for(int i=n-1;i>=0;i--){

            int count=suff[nums[i]].first;
            long long totalDist=suff[nums[i]].second;

            dist[i]+=totalDist-(long long)count*i;

            suff[nums[i]].first++;
            suff[nums[i]].second+=i;

        }

        return dist;
    }
};

int main(){
    
    Solution *s=new Solution();
    vector<int> arr={1,1,2,2,3,5,6,2,2,1};
    vector<long long> res=s->distance(arr);

    

    return 0;
}