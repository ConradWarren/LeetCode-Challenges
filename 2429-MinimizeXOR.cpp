class Solution {
public:
int minimizeXor(int num1, int num2) {

	int number_of_bits = 0;
	int num_x = 0;

	for (int i = 30; i >= 0; i--) {
		if (num2 & (1 << i)) number_of_bits++;
	}

	for (int i = 30; i >= 0; i--) {

		if (number_of_bits == 0) return num_x;
		
		if (num1 & (1 << i)) {
			num_x |= (1 << i);
			number_of_bits--;
		}
	}

	for (int i = 0; i <= 30; i++) {

		if (number_of_bits == 0) return num_x;
		
		if ((num1 & (1 << i)) == 0) {
			number_of_bits--;
			num_x |= (1 << i);
		}
	}

	return num_x;
}
};
