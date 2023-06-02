#include <vector>

class Solution {
public:
int largestCombination(std::vector<int>& candidates) {

	std::vector<int> valid_bits(32, 0);
	int bit_idx = 0;
	int result = 0;

	for (int i = 0; i < candidates.size(); i++) {
		bit_idx = 0;
		while ((1 << bit_idx) <= candidates[i]) {

			if (candidates[i] & (1 << bit_idx)) valid_bits[bit_idx]++;
			
			bit_idx++;
		}
	}

	for (int i = 0; i < valid_bits.size(); i++) {
		result = (result > valid_bits[i]) ? result : valid_bits[i];
	}

	return result;
}
}
