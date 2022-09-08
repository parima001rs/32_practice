#include <bits/stdc++.h>
using namespace std;
#define C 4
#define R 4

// TC:O(M^N) & SC:O(1)
int solveBrute(bool mat[R][C]){
    int rowIndex = -1;
    int maxCount = 0;

    for(int i=0; i<R; i++){
        int count = 0;
        for(int j=0; j<C; j++){
            if(mat[i][j] == 1){
                count++;
            }
        }
        if(count > maxCount){
            maxCount = count;
            rowIndex = i;
        }
    }
    return rowIndex;
}

//Better: Since each row is sorted, we can use binary search
//We find the index of first instance of 1 in each row. 
// The count of 1s will 
// be equal to total number of columns minus the index of first 1.
//TC:O(mlogn) & SC:O(logn) ~ stack space
int first(bool arr[], int low, int high){
    if(high >= low){
        int mid = low + (high-low)/2;
        if((mid == 0 || arr[mid-1] == 0) && arr[mid] == 1)
            return mid;
        else if(arr[mid] == 0)
            return first(arr, mid+1, high);
        else    
            return first(arr, low, mid-1);
    }
    return -1;
}

int solveBetter(bool mat[R][C]){
    int row_ind = 0, maxi = -1;
    int index; //first instance of 1
    for(int i=0; i<R; i++){
        index = first(mat[i], 0, C-1);
        if(index != -1 && C-index > maxi){ //if not out of bound
            maxi = C - index; //count of 1s
            row_ind = i;
        }
    }
    return row_ind;
}

//Optimised
// at worst case TC:O(mlogn)
int solveOptimised(bool mat[R][C]){
    int i, index;
    
    int row_ind = 0;
    int maxi = first(mat[0], 0, C-1);

    for(i=1; i<R; i++){
        if(maxi != -1 && mat[i][C-maxi-1] == 1){ //check the previous col of next row if it is 1
            index = first(mat[i], 0, C-maxi); // find the first instance of 1 in that row
            if(index != -1 && C-index > maxi){ // if the count of 1s > maxi , update it
                maxi = C-index;
                row_ind = i;
            }
        }
        else{
            maxi = first(mat[i], 0, C-1);
        }
    }
    return row_ind;
}

//Optimal
// TC:O(m+n) & SC:O(1)
int solveOptimal(bool mat[R][C]){
    int j;
    int row_ind = 0;
    j = C-1;

    for(int i=0; i<R; i++){
        bool flag = false;
        while(j >= 0 && mat[i][j] == 1){
            j = j-1;
            flag = true;
        }
        if(flag){
            row_ind = i;
        }
    }
    if(row_ind == 0 && mat[0][C-1] == 0)
        return -1;
    return row_ind;
}

int main(){
    bool mat[R][C] = { {0, 0, 0, 1},
                    {0, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0}};
 
    cout << solveOptimal(mat);
    return 0;
}