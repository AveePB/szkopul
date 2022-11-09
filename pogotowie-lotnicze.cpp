#include <bits/stdc++.h>

using namespace std;

vector <long long int> sum_pref;
int n_cities = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n_cities;
    sum_pref.push_back(0);

    for(int i=0; i<n_cities-1; i++){
        long long int distance;
        cin >> distance;

        sum_pref.push_back(distance + sum_pref[i]);
    }

    vector<int> best_locs;
    long long int global_smallest_difference = 9223372036854775807;


    for(int i=1; i<sum_pref.size()-1; i++){
        long long int left_side = sum_pref[i] - sum_pref[0];
        long long int right_side = sum_pref[sum_pref.size()-1] - sum_pref[i];

        long long int current_difference = abs(left_side - right_side);

        if (current_difference < global_smallest_difference){
            best_locs.clear();
            best_locs.push_back(i+1);

            global_smallest_difference = current_difference;
        }
        else if(current_difference == global_smallest_difference){
            best_locs.push_back(i+1);
        }
    }

    sort(best_locs.begin(), best_locs.end());

    for(int loc: best_locs){
        cout << loc << " ";
    }

    return 0;
}
