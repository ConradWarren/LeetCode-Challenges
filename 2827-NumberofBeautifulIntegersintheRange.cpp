#include <cmath>

class Solution {
public:
int numberOfBeautifulIntegers(int low, int high, int k) {
	
	int num = (low % k == 0) ? low : (k - (low % k)) + low;
	int length = 0;
	int result = 0;
	int current = 0;
	int even_count = 0;
	int odd_count = 0;

	for (num; num <= high; num += k) {
		current = num;
		while (current){

			if ((current % 10) % 2) {
				odd_count++;
			}
			else {
				even_count++;
			}
			current /= 10;
			length++;
		}

		if (odd_count == even_count) {
			result++;
		}
		odd_count = 0;
		even_count = 0;

		if (length % 2 == 1) {
			num = std::pow(10, length);
			num = (num % k == 0) ? num : (k - (num % k)) + num;
			num -= k;
		}
		length = 0;
	}

	return result;
}
};
