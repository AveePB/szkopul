#include<bits/stdc++.h>

using namespace std; 

const int MAXN = 1000+7; 

vector<vector<int>> t(MAXN, vector<int>(MAXN)), 
a(MAXN, vector<int>(MAXN)); 

int n{};


int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n; 

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> a[i][j];
    
    for(int i=1; i<=n; i++){
        t[1][i] = a[1][i] + t[1][i-1]; 
        t[i][1] = a[i][1] + t[i-1][1]; 
    }

    for(int i=2; i<=n; i++)
        for(int j=2; j<=n; j++)
            t[i][j] = a[i][j] + max(t[i-1][j], t[i][j-1]); 

    
    cout << t[n][n] << endl; 
    return 0; 
}
