#include <bits/stdc++.h>
#define int long long int 
using namespace std;

string s1="", s2="";
int ans = 0;

int dp[100][100][100];
int solve(int i, int j, int k){

    if(i >= s1.size() || j >= s2.size()){
        return 0;
    }

    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }
    int ans1 = 0, ans2 = 0, ans3 = 0;

    solve(i+1, j, k);   // going through all n*m states
    solve(i, j+1, k);

    if(s1[i]==s2[j]){
        dp[i][j][k] = 1+solve(i+1, j+1, k);
        ans = max(dp[i][j][k], ans);
        return dp[i][j][k];
    }
    else if(k > 0 && s1[i] != s2[j]){
        dp[i][j][k] = 1+solve(i+1, j+1, k-1);
        ans = max(dp[i][j][k], ans);
        return dp[i][j][k];
    }

    return dp[i][j][k] = 0;
}

int32_t main(){

    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        ans = 0;
        memset(dp, -1, sizeof dp);
        cin>>s1>>s2;
        solve(0, 0, k);
        cout<<ans<<endl;
    }
    return 0;
}

