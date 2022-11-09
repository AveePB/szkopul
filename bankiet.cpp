#include <iostream>
#include <vector>

using namespace std; 

int main()
{
	int n_guests = 0;
	int n_tables = 0;
	int current_i = 0;
	int potential_i = 0;
	vector <int> guest_nums; 

	guest_nums.push_back(0); 
	cin >> n_guests;

	for (int i = 0; i < n_guests; i++) {
		int guest_n = 0;
		cin >> guest_n;
		guest_nums.push_back(guest_n);
	}
	
	for (int i = 1; i <= n_guests; i++) {
		
		int current_i = i; 
		int potential_i = i; 

		if (guest_nums[potential_i] != 0) 
			while (true)
			{

				if (guest_nums[potential_i] == current_i) {
					guest_nums[potential_i] = 0; 
					n_tables++;
					break; 
				}
				int j = guest_nums[potential_i]; 
				guest_nums[potential_i] = 0; 
				potential_i = j; 
			}
	}
	cout << n_tables << endl;



	return 0;
}
