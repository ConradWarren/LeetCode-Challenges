#include <string>

class Solution {
public:
int countSegments(std::string s) {

	bool segment_found = false;
	int count = 0;
	for (int i = 0; i < s.length(); i++) {

		if (s[i] != ' ' && !segment_found) {
			count++;
			segment_found = true;
		}
		else if (s[i] == ' ') {
			segment_found = false;
		}

	}

	return count;
}
};
