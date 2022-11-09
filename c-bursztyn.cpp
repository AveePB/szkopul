#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, m, k = 0;

    cin >> n >> m >> k;

    vector<vector<long long int>> area(n, vector<long long int>(m));
    vector<vector<long long int>> sum_pref(n, vector<long long int>(m+1));
    //pref array for each row

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> area[i][j];
            sum_pref[i][j+1] = sum_pref[i][j] + area[i][j];
        }
    }
    long long int max_ambers = 0;

    for(int i=0; i<n-k+1; i++){
        for(int j=0; j<m-k+1; j++){
           long long int ambers = 0;

            for(int l=0; l<k; l++){
                ambers += sum_pref[l+i][j+k] - sum_pref[l+i][j];
            }
            max_ambers = max(max_ambers, ambers);
        }
    }
    cout << max_ambers << endl;


    return 0;
}
