#include <bits/stdc++.h>

using namespace std;

int n_stairs{}; 
int n_combinations{}; 
vector<string> answers; 

void next_one(int sum, string digits){
    if (sum == n_stairs){
        answers.push_back(digits);
        n_combinations++;  
        return; 
    }
    else if (sum > n_stairs){
        return; 
    }

    for(int i=1; i<3; i++){
        next_one(sum+i, digits+to_string(i)+" "); 
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0); 
    cin.tie(0); 

    cin >> n_stairs; 
    next_one(0, ""); 
    cout << n_combinations << endl;
    
    for(string answer: answers)
        cout << answer << endl;  
    
    return 0;
}