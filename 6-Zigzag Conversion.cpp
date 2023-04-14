#include <string>
#include <vector>

class Solution {
public:
std::string convert(std::string s, int numRows) {

	std::string result = "";
	std::vector<std::string> rows(numRows);
	int current_row = 0;
	int idx = 0;
	

	while (idx < s.length()) {

		while (current_row < numRows && idx < s.length()) {
			rows[current_row] += s[idx];
			idx++;
			current_row++;
		}

		current_row = numRows - 2;
		while (current_row > 0 && idx < s.length()) {
			rows[current_row] += s[idx];
			idx++;
			current_row--;
		}

		current_row = 0;
	}

	for (int i = 0; i < numRows; i++) {
		result += rows[i];
	}

	return result;
}
};
