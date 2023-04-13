#include <vector>

class Solution {
public:
	bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {

		std::vector<int> stack;

		int idx_push = 0;
		int idx_pop = 0;

		while (idx_push < pushed.size() && idx_pop < popped.size()) {

			if (stack.empty() || stack.back() != popped[idx_pop]) {
				stack.push_back(pushed[idx_push]);
				idx_push++;
			}
			else if (stack.back() == popped[idx_pop]) {
				stack.pop_back();
				idx_pop++;
			}
		}

		while (idx_pop < popped.size() && !stack.empty() && stack.back() == popped[idx_pop]) {
			stack.pop_back();
			idx_pop++;
		}

		return (idx_pop == popped.size()) ? true : false;
	}
};
