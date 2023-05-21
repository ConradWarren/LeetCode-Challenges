#include <string>

class Solution {
public:
std::string makeSmallestPalindrome(std::string s) {

	int low = (s.length() % 2) ? (s.length() / 2) : ((s.length() / 2) - 1);
	int high = s.length() / 2;

	while (low >= 0 && high < s.length()) {

		if (s[low] < s[high]) s[high] = s[low];
			
		else if (s[low] > s[high]) s[low] = s[high];

		low--;
		high++;

	}

	return s;
}
};
