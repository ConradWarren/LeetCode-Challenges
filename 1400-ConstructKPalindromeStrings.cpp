#include <string>
#include <unordered_map>

class Solution {
public:
bool canConstruct(std::string s, int k) {
	
	std::unordered_map<char, int> character_counts;
	for (int i = 0; i < s.length(); i++) {
		character_counts[s[i]]++;
	}

	if (s.length() < k) return false;
	
	int odd_count = 0;
	for (auto& x : character_counts) {
		if (x.second % 2) odd_count++;
	}

	if (odd_count > k) {
		return false;
	}

	return true;
}
};
