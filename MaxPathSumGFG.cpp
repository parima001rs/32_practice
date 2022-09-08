#include <bits/stdc++.h>
using namespace std;


int f(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp){
    if(j<0||j>= mat[0].size()) return -1e9;
    if(i==0) return mat[0][j];
    
    if(dp[i][j]!=-1)return dp[i][j];

    int up=mat[i][j]+f(i-1,j,mat,dp);
    int left=mat[i][j]+f(i-1,j-1,mat,dp);
    int right=mat[i][j]+f(i-1,j+1,mat,dp);
    
    return dp[i][j]=max(up,max(left,right));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int maxi=-1e9;
    vector<vector<int>>dp(n,vector<int>(m,-1));

    for(int j=0; j<m; j++){ //call from all the cols from last row
        maxi=max(maxi,f(n-1,j,matrix,dp));
    }
    return maxi;
}


int main(){
    vector<vector<int>>mat = { 
                    { 10, 10, 2, 0, 20, 4 },
                    { 1, 0, 0, 30, 2, 5 },
                    { 0, 10, 4, 0, 2, 0 },
                    { 1, 0, 2, 20, 0, 4 } };
             
    cout << getMaxPathSum(mat) << endl;
    return 0;
}