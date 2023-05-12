#include <string>

class Solution {
public:
int nextGreaterElement(int n) {

	std::string num = std::to_string(n);

	std::next_permutation(num.begin(), num.end());

	long result = std::stol(num);

	if (result <= n || result > INT_MAX) {
		return -1;
	}

	return int(result);
}
};
