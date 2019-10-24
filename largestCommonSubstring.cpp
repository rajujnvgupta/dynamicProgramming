/*
    auther @rajujnvgupta
    25/oct/2019

*/

#include <bits/stdc++.h>
#define int long long int 
using namespace std;

string s1="", s2="";
int ans = 0;

int dp[100][100];
int solve(int i, int j){
    ///maintaining global maximum
    ///ans = max(ans, len);
    if(i >= s1.size() || j >= s2.size()){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans1 = 0, ans2 = 0, ans3 = 0;

    solve(i+1, j);   // going through all n*m states
    solve(i, j+1);

    if(s1[i]==s2[j]){
        dp[i][j] = 1+solve(i+1, j+1);
        ans = max(dp[i][j], ans);
        return dp[i][j];
    }
    else{
	//intruducing break point when found a different in current working substring
        return dp[i][j] = 0; ///= ans = max(ans, max(ans1, max(ans2, ans3)));
    }
    
}

int32_t main(){

    int t;
    cin>>t;
    while(t--){
       /// memset(dp, -1, sizeof dp);
        ans = 0;
        memset(dp, -1, sizeof dp);
        cin>>s1>>s2;
        solve(0, 0);
        cout<<ans<<endl;
    }
    return 0;
}

