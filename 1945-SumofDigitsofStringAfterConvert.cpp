#include <string>

class Solution {
public:
int getLucky(std::string s, int k) {

	std::string transform_1;
	int transform_2 = 0;

	for (int i = 0; i < s.length(); i++) {
		int temp = int(s[i]) - int('a') + 1;
		transform_1 += std::to_string(temp);
	}

	for (int i = 0; i < transform_1.length(); i++) {
		transform_2 += int(transform_1[i]) - int('0');
	}

	for (int i = 0; i < k - 1; i++) {
		int temp = 0;
		while (transform_2) {
			temp += transform_2 % 10;
			transform_2 /= 10;
		}
		transform_2 = temp;
	}

	return transform_2;
}
};
