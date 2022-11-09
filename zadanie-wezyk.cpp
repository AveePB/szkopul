#include <iostream>

using namespace std; 

int main()
{
	int n = 0; 

	cin >> n; 

	for (int i = n; i <= n * n; i += n) {

		if ((i / n) % 2 == 0)
			for (int j = i; j > (i - n); j--)
				cout << " " << j;
		else 
			for (int j=i-n; j < i; j++)
				cout << " " << j+1;
		cout << endl;
		
	}
	
	return 0; 
}
