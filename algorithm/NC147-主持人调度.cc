class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算成功举办活动需要多少名主持人
     * @param n int整型 有n个活动
     * @param startEnd int整型vector<vector<>> startEnd[i][0]用于表示第i个活动的开始时间，startEnd[i][1]表示第i个活动的结束时间
     * @return int整型
     */
    
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        } else {
            return a[1] < b[1];
        }
    }
    
    int minmumNumberOfHost(int n, vector<vector<int> >& startEnd) {
        // write code here
        if (startEnd.size() == 0) return 0;
        std::sort(startEnd.begin(), startEnd.end(), compare);

        vector<int> tails;
        tails.push_back(startEnd[0][1]);
        for (int i = 1; i < startEnd.size(); i++) {
            int j = 0;
            for (; j < tails.size(); j++) {
                if (startEnd[i][0] < tails[j]) {
                    continue;
                } else {
                    tails[j] = startEnd[i][1];
                    break;
                }
            }
            if (j == tails.size()) {
                tails.push_back(startEnd[i][1]);
            }
        }
        
        return tails.size();
    }
};
