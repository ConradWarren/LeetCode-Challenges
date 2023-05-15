class Solution {
public:
int findTheLongestBalancedSubstring(std::string s) {

	int zero_count = 0;
	int one_count = 0;
	int max_length = 0;
	std::string result = "";

	for (int i = 0; i < s.length(); i++) {

		if (s[i] == '0' && !one_count) {
			zero_count++;
		}
		else if (s[i] == '1' && zero_count > one_count) {
			one_count++;
		}
		else {
			zero_count = (zero_count < one_count) ? zero_count : one_count;
			max_length = (max_length > zero_count) ? max_length : zero_count;

			zero_count = (s[i] == '0') ? 1 : 0;
			one_count = 0;
		}
	}

	zero_count = (zero_count < one_count) ? zero_count : one_count;
	max_length = (max_length > zero_count) ? max_length : zero_count;



	return max_length * 2;
}
};
