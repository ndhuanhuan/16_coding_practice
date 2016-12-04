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
		cout << a.start << " " << a.end << endl;
	}

	cout << "end of original intervals." << endl;



	sort(intervals.begin(), intervals.end(), compInterval());
	for (auto a : intervals) 
	{
		cout << a.start << " " << a.end << endl;
	}
	cout << "end of sorted intervals." << endl;




	vector<Interval> res = myInsert(intervals, Interval(4, 9));
	for (auto a : res)
	{
		cout << a.start << " " << a.end << endl;
	}
	cout << "end of sorted intervals." << endl;

	return 0;
}

