#include <bits/stdc++.h>
using namespace std;

// the number of subarrays with at most K distinct elements
//TC:O(N) & SC:O(K) giving TLE on gfg
int most_k_chars(string &s, int k) {
    if (s.size() == 0) {
        return 0;
    }
    unordered_map<char, int> table;
    int num = 0, left = 0;
    for (int i = 0; i < s.size(); i++) {
        table[s[i]]++;
        while (table.size() > k) {
            table[s[left]]--;
            if (table[s[left]] == 0) {
                table.erase(s[left]);
            }
            left++;
        }
        num += i - left + 1;
    }
    return num;
}

int solve(string &s, int k) {
    return most_k_chars(s, k) - most_k_chars(s, k - 1);
}

//Optimal same TC & SC
long long int atMostK(string s, int k){
        vector<long long int> f(26, 0);
        long long int start = 0, count = 0, distinct = 0;
        
        for(int i=0; i<s.size(); i++){
            if(f[s[i] - 'a'] == 0) distinct++;
            f[s[i] - 'a']++;
            
            while(distinct > k){
                f[s[start] - 'a']--;
                if(f[s[start] - 'a'] == 0) distinct--;
                start++;
            }
            if(distinct <= k)
                count += i-start + 1;
        }
        return count;
    }
    
    
long long int solveBetter(string s, int k) {
    //code here.
    return atMostK(s, k) - atMostK(s, k-1);
}

int main() {
    string s1 = "pqpqs";
    cout << "Answer should be 7: " << solve(s1, 2) << endl;
    // string s2 = "aabab";
    // cout << "Answer should be 0: " << exact_k_chars(s2, 3) << endl;

    return 0;
}


