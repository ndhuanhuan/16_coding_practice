// https://zxi.mytechroad.com/blog/divide-and-conquer/leetcode-1274-number-of-ships-in-a-rectangle/
class Solution {
public:
  // Modify the interface to pass sea as a reference.
  int countShips(Sea& sea, vector<int> topRight, vector<int> bottomLeft) {
    int x1 = bottomLeft[0], y1 = bottomLeft[1];
    int x2 = topRight[0], y2 = topRight[1];    
    if (x1 > x2 || y1 > y2 || !sea.hasShips(topRight, bottomLeft))
      return 0;
    if (x1 == x2 && y1 == y2)
      return 1;
    int xm = x1 + (x2 - x1) / 2;
    int ym = y1 + (y2 - y1) / 2;
    return countShips(sea, {xm, ym}, {x1, y1}) + countShips(sea, {xm, y2}, {x1, ym + 1})
         + countShips(sea, {x2, ym}, {xm + 1, y1}) + countShips(sea, {x2, y2}, {xm + 1, ym + 1});
  }
};
