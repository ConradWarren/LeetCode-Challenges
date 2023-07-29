#include <vector>

class Solution {
public:
double Solve_Probablity(int a, int b, std::vector<std::vector<double>>& cache) {

	if (b <= 0 && a <= 0) {
		return 0.5;
	}
	if (a <= 0) {
		return 1.0;
	}
	if (b <= 0) {
		return 0.0;
	}
	if (cache[a][b] != -1) {
		return cache[a][b];
	}

	double sum = 0;

	sum += Solve_Probablity(a-4, b, cache);
	sum += Solve_Probablity(a-3, b-1, cache);
	sum += Solve_Probablity(a-2, b-2, cache);
	sum += Solve_Probablity(a-1, b-3, cache);

	cache[a][b] = sum / 4.0;

	return sum/4.0;
}

double soupServings(int n) {

	if (n > 5000) {
		return 1.0;
	}

	n = (n % 25) ? (n / 25) + 1 : n / 25;
	std::vector<std::vector<double>> cache(n+1, std::vector<double>(n+1, -1));

	return Solve_Probablity(n, n, cache);
}
};
