#include<bits/stdc++.h>
using namespace std;
void FractionKnapsack(int n,double weight[],double value[],int Max) {
    vector<pair<double,int>> ratio(n);
    for (int i=0; i<n; i++) {
        ratio.push_back( { value[i]/weight[i],i });
    }
    sort(ratio.begin(),ratio.end(),greater<>());

    double TotVal=0.0,TotWeight=0.0;
    for(int i=0; i<n; i++) {
        int idx = ratio[i].second;

        if(weight[idx] <= Max) {
            TotVal += value[idx];
            Max -= weight[idx];
        }
        else{
            TotVal += (value[idx]/weight[idx]) * Max;
            break;
        }
    }
    cout << "Total value of the sack is : " << TotVal;
}
int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    double weight[n],value[n];
    int Max;
    cout << "Enter " << n << " number of weights: ";
    for(int i=0; i<n; i++) {
        cin >> weight[i];
    }
    cout << "Enter " << n << " number of values: ";
    for(int i=0; i<n; i++) {
        cin >> value[i];
    }
    cout << "Enter maximum capacity: ";
    cin >> Max;

    FractionKnapsack(n,weight,value,Max);
}