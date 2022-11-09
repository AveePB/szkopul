#include <bits/stdc++.h>


using namespace std;

const long long int MODULO_A = 1e9 + 7;
const long long int A = 59;

string is_cheated(string essay, long long int key_hash_A, long long int key_sentence_len){
    vector<long long int>sum_hash_A;
    vector<long long int>powers_A;

    powers_A.push_back(1);

    for(int i=1; i<essay.length(); i++){
        powers_A.push_back(powers_A[i-1] * A);
        powers_A[i] %= MODULO_A;
    }

    sum_hash_A.push_back( (long long int) essay[0]);

    for(int i=1; i<essay.length(); i++){
        sum_hash_A.push_back(sum_hash_A[i-1]);
        long long int change_A = (long long int)essay[i] * powers_A[i];
        change_A %= MODULO_A;

        sum_hash_A[i] += change_A;
        sum_hash_A[i] %= MODULO_A;

    }

    for(int start=1; start<=essay.length()-key_sentence_len; start++){
       int end_ = start + key_sentence_len - 1;
       int power_i = essay.length() - 1 - start;

       long long int subword_hash_a = sum_hash_A[end_] - sum_hash_A[start - 1];
       subword_hash_a += MODULO_A;
       subword_hash_a %= MODULO_A;

       long long int key_hash_A_now = key_hash_A;
       key_hash_A_now += MODULO_A;
       key_hash_A_now %= MODULO_A;
       key_hash_A_now *= powers_A[start];
       key_hash_A_now %= MODULO_A;

       if (subword_hash_a == key_hash_A_now)
           return "TAK";
    }

    return "NIE";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int key_hash_A = 0;
    int n = 0;

    string key_sentence = "";
    string essay = "";

    cin >> n;
    cin >> key_sentence;


    vector<long long int> powers_A;
    powers_A.push_back(1);

    for(int i=1; i<key_sentence.length(); i++){
        powers_A.push_back(powers_A[i-1] * A);
        powers_A[i] %= MODULO_A;
    }

    for(int i=0; i<key_sentence.length(); i++){
        long long int change_A = (long long int)key_sentence[i] * powers_A[i];
        change_A %= MODULO_A;
        key_hash_A += change_A;
        key_hash_A %= MODULO_A;
    }


    vector<string> answers;

    for(int i=0; i<n; i++){
        cin >> essay;
        essay = "#" + essay;
        answers.push_back(is_cheated(essay, key_hash_A, key_sentence.length()));
    }

    for (string answer: answers)
        cout << answer << endl;

    return 0;
}
