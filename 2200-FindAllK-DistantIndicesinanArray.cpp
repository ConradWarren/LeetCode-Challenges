#include <vector>

class Solution {
public:
std::vector<int> findKDistantIndices(std::vector<int>& nums, int key, int k) {

	std::vector<std::pair<int, int>> valid_ranges;
	std::vector<int> result;

	for (int i = 0; i < nums.size(); i++) {
		
		if (nums[i] == key) {

			if (valid_ranges.empty()) {
				valid_ranges.push_back({ 0,0 });
				valid_ranges[0].first = (0 > i - k) ? 0 : i - k;
				valid_ranges[0].second = (nums.size() - 1 < i + k) ? nums.size() - 1 : i + k;
			}
			else if(valid_ranges.back().second >= i - k){
				valid_ranges.back().second = (nums.size() - 1 < i + k) ? nums.size() - 1 : i + k;
			}
			else {
				valid_ranges.push_back({ i - k, 0 });
				valid_ranges.back().second = (nums.size() - 1 < i + k) ? nums.size() - 1 : i + k;
			}
		}
	}

	for (int i = 0; i < valid_ranges.size(); i++) {

		for (int j = valid_ranges[i].first; j <= valid_ranges[i].second; j++) {
			result.push_back(j);
		}

	}

	return result;
}
};
