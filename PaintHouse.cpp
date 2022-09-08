#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //by updating given matrix
    int solve(vector<vector<int>> &costs, int n){
        if(n == 0) return 0;
        
        for(int i=1; i<n; i++){
            costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
            costs[i][2] += min(costs[i-1][0], costs[i-1][1]);
        }

        int res = min(costs[n-1][1], min(costs[n-1][0], costs[n-1][2]));
        return res;
    }

    //without updating given matrix
    int solveBetter(vector<vector<int>> &costs, int n){
        it(n == 0) return 0;

        vector<vector<int> > dp(n, vector<int>(3, 0));

        // Base Case
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];

        for (int i = 1; i < n; i++) {
            dp[i][0] = min(dp[i - 1][1],dp[i - 1][2]) + costs[i][0];
            dp[i][1] = min(dp[i - 1][0],dp[i - 1][2]) + costs[i][1];
            dp[i][2] = min(dp[i - 1][0],dp[i - 1][1]) + costs[i][2];
        }

        cout << min(dp[n - 1][0],min(dp[n - 1][1],dp[n - 1][2]));
    }

};



int main(){
    vector<vector<int>> costs{ { 14, 2, 11 },
                                { 11, 14, 5 },
                                { 14, 3, 10 } };
    int N = costs.size();
    Solution obj;
    int res = obj.minCost(costs, N);
    cout<<res;
    return 0;
}