#include <string>
#include <vector>

class Solution {
public:
std::string largestWordCount(std::vector<std::string>& messages, std::vector<std::string>& senders) {

	std::unordered_map<std::string, int> word_counts;
	std::string result;
	int highest_word_count = 0;
	bool found_word = false;
	int current_word_count = 0;

	for (int i = 0; i < messages.size(); i++) {

		found_word = false;
		current_word_count = 0;

		for (int j = 0; j < messages[i].length(); j++) {

			if (messages[i][j] != ' ') found_word = true;
			
			else if (found_word) {
				found_word = false;
				current_word_count++;
			}
		}
		current_word_count += (found_word) ? 1 : 0;
		word_counts[senders[i]] += current_word_count;
	}

	for (auto &x : word_counts) {
		if (x.second > highest_word_count || (x.second == highest_word_count && x.first > result)) {
			highest_word_count = x.second;
			result = x.first;
		}
	}

	return result;
}
};
