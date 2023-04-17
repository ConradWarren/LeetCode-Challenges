#include <vector>

class Solution {
public:
int recursive_soloution(std::vector<std::vector<int>>& costs, int a_city_count, int b_city_count, int idx, std::vector<std::vector<int>>& cache) {

	if (a_city_count < 0 || b_city_count < 0) {
		return 10000000;
	}

	if (a_city_count == 0 && b_city_count == 0) {
		return 0; 
	}

	if (cache[a_city_count][b_city_count] != -1) {
		return cache[a_city_count][b_city_count];
	}

	int cost_a = costs[idx][0] + recursive_soloution(costs, a_city_count - 1, b_city_count, idx + 1, cache);
	int cost_b = costs[idx][1] + recursive_soloution(costs, a_city_count, b_city_count-1, idx + 1, cache);
	
	cache[a_city_count][b_city_count] = (cost_a < cost_b) ? cost_a : cost_b;

	return cache[a_city_count][b_city_count];
}


int twoCitySchedCost(std::vector<std::vector<int>>& costs) {

	std::vector<std::vector<int>> cache((costs.size() / 2) + 1, std::vector<int>((costs.size() / 2) + 1, -1));

	return recursive_soloution(costs, costs.size() / 2, costs.size() / 2, 0, cache);
}
};
