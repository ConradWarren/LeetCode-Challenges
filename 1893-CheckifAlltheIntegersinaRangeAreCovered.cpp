class Solution {
public:
bool isCovered(std::vector<std::vector<int>>& ranges, int left, int right) {

	std::sort(ranges.begin(), ranges.end());

	for (int i = 0; i < ranges.size(); i++) {
		if (ranges[i][0] <= left && ranges[i][1] >= left) left = ranges[i][1] + 1;
	}

	return (left > right) ? true : false;
}
};
