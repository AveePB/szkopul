#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+7;
bool visited[MAXN]{}, sign[MAXN]{};
vector<vector<int>> graph(MAXN);
int n{}, m{}, a{}, b{};

void dfs(int v, bool si){
    if(visited[v])
        return;
    visited[v] = true;
    sign[v] = si;
    for(auto neighbor: graph[v])
        dfs(neighbor, !si);
}

bool is_valid(){
    for(int i=1; i<=n; i++){
        if(graph[i].empty())
            return false;
    }
    return true;
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
        if(visited[i])
            continue;
        dfs(i, 1);
    }

    if(is_valid()){
        cout << "TAK\n";
        for(int i=1; i<=n; i++){
            if(sign[i])
                cout << 'K';
            else 
                cout << 'S';
            cout << '\n';
        }
    }
    else{
        cout << "NIE\n";
    }

    return 0;
}
