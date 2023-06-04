#include <vector>

class Solution {
public:
long long matrixSumQueries(int n, std::vector<std::vector<int>>& queries) {

	std::vector<bool> filled_rows(n, false);
	std::vector<bool> filled_coloums(n, false);
	int used_rows = 0;
	int used_coloums = 0;
	long long sum = 0;

	for (int i = queries.size() - 1; i >= 0; i--) {

		if (queries[i][0] == 0 && !filled_rows[queries[i][1]]) {

			filled_rows[queries[i][1]] = true;

			used_rows++;

			sum += (long long)(queries[i][2]) * (long long)(n - used_coloums);
		}
		else if (queries[i][0] == 1 && !filled_coloums[queries[i][1]]) {

			filled_coloums[queries[i][1]] = true;

			used_coloums++;

			sum += (long long)(queries[i][2]) * (long long)(n - used_rows);
		}

		if (used_coloums == n || used_rows == n) break;
	}
	return sum;
}
};
