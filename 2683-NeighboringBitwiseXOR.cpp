#include <vector>

class Solution {
public:
bool doesValidArrayExist(std::vector<int>& derived) {

	int first = 1;
	int current = 1;

	for (int i = 0; i < derived.size() - 1; i++) {
		if (derived[i]) current ^= 1;
	}

	if ((derived.back() && first != current) || (!derived.back() && first == current)) {
		return true;
	}

	first = 0;
	current = 0;

	for (int i = 0; i < derived.size() - 1; i++) {
		if (derived[i]) current ^= 1;
	}

	if ((derived.back() && first != current) || (!derived.back() && first == current)) {
		return true;
	}

	return false;
}
};
