#include <bits/stdc++.h>

using namespace std; 

int n_clns{}, n_rows{}, n_points{}; 
int side{}; 

void find_biggest_area(vector<vector<int>>& sum_pref);

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    cin >> n_clns >> n_rows; 
    cin >> n_points; 

    side = min(n_clns, n_rows); 
    
    vector<vector<int>> grounds(n_rows, vector<int>(n_clns));
    vector<vector<int>> sum_pref(n_rows+1, vector<int>(n_clns+1)); 

    for(int i=0; i<n_points; i++){
        int x{}, y{}; 
        cin >> x >> y; 
        grounds[y-1][x-1] = 1; 
    }

    for(int row=0; row<n_rows; row++)
        for(int cln=0; cln<n_clns; cln++)
            sum_pref[row+1][cln+1] = (
                sum_pref[row][cln+1] + sum_pref[row+1][cln]
                - sum_pref[row][cln] + grounds[row][cln]);

    find_biggest_area(sum_pref); 
    return 0; 
}


void find_biggest_area(vector<vector<int>>& sum_pref){
    for(int current_side=side; current_side>0; current_side--){
    
        for(int c=0; c<(n_clns-current_side)+1; c++){
            int d = c + (current_side-1);

            for(int a=0; a<(n_rows-current_side)+1; a++){
                int b = a + (current_side-1); 

                int sum = (
                sum_pref[b+1][d+1] - sum_pref[a][d+1] 
                - sum_pref[b+1][c] + sum_pref[a][c]);

                if (sum == 0){
                    cout << current_side * current_side << endl; 
                    return;
                }
            }
        }
    }
    cout << 0 << endl;  
}
