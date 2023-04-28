#include <vector>
#include <unordered_map>

class Solution {
public:
std::vector<int> majorityElement(std::vector<int>& nums) {

	int limit = nums.size() / 3;
	std::unordered_map<int, int> occurance_map;
	std::vector<int> result;

	for (int i = 0; i < nums.size(); i++) {
		occurance_map[nums[i]]++;
	}

	for (auto& num : occurance_map) {
		if (num.second > limit) {
			result.push_back(num.first);
		}
	}

	return result;
}

};
