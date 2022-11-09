#include<bits/stdc++.h>

using namespace std;

const long long FAKE_INF = 1000000000;

vector<vector<pair<long long, long long>>> graph1; //stores available processes before the tax
vector<vector<pair<long long, long long>>> graph2; //stores available processes after the tax

vector<long long> metal_prices;

vector<long long> costs1; //stores costs of the process before the tax
vector<long long> costs2; //stores costs of the process after the tax

//output = costs1[i] + costs2[i] + metal_prices[i]/2

void dijkstra_1(pair<long long, long long> start_metal){
    queue<pair<long long, long long>> q;
    q.push(start_metal);
    costs1[start_metal.first] = 0; //WE SET METAL START COST FOR 0

    while (!q.empty()){
        pair<long long, long long> current_metal = q.front(); //GET METAL AND REMOVE IT
        q.pop();

        for(pair<long long, long long> metal: graph1[current_metal.first]){
            if (metal.second + costs1[current_metal.first] < costs1[metal.first]){ //IF COSTS ARE LESS THEN UPDATE
                costs1[metal.first] = metal.second + costs1[current_metal.first];
                q.push(metal); //EXPLORE GRAPH
            }
        }
    }
}

void dijkstra_2(pair<long long, long long> start_metal){
    queue<pair<long long, long long>> q;
    q.push(start_metal);
    costs2[start_metal.first] = 0; //WE SET METAL START COST FOR 0

    while (!q.empty()){
        pair<long long,  long long> current_metal = q.front(); //GET METAL AND REMOVE IT
        q.pop();

        for(pair<long long, long long> metal: graph2[current_metal.first]){ //IF COSTS ARE LESS THEN UPDATE
            if (metal.second + costs2[current_metal.first] < costs2[metal.first]){
                costs2[metal.first] = metal.second + costs2[current_metal.first];
                q.push(metal); //EXPLORE GRAPH
            }
        }
    }

}

// pair<product_metal, price>

int main()
{
    int n_metals, n_processes = 0;
    cin >> n_metals;

    //RESIZING FOR CLEANER CODE
    metal_prices.resize(n_metals+1, 0);
    graph1.resize(n_metals+1);
    graph2.resize(n_metals+1);

    costs1.resize(n_metals+1, FAKE_INF);
    costs2.resize(n_metals+1, FAKE_INF);

    //READING METAL PRICES
    for(int i=1; i<=n_metals; i++)
        cin >> metal_prices[i];

    cin >> n_processes;

    //READING AVAILABLE CHEMICAL PROCESSES
    for(int i=0; i<n_processes; i++){
        long long a, b, c = 0;
        cin >> a; //source metal
        cin >> b; //product metal
        cin >> c; //price

        graph1[a].push_back({b, c});
        graph2[b].push_back({a, c});
    }

    //TWO DIJKSTRAS (TWO FOR BETTER VIEW AND UNDERSTANDING)
    dijkstra_1({1, 0});
    dijkstra_2({1, 0});

    long long output = 2*FAKE_INF; //WE MAKE SURE THAT OUTPUT HAS THE LARGEST VAL

    for(int i=2; i<=n_metals; i++){
        long long summary_cost = costs1[i] + costs2[i] + metal_prices[i]/2; //COMPUTING SUMMARY COST
        if (summary_cost < output)
            output = summary_cost;
    }

    if (output > 1000000000)
        cout << 50000000 << endl;
    else
        cout << output << endl;

    return 0;
}
