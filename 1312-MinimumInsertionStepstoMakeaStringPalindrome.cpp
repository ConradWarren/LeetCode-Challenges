#include <string>
#include <vector>

class Solution {
public:
int Longest_Palindronic_Substring(std::string& s, std::vector<std::vector<int>>& cache, int left_border, int right_border) {

	if (left_border > right_border) return 0; 
	
	if (left_border == right_border) return 1;
	
	if (cache[left_border][right_border] != -1) return cache[left_border][right_border];
	
	if (s[left_border] == s[right_border]) cache[left_border][right_border] = 2 + Longest_Palindronic_Substring(s, cache, left_border + 1, right_border - 1);
	
	else cache[left_border][right_border] = max(Longest_Palindronic_Substring(s, cache, left_border + 1, right_border), Longest_Palindronic_Substring(s, cache, left_border, right_border - 1));

	return cache[left_border][right_border];
}

int minInsertions(std::string s) {

	std::vector<std::vector<int>> cache(s.length(), std::vector<int>(s.length(), -1));

	int longest_substring = Longest_Palindronic_Substring(s, cache, 0, s.length() - 1);

	return s.length()-longest_substring; 
}
};
