#include <bits/stdc++.h>
using namespace std;

// We have to cross a river of length n meters in which 
// there are n-1 stones at a distance of 1 meter each. 
// We can jump Upton m meters in a single jump. 
// Find the number of possible ways we can cross the river.

void solve(int n, int m){
    int dp[n+1];
    dp[0] = 0;
    for(int i=1; i<n; i++){
        dp[i] = INT_MAX;
        for(int j=1; j<=m; j++){
            if(i-j > 0){
                dp[i] = dp[i]+ dp[i-j];
            }
        }
    }
    cout<<dp[n];
}

int main(){
    int n = 5;
    int m = 2;
    solve(n, m);
    return 0;
}