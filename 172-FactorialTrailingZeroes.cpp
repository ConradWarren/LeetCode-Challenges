class Solution {
public:
int trailingZeroes(int n) {

	int multiple_of_five = 5;
	int result = 0;

	while (n / multiple_of_five) {

		result += n / multiple_of_five;
		multiple_of_five *= 5;

	}
	return result;
}
};
