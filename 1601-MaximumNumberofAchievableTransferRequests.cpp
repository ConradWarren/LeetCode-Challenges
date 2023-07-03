#include <vector>

class Solution {
public:
int Count_Valid(std::vector<std::vector<int>>& requsts, std::vector<int>& n_degree, int idx, int non_zero_count){

	if (idx >= requsts.size()) {
		
		return (non_zero_count == 0) ? 0 : INT_MIN;
	}

	int skip_request = Count_Valid(requsts, n_degree, idx + 1, non_zero_count);


	n_degree[requsts[idx][0]]--;
	non_zero_count += (n_degree[requsts[idx][0]] == 0) ? -1 : 0;
	non_zero_count += (n_degree[requsts[idx][0]] == -1) ? 1 : 0;

	n_degree[requsts[idx][1]]++;
	non_zero_count += (n_degree[requsts[idx][1]] == 0) ? -1 : 0;
	non_zero_count += (n_degree[requsts[idx][1]] == 1) ? 1 : 0;
	
	int take_request = Count_Valid(requsts, n_degree, idx + 1, non_zero_count)+1;

	n_degree[requsts[idx][0]]++;
	n_degree[requsts[idx][1]]--;
	
	return (skip_request > take_request) ? skip_request : take_request;
}

int maximumRequests(int n, std::vector<std::vector<int>>& requests) {

	std::vector<int> n_degree(n, 0);
	return Count_Valid(requests, n_degree, 0, 0);
}
};
