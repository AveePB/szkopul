#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1007;

vector<int>visited(MAX_N);
vector<vector<int>>G(MAX_N, vector<int>(0));


void dfs(int crossroad_id, int previous_crossroad_id){
    visited[crossroad_id]++;

    for(auto n: G[crossroad_id]){
        if (n != previous_crossroad_id){
            if(visited[n]+1 >= 2){
                cout << "TAK" << endl;
                exit(0);
            }
            else{
                dfs(n, crossroad_id);
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k = 0;

    cin >> n >> k;

    for(int i=0; i<k; i++){
        int u, w = 0;
        cin >> u >> w;

        G[u].push_back(w);
        G[w].push_back(u);
    }

    for(int i=1; i<=n; i++){
        dfs(i, 0);
        visited.clear();
        visited.resize(MAX_N, 0);
    }

    cout << "NIE" << endl;

    return 0;
}
