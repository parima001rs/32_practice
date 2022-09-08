#include<bits/stdc++.h>
using namespace std;

/*
1.Brute force: Find all possible substrings O(N^2), 
             then find longest palindromic O(N); 
             TC:O(N^3) & SC:O(1)
2.DP:  TC:O(N^2) SC:O(N^2)
3.Expand around center: TC:O(N^2) & SC:O(1)
4.Manacher's Algorithm: TC:O(N) & SC:O(1) (Non-trivial)
*/
class Solution{
public:
    bool isPalindrome(string str){
        int i=0, j=str.size()-1;
        while(i<j){
            if(str[i++] != str[j--])
                return false;
        }
        return true;
    }
    // BruteForce
    string solveBrute(string str){
        int n = str.size();
        if(n == 0) return "";
        if(n == 1) return str;
        string result = "";
        for(int i=0; i<n; i++){
            for(int j=1; j<n-i; j++){
                if(isPalindrome(str.substr(i, j))){
                    if(result.size() < j)
                        result  = str.substr(i, j);
                }
            }
        }
        return result;
    }

    //DP approach
    string solveDP(string s)
    {
        int n = s.size();
        if (n == 0) return "";
        if (n == 1) return s;

        // dp[i][j] will be 'true' if the string from index i to j is a palindrome.
        bool dp[n][n];

        //Initialize with false
        memset(dp, 0, sizeof(dp));

        //Every Single character is palindrome
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        string ans = "";
        ans += s[0];

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    //If it is of two character OR if its susbtring is palindrome.
                    if (j - i == 1 || dp[i + 1][j - 1])
                    {
                        //Then it will also a palindrome substring
                        dp[i][j] = true;

                        //Check for Longest Palindrome substring
                        if (ans.size() < j - i + 1)
                            ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return ans;
    }

    //Expand around center Approach
    string expand(string str, int left, int right){
        while(left>=0 && right<str.size() && str[left] == str[right]){
            left--;
            right++;
        }
        return str.substr(left+1, right-left-1);
    }

    string solveEAC(string str){
        int n = str.size();
        if(n == 0) return "";
        if(n == 1) return str;

        string res = "";
        for(int i=0; i<n; i++){
            string temp = expand(str, i, i); //odd length palindrome
            if(res.size() < temp.size())
                res = temp;

            temp = expand(str, i, i+1); //even length palindrome
            if(res.size() < temp.size())
                res = temp;
        }
        return res;
    }

    // Manacher's Algorithm
    // code : https://leetcode.com/problems/longest-palindromic-substring/discuss/2967/22-line-C%2B%2B-Manacheru2019s-Algorithm-O(n)-Solution
    // video : https://youtu.be/V-sEwsca1ak


};


int main(){
    string str = "babacabd";
    Solution obj;
    string res = obj.solveEAC(str);
    cout<<res;

    return 0;
}