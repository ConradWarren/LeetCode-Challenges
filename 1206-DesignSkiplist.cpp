class Skiplist {
public:

	int arr[20001];

	Skiplist() {
		memset(arr, 0, sizeof(arr));
	}

	bool search(int target) {
		if (arr[target]) {
			return true;
		}
		return false;
	}

	void add(int num) {
		arr[num]++;
	}

	bool erase(int num) {
		if (arr[num]) {
			arr[num]--;
			return true;
		}
		return false;
	}
};
