#include <bits/stdc++.h>

using namespace std; 

struct point{
    long long x, y; 
};

vector<point>north; 
vector<point>south; 

int n_points{}; 

long long vector_calcs(const point& a, const point& b){
	return a.x*b.y - a.y*b.x;
}

bool operator < (const point& p1, const point& p2){
    long long d1 = p1.x * p1.x + p1.y * p1.y; 
    long long d2 = p2.x * p2.x + p2.y * p2.y; 
    
    return ((vector_calcs(p1, p2) < 0) or (vector_calcs(p1, p2) == 0 and d1 < d2));  
}

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n_points; 

    for(int i=0; i<n_points; i++){
        long long x{}, y{}; 
        cin >> x >> y; 

        if (y > 0 or (y == 0 and x < 0))
            north.push_back({x, y});
        else
            south.push_back({x, y});     
    }
    sort(north.begin(), north.end());
    sort(south.begin(), south.end());
    
    
    for(point s_point: south)
        cout << s_point.x << " " << s_point.y << endl; 

    for(point n_point: north)
        cout << n_point.x << " " << n_point.y << endl; 

    return 0; 
}
