#include <vector>

class Solution {
public:
int numWays(std::vector<std::string>& words, std::string target) {

	std::vector<std::vector<int>> character_counts(words[0].size(), std::vector<int>(26, 0));
	std::vector<int> number_of_ways(target.length() + 1, 0);
	number_of_ways[0] = 1;

	for (auto& word : words) {
		for (int i = 0; i < word.length(); i++) {
			character_counts[i][int(word[i]) - int('a')]++;
		}
	}
	
	for (int i = 0; i < words[0].size(); i++) {
		for (int j = int(target.length()) - 1; j >= 0; j--) {

			number_of_ways[j + 1] += int(((long long)(number_of_ways[j]) * (long long)(character_counts[i][int(target[j]) - int('a')])) % 1000000007);
			number_of_ways[j+1] = number_of_ways[j + 1] % 1000000007;
		}
	}
	
	return number_of_ways.back();
}
};
