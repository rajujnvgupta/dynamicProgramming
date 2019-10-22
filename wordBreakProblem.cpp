/*
    @rajujnvgupta
	22/10/2019
    top down approaches
*/
#include <bits/stdc++.h>
using namespace std;

bool check(string str, map<string, bool>mp){
    ///checking str is present in dictionary or not
    if(mp.count(str)){
        cout<<str<<endl;
        return true;
    }
    return false;
}

bool solve(string str, map<string, bool>mp, int *dp, int j, int len){

    ///this condition meaning word splitted successfull up to length
    if(len == str.size()){
        return true;
    }
    ///this condition meaning word splitted fail up to length
    if(j >= str.size()){
        return false;
    }

    if(dp[j] == -1){
        ///making that up to j length is calculated
        dp[j] = 0;
        string temp="";
        for(int i = j; i < str.size(); i++){
            temp += str[i];
            if(check(temp, mp)){
                bool bl = solve(str, mp, dp, i+1, len+temp.size()); ///length size 
                dp[j] = bl;
                if(bl){
                    return true;
                }
                
            }
        }
    }

    return dp[j]==1;
}

int main() {

        //number of word in dictionary
        int n;
        cin>>n;
        map<string, bool>mp;
        string str;
        for(int i = 0; i < n; i++){
            
            cin>>str;
            ///dictionary contain key
            mp[str] = 1;
        }
        
        ///taking splitting word
        cin>>str;
        //dp for memoisation 
        int dp[n+1];
        memset(dp, -1, sizeof dp);
    /// map<pair<int, int>, bool>dp;
        if(solve(str, mp, dp, 0, 0)){
            cout<<"true"<<endl;
        }
        else{
            cout<<"false"<<endl;
        }
    return 0;
}

