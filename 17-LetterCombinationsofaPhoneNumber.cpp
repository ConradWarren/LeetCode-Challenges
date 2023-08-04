#include <vector>

class Solution {
public:
void Combination_Builder(std::vector<std::string>& key, std::string current, std::string& digits, int idx, std::vector<std::string>& result) {
	
	if (idx >= digits.length()) {
		result.push_back(current);
		return;
	}

	for (int i = 0; i < key[digits[idx] - '2'].length(); i++) {
		Combination_Builder(key, current + key[digits[idx] - '2'][i], digits, idx + 1, result);
	}
}

std::vector<std::string> letterCombinations(std::string digits) {

	if (digits.empty()){
		return {};
	}
	std::vector<std::string> key = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	std::vector<std::string> result;

	Combination_Builder(key, "", digits, 0, result);

	return result;
}
};
