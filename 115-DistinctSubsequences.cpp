#include <vector>

class Solution {
public:
int Count_Distinct_Sequences(std::string& s, std::string& t, int idx_s, int idx_t, std::vector<std::vector<int>>& cache) {

	if (idx_t >= t.length()) return 1;
	
	if (idx_s >= s.length()) return 0;
	
	if (cache[idx_s][idx_t] != -1) return cache[idx_s][idx_t];
	
	int skips = Count_Distinct_Sequences(s, t, idx_s + 1, idx_t, cache);

	int takes = (s[idx_s] == t[idx_t]) ? Count_Distinct_Sequences(s, t, idx_s + 1, idx_t + 1, cache) : 0;

	cache[idx_s][idx_t] = skips + takes;

	return cache[idx_s][idx_t];
}

int numDistinct(std::string s, std::string t) {

	std::vector<std::vector<int>> cache(s.length(), std::vector<int>(t.length(), -1));

	return Count_Distinct_Sequences(s, t, 0, 0, cache);
}
};
