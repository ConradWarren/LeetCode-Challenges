#include <vector>

class Solution {
public:
double Valid_Move_Counter(std::vector<std::pair<int, int>>& directions, int n, int k, int row, int coloumn, std::vector<std::vector<double>>& cache) {

	if (row < 0 || coloumn < 0 || row >= n || coloumn >= n) {
		return 0.0;
	}

	if (k == 0) {
		return 1.0;
	}

	if (cache[(row * n) + coloumn][k] != -1.0) {
		return cache[(row * n)+coloumn][k];
	}

	double sum = 0;
	for (int i = 0; i < directions.size(); i++) {
		sum += Valid_Move_Counter(directions, n, k - 1, row + directions[i].first, coloumn + directions[i].second, cache);
	}

	cache[(row * n) + coloumn][k] = (sum / 8.0);

	return (sum / 8.0);
}

double knightProbability(int n, int k, int row, int column) {

	std::vector<std::pair<int, int>> directions = { {2,1}, {2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2} };
	std::vector<std::vector<double>> cache(n * n, std::vector<double>(k + 1, -1.0));

	return Valid_Move_Counter(directions, n, k, row, column, cache);
}
};
