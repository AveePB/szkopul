#include <iostream>
#include <vector>

using namespace std;

string reverse_str(string str) {
	string new_str = "";
	for (int i = str.size(); i > 0; i--)
		new_str += str[i - 1];
	return new_str;
}


void moving(string n1, string n2) {
	vector <int> n_per_n; 
	int n_iters = 0;
	int n_moves = 0;

	n1 = reverse_str(n1);
	n2 = reverse_str(n2);

	if (n1.length() >= n2.length())
		n_iters = n1.length();
	else
		n_iters = n2.length();

	for (int i = 0; i < n_iters; i++) {
		n_per_n.push_back(0);
		n_per_n.push_back(0);

		int n_1 = 0;
		int n_2 = 0;
		
		if (i < n1.length())  
			n_1 = n1[i] - '0';
		if (i < n2.length())
			n_2 = n2[i] - '0';
		
		int sum_of_ns = n_1 + n_2 + n_per_n[i];
		int n_10s = (sum_of_ns / 10);

		if (n_10s > 0){
			n_moves++;
			n_per_n[i + 1] += n_10s;
			n_per_n[i] = sum_of_ns - n_10s * 10;
		}
	}
	cout << n_moves << endl;
}



int main()
{
	int n_tests = 0; 
	vector<vector<string>>tests;

	cin >> n_tests;
	for (int i = 0; i < n_tests; i++) {
		vector<string>ns;
		string n1, n2 = "";

		cin >> n1 >> n2;
		ns.push_back(n1);
		ns.push_back(n2);

		tests.push_back(ns);
	}

	for (int i = 0; i < tests.size(); i++) {
		moving(tests[i][0], tests[i][1]);
	}

	return 0;
}
