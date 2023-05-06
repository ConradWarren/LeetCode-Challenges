#include <vector>

class Solution {
public:
int candy(std::vector<int>& ratings) {

	if (ratings.size() == 1) {
		return 1;
	}

	std::vector<int> distributed_candy(ratings.size(), 0);
	std::vector<std::pair<int, int>> sortable_ratings(ratings.size());

	for (int i = 0; i < sortable_ratings.size(); i++) {
		sortable_ratings[i].first = ratings[i];
		sortable_ratings[i].second = i;
	}

	std::sort(sortable_ratings.begin(), sortable_ratings.end());

	for (int i = 0; i < sortable_ratings.size(); i++) {

		int idx = sortable_ratings[i].second;

		if (idx == 0) {
			if (ratings[idx + 1] == ratings[idx]) {
				distributed_candy[idx] = 1;
			}
			else {
				distributed_candy[idx] = distributed_candy[idx + 1] + 1;
			}
		}
		else if (idx == ratings.size()-1) {

			if (ratings[idx - 1] == ratings[idx]) {
				distributed_candy[idx] = 1;
			}
			else {
				distributed_candy[idx] = distributed_candy[idx - 1] + 1;
			}
		}
		else {

			if (ratings[idx] == ratings[idx + 1] && ratings[idx] == ratings[idx - 1]) {
				distributed_candy[idx] = 1;
			}
			else if (ratings[idx] == ratings[idx + 1]) {
				distributed_candy[idx] = distributed_candy[idx - 1] + 1;
			}
			else if (ratings[idx] == ratings[idx-1]) {
				distributed_candy[idx] = distributed_candy[idx + 1] + 1;
			}
			else {
				distributed_candy[idx] = (distributed_candy[idx + 1] > distributed_candy[idx - 1]) ? distributed_candy[idx + 1] + 1 : distributed_candy[idx - 1] + 1;
			}
		}
	}
	return std::accumulate(distributed_candy.begin(), distributed_candy.end(), 0);
}
};
