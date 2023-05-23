class DataStream {
public:

	DataStream(int value_input, int k_input) {

		value = value_input;
		count = 0;
		k = k_input;
	}

	bool consec(int num) {

		count = (num == value) ? count + 1 : 0;

		return (count >= k) ? true : false;
	}

private:
	int k;
	int count;
	int value;
};
