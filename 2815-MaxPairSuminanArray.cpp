#include <vector>

class Solution {
public:
int maxSum(std::vector<int>& input) {

	std::vector<std::vector<bool>> nums(input.size(), std::vector<bool>(10, false));
	std::vector<bool> used_nums(input.size(), false);
	int temp = 0;
	int current_max = INT_MIN;
	int result = 0;


	for (int i = 0; i < input.size(); i++) {

		temp = input[i];

		while (temp){
			nums[i][temp % 10] = true;
			temp /= 10;
		}
	}

	for (int i = 9; i > 0; i--) {

		current_max = INT_MIN;

		for (int j = 0; j < input.size(); j++) {

			if (used_nums[j] || !nums[j][i]) {
				continue;
			}

			used_nums[j] = true;

			result = (result > current_max + input[j]) ? result : current_max + input[j];

			current_max = (current_max > input[j]) ? current_max : input[j];

		}

	}

	return (result > 0) ? result : -1;
}
};
