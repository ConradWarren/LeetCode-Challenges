#include <vector>

class Solution {
public:
long long putMarbles(std::vector<int>& weights, int k) {
	
	std::vector<int> options(weights.size() - 1);
	long long result = 0;

	for (int i = 0; i < weights.size()-1; i++) {
		options[i] = weights[i] + weights[i + 1];
	}

	std::sort(options.begin(), options.end());

	for (int i = 0; i < k - 1; i++) {
		result -= options[i];
		result += options[options.size()-1-i];
	}



	return result;
}
};
