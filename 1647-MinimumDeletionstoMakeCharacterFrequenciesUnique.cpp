class Solution {
public:
int minDeletions(std::string s) {

	std::vector<int> frequency_occurances;
	std::vector<int> character_occurances(26, 0);
	int max_occurance = 0;
	int current = 0;
	int result = 0;

	for (int i = 0; i < s.length(); i++) {
		character_occurances[s[i] - 'a']++;
		max_occurance = (max_occurance > character_occurances[s[i] - 'a']) ? max_occurance : character_occurances[s[i] - 'a'];
	}

	frequency_occurances.resize(max_occurance + 1);

	for (int i = 0; i < character_occurances.size(); i++) {
		frequency_occurances[character_occurances[i]]++;
	}
	frequency_occurances[0] = 0;

	for (int i = max_occurance; i > 0; i--) {

		current += frequency_occurances[i];
		
		if (current == 0) {
			continue;
		}
		current--;
		result += current;
	}

	return result;
}
};
