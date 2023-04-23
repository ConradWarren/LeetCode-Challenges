#include <string>

class Solution {
public:
std::string addStrings(std::string num1, std::string num2) {

	if (num2.length() > num1.length()) return addStrings(num2, num1);
	
	std::reverse(num1.begin(), num1.end());
	std::reverse(num2.begin(), num2.end());

	int carry = 0;
	int idx = num2.length();
	for (int i = 0; i < num2.length(); i++) {

		int current_num = int(num1[i]) - int('0') + int(num2[i]) - int('0') + carry;

		if (current_num > 9) {
			current_num -= 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		num1[i] = char(current_num + int('0'));
	}

	while (carry && idx < num1.length()) {
		int current_num = int(num1[idx]) - int('0') + carry;
		if (current_num > 9) {
			current_num -= 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		num1[idx] = char(current_num + int('0'));
		idx++;
	}

	if (carry) num1 += '1';
	std::reverse(num1.begin(), num1.end());

	return num1;
}
};
