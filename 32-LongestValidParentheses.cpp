#include <string>
#include <stack>

class Solution {
public:
int longestValidParentheses(std::string s) {

	std::stack<int> open_bracket_stack;
	std::stack<std::pair<int, int>> valid_bracket_stack;
	
	for (int i = 0; i < s.length(); i++) {

		if (s[i] == '(') open_bracket_stack.push(i);
		
		else if(!open_bracket_stack.empty()){
			std::pair<int, int> temp_pair = { open_bracket_stack.top(), i };
			open_bracket_stack.pop();

			while (!valid_bracket_stack.empty()) {

				if (valid_bracket_stack.top().first > temp_pair.first) valid_bracket_stack.pop();
				
				else if (valid_bracket_stack.top().second + 1 == temp_pair.first) {
					temp_pair.first = valid_bracket_stack.top().first;
					valid_bracket_stack.pop();
				}
				else break;
			}
			valid_bracket_stack.push(temp_pair);
		}
	}

	int best = 0;
	while (!valid_bracket_stack.empty()) {
		best = max(best, (valid_bracket_stack.top().second - valid_bracket_stack.top().first) + 1);
		valid_bracket_stack.pop();
	}

	return best;
}
};
