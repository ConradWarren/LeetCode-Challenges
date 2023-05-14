#include <vector>
#include <unordered_map>

class Solution {
public:

int GCD(int x, int y) {

	if (y == 0) {
		return x;
	}
	return GCD(y, x % y);
}

int Solve_Max(std::vector<std::vector<int>>& gcd_pairs, int used_nums, int n, std::unordered_map<int, int>& cache) {

	if (!n) return 0;
	
	if (cache.find(used_nums) != cache.end()) return cache[used_nums];
	
	int best_score = 0;
	int score = 0;
	for (int i = 0; i < gcd_pairs.size(); i++) {

		if (used_nums & (1 << i)) continue;
		
		used_nums |= (1 << i);

		for (int j = i + 1; j < gcd_pairs.size(); j++) {

			if (used_nums & (1 << j)) continue;
			
			used_nums |= (1 << j);

			score = (n * gcd_pairs[i][j]) + Solve_Max(gcd_pairs, used_nums, n - 1, cache);

			best_score = (best_score > score) ? best_score : score;

			used_nums ^= (1 << j);
		}
		used_nums ^= (1 << i);
	}

	cache[used_nums] = best_score;

	return best_score;
}



int maxScore(std::vector<int>& nums) {

	int n = nums.size() / 2;
	int used_nums = 0;
	std::vector<std::vector<int>> gcd_pairs(nums.size(), std::vector<int>(nums.size(), 0));
	std::unordered_map<int, int> cache;

	for (int i = 0; i < nums.size(); i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			gcd_pairs[i][j] = GCD(nums[i], nums[j]);
		}
	}
	
	return Solve_Max(gcd_pairs, used_nums, n, cache);
}
};
