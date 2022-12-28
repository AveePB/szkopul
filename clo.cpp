#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+7;
vector<vector<int>> graph(MAXN);
int n{}, m{}, a{}, b{};
bool visited[MAXN]{};
int ans[MAXN]{};

pair<int, int> dfs_detect_cycle(int v, int pre_v){
    if(visited[v] == true)
        return {v, pre_v};
    visited[v] = true;

    for(auto subv: graph[v]){
        if(subv != pre_v){
            pair<int, int> edge = dfs_detect_cycle(subv, v);
            if(edge.first != -1 && edge.second != -1)
                return edge;
        }
    }
    return {-1, -1};
}

void dfs(int v, int pre_v){
    if(ans[v] != 0)
        return;
    ans[v] = pre_v;

    for(auto subv: graph[v])
        dfs(subv, v);
}

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(int i=1; i<=n; i++){
        if(ans[i] != 0)
            continue;
       
        pair<int, int> edge = dfs_detect_cycle(i, i);
        if(edge.first == -1 && edge.second == -1){
            cout << "NIE\n";
            return 0;
        }
         

        for(int j=0; j<graph[edge.first].size(); j++)
            if(edge.second == graph[edge.first][j])
                swap(graph[edge.first][j], graph[edge.first].back());

        for(int j=0; j<graph[edge.second].size(); j++)
            if(edge.first == graph[edge.second][j])
                swap(graph[edge.second][j], graph[edge.second].back());
            
        graph[edge.first].pop_back();
        graph[edge.second].pop_back();
        
        
        dfs(edge.first, edge.first);
        ans[edge.first] = edge.second;
    }
   
    cout << "TAK\n";
    for(int i=1; i<=n; i++)
        cout << ans[i] << '\n';
    
    return 0;
}
