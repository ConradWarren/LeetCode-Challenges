#include <vector>
#include <unordered_map>

class Solution {
public:
bool Solve_Can_Cross(std::unordered_map<int, int>& stones, int k, int current_stone, int target, std::vector<std::vector<bool>>& cache) {

	if (stones.find(current_stone) == stones.end()) return false;
	
	if (current_stone == target) return true;
	
	if (!cache[stones[current_stone]][k]) return false;
	
	if (k == 0) return Solve_Can_Cross(stones, 1, current_stone + 1, target, cache);
	
	if (k == 1) {
		if (Solve_Can_Cross(stones, 1, current_stone + 1, target, cache)) return true;
		
		if (Solve_Can_Cross(stones, 2, current_stone + 2, target, cache)) return true;
		
		return false;
	}

	if (Solve_Can_Cross(stones, k + 1, current_stone + k + 1, target, cache)) return true;
	
	if (Solve_Can_Cross(stones, k, current_stone + k, target, cache)) return true;
	
	if (Solve_Can_Cross(stones, k - 1, current_stone + k - 1, target, cache)) return true;
	
	cache[stones[current_stone]][k] = false;

	return false;
}

bool canCross(std::vector<int>& stones) {

	std::unordered_map<int, int> stone_map;
	std::vector<std::vector<bool>> cache(stones.size(), std::vector<bool>(stones.size(), true));
	int target = stones.back();

	for (int i = 0; i < stones.size(); i++) {
		stone_map[stones[i]] = i;
	}

	return Solve_Can_Cross(stone_map, 0, 0, target, cache);
}
};
