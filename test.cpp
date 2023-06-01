class DataStream {
public:

	int valid_count;
	int value;
	int k;

	DataStream(int input_value, int input_k) {
		k = input_k;
		value = input_value;
		valid_count = 0;
	}

	bool consec(int num) {

		if (num == value) valid_count++;
		
		else valid_count = 0;
        
		return (valid_count >= k);
	}
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
