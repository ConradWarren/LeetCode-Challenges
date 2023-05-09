#include <vector>
#include <string>

class Solution {
public:
std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {

	std::vector<std::string> current_words;
	std::vector<std::string> result;
	std::string current_line;

	int current_width =0;
	int idx = 0;

	while (idx < words.size()) {

		current_line.clear();
		current_words.clear();
		current_width = 0;

		if (words[idx].length() == maxWidth) {
			result.push_back(words[idx]);
			idx++;
		}

		while (idx < words.size() && (current_width + words[idx].length()) <= maxWidth) {
			current_width += words[idx].length();
			current_width++;
			current_words.push_back(words[idx]);
			idx++;
		}

		if (current_words.empty()) {
			break;
		}

		current_width = 0;
		for (int i = 0; i < current_words.size(); i++) {
			current_width += current_words[i].length();
		}

		int white_space_needed = (current_words.size() == 1) ? 0 : (maxWidth - current_width)/(current_words.size()-1);

		int extra_spaces = (current_words.size() == 1) ? (maxWidth - current_width) : (maxWidth - current_width) % (current_words.size() - 1);

		for (int i = 0; i < current_words.size() - 1; i++) {

			current_line += current_words[i];

			for (int j = 0; j < white_space_needed; j++) {
				current_line += ' ';
			}

			if (extra_spaces) {
				current_line += ' ';
				extra_spaces--;
			}

		}

		current_line += current_words.back();

		while (extra_spaces) {
			current_line += ' ';
			extra_spaces--;
		}

		result.push_back(current_line);
	}


	if (current_words.size() > 1) {

		result.pop_back();
		current_line.clear();
		for (int i = 0; i < current_words.size(); i++) {
			current_line += current_words[i];
			current_line += ' ';
		}

		if (current_line.length() > maxWidth) {
			current_line = current_line.substr(0, current_line.length() - 1);
		}

		while (current_line.length() < maxWidth) {
			current_line += ' ';
		}

		result.push_back(current_line);

	}

	return result;
}
};
