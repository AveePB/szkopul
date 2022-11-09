#include <iostream>
#include <vector>

using namespace std; 


void greatest_sum(vector<int>nums){
	int num_vector_size = nums.size();
	if (num_vector_size < 1)
		cout << 0 << endl;
	
	int curr_max = nums[0]; 
	int global_max = nums[0]; 

	for (int i = 1; i < num_vector_size; i++) {
		if (curr_max < 0) 
			curr_max = nums[i];
		else 
			curr_max += nums[i];

		if (global_max < curr_max)
			global_max = curr_max;
	}
	cout << global_max << endl;

}

int main()
{
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        cout.tie(NULL);

	vector<int>nums;
	int input_number = -1;
	while (true)
	{
		cin >> input_number;
		if (input_number == 0)
			break;
		nums.push_back(input_number);
		


	}
    greatest_sum(nums);
	
	return 0; 
}
