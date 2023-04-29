class Solution {
public:
int kthFactor(int n, int k) {

	for (int i = 1; i * 2 <= n; i++) {

		if (n % i == 0) {
			k--;
			if (k == 0) return i;
		}
	}

	if (k == 1) return n;
	

	return -1;
}
};
