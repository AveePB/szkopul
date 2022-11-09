#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3+7; 

vector<int> v(MAXN); 
int n{}, max_s{}, sum{};

int main()
{
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n; 
    
    for(int i=0; i<n; i++){
        cin >> v[i];
        sum += v[i]; 
    }
    max_s = (sum+1)/2;
    vector<int> dp(max_s+1); 

    for(int i=0; i<n; i++)
        for(int j=max_s; j>0; j--)
            if(v[i] <= j)
                dp[j] = max(dp[j], dp[j-v[i]] + v[i]);

    int i1 = max(sum-dp[max_s], dp[max_s]); 
    int i2 = min(sum-dp[max_s], dp[max_s]);

    cout << i1 << " " << i2 << endl; 

    return 0;
}