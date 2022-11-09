#include <iostream>

using namespace std; 

int main()
{
	long long a, b = 0;

	cin >> a >> b;



	long long n_5 = (b/5 - (a-1)/5); 
	long long n_3 = (b/3 - (a-1)/3);
	long long n_15 = (b/15 - (a-1)/15);
	

	cout << (n_5 + n_3 - n_15) << endl;

	return 0;
}
