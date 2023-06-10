class Solution {
public:
std::string replaceDigits(std::string s) {

	for (int i = 1; i < s.length(); i++) {

		if (s[i] >= '0' && s[i] <= '9') {

			s[i] = s[i - 1] + int(s[i] - '0');

		}
	}
	return s;
}
};
