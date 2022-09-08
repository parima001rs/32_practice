#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/find-excel-column-number-column-title/
// column  column number
//   A  ->  1
//   B  ->  2
//   C  ->  3
//   ...
//   Z  ->  26
//   AA ->  27
//   AB ->  28 
//Binary to decimal conversion with base 26

//TC:O(N) & SC:O(1)
int solve(string s){
    int result = 0;
    for(int i=0; i<s.size(); i++){
        result *= 26;
        result += s[i] - 'A' + 1;
        //Another way
        // int d = s[i] - 'A' + 1;
        // result = result * 26 + d;
        
    }
    return result;
}

int main(){
    string s = "AC";
    int ans = solve(s);
    cout<<ans;

    return 0;
}