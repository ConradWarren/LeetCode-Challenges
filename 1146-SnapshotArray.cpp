class SnapshotArray {
public:

	SnapshotArray(int length) {
		cache.resize(length);
		current_snap_id = 0;
	}

	void set(int index, int val) {

		cache[index].push_back({ val, current_snap_id });

	}

	int snap() {
		current_snap_id++;

		return current_snap_id - 1;
	}

	int get(int index, int snap_id) {

		if (cache[index].empty()) {
			return 0;
		}

        int low =0; 
        int high = cache[index].size();
        int mid = (low + high)/2;

        while(low < high){
            
            if(cache[index][mid].second <= snap_id){
                low = mid+1;
            }else{
                high = mid;
            }
            mid = (low+ high)/2;
        }

		return (low > 0) ? cache[index][low-1].first : 0;
	}
private:
	std::vector<std::vector<std::pair<int, int>>> cache;
	int current_snap_id;
};
