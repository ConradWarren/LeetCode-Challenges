#include <vector>
#include <unordered_map>

class Solution {
public:
int digArtifacts(int n, std::vector<std::vector<int>>& artifacts, std::vector<std::vector<int>>& dig) {

	std::vector<std::vector<int>> grid(n, std::vector<int>(n, 0));
	std::unordered_map<int, int> uncovered_artifacts;
	int result = 0;

	for (int i = 0; i < artifacts.size(); i++) {
		for (int j = artifacts[i][0]; j <= artifacts[i][2]; j++) {
			for (int z = artifacts[i][1]; z <= artifacts[i][3]; z++) {
				grid[j][z] = (i + 1);
				uncovered_artifacts[i + 1]++;
			}
		}
	}

	for (int i = 0; i < dig.size(); i++) {

		if (grid[dig[i][0]][dig[i][1]]) {
			uncovered_artifacts[grid[dig[i][0]][dig[i][1]]]--;
			result += (!uncovered_artifacts[grid[dig[i][0]][dig[i][1]]]) ? 1 : 0;
			grid[dig[i][0]][dig[i][1]] = 0;
		}
	}
	return result;
}

};
