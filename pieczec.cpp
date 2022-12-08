#include<bits/stdc++.h>
using namespace std;

int q{}, n{}, m{}, a{}, b{};

bool check_grid(string g[], vector<pair<int, int>>& s);
void set_steps(string p[], vector<pair<int, int>>& s);

pair<int, int> get_start(string p[]){
    for(int i=0; i<a; i++)
        for(int j=0; j<b; j++)
            if(p[i][j] == 'x')
                return {i, j};
    return {0, 0};
}

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> q;
    while(q--){
        cin >> n >> m >> a >> b;
        vector<pair<int, int>> steps;
        string pattern[a+7];
        string grid[n+7];

        for(int i=0; i<n; i++)
            cin >> grid[i];
    
        for(int i=0; i<a; i++)
            cin >> pattern[i];
        
        set_steps(pattern, steps);
        
        if(check_grid(grid, steps))
            cout << "TAK\n";
        else 
            cout << "NIE\n";
    }

    return 0;
}


bool check_grid(string g[], vector<pair<int, int>>& s){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(g[i][j] == 'x'){
                for(auto p: s){
                    int x = i+p.first;
                    if(x < 0 || x >= n)
                        return false;

                    int y = j+p.second;
                    if(y < 0 || y >= m)
                        return false;

                    if(g[x][y] != 'x')
                        return false;
                    g[x][y] = '.';
                }
            }
        }
    }
    return true; 
}

void set_steps(string p[], vector<pair<int, int>>& s){
    pair<int, int> start = get_start(p);
     for(int i=0; i<a; i++)
        for(int j=0; j<b; j++)
            if(p[i][j] == 'x')
                s.push_back({i-start.first, j-start.second});
}
