/*
    @rajujnvgupta

    2/nov/2019

    finding largest squire area having one in given grid filled with 0 and 1
*/

#include <bits/stdc++.h>
#define int long long
///#define COL 1005
///#define ROW 1005

using namespace std;
int row, col;

int solve(vector<int>Mat){

    stack<int>S;
    int areaMax = 0;
    int currArea = 0;
    int i;
    for(i = 0; i < col;){

        if(S.empty() || Mat[S.top()] <= Mat[i]){
            S.push(i++);
        }

        else{
            int index = S.top();
            S.pop();
            if(S.empty()){
                int curr = min(Mat[index], i);
                //currArea = Mat[index]*i;
                currArea = curr*curr;
            }
            else{
                int curr = min(Mat[index], i-S.top()-1);
                //currArea = (i-S.top()-1)*Mat[index];
                currArea = curr*curr;
            }
            areaMax = max(areaMax, currArea);
        }
    }
    while(!S.empty()){
        int index = S.top();
        S.pop();
        if(S.empty()){

                int curr = min(Mat[index], i);
                //currArea = Mat[index]*i;
                currArea = curr*curr;
        }
        else{
                int curr = min(Mat[index], i-S.top()-1);
                //currArea = (i-S.top()-1)*Mat[index];
                currArea = curr*curr;
        }
        areaMax = max(currArea, areaMax);
    }
    return areaMax;
}

int32_t main(){

    cin>>row>>col;
    ///vector<vector<bool>>Mat(row, vector<bool>(col));
    vector<int>Mat(col, 0);
    int areaMax = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j< col; j++){
            bool bl;
            cin>>bl;
            if(!bl){
                Mat[j] = 0;
            }
            else{

                Mat[j]+=bl;
            }
        }
         areaMax = max(areaMax ,solve(Mat));
    }
    cout<<sqrt(areaMax)<<endl;
    return 0;
}

