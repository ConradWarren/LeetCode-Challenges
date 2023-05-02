#include <vector>

class Solution {
public:
int findTheWinner(int n, int k) {

	std::vector<bool> removed(n, false);
	int removed_count = 0;
	int temp_k = k;

	while (removed_count < n - 1) {
		
		for (int i = 0; i < n; i++) {

			if (removed[i]) {
				continue;
			}

			temp_k--;
			if (temp_k == 0) {
				removed_count++;
				removed[i] = true;
				temp_k = k;
				if (removed_count == n - 1) {
					break;
				}
			}
		}
	}



	auto it = std::find(removed.begin(), removed.end(), false);



	return (it - removed.begin())+1;
}
};
