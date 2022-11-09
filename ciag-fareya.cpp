#include <iostream>
#include <cmath>

using namespace std;

void farey_sequence(int n){
    double a=0, b=1, c=1, d=n;
    double p, q;

    cout << "0/1 1/" << n;

    while (q != 1){

        p = floor((n + b) / d) * c - a;
        q = floor((n + b) / d) * d - b;

        cout << ' '  << p << '/' << q;

        a = c;
        b = d;
        c = p;
        d = q;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0;
    cin >> n;

    farey_sequence(n);

    return 0;
}
