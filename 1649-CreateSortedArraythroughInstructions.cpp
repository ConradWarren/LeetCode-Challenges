#include <vector>

class Solution {
public:
void Merge_Sort(int low, int high, std::vector<std::pair<int, int>>& arr, std::vector<int>& left_edge_cost, std::vector<int>& right_edge_cost){

	if (low >= high) {
		return;
	}

	int mid = (low + high) / 2;
	Merge_Sort(low, mid, arr, left_edge_cost, right_edge_cost);
	Merge_Sort(mid+1,high, arr, left_edge_cost, right_edge_cost);
	int idx_1 = low;
	int idx_2 = mid+1;
	int cost = 0;

	while (idx_1 <= mid && idx_2 <= high) {
		if (arr[idx_1].first < arr[idx_2].first) {
			cost++;
			idx_1++;
		}
		else {
			left_edge_cost[arr[idx_2].second] += cost;
			idx_2++;
		}
	}
	while (idx_2 <= high) {
		left_edge_cost[arr[idx_2].second] += cost;
		idx_2++;
	}

	idx_1 = low;
	idx_2 = mid + 1;
	cost = 0;

	std::vector<std::pair<int, int>> temp(high - low + 1);

	while (idx_1 <= mid && idx_2 <= high) {
		if (arr[idx_1].first > arr[idx_2].first) {
			right_edge_cost[arr[idx_2].second] += (mid - idx_1 + 1);
			temp[idx_2 + idx_1 - low - mid-1] = arr[idx_2];
			idx_2++;
		}
		else {
			temp[idx_2 + idx_1 - low - mid - 1] = arr[idx_1];
			idx_1++;
		}
	}

	while (idx_1 <= mid) {
		temp[idx_2 + idx_1 - low - mid - 1] = arr[idx_1];
		idx_1++;
	}

	while (idx_2 <= high) {
		temp[idx_2 + idx_1 - low - mid-1] = arr[idx_2];
		idx_2++;
	}
	
	for (int i = 0; i < temp.size(); i++) {
		arr[low + i] = temp[i];
	}

}
int createSortedArray(std::vector<int>& instructions) {

	std::vector<int> left_edge_cost(instructions.size(), 0);
	std::vector<int> right_edge_cost(instructions.size(), 0);
	std::vector<std::pair<int, int>> sortable_arr(instructions.size());
	int cost = 0;


	for (int i = 0; i < instructions.size(); i++) {
		sortable_arr[i].first = instructions[i];
		sortable_arr[i].second = i;
	}

	Merge_Sort(0, instructions.size()-1, sortable_arr, left_edge_cost, right_edge_cost);

	for (int i = 0; i< left_edge_cost.size(); i++) {
		cost += (left_edge_cost[i] < right_edge_cost[i]) ? left_edge_cost[i] : right_edge_cost[i];
		cost %= 1000000007;
	}


	return cost;
}
};
