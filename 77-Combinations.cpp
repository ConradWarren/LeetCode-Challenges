#include <vector>

class Solution {
public:
void Solve(int n, int k, int last_valid, std::vector<int>& current, std::vector<std::vector<int>>& result) {

	if (current.size() == k) {
		result.push_back(current);
		return;
	}

	for (int i = last_valid + 1; i <= n; i++) {
		current.push_back(i);
		Solve(n, k, i, current, result);
		current.pop_back();
	}

	return;
}
std::vector<std::vector<int>> combine(int n, int k) {
	
	std::vector<std::vector<int>> result;
	std::vector<int> current;

	Solve(n, k, 0, current, result);

	return result;
}
};
