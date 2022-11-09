#include <iostream>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

bool is_prime(int n){
    if (n == 1)
        return false;
    else if (n == 2)
        return true;

    for (int i=2; i<=sqrt(n); i++){
        if (n%i == 0)
            return false;
    }
    return true;
}


bool is_sum_prime(string n_str) {
    int sum_of_n = 0;
    for (char n_char: n_str){
        sum_of_n += n_char - '0';
    }
    return is_prime(sum_of_n);
}


bool is_binary_sum_prime(int n){
    bitset<20> n_binary(n);
    return is_sum_prime(n_binary.to_string());
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n_super_b = 0;
    int a, b = 0;
    cin >> a >> b;

    for (int i=a; i<=b; i++){
        if (is_prime(i))
            if (is_sum_prime(to_string(i)))
                if (is_binary_sum_prime(i))
                    n_super_b++;
    }
    cout << n_super_b << endl;

    return 0;
}
