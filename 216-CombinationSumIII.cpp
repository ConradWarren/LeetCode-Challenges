#include <vector>

class Solution {
public:
void Combination_Builder(int target, int k,int idx, std::vector<int>& current_arr, std::vector<std::vector<int>>& result) {

	if (k == 0) {
		if (target == 0) result.push_back(current_arr);
		return;
	}
	if (target < 0 || idx >= 10) return;
	
	Combination_Builder(target, k, idx + 1, current_arr, result);

	current_arr.push_back(idx);
	Combination_Builder(target - idx, k-1, idx + 1, current_arr, result);
	current_arr.pop_back();
}

std::vector<std::vector<int>> combinationSum3(int k, int n) {

	std::vector<int> current_arr;
	std::vector<std::vector<int>> result;

	Combination_Builder(n, k, 1, current_arr, result);

	return result;
}
};
