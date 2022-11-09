#include <bits/stdc++.h>

using namespace std;

const long long FAKE_INF =  922337203685477000;

vector<vector<pair<long long, long long>>> tunels;
vector<long long> costs;

int n_caves, n_tunels = 0;
//n_caves is the dragon's cave number !!!

void dijkstra(pair<long long, long long> start_point){
    queue<pair<long long, long long>> tunels_to_check;
    tunels_to_check.push(start_point);
    costs[start_point.first] = 0;

    while (!tunels_to_check.empty()){
        pair<long long, long long> current_tunel;
        current_tunel = tunels_to_check.front();
        tunels_to_check.pop();

        for(pair<long long, long long> tunel: tunels[current_tunel.first]){
            long long cost = tunel.second + costs[current_tunel.first];

            if (cost < costs[tunel.first]){
                costs[tunel.first] = cost;
                tunels_to_check.push(tunel);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n_caves >> n_tunels;

    tunels.resize(n_tunels+1);
    costs.resize(n_tunels+1, FAKE_INF);

    for(int i=0; i<n_tunels; i++){
        long long loc_a, loc_b, cost = 0;
        cin >> loc_a >> loc_b >> cost;

        tunels[loc_a].push_back({loc_b, cost});
    }

    dijkstra({1, 0});

    if (costs[n_caves] == FAKE_INF)
        cout << -1 << endl;
    else
        cout << ((costs[n_caves] != 0)? costs[n_caves] : 199999000000000) << endl;


    return 0;
}
