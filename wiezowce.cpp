#include<bits/stdc++.h>
using namespace std;

struct skyscraper{
    int idx{}, height{}; 
}; 

struct request{
    int idx{}, l{}, r{}, limit{}; 
}; 

const int MAXN = 1e6+7;
skyscraper skyscrapers[MAXN]; 
request requests[MAXN];

int seg[4*MAXN], output[MAXN]; 
int n{}, q{}, base{};

void set_base(int& x){
    base = 1;
    while(base < x) 
        base *= 2;
}

void update_inc(int pos, int val){
    int node = base+pos; 
    while (node){
        seg[node] += val; 
        node /= 2; 
    }
}

int query_sum(int s, int e){
    int res{};
    s = s - 1 + base; 
    e = e + 1 + base;

    while(s/2 != e/2){
        if(s%2 == 0) 
            res += seg[s+1]; 
        if(e%2 == 1) 
            res += seg[e-1]; 
        s /= 2; 
        e /= 2; 
    }
    return res; 
}

bool skyscraper_comp(skyscraper s1, skyscraper s2){
    return s1.height < s2.height;  
}

bool request_comp(request r1, request r2){
    return r1.limit < r2.limit; 
}

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0); 
    
    //INPUT BASE
    cin >> n >> q; 
    set_base(n);
    
    //WE SET AND SORT SKYSCRAPERS
    for(int i=0; i<n; i++){
        skyscrapers[i].idx = i;
        cin >> skyscrapers[i].height; 
    }
    sort(skyscrapers, skyscrapers+n, skyscraper_comp);

    //WE SET AND SORT REQUESTS 
    for(int i=0; i<q; i++){
       cin >> requests[i].l >> requests[i].r >> requests[i].limit; 
       requests[i].idx = i;
       requests[i].l--; 
       requests[i].r--; 
    } 
    sort(requests, requests+q, request_comp);
    skyscrapers[n].height = INT_MAX;
    
    int curr_idx{};     
    for(int i=0; i<q; i++){
            while(skyscrapers[curr_idx].height <= requests[i].limit){
                update_inc(skyscrapers[curr_idx].idx, 1); 
                curr_idx++;
            }
        output[requests[i].idx] = query_sum(requests[i].l, requests[i].r);
    }

    for(int i=0; i<q; i++)
        cout << output[i] << '\n';  
    
    return 0; 
}
