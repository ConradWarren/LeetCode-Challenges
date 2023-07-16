#include <vector>
#include <unordered_map>

class Solution {
public:
void Find_Smallest_Team(std::vector<int>& staff_bitmasks, int idx, int bitmask, std::vector<int>& path, std::vector<int>& result, std::vector<std::vector<int>>& cache) {

	if (bitmask == 0) {
		if (path.size() < result.size() || result.empty()) {
			result = path;
		}
		return;
	}

	if (idx >= staff_bitmasks.size()) {
		return;
	}

	if (cache[bitmask][idx] <= path.size()) {
		return;
	}
	cache[bitmask][idx] = path.size();

	Find_Smallest_Team(staff_bitmasks, idx + 1, bitmask, path, result, cache);

	path.push_back(idx);

	Find_Smallest_Team(staff_bitmasks, idx + 1, bitmask & ~(staff_bitmasks[idx]), path, result, cache);

	path.pop_back();
}

std::vector<int> smallestSufficientTeam(std::vector<std::string>& req_skills, std::vector<std::vector<std::string>>& people) {

	std::unordered_map<std::string, int> skill_map;
	std::vector<int> staff_bitmasks(people.size(), 0);
	int skill_bitmask = (1 << int(req_skills.size())) - 1;
	std::vector<int> result;
	std::vector<int> path;
	std::vector<std::vector<int>> cache(skill_bitmask + 1, std::vector<int>(people.size(), INT_MAX));


	for (int i = 0; i < req_skills.size(); i++) {
		skill_map[req_skills[i]] = i;
	}

	for (int i = 0; i < people.size(); i++) {
		for (int j = 0; j < people[i].size(); j++) {
			staff_bitmasks[i] |= (1 << skill_map[people[i][j]]);
		}
	}

	Find_Smallest_Team(staff_bitmasks, 0, skill_bitmask, path, result, cache);

	return result;
}
};
