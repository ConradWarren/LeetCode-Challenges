#include <string>

class Solution {
public:
int maxVowels(std::string s, int k) {


	int current_vowel_count = 0;
	int best_vowel_count = 0;
	int back_idx = 0;

	for (int i = 0; i < k; i++) {
		if (s[i] == 'a' || s[i] == 'e' ||s[i]=='i'|| s[i] == 'o' || s[i] == 'u') {
			current_vowel_count++;
		}
	}
	best_vowel_count = current_vowel_count;

	for (int i = k; i < s.length(); i++) {

		if (s[i] == 'a' || s[i] == 'e' ||s[i]=='i'|| s[i] == 'o' || s[i] == 'u') {
			current_vowel_count++;
		}

		if (s[back_idx] == 'a' || s[back_idx] == 'e' ||s[back_idx]=='i'|| s[back_idx] == 'o' || s[back_idx] == 'u') {
			current_vowel_count--;
		}
		back_idx++;
		best_vowel_count = (best_vowel_count > current_vowel_count) ? best_vowel_count : current_vowel_count;
	}

	return best_vowel_count;
}
};
