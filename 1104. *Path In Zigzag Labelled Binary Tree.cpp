// https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/discuss/323293/C%2B%2B-O(log-n)
class Solution {
public:
    vector<int> pathInZigZagTree(int label, int level = 0) {
      while (1 << level <= label) ++level;
      vector<int> res(level);
      for(; label >= 1; label /= 2, --level) {
        res[level - 1] = label;
        
        label = (1 << level) - 1 - label + (1 << (level - 1));
         // cout<< "label " << label << "level" << level << (1 << level) << endl;
      }
      return res;
    }
};

// label = (1 << level) - 1 - label + (1 << (level - 1));
// I was confused that part too and tried to understand it this way: for the nodes in the same row, each pair of two nodes at the symmetrical position has the same sum. Like in the 3rd row the sum of each pair of nodes (4, 7), (5, 6) is 11. As @votrubac said "The maximum label in the level is 1 << level - 1, and the minimum is 1 << (level - 1)" so we can get the pair sum by adding the maximum label and the minimum label, then minus the current LABEL we can get the number which is in the symmetrical position of current LABEL.
