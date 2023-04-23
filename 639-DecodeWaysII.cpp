class Solution {
public:
int Solve_Number_of_Decodings(std::string& s, int current, int idx, std::vector<int>& cache) {

	if (idx == s.length()) {
		if (current > 26) return 0;
		return 1;
	}

	if (current > 26) return 0;

	int starts_new = 0;
	if (cache[idx] != -1) {
		starts_new = cache[idx];
	}
	else if (s[idx] == '*') {
		for (int i = 1; i < 10; i++) {
			starts_new += Solve_Number_of_Decodings(s, i, idx + 1, cache);
			starts_new %= 1000000007;
		}
		cache[idx] = starts_new;
	}
	else {
		starts_new = (s[idx] == '0') ? 0 : Solve_Number_of_Decodings(s, (int(s[idx]) - int('0')), idx + 1, cache);
		cache[idx] = starts_new;
	}

	int continues = 0;
	if (s[idx] == '*') {
		current *= 10;
		for (int i = 1; i < 10; i++) {
			continues += Solve_Number_of_Decodings(s, current + i, idx + 1, cache);
			continues %= 1000000007;
		}
	}
	else {
		current = (current * 10) + (int(s[idx]) - int('0'));
		continues = Solve_Number_of_Decodings(s, current, idx + 1, cache);
	}
	return (starts_new + continues) % 1000000007;
}


int numDecodings(std::string s) {

	if (s[0] == '0') return 0;

	std::vector<int> cache(s.length(), -1);

	int result = 0;

	if (s[0] == '*') {

		for (int i = 1; i < 10; i++) {
			result += Solve_Number_of_Decodings(s, i, 1, cache);
			result %= 1000000007;
		}

	}
	else {
		result = Solve_Number_of_Decodings(s, (int(s[0]) - int('0')), 1, cache);
	}

	return (result) % 1000000007;
}

};
