#include <bits/stdc++.h>
using namespace std; 

const int B = 1e5+7; 
vector<int> seg(3*B, 0), lazy(3*B, 0); 
int base{};

void set_base(int curr_n, int &curr_base){
    int x = ceil(log2((double) curr_n));
    curr_base = (int) pow(2, x);
    curr_base -= 1; //BECAUSE THE ROOT IS 0
}

void update_inc(int s, int e, int curr_s, int curr_e, int node, int val){
    if(curr_s > curr_e)
        return; 

    if(lazy[node] != 0){
        seg[node] += lazy[node]; 
        if(curr_s != curr_e){
            lazy[2*node+1] += lazy[node]; 
            lazy[2*node+2] += lazy[node]; 
        }
        lazy[node] = 0;
    }
    if(s > curr_e || curr_s > e)
        return; 

    if(s <= curr_s && curr_e <= e){
        seg[node] += val; 
        if(curr_s != curr_e){
            lazy[2*node+1] += val; 
            lazy[2*node+2] += val; 
        }
        return; 
    }

    int mid = (curr_s+curr_e)/2; 
    update_inc(s, e, curr_s, mid, 2*node+1, val); 
    update_inc(s, e, mid+1, curr_e, 2*node+2, val); 

    seg[node] = max(seg[2*node+1], seg[2*node+2]); 
}

int query_max(int s, int e, int curr_s, int curr_e, int node){
    if(curr_s > curr_e)
        return 0;

    if(lazy[node] != 0){
        seg[node] += lazy[node]; 
        if(curr_s != curr_e){
            lazy[2*node+1] += lazy[node]; 
            lazy[2*node+2] += lazy[node];   
        }
        lazy[node] = 0; 
    }

    if(s > curr_e || curr_s > e)
        return 0; 

    if(s <= curr_s && curr_e <= e)
        return seg[node]; 

    int mid = (curr_s+curr_e)/2;

    return max(
        query_max(s, e, curr_s, mid, 2*node+1), 
        query_max(s, e, mid+1, curr_e, 2*node+2)); 
}

bool is_accepted(int s, int e, int req_seats, int seats){
    if(query_max(s, e, 0, base, 0)+req_seats > seats)
        return false; 

    update_inc(s, e, 0, base, 0, req_seats); 
    return true; 
}

// THE ROOT IS 0 SO, 
// 2*pos+1 <= left son 
// 2*pos+2 <= right son

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    //INPUT 
    int n{}, m{}, z{}; 
    cin >> n >> m >> z;

    set_base(n, base);

    for(int i=0; i<z; i++){
        int p{}, k{}, l{};
        cin >> p >> k >> l; 

        if(is_accepted(p-1, k-2, l, m))
            cout << 'T' << '\n'; 
        else 
            cout << 'N' << '\n';  
    }
    
    //0..N-1
    return 0; 
}
