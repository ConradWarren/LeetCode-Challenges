#include <vector>

class Solution {
public:

int Get_Group(std::vector<int>& groups, int x) {

	if (groups[x] == x) {
		return x;
	}
	if (groups[x] == -1) {
		groups[x] = x;
		return groups[x];
	}
	groups[x] = Get_Group(groups, groups[x]);
	return groups[x];
}

void Union(int x, int y, std::vector<int>& groups, std::vector<int>& n_degree) {

	int group_x = Get_Group(groups, x);
	int group_y = Get_Group(groups, y);

	if (group_x == group_y) {
		return;
	}
	if (n_degree[group_x] >= n_degree[group_y]) {
		groups[group_x] = group_y;
		if(n_degree[group_x] == n_degree[group_y]) n_degree[group_x]++;
	}
	else {
		groups[group_y] = group_x;
	}
}

int largestComponentSize(std::vector<int>& nums) {
	
	std::vector<int> groups;
	std::vector<int> group_counts;
	std::vector<int> n_degree;
	int largest_num = 0;
	int largest_group = 0;

	for (int i = 0; i < nums.size(); i++) {
		largest_num = (largest_num > nums[i]) ? largest_num : nums[i];
	}

	groups.resize(largest_num + 1, -1);
	group_counts.resize(largest_num + 1, 0);
	n_degree.resize(largest_num + 1, 1);

	for (int i = 0; i < nums.size(); i++) {
		for (int j = 2; j <= std::sqrt(nums[i]); j++) {
			if (nums[i] % j == 0) {
				Union(j, nums[i], groups, n_degree);
				Union(nums[i], nums[i]/j, groups, n_degree);
			}
		}
	}

	for (int i = 0; i < nums.size(); i++) {
		int group = Get_Group(groups, nums[i]);
		group_counts[group]++;
		largest_group = (largest_group > group_counts[group]) ? largest_group : group_counts[group];
	}

	return largest_group;
}
};
