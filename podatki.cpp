#include <iostream>
#include <cmath>

using namespace std;


int get_tax(int fee){
    if (fee == 2){
        return 1;
    }

    int blockpoint = ceil(sqrt(fee));

    for (int d=2; d<blockpoint; d++){
        if (fee % d == 0){
               if (d > 10)
                    return 3;
               if (d > 2)
                    return d-1;
               return d;
        }
    }
    return 1;
}


int main()
{
        int n;
        cin >> n;
        cout << get_tax(n) << endl;
    return 0;
}
