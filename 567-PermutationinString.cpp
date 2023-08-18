#include <string>
#include <vector>

class Solution {
public:
bool checkInclusion(std::string s1, std::string s2) {

	std::vector<int> needed(26, 0);
	std::vector<int> current(26, 0);
	int back_idx = 0;
	int under_conflicts = 0;
	int over_conflicts = 0;
	
	for (int i = 0; i < s1.length(); i++) {
		needed[s1[i] - 'a']++;
		if (needed[s1[i] - 'a'] == 1) {
			under_conflicts++;
		}
	}

	for (int i = 0; i < s2.length(); i++) {
		
		current[s2[i] - 'a']++;

		if (current[s2[i] - 'a'] == needed[s2[i] - 'a']) {
			under_conflicts--;
		}
		else if (current[s2[i] - 'a'] > needed[s2[i] - 'a']) {
			over_conflicts++;
		}

		while (over_conflicts != 0) {

			current[s2[back_idx] - 'a']--;

			if (current[s2[back_idx] - 'a'] == needed[s2[back_idx] - 'a']) {
				over_conflicts--;
			}
			else if (current[s2[back_idx] - 'a'] + 1 == needed[s2[back_idx]-'a']) {
				under_conflicts++;
			}

			back_idx++;
		}

		if (over_conflicts == 0 && under_conflicts == 0) {
			return true;
		}

	}

	return false;
}
};
