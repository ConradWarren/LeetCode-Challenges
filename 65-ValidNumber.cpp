#include <string>

class Solution {
public:
bool isNumber(std::string s) {

	if ((int(s.back()) < 48 || int(s.back()) > 57) && s.back() != '.') {
		return false;
	}

	bool decimal_found = false;
	bool number_found = false;
	bool e_found = false;

	int idx = 0;

	while (idx < s.length() && (s[idx] == '+' || s[idx] == '-')) {
		idx++;
	}

	if (idx > 1) return false;
	
	for (int i = idx; i < s.length(); i++) {

		if ((int(s[i]) >= 48 && int(s[i]) <= 57)) number_found = true;
		
		else if (s[i] == '.') {

			if (decimal_found || e_found) return false;
			
			decimal_found = true;
		}
		else if (s[i] == 'e' || s[i] == 'E') {

			if (e_found || !number_found) return false;
			
			e_found = true;
		}
		else if (s[i] == '+' || s[i] == '-') {

			if (!e_found) return false;
			
			if (s[i - 1] != 'e' && s[i - 1] != 'E') return false;
		}
		else {
			return false;
		}

	}

	return number_found;
}
};
