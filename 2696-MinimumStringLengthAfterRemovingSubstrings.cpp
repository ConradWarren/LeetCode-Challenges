#include <string>
#include <stack>

class Solution {
public:
int minLength(std::string s) {

	std::stack<char> character_stack;

	for (int i = 0; i < s.length(); i++) {

		if (character_stack.empty()) {
			character_stack.push(s[i]);
		}
		else if (character_stack.top() == 'A' && s[i]=='B') {
			character_stack.pop();
		}
		else if (character_stack.top() == 'C' && s[i] == 'D') {
			character_stack.pop();
		}
		else {
			character_stack.push(s[i]);
		}

	}

	return character_stack.size();
}
};
