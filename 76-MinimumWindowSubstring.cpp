#include <vector>
class Solution {
public:
std::string minWindow(std::string s, std::string t) {

	int back_idx = 0;
	int unique_count = 0;
	int result_length = INT_MAX;
	std::pair<int, int> result_idx;
	std::vector<int> needed_characters(58, 0);
	std::vector<int> current_characters(58, 0);
	

	for (int i = 0; i < t.length(); i++) {
		needed_characters[t[i]-'A']++;
		if (needed_characters[t[i]-'A'] == 1) {
			unique_count++;
		}
	}

	for (int i = 0; i < s.length(); i++) {

		if (needed_characters[s[i]-'A'] == 0) {
			continue;
		}
		
		current_characters[s[i]-'A']++;

		if (current_characters[s[i]-'A'] == needed_characters[s[i]-'A']) {
			unique_count--;
		}

		while (unique_count == 0) {

			if (result_length > i - back_idx + 1) {
				result_idx = { back_idx, i - back_idx + 1 };
				result_length = i - back_idx + 1;
			}

			if (needed_characters[s[back_idx]-'A'] != 0 && current_characters[s[back_idx]-'A'] == needed_characters[s[back_idx]-'A']) {
				unique_count++;
			}

			if (needed_characters[s[back_idx]-'A'] != 0) {
				current_characters[s[back_idx]-'A']--;
			}

			back_idx++;
		}
	}

	return s.substr(result_idx.first, result_idx.second);
}
};
