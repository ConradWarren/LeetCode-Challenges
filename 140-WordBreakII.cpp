#include <vector>
#include <string>

class Solution {
public:
void Solve(std::string& s, int idx, std::vector<std::string>& words,std::vector<int>& current, std::vector<std::vector<int>>& output) {

	if (idx >= s.length()) {
		output.push_back(current);
		return;
	}

	
	for (int i = 0; i < words.size(); i++) {

		if (words[i].length() + idx <= s.length() && words[i] == s.substr(idx, words[i].length())) {
			current.push_back(i);
			Solve(s, idx + int(words[i].length()), words, current, output);
			current.pop_back();
		}

	}
}

std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
	
	std::vector<std::vector<int>> indexed_result;
	std::vector<int> current;
	std::vector<std::string> result;

	Solve(s, 0, wordDict, current, indexed_result);

	result.resize(indexed_result.size());

	for (int i = 0; i < indexed_result.size(); i++) {
		for (int j = 0; j < indexed_result[i].size(); j++) {

			if (!result[i].empty()) {
				result[i] += " ";
			}
			result[i] += wordDict[indexed_result[i][j]];
		}
	}
	return result;
}
};
