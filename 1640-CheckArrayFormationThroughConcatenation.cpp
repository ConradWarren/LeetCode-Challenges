#include <vector>

class Solution {
public:
bool canFormArray(std::vector<int>& arr, std::vector<std::vector<int>>& pieces) {

	std::unordered_map<int, int> pieces_idx_map;
	std::vector<int> pieces_arr;

	for (int i = 0; i < pieces.size(); i++) {
		pieces_idx_map[pieces[i][0]] = i;
	}

	for (int i = 0; i < arr.size(); i++) {

		if (pieces_idx_map.find(arr[i]) == pieces_idx_map.end()) {
			continue;
		}

		for (int j = 0; j < pieces[pieces_idx_map[arr[i]]].size(); j++) {
			pieces_arr.push_back(pieces[pieces_idx_map[arr[i]]][j]);
		}

	}

	return (arr == pieces_arr) ? true : false;
}
};
