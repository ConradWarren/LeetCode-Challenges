#include <cmath>
#include <vector>

class Solution {
public:
bool Solve_Game(int n, bool player_flag, std::vector<bool>& cache, std::vector<bool>& has_cache) {

	if (has_cache[n]) {
		return (cache[n]) ? player_flag : !player_flag;
	}

	int idx = std::sqrt(n);

	if (idx * idx == n) {
		has_cache[n] = true;
		cache[n] = true;
		return player_flag;
	}

	while (idx > 0) {

		if (Solve_Game(n - (idx * idx), !player_flag, cache, has_cache) == player_flag) {
			has_cache[n] = true;
			cache[n] = true;
			return player_flag;
		}
		idx--;
	}

	has_cache[n] = true;
	cache[n] = false;
	return !player_flag;
}

bool winnerSquareGame(int n) {

	std::vector<bool> cache(n + 1);
	std::vector<bool> has_cache(n + 1, false);


	return Solve_Game(n, true, cache, has_cache);
}
};
