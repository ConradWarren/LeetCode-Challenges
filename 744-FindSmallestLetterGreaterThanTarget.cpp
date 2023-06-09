#include <vector>

class Solution {
public:
char nextGreatestLetter(std::vector<char>& letters, char target) {

	int low = 0;
	int high = letters.size();
	int mid = (low + high) / 2;

	while (low < high) {

		if (letters[mid] > target) {
			high = mid;
		}
		else {
			low = mid + 1;
		}

		mid = (low + high) / 2;
	}

	return (low >= letters.size()) ? letters.front() : letters[low];
}
};
