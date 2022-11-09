#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

//false -> red
//true -> black

bool colors[100005];
bool visited[100005];

vector<vector<int>> conns(100005, vector<int>(0));

void dfs(bool previous_color, int point_id){
    visited[point_id] = true;
    colors[point_id] = not(previous_color);

    for(auto n: conns[point_id])
        if (not(visited[n])){
            dfs(colors[point_id], n);
        }
        else{
            if (colors[n] == colors[point_id]){
                cout << "NIE" << endl;
                exit(0);
            }
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k = 0;

    cin >> n >> k;


    for(int i=0; i<k; i++){
        int p1, p2 = 0;
        cin >> p1 >> p2;
        conns[p1].push_back(p2);
    }

    dfs(false, 0);

    cout << "TAK" << endl;

    return 0;
}
