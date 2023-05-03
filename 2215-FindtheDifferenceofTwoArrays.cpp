#include <vector>
#include <unordered_map>

class Solution {
public:
std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {

	std::unordered_map<int, int> occurance_map;
	std::vector<std::vector<int>> result(2);

	for (int i = 0; i < nums1.size(); i++) {
		occurance_map[nums1[i]] = 1;
	}

	for (int i = 0; i < nums2.size(); i++) {
		if (occurance_map[nums2[i]] == 1) {
			occurance_map[nums2[i]] = -1;
		}
		else if(occurance_map[nums2[i]] != -1) {
			occurance_map[nums2[i]] = 2;
		}
	}

	for (auto& num : occurance_map) {
		if (num.second == 1) {
			result[0].push_back(num.first);
		}
		else if (num.second == 2) {
			result[1].push_back(num.first);
		}
	}

	return result;
}
};
