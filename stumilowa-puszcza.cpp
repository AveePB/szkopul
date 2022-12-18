#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+7;
vector<set<int>> g(MAXN);
int n{}, m{}, p{}, q{};

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> p >> q;
        g[p].insert(q);
        g[q].insert(p);
    }

    for(int i=1; i<=n; i++){
        if(g[i].size() == 0){
            cout << "Wiewior sam!";
        }
        else{
            for(auto neighbor: g[i]){
                cout << neighbor << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
