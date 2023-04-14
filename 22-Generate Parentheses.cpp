#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
void Combination_Builder(std::vector<std::string>& result,std::unordered_map<std::string, bool>& Memo, std::string& current, int n) {

	if (Memo[current]) return;
	
	Memo[current] = true;

	if (n == 0) {
		result.push_back(current);
		return;
	}
	
	for (int i = 0; i < int(current.length())-1; i++) {
		if (current[i] == '(') {
			std::string temp = current.substr(0, i + 1) + "()" + current.substr(i + 1);
			Combination_Builder(result,Memo, temp, n - 1);
		}
	}
	std::string temp = current + "()";
	Combination_Builder(result,Memo, temp, n - 1);
}

std::vector<std::string> generateParenthesis(int n) {

	std::unordered_map<std::string, bool> memo;
	std::vector<std::string> result;
	std::string current = "";

	Combination_Builder(result,memo, current, n);

	return result;
}
};
