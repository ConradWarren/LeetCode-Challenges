#include <vector>
#include <unordered_map>

class Solution {
public:
int mostFrequentEven(std::vector<int>& nums) {

	std::unordered_map<int, int> num_occurances;
	int most_frequent_num = -1;
	int highest_occurances = -1;


	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] % 2 == 0) {
			num_occurances[nums[i]]++;
		}
	}

	for (auto& num : num_occurances) {
		if (num.second > highest_occurances) {
			most_frequent_num = num.first;
			highest_occurances = num.second;
		}
		else if (num.second == highest_occurances && num.first < most_frequent_num) {
			most_frequent_num = num.first;
		}
	}

	return most_frequent_num;
}
};
