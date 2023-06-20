#include <string>
#include <vector>

class Solution {
public:
bool Solve(std::string& s, int idx, std::vector<std::string>& words, std::vector<bool>& cache) {

	if (idx >= s.size()) return true;
	
	if (!cache[idx]) return false;
	
	for (int i = 0; i < words.size(); i++) {
		if (words[i].length() + idx <= s.length() && words[i] == s.substr(idx, words[i].length()) && Solve(s, idx + int(words[i].length()), words, cache)) {
			return true;
		}
	}

	cache[idx] = false;

	return false;
}

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {

	std::vector<bool> cache(s.length(), true);

	return Solve(s, 0, wordDict, cache);
}
};
