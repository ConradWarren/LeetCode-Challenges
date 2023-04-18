#include <string>
#include <vector>

class Solution {
public:
bool Solve(std::string& s1, std::string& s2, std::string& s3, int idx_1, int idx_2, int idx_3, std::vector<std::vector<int>>& cache) {

	if (idx_3 >= s3.length()) {
		return true;
	}

	if (cache[idx_1][idx_2] != -1) {
		return cache[idx_1][idx_2];
	}

	if (idx_1 < s1.length() && s1[idx_1] == s3[idx_3]) {

		if (Solve(s1, s2, s3, idx_1 + 1, idx_2, idx_3 + 1, cache)) {
			cache[idx_1][idx_2] = 1;
			return true;
		}

	}

	if (idx_2 < s2.length() && s2[idx_2] == s3[idx_3]) {
		if (Solve(s1, s2, s3, idx_1, idx_2+1, idx_3 + 1, cache)) {
			cache[idx_1][idx_2] = 1;
			return true;
		}
	}
	cache[idx_1][idx_2] = 0;
	return false;
}


bool isInterleave(std::string s1, std::string s2, std::string s3) {

	if (s1.length() + s2.length() != s3.length()) {
		return false;
	}

	std::vector<std::vector<int>> cache(s1.length()+1, std::vector<int>(s2.length()+1, -1));

	return Solve(s1, s2, s3, 0, 0, 0, cache);
}
};
