#include <iostream>
#include <string>

using namespace std; 

string to_quinary(long long n) {
    long long divided_n = n; 
    string quinary_n = "";
    string correct_quinary_n = "";

    while (divided_n != 0) {
        quinary_n += to_string((divided_n%5)*2);
        divided_n /= 5; 
    }
     
    for (long long i = quinary_n.length()-1; i >= 0; i--)
        correct_quinary_n += quinary_n[i]; 
    
    return correct_quinary_n;
}

int main()
{
    long long n = 0; 
    
    cin >> n;
    cout << to_quinary(n) << endl;
     
    return 0; 
}
