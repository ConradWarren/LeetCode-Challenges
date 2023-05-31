#include <string>
#include <unordered_map>

class UndergroundSystem {
public:
	UndergroundSystem() {

	}

	void checkIn(int id, std::string stationName, int t) {
		time_stamps[id] = t;
		entered_stations[id] = stationName;
	}

	void checkOut(int id, std::string stationName, int t) {
		std::string first_station = entered_stations[id];
		int time_diff = t - time_stamps[id];
		time_sums[first_station][stationName] += time_diff;
		frequency[first_station][stationName]++;
	}

	double getAverageTime(std::string startStation, std::string endStation) {

		return double(time_sums[startStation][endStation]) / double(frequency[startStation][endStation]);
	}

private:

	std::unordered_map<int, int> time_stamps;
	std::unordered_map<int, std::string> entered_stations;
	std::unordered_map<std::string, std::unordered_map<std::string, int>> time_sums;
	std::unordered_map<std::string, std::unordered_map<std::string, int>> frequency;
};
