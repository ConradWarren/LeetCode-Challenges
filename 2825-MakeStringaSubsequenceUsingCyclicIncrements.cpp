#include <string>

class Solution {
public:
bool canMakeSubsequence(std::string str1, std::string str2) {

	int idx = 0;

	for (int i = 0; i < str1.length(); i++) {

		if (str1[i] == str2[idx]) {
			idx++;
		}
		else if (((str1[i] - 'a') + 1)%26 == str2[idx]-'a') {
			idx++;
		}

		if (idx >= str2.length()) {
			return true;
		}
	}


	return false;
}
};
