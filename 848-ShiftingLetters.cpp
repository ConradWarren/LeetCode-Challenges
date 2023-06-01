#include <string>
#include <vector>

class Solution {
public:
std::string shiftingLetters(std::string s, std::vector<int>& shifts) {

	for (int i = shifts.size() - 2; i >= 0; i--) {
		shifts[i] += shifts[i + 1];
		shifts[i] %= 26;
	}

	for (int i = 0; i < s.length(); i++) {

		s[i] = (((s[i] + shifts[i]) - int('a')) % 26) + int('a');
	}


	return s;
}
};
