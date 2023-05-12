#include <vector>

class Solution {
public:
std::vector<int> findAnagrams(std::string s, std::string p) {

	if (p.length() > s.length()) return {};
	
	std::vector<int> current_counts(26, 0);
	std::vector<int> p_counts(26, 0);
	std::vector<int> result;
	bool valid_flag = false;
	
	for (int i = 0; i < p.length(); i++) {
		p_counts[int(p[i]) - int('a')]++;
	}
	
	for (int i = 0; i < p.length(); i++) {
		current_counts[int(s[i]) - int('a')]++;
	}

	if (current_counts == p_counts) {
		result.push_back(0);
		valid_flag = true;
	}
	
	int idx = 0;
	for (int i = p.length(); i < s.length(); i++) {

		current_counts[int(s[i]) - int('a')]++;
		current_counts[int(s[idx]) - int('a')]--;

		if (current_counts[int(s[i]) - int('a')] == p_counts[int(s[i]) - int('a')] && current_counts[int(s[idx]) - int('a')] == p_counts[int(s[idx]) - int('a')] && (valid_flag || current_counts == p_counts)) {
			result.push_back(idx + 1);
			valid_flag = true;
		}
		else valid_flag = false;
		
		idx++;
	}
	return result;
}
};
