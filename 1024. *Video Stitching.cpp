// https://leetcode.com/problems/video-stitching/discuss/270004/Leetcode-Weekly-Contest-131-screen-record
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        
         // t indicates the coverage time of selected videos([0, t]), and next_t indicates the latest time that we can cover after adding a video.
         // Since the current coverage time is [0, t], the interval of the next video [x, y] we need to find must satisfy x <= t.
         // In all videos[x_i, y_i] that meet the criteria, obviously the video with the latest end time will be better.
        int n = clips.size(), ret = 0, t = 0, next_t = 0;
        for (int i = 0; i < n && t < T; i++) {
            if (clips[i][0] > t) {
                t = next_t;    //start a new batch
                ++ret;
            }
            
            if (clips[i][0] > next_t) {
                break;
            }
            
            next_t = max(next_t, clips[i][1]);  //compare with peer inside same batch which satisfy x <= t
        }
        
        if (t < T) {
            t = next_t;
            ++ret;
        }
        return t < T ? -1 : ret;
    }
};
