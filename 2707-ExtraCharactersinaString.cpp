#include <vector>

class Solution {
public:
int Solve_Max_Covered(std::vector<std::pair<int, int>>& substrings, int idx, int lowest_valid_idx, std::vector<int>& cache) {

	if (idx >= substrings.size()) return 0;
	
	if (lowest_valid_idx > substrings[idx].first) return Solve_Max_Covered(substrings, idx + 1, lowest_valid_idx, cache);
	
	if (cache[idx] != -1) return cache[idx];
	
	int skips = Solve_Max_Covered(substrings, idx + 1, lowest_valid_idx, cache);

	int takes = substrings[idx].second - substrings[idx].first + 1 + Solve_Max_Covered(substrings, idx + 1, substrings[idx].second + 1, cache);

	cache[idx] = (takes > skips) ? takes : skips;

	return cache[idx];
}

int minExtraChar(std::string s, std::vector<std::string>& dictionary) {

	std::vector<std::pair<int, int>> valid_substring_ranges;
	std::vector<int> cache;

	for (int i = 0; i < dictionary.size(); i++) {

		auto It = s.find(dictionary[i]);
		while (It != std::string::npos) {
			valid_substring_ranges.push_back({ It,It + dictionary[i].length() - 1 });
			It = s.find(dictionary[i], It + 1);
		}
	}
	std::sort(valid_substring_ranges.begin(), valid_substring_ranges.end());

	cache.resize(valid_substring_ranges.size(), -1);
	
	return s.length() - Solve_Max_Covered(valid_substring_ranges, 0, 0, cache);
}
};
