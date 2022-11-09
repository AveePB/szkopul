#include <bits/stdc++.h>

using namespace std; 

vector<int> answers; 
vector<int> ts; 
map<int, int> t_idx; 
int n_ts{}, n_cars;  

void test(){
    int c{}; 
    cin >> c; 

    for(int t: ts){
        if(c >= t){
            answers.push_back(t_idx[t]); 
            return;
        }
    }
    answers.push_back(n_ts); 
}

int main(){
    cin >> n_ts >> n_cars; 
    
    for(int i=0; i<n_ts; i++){
        int t{}; 
        cin >> t;

        if(t_idx.find(t) != t_idx.end())
            continue; 

        ts.push_back(t); 
        t_idx[t] = i;  
    }
    
    for(int i=0; i<n_cars; i++)
        test();
    
    for(int a: answers)
        cout << a << " "; 

    return 0; 
}