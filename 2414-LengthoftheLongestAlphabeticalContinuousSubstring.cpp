#include <string>

class Solution {
public:
int longestContinuousSubstring(std::string s) {

	int current_streak = 1;
	int longest_streak = 1;
	int current_ascii_val = 0;

	for (int i = 0; i < s.length(); i++) {

		if (s[i] == current_ascii_val + 1) {
			current_streak++;
			current_ascii_val++;
			longest_streak = max(current_streak, longest_streak);
		}
		else {
			current_ascii_val = int(s[i]);
			current_streak = 1;
		}

	}

	return longest_streak;
}
};
