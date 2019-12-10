/*
  10/dec/2019 @rajujnvgupta
  //problem link
  https://codeforces.com/problemset/problem/846/F
*/


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 1e6+5;
int last_index_of_num[N];
int32_t main() {
    
    int n;
    cin>>n;
    int arr[n+1];
    arr[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }
    memset(last_index_of_num, 0, sizeof(last_index_of_num));
    int ans[n+1];
    memset(ans, 0, sizeof(ans));
    double sum = 0;
    for(int i = 1; i <= n; i++){
        ans[i] = ans[i-1] + (i - last_index_of_num[arr[i]]);
        last_index_of_num[arr[i]] = i;
        sum+=ans[i];
    }
    double Ans = 0.0;
    Ans = ((2*(sum-n)+n)/(n*n*1.0));   ///Ans = ((2*(sum-n)+n)/n*n*1.0); very dangerous, apply proper bracket
    cout<<fixed<<setprecision(6)<<Ans<<'\n';
    return 0;
}
