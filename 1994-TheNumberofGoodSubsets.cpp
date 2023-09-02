class Solution {
public:
int Prime_Factors(int num) {

	int result = 0;

	if (num % 4 == 0) return -1;

	if (num % 2 == 0) {
		result |= (1 << 1);
		num /= 2;
	}

	for (int idx = 3; idx * idx <= num; idx += 2) {

		if (num % (idx * idx) == 0) return -1;

		if (num % idx == 0) {
			result |= (1 << (idx - 1));
			num /= idx;
		}
	}

	if (num != 1) result |= (1 << (num - 1));
	
	return result;
}

int Count_Good_Subsets(std::vector<int>& nums, int idx, int bitmask, std::unordered_map<int, int>& occurances) {

	if (idx >= nums.size()) {
		return (bitmask) ? 1 : 0;
	}
	

	int skip = Count_Good_Subsets(nums, idx + 1, bitmask, occurances);
	skip %= (int(1e9) + 7);

	long long take = (nums[idx] & bitmask) ? 0 : Count_Good_Subsets(nums, idx + 1, bitmask | nums[idx], occurances);

	take *= occurances[nums[idx]];
	take %= (int(1e9) + 7);

	return (skip + take) % (int(1e9) + 7);
}

int numberOfGoodSubsets(std::vector<int>& nums) {

	std::vector<int> factor_masks(nums.size());
	std::unordered_map<int, int> occurances;
	
	long long result = 0;

	for (int i = 0; i < nums.size(); i++) {
		factor_masks[i] = Prime_Factors(nums[i]);
		occurances[factor_masks[i]]++;
	}
	
	std::sort(factor_masks.rbegin(), factor_masks.rend());

	factor_masks.erase(std::unique(factor_masks.begin(), factor_masks.end()), factor_masks.end());
	
	while (!factor_masks.empty() && factor_masks.back() < 1) {
		factor_masks.pop_back();
	}

	if (factor_masks.empty()) return 0;

	result = Count_Good_Subsets(factor_masks, 0, 0, occurances);

	while (occurances[0] > 20) {
		result *= (1 << 20);
		result %= int(1e9) + 7;
		occurances[0] -= 20;
	}

	result *= (1 << occurances[0]);
	result %= int(1e9) + 7;
	
	return result;
}
};
