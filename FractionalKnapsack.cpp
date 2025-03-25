#include<bits/stdc++.h>
using namespace std;

double FractionKnapsack(int weight[], int value[],int W,int n) {
    vector<pair<double,int>> ratio;

    for(int i=0; i<n; i++) {
        ratio.push_back({((double)value[i]/weight[i]),i});
    }
    sort(ratio.rbegin(),ratio.rend());   // Or it can be sort(ratio.begin(),ratio.end(),greater<>())

    double TotValue = 0.0;

    for(int i=0; i<ratio.size(); i++) {
        int j = ratio[i].second;
        if(W>=weight[j]) {
            TotValue += value[j];
            W -= weight[j];
        }
        else {
            TotValue += ((double)value[j]/weight[j]) * W;
            break;
        }
    }
    return TotValue;
}
int main() {
    int W;              //= 50;
    int n;
    cout << "Enter number of items: ";
    cin>>n;

    int weight[n];     //= {1,2,3};
    int value[n];     //= {10,15,40};

    cout<< "Enter " << n << " number of weights: ";
    for(int i=0; i<n; i++) {
        cin>> weight[i];
    }
    cout<< "Enter " << n << " number of values: ";
    for(int i=0; i<n; i++) {
        cin>> value[i];
    }
    cout << "Enter maximum knapsack capacity: ";
    cin>>W;
    double total = FractionKnapsack(weight,value,W,n);

    // cout << "The weight of the items: " << endl;
    // for(auto i: weight) {
    //     cout << i << " ";
    // } 
    // cout << endl;
    // cout << "The value of the items: " << endl;
    // for(auto i: value) {
    //     cout << i << " ";
    // } 
    // cout << endl;

    cout << "The total value of in the knapsack is: " << total << endl;
}
