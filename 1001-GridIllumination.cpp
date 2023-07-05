class Solution {
public:
std::vector<int> gridIllumination(long long n, std::vector<std::vector<int>>& lamps, std::vector<std::vector<int>>& queries) {

	std::unordered_map<int, int> illumated_postive_daigonals;
	std::unordered_map<int, int> illumated_negative_daigonals;
	std::unordered_map<int, int> illumated_rows;
	std::unordered_map<int, int> illumated_coloums;
	std::unordered_set<long long> lamp_set;
	std::vector<int> result(queries.size(), 0);
	std::vector<std::pair<int, int>> directions = { {0,0},{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} };
	long long x = 0;
	long long y = 0;

	for (int i = 0; i < lamps.size(); i++) {

		if (lamp_set.find((long long)(lamps[i][0] * n) +lamps[i][1]) ==lamp_set.end()) {
			lamp_set.insert((lamps[i][0] * n) + lamps[i][1]);
			illumated_rows[lamps[i][0]]++;
			illumated_coloums[lamps[i][1]]++;
			illumated_negative_daigonals[lamps[i][0] - lamps[i][1]]++;
			illumated_postive_daigonals[lamps[i][1] + lamps[i][0]]++;
		}
	}

	for (int i = 0; i < queries.size(); i++) {

		if (illumated_rows[queries[i][0]] > 0) {
			result[i] = 1;
		}
		else if (illumated_coloums[queries[i][1]] > 0) {
			result[i] = 1;
		}
		else if (illumated_postive_daigonals[queries[i][1]+queries[i][0]] > 0) {
			result[i] = 1;
		}
		else if (illumated_negative_daigonals[queries[i][0]-queries[i][1]] > 0) {
			result[i] = 1;
		}

		for (int j = 0; j < directions.size(); j++) {

			y = queries[i][0] + directions[j].first;
			x = queries[i][1] + directions[j].second;
			
			if (x < 0 || y < 0 || x >= n || y >= n) {
				continue;
			}

			if (lamp_set.find((y * n) + x) != lamp_set.end()) {
				lamp_set.erase((y * n) + x);
				illumated_rows[y]--;
				illumated_coloums[x]--;
				illumated_negative_daigonals[y - x]--;
				illumated_postive_daigonals[y+x]--;
			}
		}
	}


	return result;
}
};
