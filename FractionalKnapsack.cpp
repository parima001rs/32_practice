#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool comp(Item a, Item b){
    double x = (double) a.value / (double) a.weight;
    double y = (double) b.value / (double) b.weight;
    return x > y;
}

//TC:O(nlogn + n) & SC:O(1)
double solve(Item arr[], int n, int W){
    sort(arr, arr+n, comp);
    double profit = 0.0;

    for(int i=0; i<n; i++){
        if(arr[i].weight <= W){
            W -= arr[i].weight;
            profit += arr[i].value;
        }
        else if(arr[i].weight > W){
            profit += (arr[i].value/ (double)arr[i].weight) * (double)(W);
            break;
        }
    }
    return profit;
}

int main(){
    int n = 3, W = 50;
    Item arr[n] = {{60, 10}, {100, 20}, {120,30}};
    double maxProfit = solve(arr, n, W);
    cout<<maxProfit;

    return 0; 
}