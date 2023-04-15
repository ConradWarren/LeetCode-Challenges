#include <string>

class Solution {
public:
int percentageLetter(std::string s, char letter) {

	int count = std::count(s.begin(), s.end(), letter);
	count *= 100;
	count /= s.length();
	return count;
}
};
