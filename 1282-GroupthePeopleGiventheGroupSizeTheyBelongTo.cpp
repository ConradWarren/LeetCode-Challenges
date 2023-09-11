class Solution {
public:
std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes) {
	
	std::unordered_map<int, std::vector<int>> group_map;
	std::vector<std::vector<int>> result;
	std::vector<int> current_group;


	for (int i = 0; i < groupSizes.size(); i++) {
		group_map[groupSizes[i]].push_back(i);
	}

	for (auto &x : group_map) {
		for (int i = 0; i < x.second.size() / x.first; i++) {
			result.push_back({});
			for (int j = i * x.first; j < (i * x.first) + x.first; j++) {
				result.back().push_back(x.second[j]);
			}
		}
	}

	return result;
}
};
