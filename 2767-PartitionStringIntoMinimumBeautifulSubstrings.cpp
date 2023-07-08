#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
int Solve_Min_Substring(std::string& s, std::unordered_set<std::string>& valid_strings, int idx, std::string current) {

	if (idx >= s.length()) return (current.empty()) ? 0 : 100000;
	
	if (current.empty() && s[idx] == '0') return 100000;

	current += s[idx];

	int start_new = (valid_strings.find(current) != valid_strings.end()) ? 1 + Solve_Min_Substring(s, valid_strings, idx + 1, "") : 100000;
	int takes = Solve_Min_Substring(s, valid_strings, idx + 1, current);
	return (start_new < takes) ? start_new : takes;
}

int minimumBeautifulSubstrings(std::string s) {

	std::unordered_set<std::string> powers_of_five = { "1", "101", "11001", "1111101", "1001110001", "110000110101","11110100001001" };

	int result = Solve_Min_Substring(s, powers_of_five, 0, "");

	return (result < 100000) ? result : -1;
}
};
