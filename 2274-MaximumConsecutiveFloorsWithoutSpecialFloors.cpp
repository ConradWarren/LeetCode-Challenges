#include <vector>

class Solution {
public:
int maxConsecutive(int bottom, int top, std::vector<int>& special) {

	int result = 0;

	std::sort(special.begin(), special.end());

	result = (result > special.front() - bottom) ? result : special.front() - bottom;
	result = (result > top - special.back()) ? result : top - special.back();

	for (int i = 0; i < special.size() - 1; i++) {
		result = (result > (special[i + 1] - special[i] - 1)) ? result : (special[i + 1] - special[i] - 1);
	}

	return result;
}
};
