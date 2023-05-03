#include <vector>
#include <unordered_map>

int subarraySum(std::vector<int>& nums, int k) {

	std::vector<int> sub_array_sums(nums.size(), 0);
	std::unordered_map<int, std::vector<int>> sum_occurances;
	int result = 0;

	sub_array_sums[0] = nums[0];
	sum_occurances[sub_array_sums[0]].push_back(0);

	for (int i = 1; i < nums.size(); i++) {
		sub_array_sums[i] = nums[i] + sub_array_sums[i - 1];
		sum_occurances[sub_array_sums[i]].push_back(i);
	}
	
	if (sum_occurances.find(k) != sum_occurances.end()) {
		result += sum_occurances[k].size();
	}

	for (auto& x : sum_occurances) {
		if (sum_occurances.find(x.first - k) != sum_occurances.end()) {
			int idx_1 = 0;
			int idx_2 = 0;
			while (idx_1 < sum_occurances[x.first - k].size() && idx_2 < x.second.size()) {
				if (sum_occurances[x.first - k][idx_1] < x.second[idx_2]) {
					idx_1++;
					result += x.second.size() - idx_2;
				}
				else idx_2++;
			}
		}
	}

	return result;
}
