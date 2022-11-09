#include <iostream>
#include <vector>

using namespace std; 

bool is_in(vector<long long> nums, long long n) {
	for (long long num : nums) {
		if (num == n)
			return true;
	}
	return false;
}

int main()
{	
	long long n = 0; 
	cin >> n; 
	
	vector<long long>nds; 

	for (long long i = 1; (i * i) <= n; i++) {
		if (n % i == 0) {
			cout << i << endl;
			nds.push_back(i);
		}
			
	}
	
	for (int i = nds.size()-1; i >= 0 ; i--) {
		long long p_nd = (n / nds[i]);

		if (!is_in(nds, p_nd))
			cout << p_nd << endl;
	}

	return 0; 
}
