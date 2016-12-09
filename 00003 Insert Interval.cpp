#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}

};

struct compInterval {
	bool operator()(const Interval &a, const Interval &b) const {
		return a.start<b.start;
	}
};
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
{
	int i = 0;
	vector<Interval> result;
	// Insert intervals appeared before newInterval.
	while (i < intervals.size() && newInterval.start > intervals[i].end) {
		result.push_back(intervals[i++]);
	}

	// Merge intervals that overlap with newInterval.
	while (i < intervals.size() && newInterval.end >= intervals[i].start) {
		newInterval = { min(newInterval.start, intervals[i].start),
			max(newInterval.end, intervals[i].end) };
		++i;
	}
	result.push_back(newInterval);

	// Insert intervals appearing after newInterval.
	result.insert(result.end(), intervals.begin() + i, intervals.end());
	return result;
}

vector<Interval> myInsert(vector<Interval> &intervals, Interval newInterval)
{
	int i = 0, left = 0, right = intervals.size();
	vector<Interval> result;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (intervals[mid].start < newInterval.start) left = mid + 1;
		else right = mid;
	}


	if (left > 0)
	{
		i = left - 1;
		if (i>0)
			//insert intervals that are before insert position.
			result.insert(result.end(), intervals.begin(), intervals.begin() + i);
		while (i < intervals.size() && newInterval.start > intervals[i].end) {
			result.push_back(intervals[i++]);
		}
	}

	while (i < intervals.size() && newInterval.end >= intervals[i].start) {
		newInterval = { min(newInterval.start, intervals[i].start),
			max(newInterval.end, intervals[i].end) };
		++i;
	}
	result.push_back(newInterval);

	// Insert intervals appearing after newInterval.
	result.insert(result.end(), intervals.begin() + i, intervals.end());
	return result;
}



static bool myCompare(Interval it1, Interval it2) {
	return it1.start < it2.start;
}
vector<Interval> merge(vector<Interval>& intervals) {
	if (intervals.size() <= 1) return intervals;
	int cover = 0;
	vector<Interval> res;
	sort(intervals.begin(), intervals.end(), myCompare);
	res.push_back(intervals[0]);
	cover += (intervals[0].end - intervals[0].start+1);
	for (int i = 1; i < intervals.size(); ++i) {
		int pre_end = res.back().end;
		if (intervals[i].start > pre_end) 
		{
			res.push_back(intervals[i]);
			cover += (intervals[i].end - intervals[i].start+1);
		}
			
		else 
		{
			res.back().end = max(pre_end, intervals[i].end);
			cover += (res.back().end - pre_end);
		}
			
	}

	std::cout << "Total coverage: " << cover << endl;
	return res;
}




int main() {

	vector<Interval> intervals;
	//[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]
	intervals.push_back(Interval(3, 5));
	intervals.push_back(Interval(6, 7));
	intervals.push_back(Interval(12, 16));
	intervals.push_back(Interval(8, 10));
	intervals.push_back(Interval(1, 2));
	for (auto a : intervals)
	{
		std::cout << a.start << " " << a.end << endl;
	}

	std::cout << "end of original intervals." << endl;



	sort(intervals.begin(), intervals.end(), compInterval());
	for (auto a : intervals) 
	{
		std::cout << a.start << " " << a.end << endl;
	}
	std::cout << "end of sorted intervals." << endl;


	vector<Interval> intervals2;
	//[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]
	intervals2.push_back(Interval(1, 3));
	intervals2.push_back(Interval(2, 6));
	intervals2.push_back(Interval(8, 10));
	intervals2.push_back(Interval(15, 18));


	vector<Interval> res = merge(intervals2);
	for (auto a : res)
	{
		std::cout << a.start << " " << a.end << endl;
	}
	std::cout << "end of merged intervals." << endl;



	/*vector<Interval> res = myInsert(intervals, Interval(4, 9));
	for (auto a : res)
	{
		std::cout << a.start << " " << a.end << endl;
	}
	std::cout << "end of sorted intervals." << endl;*/

	return 0;
}

