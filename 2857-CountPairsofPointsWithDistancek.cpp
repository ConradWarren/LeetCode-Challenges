class Solution {
public:
int countPairs(std::vector<std::vector<int>>& coordinates, int k) {

	std::map<std::pair<int, int>, int> cache;
	int x = 0, y = 0;
	int result = 0;

	for (int i = 0; i < coordinates.size(); i++) {

		for (int j = 0; j <= k; j++) {

			x = coordinates[i][0] ^ j;
			y = coordinates[i][1] ^ (k - j);

			if (cache.find({ x, y }) != cache.end()) {
				result += cache[{x, y}];
			}
		}
		cache[{coordinates[i][0], coordinates[i][1]}]++;
	}

	return result;
}
};
