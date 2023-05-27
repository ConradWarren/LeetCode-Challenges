#include <vector>

class Solution {
public:
std::vector<int> Prime_Factors(int n) {

	std::vector<int> result;

	while (n % 2 == 0) {
		result.push_back(2);
		n /= 2;
	}

	int idx = 3;

	while (idx * idx <= n) {

		if (n % idx == 0) {
			result.push_back(idx);
			n /= idx;
		}
		else idx += 2;
	}

	if (n != 1) result.push_back(n);

	return result;
}


int smallestValue(int n) {

	std::vector<int> primes = Prime_Factors(n);
	int sum = 0;
	int last_sum = -1;

	while (primes.size() > 1) {
		sum = std::accumulate(primes.begin(), primes.end(), 0);
		if (sum == last_sum) return sum;
		last_sum = sum;
		primes = Prime_Factors(sum);
	}

	return primes.front();
}
};
