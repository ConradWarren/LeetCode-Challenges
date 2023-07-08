#include <vector>

class Solution {
public:
std::vector<long long> countBlackBlocks(int m, int n, std::vector<std::vector<int>>& coordinates) {

	std::vector<long long> result(5, 0);
	std::unordered_set<long long> valid_squares;
	std::unordered_set<long long> squares_to_check;
	std::vector<std::pair<int, int>> directions = { {0, 0},{-1, 0},{-1, -1},{0, -1} };
	int count = 0;
	long long x = 0;
	long long y = 0;
	long long total_squares = (long long)(m - 1) * (long long)(n - 1);


	for (int i = 0; i < coordinates.size(); i++) {

		valid_squares.insert(((long long)(coordinates[i][0]) * (long long)(n)) + coordinates[i][1]);

		for (int j = 0; j < directions.size(); j++) {
			x = coordinates[i][1] + directions[j].second;
			y = coordinates[i][0] + directions[j].first;

			if (y < 0 || x < 0 || x >= n - 1 || y >= m - 1) {
				continue;
			}
			squares_to_check.insert((y * n) + x);
		}
	}

	for (auto& square : squares_to_check) {

		total_squares--;
		count = 0;

		if (valid_squares.find(square) != valid_squares.end()) count++;
		
		if (valid_squares.find(square + 1) != valid_squares.end()) count++;
		
		if (valid_squares.find(square + n) != valid_squares.end()) count++;
		
		if (valid_squares.find(square + n + 1) != valid_squares.end()) count++;
		
		result[count]++;
	}

	result[0] = total_squares;

	return result;
}
};
