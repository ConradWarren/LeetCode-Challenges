#include <string>

class Solution {
public:
bool Is_Subsequence(std::string& s, std::string& p, int idx_s, int idx_p) {

	if (idx_p >= p.length()) {
		return true;
	}
	if (idx_s >= s.length()) {
		return false;
	}

	if (s[idx_s] != p[idx_p]) {
		return Is_Subsequence(s, p, idx_s + 1, idx_p);
	}

	return Is_Subsequence(s, p, idx_s + 1, idx_p + 1);
}

int maximumRemovals(std::string s, std::string p, std::vector<int>& removable) {
	
	int high = removable.size();
	int low = 0;
	int mid = (low + high) / 2;
	
	while (low < high) {

		std::string temp_s = s;

		for (int i = 0; i <= mid; i++) {
			temp_s[removable[i]] = 'A';
		}

		if (Is_Subsequence(temp_s, p, 0, 0) ) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
		mid = (low + high) / 2;
	}
	return low;
}
};
