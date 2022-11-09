#include <iostream>
#include <vector>

using namespace std; 

long long calculations(pair<long long, long long > a, pair<long long, long long> b, pair<long long, long long > c ) {
    long long xa = (a.first - c.first); 
    long long xb = (b.first - c.first); 
    long long ya = (a.second - c.second); 
    long long yb = (b.second - c.second); 
    
    return (xa) * (yb) - (xb) * (ya);
}


int main()
{   
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    vector<pair<long long, long long>> points;
    long long n, x1, y1; 
    bool b = true; 

    cin >> n; 
    cin >> x1 >> y1; 

    points.push_back({ x1, y1 }); 

    for (int i = 0; i < n-1; i++) {
        long long x, y; 
        cin >> x >> y;
        
        if (x1 != x || y1 != y) {
            points.push_back({ x, y }); 
            x1 = x; 
            y1 = y;
        }
    }
    n = points.size(); 
    pair<long long, long long> p1, p2, p3; 

    p1 = points[0]; 
    p2 = points[1]; 

    for (int i = 2; i < n; i++) {
        p3 = points[i]; 

        if (calculations(p1, p2, p3) != 0) {
            cout << "NIE" << endl; 
            b = false; 
            break; 
        }
    }

    if (b)
        cout << "TAK" << endl;

    return 0;
}
