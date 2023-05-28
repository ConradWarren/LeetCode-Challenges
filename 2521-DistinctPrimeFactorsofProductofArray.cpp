#include <vector>
#include <unordered_set>

class Solution {
public:
void Prime_Factorization(int num, std::unordered_set<int>& primes) {

	if (num % 2 == 0) {
		primes.insert(2);
		while (num % 2 == 0) {
			num /= 2;
		}
	}

	int idx = 3;

	while (idx * 2 <= num) {

		if (num % idx == 0) {
			primes.insert(idx);
			while (num % idx == 0) {
				num /= idx;
			}
		}
		idx += 2;
	}

	if (num != 1) primes.insert(num);
}

int distinctPrimeFactors(std::vector<int>& nums) {

	std::unordered_set<int> primes;

	for (int i = 0; i < nums.size(); i++) {
		Prime_Factorization(nums[i], primes);
	}

	return int(primes.size());
}
};
