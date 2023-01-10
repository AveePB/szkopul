#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+7;
pair<int, int> ans[N];
int n{}, m{}, q{}, first=-1, last{}, total_sum{};
string s;

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> m >> s;
    for(int i=0; i<n; i++){
        if(s[i] == 'T'){
            total_sum += 2;
        }
        else{
            total_sum++;
            last = i;
            if(first == -1)
                first = i;
        }
    }
    
    for(int i=0; i<N; i++) ans[i] = {-1, -1};
    int ptr1 = 0, ptr2 = n-1, curr_sum = total_sum;

    while(curr_sum>0){
        ans[curr_sum] = {ptr1, ptr2};
        if(s[ptr1] == 'T') ptr1++;
        else if (s[ptr2] == 'T') ptr2--;
        else ptr1++, ptr2--;
        curr_sum -= 2;
    }

    if(first <= (n-1) - last){
        ptr1 = first+1;
        ptr2 = n-1;
        curr_sum = total_sum - (2*first)-1;
    }
    else{
        ptr1 = 0;
        ptr2 = last-1;
        curr_sum = total_sum - 2*((n-1) - last) - 1;
    }

    while(curr_sum>0){
        ans[curr_sum] = {ptr1, ptr2};
        if(s[ptr1] == 'T') ptr1++;
        else if (s[ptr2] == 'T') ptr2--;
        else ptr1++, ptr2--;
        curr_sum -= 2;
    }

    while (m--){
        cin >> q;
        if(ans[q].first != -1) 
            cout << ans[q].first+1 << ' ' << ans[q].second+1;
        else
            cout << "NIE";
        cout << '\n';
    }
    

    
    return 0;
}
