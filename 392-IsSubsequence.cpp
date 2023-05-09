class Solution {
public:
bool isSubsequence(std::string s, std::string t) {

	int idx_s = 0;
	int idx_t = 0;
	
	while (idx_s < s.length() && idx_t < t.length()) {

		if (s[idx_s] == t[idx_t]) {
			idx_s++;
			idx_t++;
		}
		else {
			idx_t++;
		}
	}


	return (idx_s >= s.length()) ? true : false;
}
};
