/*
    @rajujnvgupta
    31/oct/2019

*/
/*


given 2D obstacleGrid of 0 and 1 having 1 meaning blocked and empty not blocked;
    calculate total number of unique path
    */

#include<bits/stdc++.h>
using namespace std;
const long inf = -1000000000;
#define loop(i, n) for(int i = 0; i < n; i++)
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        int m = (long)obstacleGrid.size();
        int n = (long)obstacleGrid[0].size();
        long dp[m][n];
        
        const long inf = -1000000000;
        
        memset(dp, 0, sizeof(dp));
        
        
        for(int i = 0; i < m; i++){
            for(int j =0; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j] = inf;
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            if(obstacleGrid[i][0] == inf){
                break;
            }
            else{
                dp[i][0] = 1;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(obstacleGrid[0][i] == inf){
                break;
            }
            else{
                dp[0][i] = 1;
            }
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == inf || (obstacleGrid[i-1][j] == inf && obstacleGrid[i][j-1] == inf)){
                    continue;
                }
                else if(obstacleGrid[i-1][j] == inf){
                    dp[i][j] = dp[i][j-1];
                }
                else if(obstacleGrid[i][j-1]==inf){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];                    
                }
                
                ///dp[i][j] = max(ans, dp[i][j]);
            }
        }
        return dp[m-1][n-1];      
    }

    int main(){
        int m, n;
        cin>>m>>n;
        vector<vector<int>> obstacleGrid(m, vector<int>(n));
        loop(i,n){
            loop(j, n){
                cin>>obstacleGrid[i][j];
            }
        }
        cout<<uniquePathsWithObstacles(obstacleGrid);
        return 0;
    }
