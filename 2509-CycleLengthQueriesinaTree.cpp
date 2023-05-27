#include <vector>

class Solution {
public:
std::vector<int> cycleLengthQueries(int n, std::vector<std::vector<int>>& queries) {

	std::vector<int> result(queries.size());
	int node_1 = 0;
	int node_2 = 0;
	int count = 0;

	for (int i = 0; i < queries.size(); i++) {

		node_1 = queries[i][0];
		node_2 = queries[i][1];

		count = 1;
		while (node_1 != node_2) {

			if (node_1 > node_2) {
				node_1 /= 2;
				count++;
			}
			else {
				node_2 /= 2;
				count++;
			}
		}

		result[i] = count;
	}

	return result;
}
};
