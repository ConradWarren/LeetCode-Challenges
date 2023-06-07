#include <string>
#include <vector>

class Solution {
public:
long long appealSum(std::string s) {

	long long result = 0;
	int n = int(s.length());
	int relative_idx = 0;
	int relative_length = 0;

	std::vector<int> character_idx(26, -1);

	for (int i = 0; i < s.length(); i++) {

		if (character_idx[s[i]-'a'] == -1) {
			result += ((long long)(n - i) * (long long)(i + 1));
		}
		else {

			relative_length = n - character_idx[s[i] - 'a'] - 1;
			relative_idx = i - character_idx[s[i] - 'a'] - 1;
			result += ((long long)(relative_length - relative_idx) * (long long)(relative_idx + 1));
		}
		character_idx[s[i]-'a'] = i;
	}

	return result;
}
};
