#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+7; 
vector<vector<int>> curr_pos(MAXN);
string ans{}, card[MAXN]{}; 
int n{}, pos[MAXN]{}; 

int count_letters(int letter, int idx, int max_counter){
    int counter{}, i=pos[idx];

    while(counter < max_counter && i < (card[idx].size())){
        if(letter == int(card[idx][i])){
            counter++;
            curr_pos[idx][counter] = i;
        }
        i++;
    }

    return counter; 
}

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n; 
    
    for(int i=0; i<n; i++){
        cin >> card[i];
        curr_pos[i].resize(int(card[i].size())+7);
    }
    
    for(int l=int('z'); l>=int('a'); l--){
        int min_apper{INT_MAX};

        for(int i=0; i<n; i++){
            int c = count_letters(l, i, min_apper); 
            min_apper = min(min_apper, c);     
        }

        if(min_apper == 0)
            continue; 
        
        for(int i=0; i<n; i++){
            pos[i] = curr_pos[i][min_apper]; 
            pos[i]++;
        }

        while (min_apper--)
            ans += char(l);
    }

    if(ans > "bitek")
        cout << ans;
    else 
        cout << "bitek"; 
    
    return 0;
}
