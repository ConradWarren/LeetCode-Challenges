#include <vector>
#include <string>

class Solution {
public:
int numberOfSubstrings(std::string s) {

	std::vector<int> character_count(3, 0);
	int substring_count = 0;
	int back_idx = 0;

	for (int i = 0; i < s.length(); i++) {

		character_count[int(s[i]) - int('a')]++;

		while (character_count[0] && character_count[1] && character_count[2]) {

			substring_count += (s.length() - i);

			character_count[s[back_idx] - int('a')]--;
			
			back_idx++;
		}
	}

	return substring_count;
}

};
