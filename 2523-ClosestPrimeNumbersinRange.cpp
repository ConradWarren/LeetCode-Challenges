#include <vector>

class Solution {
public:
std::vector<int> closestPrimes(int left, int right) {

	std::vector<bool> prime(right + 1, true);
	std::vector<int> result(2, -1);
	int last_prime = -1;
	int min_distance = INT_MAX;
	int current_distance = 0;

	prime[0] = false;
	prime[1] = false;

	for (long long i = 2; i <= right; i++) {

		if (!prime[i]) continue;
		
		for (long long j = i * i; j <= right; j += i) {
			prime[j] = false;
		}
	}

	for (int i = left; i <= right; i++) {

		if (prime[i] && last_prime != -1 && (i - last_prime) < min_distance) {
			min_distance = i - last_prime;
			result[0] = last_prime;
			result[1] = i;
			last_prime = i;
		}
		else if (prime[i]) last_prime = i;
	}
	return result;
}
};
