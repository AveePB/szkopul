#include <iostream>
#include <vector>


using namespace std;

const int MAX_N = 1007;
int n_cols, n_rows = 0;

pair<int, int> exit_position = {0, 0};
pair<int, int> mouse_position = {0, 0};

vector<vector<bool>> visited(MAX_N, vector<bool>(0));
vector<vector<char>>maze(MAX_N, vector<char>(0));


vector<pair<int, int>> moves = {
    {-1, 0}, //up
    {+1, 0}, //down
    {0, -1}, //left
    {0, +1}, //right
};

void bfs(pair<int, int> cur_pos){

    visited[cur_pos.first][cur_pos.second] = true;
    //position(row_i, col_i)

    for(int i=0; i<moves.size(); i++){
        pair<int, int> mod_pos = {
            cur_pos.first + moves[i].first,
            cur_pos.second + moves[i].second
        };

        if (mod_pos.first >= n_rows || mod_pos.second >= n_cols)
            continue;

        if (mod_pos.first < 0 || mod_pos.second < 0)
            continue;

        if (maze[mod_pos.first][mod_pos.second] == 'x')
            continue;

        if (visited[mod_pos.first][mod_pos.second])
            continue;

        if (maze[mod_pos.first][mod_pos.second] == 'o'){
            cout << "TAK" << endl;
            exit(0);
        }

            bfs(mod_pos);
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n_cols >> n_rows;

    for(int i=0; i<n_rows; i++){
        visited[i].resize(n_cols);
        maze[i].resize(n_cols);

        for(int j=0; j<n_cols; j++){
            cin >> maze[i][j];
            if (maze[i][j] == 'w')
                exit_position = {i, j};
        }
    }

    bfs(exit_position);
    cout << "NIE" << endl;

    return 0;
}
