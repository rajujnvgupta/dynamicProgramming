/*
    @rajujnvgupta
    23/oct/2019
*/
#include <bits/stdc++.h>
using namespace std;
string str;

///checking if word contain in dictionary
bool check(string key, map<string, bool>mp){
    if(mp[key]){
        return true;
    }
    return false;
}

void solve(map<string, bool>mp, int j, int len, vector<string>lst, string str){
    
    ///decomposition found and print
    if(len == str.size()){
        for(int i = 0; i < lst.size(); i++){
            cout<<lst[i]<<" ";
        }
        cout<<endl;
        return;
    }

    if(j>=str.size()){
        return;
    }
    ///slicing 
    string temp = "";
    for(int i = j; i < str.size(); i++){
        temp += str[i];
        if(check(temp, mp)){
            
            ///current string is taken taken
            lst.push_back(temp);
            solve(mp, i+1, len+temp.size(), lst, str);
            //backtracking
            lst.pop_back();
            ///current string is not taken
            solve(mp, i+1, len, lst, str);
        }
    } 
}

int main(){
    
    //number of word in dictionary
    int n;
    cin>>n;
    map<string, bool>mp;
    string str;
    //words of dictionary
    for(int i = 0; i < n; i++){
        cin>>str;
        mp[str] = 1;
    }
 
    ///string to be decompose
    cin>>str;
    vector<string>lst;
    solve(mp, 0, 0, lst, str);
    return 0;
}

