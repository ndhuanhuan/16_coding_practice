// https://leetcode.com/problems/distribute-candies-to-people/discuss/323298/C%2B%2B-brute-force
vector<int> distributeCandies(int c, int num) {
  vector<int> res(num);
  for (auto i = 0; c > 0; c -= ++i) 
    res[i % num] += min(i + 1, c);
  return res;
}
