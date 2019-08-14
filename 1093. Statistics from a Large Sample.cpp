// https://leetcode.com/problems/statistics-from-a-large-sample/discuss/317779/ChineseC%2B%2B-1093.-20
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int minAns = -1, maxAns = 0, modeAns = 0;
        double meanAns = 0, medianAns = 0;
        
        int num = 0;
        long long sum = 0;
        int n = count.size();
        
        for(int i=0;i<n;i++){
            int v = count[i];
            
            num += v;
            sum += v * i;
            
            if(minAns < 0 && v > 0){
                minAns = i;
            }
            if(v > 0){
                maxAns = i;
            }
            if(v > count[modeAns]){
                modeAns = i;
            }
        }
        meanAns = sum * 1.0 / num;
        
        double firstVal = 0, secondVal = 0;
        int midPos = num/2;
        int tmpNum = 0;
        for(int i=0;i<n;i++){
            int v = count[i];
            if(midPos > tmpNum && midPos <= tmpNum + v){
                firstVal = i;
            }
            if(midPos + 1 > tmpNum && midPos + 1 <= tmpNum + v){
                secondVal = i;
            }
            tmpNum += v;
            
        }
        if(num % 2 == 1){
            medianAns = firstVal;
        }else{
            medianAns = (firstVal + secondVal)/2;
        }
        return {minAns, maxAns, meanAns, medianAns, modeAns};
    }
};
