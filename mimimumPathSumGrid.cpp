/*
    @rajujnvgupta
    31/oct/2019

*/
/*


given 2D Grid of having sum weight to each sell find minimum path cast
    
    */

#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)

  int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){ 
                if(i == 0 && j == 0){
                    dp[i][j] = grid[0][0];
                }
                
                else if(i == 0 || j == 0){
                    if(i == 0){
                        dp[i][j] = grid[i][j]+dp[i][j-1];
                    }
                    else{
                        dp[i][j] = grid[i][j]+dp[i-1][j];    
                    }
                }
                else{
                    dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j]);    
                }
            }
        }
        return dp[m-1][n-1];
    }

    int main(){
        int m, n;
        cin>>m>>n;
        vector<vector<int>> Grid(m, vector<int>(n));
        loop(i,n){
            loop(j, n){
                cin>>Grid[i][j];
            }
        }
        cout<<minPathSum(Grid);
        return 0;
    }
