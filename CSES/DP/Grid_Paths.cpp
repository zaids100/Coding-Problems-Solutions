#include<bits/stdc++.h>
using namespace std;
#define ll long long
int MOD=1e9+7;

// ll paths(int r,int c,vector<vector<char>> &grid,int n,vector<vector<ll>> &memo){
      
//        if(r==n-1 && c==n-1)
//        {  
//           if(grid[r][c]!='*')return 1;
//           return 0;
//        }
//        if(r>=n || c>=n || grid[r][c]=='*')return 0;
//        if(memo[r][c]!=-1)return memo[r][c];

//        ll right=paths(r,c+1,grid,n,memo);
//        ll down=paths(r+1,c,grid,n,memo);
       
//        return (right+down)%MOD;
// }

int main()
{   
    int n; cin>>n;
    
    vector<vector<char>> grid(n,vector<char>(n,'.'));
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    
    if(grid[0][0]=='*')
    {
        cout<<0<<endl;
        exit(0);
    }

    
    dp[0][0]=1;
    
    for(int r=0;r<n;r++)
    {
        for(int c=0;c<n;c++)
        {   
           if (grid[r][c] == '*') {
                dp[r][c] = 0;  // No paths to a trap
            } else {
                if (r > 0) dp[r][c] = (dp[r][c] + dp[r-1][c]) % MOD;  // From above
                if (c > 0) dp[r][c] = (dp[r][c] + dp[r][c-1]) % MOD;  // From left
            }
        }
    }

    cout<<dp[n-1][n-1]<<endl;

    return 0;
}