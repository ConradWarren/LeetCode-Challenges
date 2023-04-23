#include <vector>

class Solution {
public:
int Tribonacci_Solve(int n, std::vector<int>& cache) {

	if (n < 2) {
		return n;
	}
	if (n == 2) {
		return 1;
	}

	if (cache[n] != -1) {
		return cache[n];
	}

	cache[n] = Tribonacci_Solve(n - 3, cache) + Tribonacci_Solve(n - 2, cache) + Tribonacci_Solve(n - 1, cache);

	return cache[n];
}
int tribonacci(int n) {
	
	std::vector<int> cache(n + 1, -1);

	return Tribonacci_Solve(n, cache);
}
};
