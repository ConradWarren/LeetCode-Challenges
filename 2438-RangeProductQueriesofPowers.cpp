#include <vector>

class Solution {
public:
std::vector<int> productQueries(int n, std::vector<std::vector<int>>& queries) {

	int current_exp = 1;
	std::vector<long long> powers;
	std::vector<int> result(queries.size());

	while (n) {

		while (current_exp * 2 <= n) {
			current_exp *= 2;
		}
		n -= current_exp;
		powers.push_back(current_exp);
		current_exp = 1;
	}

	std::reverse(powers.begin(), powers.end());

	for (int i = 0; i < queries.size(); i++) {
		long long temp = 1;
		for (int j = queries[i][0]; j <= queries[i][1]; j++) {
			temp *= powers[j];
			temp %= 1000000007;
		}
		result[i] = temp;
	}

	return result;
}
};
