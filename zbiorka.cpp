#include <bits/stdc++.h>

using namespace std; 

const long long INF = 20000000000; 

vector<pair<int, int>> coins; 
map<int, long long> dp; 

long long w{}; // the weight of gathered money 
int n{}; // n kinds of the coins 

long long best_sum(int s, long long m){

    if(s == 0) return m;
    if(s < 0) return INF; 

    if(dp.find(s) != dp.end()) return dp[s]+m; 

    long long min_m = INF; 
    for(auto c: coins){
        long long r = best_sum((s-c.second), c.first); 
        min_m = min(min_m, r); 
    }
    dp[s] = min_m;

    return dp[s] + m; 
}


int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    cin >> w >> n; 
    coins.resize(n); 
    
    for(int i=0; i<n; i++)
        cin >> coins[i].first >> coins[i].second; 
      //cin >> value >> weight 

    long long r = best_sum(w, 0); 
    if(r == INF) cout << "NIEMOZLIWE" << endl; 
    else cout << r << endl; 


    return 0; 
}