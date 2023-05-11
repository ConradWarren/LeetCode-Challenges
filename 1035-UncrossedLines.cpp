#include <vector>

class Solution {
public:
int Solve_Max_Line(std::vector<int>& nums1,std::vector<int>& nums2, int idx_1, int idx_2, std::vector<std::vector<int>>& cache) {

	if(idx_1 >= nums1.size() || idx_2 >= nums2.size()){
		return 0;
	}

	if (cache[idx_1][idx_2] != -1) {
		return cache[idx_1][idx_2];
	}


	int most_line = 0;

	int skips = Solve_Max_Line(nums1, nums2, idx_1+1, idx_2, cache);

	most_line = (most_line > skips) ? most_line : skips;

	for (int i = idx_2; i < nums2.size(); i++) {
		if (nums1[idx_1] == nums2[i]) {
			int temp = 1 + Solve_Max_Line(nums1, nums2, idx_1 + 1, i + 1, cache);
			most_line = (most_line > temp) ? most_line : temp;
		}
	}

	cache[idx_1][idx_2] = most_line;

	return cache[idx_1][idx_2];
}

int maxUncrossedLines(std::vector<int>& nums1, std::vector<int>& nums2) {

	std::vector<std::vector<int>> cache(nums1.size(), std::vector<int>(nums2.size(), -1));
	
	return Solve_Max_Line(nums1, nums2, 0, 0, cache);
}
};
