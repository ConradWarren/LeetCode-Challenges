#include <string>
#include <vector>
#include <priority_queue>

class Solution {
public:
std::string reorganizeString(std::string s) {

	std::vector<int> character_occurances(26, 0);
	std::priority_queue<std::pair<int, int>> max_heap;
	std::pair<int, int> last_valid = {-1, -1};
	std::pair<int, int> current;
	std::string result;
	int idx = 0;

	for (int i = 0; i < s.length(); i++) {
		character_occurances[s[i] - 'a']++;
	}
	for (int i = 0; i < character_occurances.size(); i++) {
		if (character_occurances[i] != 0) {
			max_heap.push({ character_occurances[i], i });
		}
	}

	while (!max_heap.empty()){

		current = max_heap.top();
		max_heap.pop();
		result += current.second + 'a';
		current.first--;

		if (last_valid.second != -1) {
			max_heap.push(last_valid);
		}

		if (current.first > 0) {
			last_valid = current;
		}
		else {
			last_valid = { -1, -1 };
		}
	}

	return (result.length() == s.length()) ? result : "";
}
};
