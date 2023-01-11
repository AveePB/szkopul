#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
string ans = "";
char c[N]{};
int n{}, curr_i=1;


int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<n; i++)
        cin >> c[i];

    while(curr_i < n){
        if(c[curr_i] == '+'){
            int curr_j = curr_i;
            while (c[curr_j] == '+')
                curr_j++;
            
            ans += "(";
            for(int i=curr_i; i<curr_j; i++)
                ans += '-';
            ans += ')';

            curr_i = curr_j;
            continue;
        }

        ans += '-';
        curr_i++;
    }
    cout << '(' << ans << ')';


    return 0;
}
