#include <vector>
#include <string>

class Solution {
public:
int Solve_Min_Distance(std::string& word, int idx, int pos_1, int pos_2, std::vector<std::vector<std::vector<int>>>& cache) {

	if (idx >= word.length()) {
		return 0;
	}

	if (cache[idx][pos_1][pos_2] != -1) {
		return cache[idx][pos_1][pos_2];
	}


	int target_y_pos = int(word[idx] - 'A') / 6;
	int target_x_pos = int(word[idx] - 'A') % 6;

	int finger_1 = std::abs((pos_1 / 6) - target_y_pos) + std::abs((pos_1 % 6) - target_x_pos) + Solve_Min_Distance(word, idx + 1, int(word[idx] - 'A'), pos_2, cache);
	int finger_2 = std::abs((pos_2 / 6) - target_y_pos) + std::abs((pos_2 % 6) - target_x_pos) + Solve_Min_Distance(word, idx + 1, pos_1, int(word[idx] - 'A'), cache);

	cache[idx][pos_1][pos_2] = (finger_1 < finger_2) ? finger_1 : finger_2;

	return cache[idx][pos_1][pos_2];
}

int minimumDistance(std::string word) {

	int result = INT_MAX;
	int current = 0;
	std::vector<std::vector<std::vector<int>>> cache(word.length(), std::vector<std::vector<int>>(26, std::vector<int>(26, -1)));

	for (int i = 1; i < word.length(); i++) {
		current = Solve_Min_Distance(word, 0, int(word[0] - 'A'), int(word[i] - 'A'), cache);
		result = (result < current) ? result : current;
	}

	return result;
}
};
