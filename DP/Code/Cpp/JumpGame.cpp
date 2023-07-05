#include <bits/stdc++.h>
using namespace std;

//[1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
int f1(int ind, vector<int>&arr){
    if(ind == 0)return 1;

    int minJump = 1e9;
    for(int i = 1; i <= arr[ind]; i++){
        if(ind - i < 0)continue;
        int temp = 1 + f1(ind - i, arr);
        minJump = min(minJump, temp);
    }
    return minJump;
}


int f3(vector<int>&a){
    int n = a.size();
    sort(a.begin(), a.end());
    if(n == 1)return -1;
    int maxFreq = n/2;
    int ptr = 0;
    int currFreq = 1;
    for(int i = ptr+1; i < n; i++){
        int currElement = a[ptr];
        if(currElement == a[i]){
            currFreq++;
            continue;
        }
        else{
            if(currFreq > maxFreq)return currElement;
            currFreq = 1;
            ptr = i;
        }
    }
    if(currFreq > maxFreq)return a[ptr];
    return -1;
}

int main(){
    // vector<int>arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    // // vector<int>arr = {1, 0, 3, 2, 6, 7};

    // int n = arr.size();
    // int ans = f1(n-1, arr);
    // if(ans >= 1e9)cout << -1;
    // else cout << ans;
    vector<int>a = {2,1,2,1};
    cout << f3(a);
    

    return 0;
}