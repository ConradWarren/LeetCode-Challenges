#include <vector>
#include <string>

class Solution {
public:
int Solve_Number_of_Decodings(std::string& s, int current, int idx, std::vector<int>& cache) {

	if (idx == s.length()) {
		if (current > 26) return 0;
		return 1;
	}

	if (current > 26) return 0;

	int starts_new = 0;
	if (cache[idx] != -1) {
		starts_new = cache[idx];
	}
	else {
		starts_new = (s[idx] == '0') ? 0 : Solve_Number_of_Decodings(s, (int(s[idx]) - int('0')), idx + 1, cache);
		cache[idx] = starts_new;
	}
	current *= 10;
	current += (int(s[idx]) - int('0'));
	int continues = Solve_Number_of_Decodings(s, current, idx + 1, cache);

	return continues + starts_new;
}


int numDecodings(std::string s) {

	if (s[0] == '0') return 0;

	std::vector<int> cache(s.length(), -1);

	return Solve_Number_of_Decodings(s, (int(s[0]) - int('0')), 1, cache);
}
};
