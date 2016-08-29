//https://discuss.leetcode.com/topic/55894/c-o-n-iterative-approach
class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int, int> lenthMap;
    	int curDepth = 0, maxLenth = 0;
    
    	for (int i = 0; i<input.size(); i++){
    		if (input[i] == '\n'){
    			continue;
    		}
    		else if (input[i] == '\t'){
    			curDepth++; //this means we are in a more deep layer
    		}
    		else{
    		    
    		    //first we get the file name of this layer(it can also be a directory)
    			int next = input.find_first_of("\n\t", i);
    			int fileNameLenth = ((next != string::npos) ? next : input.size()) - i;
    			string fileName = input.substr(i, fileNameLenth);			
                //update hash map of the length of cur layer
    			lenthMap[curDepth] = (curDepth == 0 ? 0 : lenthMap[curDepth - 1] + 1) + fileNameLenth;
    			//update max length
    			if (fileName.find_first_of('.', 0) != string::npos){
    				maxLenth = max(lenthMap[curDepth], maxLenth);
    			}
    			//skip evaluated file path;
    			i += fileNameLenth - 1;
    			
    			//will initial back to the initial status. the sturcture is xxx /n xxx/n/t xxx/n/t/t ...
    			curDepth = 0;
    		}
    	}
    
    	return maxLenth;
    }
};
