class Solution {
public:
int makeTheIntegerZero(int _num1, int _num2) {

	if (_num1 == 0) {
		return 0;
	}

	int operation_count = 1;
	long long num_1 = _num1;
	long long num_2 = _num2;
	long long idx = 0;
	int bit_count = 0;

	while (operation_count < 60) {

		num_1 -= num_2;

		if (num_1 <= 0) {
			return -1;
		}

		idx = 1;
		bit_count = 0;
		while (idx <= num_1) {

			if (!(idx & num_1)) {
				idx <<= 1;
				continue;
			}
			idx <<= 1;
			bit_count++;
		}

		if (bit_count <= operation_count && num_1 >= operation_count) {
			return operation_count;
		}
		operation_count++;
	}

	return -1;
}
};
