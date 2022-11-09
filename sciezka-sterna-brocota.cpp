#include <iostream>
#include <algorithm>

using namespace std;

string l_or_p(double a, double b, double c, double d, double m, double n){
    double a_c = a+c;
    double b_d = b+d;

    if ((m / n) > (a_c / b_d)){
        a = a_c;
        b = b_d;
        return l_or_p(a, b, c, d, m, n) + "P";
    }
    else if ((m / n) < (a_c / b_d)){
        c = a_c;
        d = b_d;
        return l_or_p(a, b, c, d, m, n) + "L";
    }
    else{
        return "";
    }
}


void task(double m, double n){
    double a = 0;
    double b = 1;

    double c = 1;
    double d = 0;

    string s = l_or_p(a, b, c, d, m, n);
    reverse(s.begin(), s.end());
    cout << s << endl;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;
    task(m, n);

    return 0;
}
