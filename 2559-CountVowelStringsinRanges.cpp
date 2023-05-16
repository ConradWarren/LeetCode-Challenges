class Solution {
public:
std::vector<int> vowelStrings(std::vector<std::string>& words, std::vector<std::vector<int>>& queries) {

	std::vector<bool> is_vowel(26, false);
	std::vector<int> valid_word_counts(words.size(), 0);
	std::vector<int> result(queries.size());

	is_vowel['a' - int('a')] = true;
	is_vowel['e' - int('a')] = true;
	is_vowel['i' - int('a')] = true;
	is_vowel['o' - int('a')] = true;
	is_vowel['u' - int('a')] = true;

	if (is_vowel[words[0].front() - int('a')] && is_vowel[words[0].back() - int('a')]) valid_word_counts[0] = 1;
	
	for (int i = 1; i < words.size(); i++) {

		if (is_vowel[words[i].front() - int('a')] && is_vowel[words[i].back() - int('a')]) valid_word_counts[i] = 1;
		
		valid_word_counts[i] += valid_word_counts[i - 1];
	}

	for (int i = 0; i < queries.size(); i++) {

		if (queries[i][0] == 0) result[i] = valid_word_counts[queries[i][1]];
		
		else result[i] = valid_word_counts[queries[i][1]] - valid_word_counts[queries[i][0] - 1];
	}

	return result;
}
};
