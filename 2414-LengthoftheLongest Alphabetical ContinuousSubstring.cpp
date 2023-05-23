#include <string>

class Solution {
public:
int longestContinuousSubstring(std::string s) {

	int current_asii_val = int('a') - 1;
	int current_length = 0;
	int best_length = 1;

	for (int i = 0; i < s.length(); i++) {
		current_length = (s[i] == current_asii_val + 1) ? current_length + 1 : 1;
		best_length = (best_length > current_length) ? best_length : current_length;
		current_asii_val = int(s[i]);
	}

	return best_length;
}
};
