#include<bits/stdc++.h>
using namespace std;

double FractionKnapsack(vector<int> weight, vector<int> value,int W) {
    vector<pair<double,int>> ratio;

    for(int i=0; i<weight.size(); i++) {
        ratio.push_back({((double)value[i]/weight[i]),i});
    }
    sort(ratio.rbegin(),ratio.rend()); // Or it can be sort(ratio.begin(),ratio.end(),greater<>())

    double TotValue = 0.0;

    for(int i=0; i<ratio.size(); i++) {
        int j = ratio[i].second;
        if(W>=weight[j]) {
            TotValue += value[j];
            W -= weight[j];
        }
        else {
            TotValue += ((double)W/weight[j]) * value[j];
            break;
        }
    }
    return TotValue;
}
int main() {
    vector<int> weight = {10,20,30,20};
    vector<int> value = {80,100,120,200};
    int W = 50;
    double total = FractionKnapsack(weight,value,W);

    cout << "The total value of items is: " << total << endl;
}
