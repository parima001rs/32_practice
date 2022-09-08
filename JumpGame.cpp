#include<bits/stdc++.h>
using namespace std;

//Greedy Approach: to find if the jump till end is possible or not
// TC:O(N) & SC:O(1)
bool canJump(vector<int>& nums){
    int n = nums.size();
    if(n <= 1) return true; // base case
    int reachable = 0;

    for(int i=0; i<n; i++){
        if(reachable < i) return false;
        reachable = max(reachable, i+nums[i]);
    }
    return true;
}

// to find minimum number of jumps to reach end
// TC:O(N^2) & SC:O(N)
int minJumpsDP(vector<int>& nums){
    int n = nums.size();
    vector<int>jumps(n, INT_MAX-1);
    jumps[0] = 0;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(i <= (j + nums[j])){
                jumps[i] = min(jumps[i], jumps[j]+1);
            }
        }
    }
    return jumps[n-1];
}

// to find minimum number of jumps to reach end
// TC:O(N) & SC:O(1)
int minJumps(vector<int>& nums){
    int n = nums.size();
    int reachable = 0;
    int curr = 0;
    int jumpCount = 0;

    for(int i=0; i<nums.size()-1; i++){
        reachable = max(reachable, nums[i]+i);
        if(i == curr){
            curr = reachable;
            jumpCount += 1;
        }
    }
    return jumpCount;
}

int main(){
    vector<int> v = {1, 1, 2, 5, 2, 1, 0, 0, 1, 3};
    // bool res = canJump(v);
    int res = minJumpsDP(v);
    cout<<res;

    return 0;
}