#include <string>

class Solution {
public:
int balancedStringSplit(std::string s) {

	int L_count = 0;
	int R_count = 0;
	int split_count = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'L') L_count++;
		else if (s[i] == 'R') R_count++;

		if (L_count == R_count) {
			split_count++;
			L_count = 0;
			R_count = 0;
		}
	}

	return split_count;
}
};
