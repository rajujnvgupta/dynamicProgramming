/*
    author @rajujnvgupta
    25/oct/2019

*/

//top down approach
#include <bits/stdc++.h>
using namespace std;

int dp[1000002];
int ans = 0;


int solve(vector<int>arr, int j, int prev){
    
    if(j == arr.size()){
        return 0;
    }

    ///if already calculated then return 
    if(dp[j] != -1){

        return dp[j];
    }

    for(int i = j; i < arr.size(); i++){
         if(arr[i] > prev){
            dp[j] = max(dp[j], 1+solve(arr, i+1, arr[i]));
        }
    }
    return dp[j];
}

int main() {
    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0; i < n; i++){

            cin>>arr[i];
        }
        memset(dp, -1, sizeof dp);
        
        cout<<solve(arr, 0, INT_MIN)<<endl;
    }
   return 0;
}

