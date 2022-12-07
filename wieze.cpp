#include<bits/stdc++.h>
using namespace std;

map<string, int> m;
int n{}, ans{};
string w{};

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> w;
        if(m.find(w) != m.end())
            m[w] += 1;
        else 
            m[w] = 1;
    }

    for(auto a: m){
        if(a.second == 1){
            ans = max(ans, int(a.first.size()));
        }
        else if(a.second > 1){
            if(m.find(a.first+a.first) == m.end())
                m[(a.first+a.first)] = a.second/2;
            else 
                m[(a.first+a.first)] += a.second/2;                
        }
    }
    cout << ans;

    return 0;
}
