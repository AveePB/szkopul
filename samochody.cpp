#include <bits/stdc++.h>
using namespace std; 

const int B = 3e5+7; 
vector<pair<int, int>> seg(4*B, pair<int, int>(0, 0));
vector<int> lazy(4*B, 0); 
int base{};

void set_base(int curr_n, int &curr_base){
    int x = ceil(log2((double) curr_n));
    curr_base = (int) pow(2, x);
    curr_base -= 1; //BECAUSE THE ROOT IS 0
}

void init_build(int n){
    for(int i=base-1; i>=0; i--){
        if(seg[2*i+1].first > seg[2*i+2].first)
            seg[i] = seg[2*i+1]; 
        else 
            seg[i] = seg[2*i+2]; 
    }
}

void update_inc(int s, int e, int curr_s, int curr_e, int node, int val){
    if(curr_s > curr_e|| curr_s > e || s > curr_e)
        return;

    if(lazy[node] != 0){
        seg[node].first += lazy[node];
        if(curr_s != curr_e){
            lazy[2*node+1] += lazy[node]; 
            lazy[2*node+2] += lazy[node]; 
        }
        lazy[node] = 0; 
    }

    if(s <= curr_s && curr_e <= e){
        seg[node].first += val; 
        if(curr_s != curr_e){
            lazy[2*node+1] += val; 
            lazy[2*node+2] += val; 
        }
        return; 
    }

    int mid = (curr_s+curr_e)/2;
    update_inc(s, e, curr_s, mid, 2*node+1, val); 
    update_inc(s, e, mid+1, curr_e, 2*node+2, val); 

    if(seg[2*node+1].first > seg[2*node+2].first)
        seg[node] = seg[2*node+1]; 
    else 
        seg[node] = seg[2*node+2]; 
}

pair<int, int> query_max(int s, int e, int curr_s, int curr_e, int node){
    if(curr_s > curr_e|| curr_s > e || s > curr_e)
        return {0, 0};

    if(lazy[node] != 0){
        seg[node].first += lazy[node];
        if(curr_s != curr_e){
            lazy[2*node+1] += lazy[node]; 
            lazy[2*node+2] += lazy[node]; 
        }
        lazy[node] = 0; 
    }

    if(s <= curr_s && curr_e <= e)
        return seg[node];
    
    int mid = (curr_s+curr_e)/2; 
    pair<int, int> p1 = query_max(s, e, curr_s, mid, 2*node+1);
    pair<int, int> p2 = query_max(s, e, mid+1, curr_e, 2*node+2); 

    if(p1.first > p2.first)
        return p1; 
    else 
        return p2;
}

// THE ROOT IS 0 SO, 
// 2*pos+1 <= left son 
// 2*pos+2 <= right son

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    //INPUT 
    int n{}, k{}; 
    cin >> n >> k;
    set_base(n, base);
    
    for(int i=0; i<n; i++){
        cin >> seg[base+i].first; 
        seg[base+i].second = i+1; 
    }

    init_build(n); 
    
    while(k--){
        int x{}, a{}, b{}; 
        cin >> x; 
        while (x--){
            int s{}, d{}; 
            cin >> s >> d; 
            update_inc(s-1, s-1, 0, base, 0, d); 
        }
        
        cin >> a >> b; 
        cout << query_max(a-1, b-1, 0, base, 0).second << '\n';
    }

    //0..N-1
    return 0; 
}
