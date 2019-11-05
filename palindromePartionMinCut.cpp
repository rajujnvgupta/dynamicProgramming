/*
        some bug are there  
*/

#include <bits/stdc++.h>
using namespace std;
#define Row 1005
#define Col 1005
const int inf = 1e5+5;
unordered_map<string , int>mp;
int minCut(vector<vector<bool>>&dp, int i, int j){

    ///already palindrome no need to partitions
    if(dp[i][j]){
        return 0;
    }
    ///this return always zero 
    if(i==j){
        return 0;
    }
    ///this key give unique state
    string key = to_string(i)+ '|' + to_string(j);
    if(mp.find(key) != mp.end()){
        return mp[key];
    }
    else{
        
        mp[key] = inf;  ///verflow in case of INT_MAX
        for(int k = i; k <= j; k++){  ///why j-1 for corner case 
                int temp  = 1+minCut(dp, i, k)+minCut(dp, k+1, j);
                mp[key]  = min(temp, mp[key]);
        }
    }
    return mp[key];
}

int palindromePartition(string str){
    ///for null string 
    if(str.size()==0){
        return 0;
    }
    vector<vector<bool>>dp(str.size()+1, vector<bool>(str.size()+1));  ///by default vector are filled with false value
    for(int i = 1; i < (int)str.size(); i++){
        for(int j = 0; j <= i; j++){  ///it avoid for zero lenth 
            bool isPalindrome =   (dp[i-1][j+1] || (i-j)<=2);  ///checking is palindrome range  (j+1 >< i -1) ;
            if(isPalindrome && str[i] == str[j]){
                dp[i][j] = true;
            }
            else{
                dp[i][j]  = false;
            }
        }
    }
    int finalAns = minCut(dp, 0, (int)str.size()-1);
    return finalAns;
    //return str.substr(left, len+1);
}


int main(){
    string str;
    cin>>str;
    cout<<palindromePartition(str)<<endl;
    return 0;
}

