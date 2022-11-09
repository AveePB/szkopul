#include <iostream>
#include <cmath>
#include <map>

using namespace std;

const long long int M = 1e9+7;
const long long int P = 59;

long long int create_hash(string word){
    long long int the_hash = 0;
    long long int powers[2007];
    powers[0] = 1;

    for(int i=1; i < 2007; i++){
        powers[i] = powers[i-1] * 59;
        powers[i] %= M;
    }

    for(int i=0; i<word.length(); i++){
        long long int change = (long long int)word[i] * powers[i];
        change %= M;

        the_hash += change;
        the_hash %= M;
    }
    return the_hash;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<long double, int> pairs;
    int n = 0;

    cin >> n;

    for (int i=0; i<n; i++){
        string tank_name = "";
        cin >> tank_name;

        long long int tank_hash = create_hash(tank_name);

        if (pairs.find(tank_hash) != pairs.end())
           pairs[tank_hash] += 1;
        else
            pairs[tank_hash] = 1;
    }

    int n_pairs = 0;
    for (const auto &item: pairs)
    {
        int n_names = item.second;
        int r = 1;

        for (int i=n_names; i>(n_names-2); i--)
            r *= i;

        r /= 2;
        n_pairs += r;
    }

    cout << n_pairs << endl;

    return 0;
}
