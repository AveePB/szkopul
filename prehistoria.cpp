#include <bits/stdc++.h> 

using namespace std; 

vector<vector<int>> graph; 
vector<int> visited; 
int n{}, m{}, q{}; 

void dfs(int t, int s);

int main(){ 
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n >> m; 

    graph.resize(n+7); 
    visited.resize(n+7); 

    while(m--){
        int t1{}, t2{}; 
        cin >> t1 >> t2; 

        graph[t1].push_back(t2); 
        graph[t2].push_back(t1); 
    }

    cin >> q; 

    for(int i=1; i<=n; i++){
        if(visited[i] == 0)
            dfs(i, i); 
    }

    while(q--){
        int t1{}, t2{}; 
        cin >> t1 >> t2;
        
        if(visited[t1] == visited[t2])
            cout << "TAK" << endl;
        else 
            cout << "NIE" << endl;   
    }

    return 0; 
}

void dfs(int t, int s){
    visited[t] = s; 
    for(auto t1: graph[t]){
        if (visited[t1] == 0)
            dfs(t1, s); 
    }
}
