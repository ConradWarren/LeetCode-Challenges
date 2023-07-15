#include <vector>

class Solution {
public:
int earliestFullBloom(std::vector<int>& plantTime, std::vector<int>& growTime) {

	std::vector<std::pair<int, int>> nums(plantTime.size());
	int time = 0;
	int current_extra_time = 0;

	for (int i = 0; i < plantTime.size(); i++) {
		nums[i].first = growTime[i];
		nums[i].second = plantTime[i];
	}

	std::sort(nums.rbegin(), nums.rend());

	for (int i = 0; i < nums.size(); i++) {

		time += nums[i].second;
		current_extra_time = (nums[i].first > current_extra_time - nums[i].second) ? nums[i].first : current_extra_time - nums[i].second;
	}

	time += current_extra_time;
	

	return time;
}
};
