// https://zxi.mytechroad.com/blog/math/leetcode-1185-day-of-the-week/
// 1970-1-1 is a Friday
inline bool leapYear(int y) {
  return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
class Solution {
public:
  string dayOfTheWeek(int day, int month, int year) {    
    vector<string> names = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    vector<int> days = {31, 28 + leapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum = 0;
    for (int i = 1970; i < year; ++i)
      sum += 365 + leapYear(i);    
    for (int i = 1; i < month; ++i)
      sum += days[i - 1];    
    sum += day;
    return names[(sum + 3) % 7];
  }
};
