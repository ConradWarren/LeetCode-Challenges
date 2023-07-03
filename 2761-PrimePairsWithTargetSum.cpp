#include <vector>
#include <unordered_set>

class Solution {
public:
    
void Generate_Primes(int n, std::unordered_set<int>& primes){

	std::vector<bool> is_prime(n + 1, true);

	for (int i = 2; i * i <= n; i++) {

		if (is_prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			primes.insert(i);
		}
	}
}

std::vector<std::vector<int>> findPrimePairs(int n) {

	std::unordered_set<int> primes;
	std::vector<std::vector<int>> result;

	Generate_Primes(n, primes);

	for (auto& x : primes) {

		if (primes.find(n - x) != primes.end()) {

			if (x < n - x) {
				result.push_back({ x, n - x });
			}
			else {
				result.push_back({n - x, x });
			}
			if (n - x != x) {
				primes.erase(n - x);
			}
		}

	}
    std::sort(result.begin(), result.end());
	return result;
}
};
