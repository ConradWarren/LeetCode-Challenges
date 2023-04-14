#include <vector>

class Solution {
public:
int solve(std::string& s, std::vector<std::vector<int>>& memo, int left_border, int right_border) {

	if (left_border > right_border) return 0;
	
	if (left_border == right_border) return 1;
	
	if (memo[left_border][right_border] != -1) return memo[left_border][right_border];
	
	if (s[left_border] == s[right_border]) memo[left_border][right_border] = 2 + solve(s, memo, left_border + 1, right_border - 1);
	else memo[left_border][right_border] = max(solve(s, memo, left_border + 1, right_border), solve(s, memo, left_border, right_border - 1));

	return memo[left_border][right_border];
}


int longestPalindromeSubseq(std::string s) {
	std::vector<std::vector<int>> memo(s.length(), std::vector<int>(s.length(), -1));

	return solve(s, memo, 0, s.length() - 1);
}
};
