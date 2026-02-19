#include <bits/stdc++.h>
using namespace std;

int main(){
   

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        vector<long long> res;
        vector<bool> used(n, false);
        long long cur = 0;

        for(int step = 0; step < n; step++){
            int best = -1;
            long long bestVal = cur;
            for(int i = 0; i < n; i++){
                if(!used[i]){
                    long long val = cur | a[i];
                    if(val > bestVal){
                        bestVal = val;
                        best = i;
                    }
                }
            }
            if(best == -1){
                for(int i = 0; i < n; i++){
                    if(!used[i]){
                        res.push_back(a[i]);
                        used[i] = true;
                    }
                }
                break;
            }else{
                res.push_back(a[best]);
                used[best] = true;
                cur |= a[best];
            }
        }

        for(long long x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
