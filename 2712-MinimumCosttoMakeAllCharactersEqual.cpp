class Solution {
public:
long long minimumCost(std::string s) {

	int target = (s[0] == '0') ? 0 : 1;

	long long cost = 0;

	for (int i = 1; i < s.length(); i++) {

		if ((int(s[i]) - int('0')) == target) continue;
		
		cost += (i < s.length() - i) ? i : s.length() - i;

		target ^= 1;
	}

	return cost;
}
};
