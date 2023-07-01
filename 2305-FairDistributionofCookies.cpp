#include <vector>

class Solution {
public:
int Solve_Min_Maxuim(std::vector<int>& nums, int idx, int maximum, std::vector<int>& distrabution) {

	if (idx >= nums.size()) {
		return maximum;
	}
	
	int current_best = INT_MAX;

	for (int i = 0; i < distrabution.size(); i++) {
		
		distrabution[i] += nums[idx];

		int current = Solve_Min_Maxuim(nums, idx+1, max(maximum, distrabution[i]), distrabution);
		
		current_best = (current_best < current) ? current_best : current;

		distrabution[i] -= nums[idx];
	}
	
	return current_best;
}


int distributeCookies(std::vector<int>& cookies, int k) {

	std::vector<int> distrabution(k, 0);

	return Solve_Min_Maxuim(cookies, 0, 0, distrabution);
}
};
