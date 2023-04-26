#include <string>

class Solution {
public:
int minimumMoves(std::string s) {

	int current_string_count = 0;
	int moves_required = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'X' && !current_string_count) {
			current_string_count = 1;
		}
		else if (current_string_count) {
			current_string_count++;
		}

		if (current_string_count == 3) {
			moves_required++;
			current_string_count = 0;
		}
	}

	if (current_string_count) moves_required++;
	
	return moves_required;
}
};
