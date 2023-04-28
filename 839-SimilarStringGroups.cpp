#include <vector>
#include <string>

class Solution {
public:
bool Is_Similar(std::string& s1, std::string& s2) {

	int conflicts = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i]) {
			conflicts++;
			if (conflicts > 2) return false;
		}
	}
	return true;
}


void Depth_First_Search(std::vector<std::vector<int>>& adjancey_list, std::vector<bool>& nodes_visted, int current_node) {

	if (nodes_visted[current_node]) {
		return;
	}

	nodes_visted[current_node] = true;

	for (int i = 0; i < adjancey_list[current_node].size(); i++) {
		Depth_First_Search(adjancey_list, nodes_visted, adjancey_list[current_node][i]);
	}

}

int numSimilarGroups(std::vector<std::string>& strs) {

	std::vector<std::vector<int>> adjancey_list(strs.size());
	std::vector<bool> nodes_visted(strs.size(), false);
	int number_of_groups = 0;

	for (int i = 0; i < strs.size(); i++) {
		for (int j = i + 1; j < strs.size(); j++) {
			if (Is_Similar(strs[i], strs[j])) {
				adjancey_list[i].push_back(j);
				adjancey_list[j].push_back(i);
			}
		}
	}

	for (int i = 0; i < strs.size(); i++) {

		if (nodes_visted[i]) continue;
		
		Depth_First_Search(adjancey_list, nodes_visted, i);
		number_of_groups++;
	}

	return number_of_groups; 
}
};
