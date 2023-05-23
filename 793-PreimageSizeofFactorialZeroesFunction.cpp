class Solution {
public:
long trailing_zeros(long k) {

	long result = 0;

	while (k) {
		k /= 5;
		result += k;
	}

	return result;
}

int preimageSizeFZF(int k) {
	
	long low = 0;
	long high = 100;
	long mid = 0;
	long zeros = trailing_zeros(high);

	while (zeros < k) {
		low = high;
		high *= 10;
		zeros = trailing_zeros(high);
	}
	
	while (low < high) {

		mid = (low + high) / 2;
		zeros = trailing_zeros(mid);

		if (zeros == k) return 5;
		
		if (zeros < k) low = mid + 1;
		
		else high = mid;
	}
	
	return 0;
}
};
