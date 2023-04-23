#include <vector>

class Solution {
public:
int Fib_Solve(int n, std::vector<int>& cache) {

	if (n == 0 || n == 1) {
		return n;
	}

	if (cache[n] != -1) {
		return cache[n];
	}

	cache[n] = Fib_Solve(n - 2, cache) + Fib_Solve(n - 1, cache);

	return cache[n];
}


int fib(int n) {

	std::vector<int> cache(n + 1, -1);

	return Fib_Solve(n, cache);
}
};
