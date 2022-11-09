#include <bits/stdc++.h>
using namespace std; 

const int MAXN = 3e4+7; 
vector<pair<int, int>> seg(3*MAXN, {0, 0}); 
vector<int> v(MAXN);
int base{};

bool is_accepted(int max_n, vector<int>& vec){
    for(int i = 1; i <= max_n; i++)
		if(!(i > vec[i-1]))
			return false;
    return true; 
}

void set_base(int num){
    base = 1; 
    while(base < num)
        base *= 2;
    base -= 1; 
}

void init_build(int num){
    for(int i=0; i<num; i++)
        seg[base+i] = {1, i+1}; 
    
    for(int i=base-1; i>=0; i--)
        seg[i].first = seg[2*i+1].first + seg[2*i+2].first;
}

int get_num(int s){
    int node{}; 
    while (seg[node].second == 0){
        if(seg[2*node+1].first < s){
            s -= seg[2*node+1].first;
            node = 2*node+2;    
        }
        else{
            node = 2*node+1; 
        }
    }

    int node_copy = node; 
    while(node_copy > 0){ 
        seg[node_copy].first--; 
        node_copy = (node_copy-1) / 2;      
    }
    seg[0].first--;
   
    return seg[node].second; 
}

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0); 
    
    int n{};  
    cin >> n; 
    
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    if(!(is_accepted(n, v))){
        cout << "NIE\n";
        return 0;  
    }
   
    set_base(n);
    init_build(n);
    
    stack<int> stck; 
    for(int i=n; i>0; i--){
        int ans = get_num(n - v[i-1]);
        stck.push(ans);     
        n--; 
    }

    while (!(stck.empty())){
        int ans = stck.top(); 
        stck.pop(); 
        cout << ans << '\n'; 
    }
    
    return 0; 
}