#include <vector>

class Solution {
public:
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {

	int low = 0;
	int high = matrix.size() * matrix[0].size();
	int mid = (low + high) / 2;

	while (low < high) {

		if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] == target) {
			return true;
		}

		if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] < target) {
			low = mid + 1;
		}
		else {
			high = mid;
		}

		mid = (low + high) / 2;
	}

	return false;
}
};
