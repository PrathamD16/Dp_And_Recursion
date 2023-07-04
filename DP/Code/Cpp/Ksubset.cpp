#include <bits/stdc++.h>
using namespace std;

bool solve(int ind, vector<int>&nums, int k, vector<bool>&visited, int sum, int target){
    //Base condition
    if(k == 1)return true;
    if(ind >= nums.size())return false;
    if(sum == target)return solve(0, nums, k-1, visited, 0, target);
    //Choice condition
    bool pick = false;
    if(!visited[ind] && nums[ind] <= target){
        visited[ind] = true;
        pick = solve(ind+1, nums, k, visited, sum + nums[ind], target);
        visited[ind] = false;
        if(pick == true)return true;
    }

    bool not_pick = solve(ind+1, nums, k, visited, sum, target);    
    return not_pick || pick;
}

bool canPartition(vector<int>&nums, int k){
    int target = 0;
    int n = nums.size();
    for(int i = 0; i < nums.size(); i++){
        target += nums[i];
    }

    if(target%k != 0)return false;
    target /= k;
    vector<bool>visited(n, false);
    return solve(0, nums, k, visited, 0, target);
}

int main(){
    vector<int>nums = {5,4,1,3,2,2,2,1};    
    int k = 4;
    cout << canPartition(nums, k);
    return 0;
}