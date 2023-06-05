#include <vector>
#include <string>

class Solution {
public:
int uniqueLetterString(std::string s) {

	int sum = 0;
	int n = s.length();
	int length = 0;
	int relative_idx = 0;
	std::vector<std::vector<int>> unique_characters_idx(26);

	for (int i = 0; i < s.length(); i++) {
		unique_characters_idx[s[i] - 'A'].push_back(i);
	}
	
	for (int i = 0; i < 26; i++) {

		if (unique_characters_idx[i].empty()) continue;
		
		if (unique_characters_idx[i].size() == 1) {
			sum += ((n - unique_characters_idx[i][0]) * (unique_characters_idx[i][0] + 1));
			continue;
		}

		sum += ((unique_characters_idx[i][1] - unique_characters_idx[i][0]) * (unique_characters_idx[i][0] + 1));
		
		for (int j = 1; j < unique_characters_idx[i].size()-1; j++) {

			length = unique_characters_idx[i][j + 1] - unique_characters_idx[i][j - 1] - 1;
			relative_idx = unique_characters_idx[i][j] - unique_characters_idx[i][j - 1] - 1;
			sum += (length - relative_idx) * (relative_idx + 1);
		}

		length = n - unique_characters_idx[i][unique_characters_idx[i].size()-2] - 1;
		relative_idx = unique_characters_idx[i].back() - unique_characters_idx[i][unique_characters_idx[i].size() - 2] - 1;

		sum += (length - relative_idx) * (relative_idx + 1);
	}
	return sum;
}
};
