#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    unordered_map<string, int> mpp;
    string team;
    for(int i = 0; i < n; i++){
        cin >> team;
        mpp[team]++;
    }
    string winner;
    int maxGoals = 0;
    for(auto it : mpp){
        if(it.second > maxGoals){
            maxGoals = it.second;
            winner = it.first;
        }
    }
    cout << winner;
    return 0;
}
