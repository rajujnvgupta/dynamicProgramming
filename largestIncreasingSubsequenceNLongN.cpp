/*
    author @rajujnvgupta
    26/oct/2019
    reference geeksforgeeks

*/

#include <bits/stdc++.h>
using namespace std;

int search(vector<int>aux, int l, int r, int key){

    while(r-l > 1){
        int mid = (r+l)/2;
        if(aux[mid] >= key){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return r;
}

int solve(vector<int>arr){

    if(v.size() == 0){
        return 0;
    }

    vector<int>aux(arr.size(),  0);
    aux[0] = arr[0];
    int largest = 1;
    for(int i = 0; i < arr.size(); i++){

        //building new sequence
        if(arr[i] < aux[0]){
            aux[0] = arr[i];
        }

        else if(arr[i] > aux[largest-1]){
            aux[largest++] = arr[i];
        }
        else{
            int index = search(aux, -1, largest-1, arr[i]);
            aux[index] = arr[i];
        }
    }

    return largest;
}

int main() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<solve(arr)<<endl;
    
    return 0;
}

