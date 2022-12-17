#include<bits/stdc++.h>
using namespace std;

const int MAXN = 25e4+7;
const int BASE = 256*1024;

int lvl[MAXN], pre[MAXN], max_pre[MAXN];
vector<int> graph[MAXN];
int seg[2*BASE+7], c{};

void change(int a, int b, int v = 1, int l=0, int r=BASE-1){
    if(b < l || r < a)
        return;
    if(a <= l && r <= b){
        ++seg[v];
        return;
    }
    int mid = (l + r) / 2;
    change(a, b, 2*v, l, mid);
    change(a, b, 2*v+1, mid+1, r);
}

int query(int i){
    int res = 0;
    i += BASE;
    while(i > 0){
        res += seg[i];
        i /= 2;
    }
    return res;
}

void dfs(int v, int p, int l){
    pre[v] = ++c;
    lvl[v] = l;
    for(auto u: graph[v]){
        if(u == p)
            continue;
        dfs(u, v, l+1);
    }
    max_pre[v] = c;
}

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int n{}, m{};
    cin >> n;
    for(int i=0; i<(n-1); i++){
        int a{}, b{};
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 1, 0);
    cin >> m;
    for(int i=0; i<(n+m-1); i++){
        int a{}, b{}; char type{};
        cin >> type;
        if(type == 'A'){
            cin >> a >> b;
            change(pre[b], max_pre[b]);
        }
        else{
            cin >> a;
            cout << lvl[a] - query(pre[a]) << '\n';
        }
    }
    return 0;
}
