

#include <vector>
using namespace std;


class TimeClock_Row {
	private:
		int id; // pin
		int in; // time out
		int out; // time in
		bool otc; // "on the clock"
	public:
		TimeClock_Row TimeClock_Row(string, int, int, bool);
};

