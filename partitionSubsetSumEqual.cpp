/*
	@rajujnvgupta
	09/nov/2019
	
	leetcode.com
	problem : Partition Equal Sum Subsets
*/

#include <bits/stdc++.h>
using namespace std;

 bool canPartition(vector<int>& arr){
        int n = (int)arr.size();
        int target = 0;
        for(int i = 0;i < n; i++){
            target += arr[i];
        }
        
        if(target&1){
        return 0;
    }

    target = target / 2;
    vector<vector<bool>>dp(target+1, vector<bool>(n+1));

    for(int i = 0; i <= n; i++){
        dp[0][i] = true;
    }

    for(int s = 1; s<=target; s++){
        for(int i = 1; i <= n; i++){
           if(s-arr[i-1] >= 0){
               dp[s][i] = (dp[s-arr[i-1]][i-1] || dp[s][i-1]);
           }
        }
    }
    
        for(int i = 0; i <= n; i++){
            if(dp[target][i]){
                return true;
            }
        }
        return false;
    }

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0;  i < n; i++){
        cin>>arr[i];
    }
    if(canPartition(arr)){
        cout<<"yes"<<endl;
        return 0;
    }
    cout<<"no"<<endl;
    return 0;
}

