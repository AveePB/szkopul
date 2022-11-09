#include <bits/stdc++.h>

using namespace std;


vector<pair<double, double>> tree_elements; 
int target_level{}; 

void next_element(pair<double, double> l_border_val, pair<double, double> middle_val, pair<double, double> r_border_val, int level){
    pair<double, double> new_middle_val; 
    
    if(level > target_level)
        return;


    new_middle_val = {
        l_border_val.first+middle_val.first, 
        l_border_val.second + middle_val.second
    }; 
    
    next_element(l_border_val, new_middle_val, middle_val, level+1); 
    
    cout << middle_val.first << "/" << middle_val.second << " "; 
    
    new_middle_val = {
        middle_val.first+r_border_val.first, 
        middle_val.second+r_border_val.second
    };

    next_element(middle_val, new_middle_val, r_border_val, level+1); 
}

int main()
{
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> target_level; 
    
    cout << "0/1 "; 
    next_element({0, 1}, {1, 1}, {1, 0}, 1);
    cout << "1/0";

    return 0;
}