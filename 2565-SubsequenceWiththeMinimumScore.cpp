#include <string>
#include <vector>

class Solution {
public:
int minimumScore(std::string s, std::string t) {

	int score = t.length();
	int idx_front = 0;
	int idx_back = t.length()-1;
	std::vector<int> has_taken(s.length(), 0);

	for (int i = 0; i < s.length() && idx_front < t.length(); i++) {

		if (s[i] == t[idx_front]) {
			idx_front++;
			has_taken[i] = idx_front;
		} 
	}

	if (idx_front >= t.length()) return 0;
	
	for (int i = s.length() - 1; i >= 0 && idx_back >= 0; i--) {

		if (has_taken[i]) score = (score < (idx_back - has_taken[i] + 1)) ? score : (idx_back - has_taken[i] + 1);
		
		if (s[i] == t[idx_back]) idx_back--;
	}

	score = (score < (idx_back + 1)) ? score : idx_back + 1;

	return score;
}
};
