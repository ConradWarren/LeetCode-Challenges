class MyHashSet {
public:
	
	bool arr[1000001];

	MyHashSet() {
		memset(arr, false, sizeof(arr));
	}

	void add(int key) {

		arr[key] = true;

	}

	void remove(int key) {
		arr[key] = false;
	}

	bool contains(int key) {
		return arr[key];
	}
};
