#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC:O(N) 
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> v;
        if(k > arr.size()){ //Edge case
            v.push_back(*max_element(arr.begin(), arr.end()));
            return v;
        }
        
        
        list<int> l; //can be used queue as well
        int i=0, j=0;

        while(j < arr.size()){ 
            if(l.empty()){  // at start
                l.push_back(arr[j]);   
            }
            else{
                while(l.size() > 0 && l.back() < arr[j]) //all smaller elements before j are useless
                    l.pop_back(); //remove those
                l.push_back(arr[j]); //enter current element at j
            }
            
            if(j-i+1 < k)
                j++;

            else if(j-i+1 == k){
                v.push_back(l.front()); //max of the subarray
                if(l.front() == arr[i]) //remove calculations
                    l.pop_front();
                i++; //slide the window
                j++;
            }
        }
        return v;

    }
};

int main(){
    vector<int>arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int k = 3;
    Solution obj;
    vector<int>res = obj.maxSlidingWindow(arr, k);
    for(auto it: res){
        cout<<it<<" ";
    }

    return 0;
}

