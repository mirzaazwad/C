#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

int main()
{
    fastio;
    int w,h;
    cin>>w>>h;
    vector<vector<int>>dp(w+1,vector<int>(h+1));
    for(int i=0;i<=w;i++){
      for(int j=0;j<=h;j++){
        if(i==j)dp[i][j]=0;
        else{
          dp[i][j]=INT_MAX;
          for(int k=1;k<i;k++){
            dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
          }
          for(int k=1;k<j;k++){
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
          }
        }
      }
    }
    cout<<dp[w][h]<<endl;
    return 0;
}