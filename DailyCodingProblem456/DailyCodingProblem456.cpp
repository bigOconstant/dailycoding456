// DailyCodingProblem456.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include < ctime >
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
enum Ttype{entry,exitE};
struct Entry {
	int timestamp;
	int count;
	Ttype type;

	friend std::ostream& operator<<(std::ostream& output, const Entry& D) {
		output << "timestamp : " << D.timestamp << " Count : " << D.count;
		if (D.type == entry) {
			output << " type:entry";
		}
		else if (D.type == exitE) {
			output << " type:exit";
		}
		else {
			output << " type:none";
		}
		return output;
	}
};

int main()
{
	
	Entry t = { 1,1,entry };
	std::vector<Entry> entryExitList;
	entryExitList.push_back({1,1,entry});
	entryExitList.push_back({2,3,entry});
	entryExitList.push_back({3,1,exitE});
	entryExitList.push_back({5,10,entry });

	std::sort(entryExitList.begin(), entryExitList.end(), [](const Entry& a, const Entry& b)-> bool {return a.timestamp < b.timestamp; });

	int start = 0, end = 0, total = 0, largest = 0, last = 0;
	std::pair<int, int> startEndLargest = {0,0};

	for (auto it = entryExitList.begin(); it < entryExitList.end(); ++it) {
		int current = total;
		if ((*it).type == entry) {
			current += (*it).count;
		}
		else {
			current -= (*it).count;
		}
		if (current > largest) {
			largest = current;
			startEndLargest.first = last;
			startEndLargest.second = (*it).timestamp;
		}

		last = (*it).timestamp;

		cout << "t:" << (*it) << endl;

	}

	cout << "start:" << startEndLargest.first << " end:" << startEndLargest.second << " total:" << largest;
	return 0;
}
