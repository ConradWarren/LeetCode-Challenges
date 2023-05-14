class Solution {
public:
int sumOfPower(std::vector<int>& nums) {

	std::sort(nums.begin(), nums.end());

	long long mod = 1000000007;
	long long sum = 0;
	long long temp_num = 0;
	long long base = 0;
	long long last_base = 0;
	std::vector<long long> square_nums(nums.size());
	
	for (int i = 0; i < nums.size(); i++) {
		temp_num = nums[i];
		square_nums[i] = temp_num * temp_num;
		square_nums[i] %= mod;
	}
	
	for (int i = 0; i < nums.size(); i++) {
		
		if (i > 1) {
			temp_num = nums[i - 2];
			last_base *= 2;
			last_base %= mod;
			last_base += temp_num;
			last_base %= mod;
		}

		temp_num = nums[i];
		base += temp_num;
		base += last_base;
		base %= mod;

		temp_num = base * square_nums[i];
		temp_num %= mod;

		sum += temp_num;
		sum %= mod;

	}


	return int(sum);
}
};
