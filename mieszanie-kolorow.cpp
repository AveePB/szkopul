#include<bits/stdc++.h>
using namespace std;

const int VALID = 0b110; //6 -> 110 (binary)
const int MAXN = 1e6+7;
int n{}, m{}, ans{}, base{}; 
int lazy[3*MAXN]{}, seg[3*MAXN]{};

void set_base(){
    base = 1;
    while (base < n)
        base *= 2;
}

void update_set(int l, int r, int curr_l, int curr_r, int node, int c){
    if(l > curr_r || curr_l > r)
        return;

    if(lazy[node] != 0){
        seg[node] = (seg[node] | lazy[node]);
        if(curr_l != curr_r){
            lazy[2*node] = (lazy[2*node] | lazy[node]); 
            lazy[2*node+1] = (lazy[2*node+1] | lazy[node]); 
        }
        lazy[node] = 0;
    }

    if(l <= curr_l && curr_r <= r){
        seg[node] = (seg[node] | (1<<c)); 
        if(curr_l != curr_r){
            lazy[2*node] = (lazy[2*node] | (1<<c)); 
            lazy[2*node+1] = (lazy[2*node+1] | (1<<c)); 
        }
        return; 
    }

    int mid = (curr_l+curr_r)/2;
    update_set(l, r, curr_l, mid, 2*node, c); 
    update_set(l, r, mid+1, curr_r, 2*node+1, c); 
    
    int bit_3 = (((1<<3)&(seg[2*node])) | ((1<<3)&(seg[2*node+1])));
    int bit_1_2 = (seg[2*node] & seg[2*node+1]); 
    seg[node] = (bit_1_2 | bit_3); 
}

int query_count(int l, int r, int curr_l, int curr_r, int node){
    if(l > curr_r || curr_l > r)
        return 0;

    if(lazy[node] != 0){
        seg[node] = (seg[node] | lazy[node]);
        if(curr_l != curr_r){
            lazy[2*node] = (lazy[2*node] | lazy[node]); 
            lazy[2*node+1] = (lazy[2*node+1] | lazy[node]); 
        }
        lazy[node] = 0;
    }

    if(l <= curr_l && curr_r <= r){
            if(seg[node] == VALID)
                return curr_r-curr_l+1;
            if(curr_l == curr_r)
                return 0; 
    }

    int mid = (curr_l+curr_r)/2; 
    int a1 = query_count(l, r, curr_l, mid, 2*node); 
    int a2 = query_count(l, r, mid+1, curr_r, 2*node+1); 
    return a1+a2;
}


int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> m;
    set_base();

    while (m--){
        int l{}, r{}, k;
        cin >> l >> r >> k;
        l--, r--;
        update_set(l, r, 0, base-1, 1, k);  
    }

    ans = query_count(0, n-1, 0, base-1, 1);
    cout << ans;  

   return 0;
}
