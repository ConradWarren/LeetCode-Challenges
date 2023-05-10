#include <string>
#include <vector>

class Solution {
public:
bool isPrefixString(std::string s, std::vector<std::string>& words) {

	int idx = 0;

	for (int i = 0; i < words.size(); i++) {

		if (s.substr(idx, words[i].length()) == words[i]) {
			idx += words[i].length();
			if (idx >= s.length()) return true;
		}
		else return false;
	}

	return false;
}
};
