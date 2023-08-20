#include <unordered_set>

class Solution {
public:
int Solve(int n, int k, int idx, std::unordered_set<int>& used_nums){

	if (n == 0) {
		return 0;
	}

	int target = k - idx;

	if (used_nums.find(target) == used_nums.end()) {
		used_nums.insert(idx);
		return idx + Solve(n - 1, k, idx + 1, used_nums);
	}

	return Solve(n, k, idx + 1, used_nums);

}

int minimumSum(int n, int k) {
	
	std::unordered_set<int> used_nums;

	return Solve(n, k, 1, used_nums);
}
};
