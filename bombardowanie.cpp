#include <bits/stdc++.h>

using namespace std; 

struct pt {
    long long x{}, y{};
};

const int MAXN = 1e5 + 7;
int n{}, m{}, ans{};
pt border[MAXN];

long long compute_field(pt A, pt B, pt C);
long long cross_product(pt A, pt B, pt C); 
bool is_danger(long long x, long long y);

int main()
{
    ios_base::sync_with_stdio(0); 
    cout.tie(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        cin >> border[i].x >> border[i].y;
    
    for (int i = 0; i < m; i++) {
        int x{}, y{};
        cin >> x >> y;
        ans += is_danger(x, y); 
    }
    cout << ans << endl; 

    return 0; 
}

long long compute_field(pt A, pt B, pt C) {  
    return abs(cross_product(A, B, C)); 
}

long long cross_product(pt A, pt B, pt C){
	return (B.x - A.x)*(C.y - A.y) - (C.x - A.x)*(B.y - A.y); 
}

bool is_danger(long long x, long long y) {
    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (cross_product(border[0], border[mid], {x, y}) < 0) 
            r = mid;
        else 
            l = mid; 
    }

    long long total_field = compute_field(border[0], border[l], border[r]); 

    long long sub_fields = compute_field({x, y}, border[l], border[0]);
    sub_fields += compute_field({x, y}, border[r], border[0]);
    sub_fields += compute_field({x, y}, border[r], border[l]); 
        
    return (total_field == sub_fields); 
}