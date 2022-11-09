#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> lengths_of_pieces;
    int n_pieces = 0;
    cin >> n_pieces;

    for(int i=0; i<n_pieces; i++){
        int length_of_piece = 0;
        cin >> length_of_piece;
        lengths_of_pieces.push_back(length_of_piece);
    }

    sort(lengths_of_pieces.begin(), lengths_of_pieces.end());
    int max_range_size = 0;
    int head = 2;
    int tail = 0;

    while(head < n_pieces){
        if ((tail + 2) > head){
            head++;
            continue;
        }

        if ((lengths_of_pieces[tail] + lengths_of_pieces[tail+1]) > lengths_of_pieces[head]){
            max_range_size = max(max_range_size, (head - tail)+1);
            head++;
            continue;
        }

        tail++;
    }

    cout << max_range_size << endl;


    return 0;
}
