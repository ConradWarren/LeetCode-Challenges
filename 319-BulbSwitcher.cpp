class Solution {
public:
int bulbSwitch(int n) {

	int buld = 1;
	int buld_count = 0;
	int offset = 3;
	while(buld <= n){
		buld_count++;
		buld += offset;
		offset += 2;
	}

	return buld_count;
}
};
