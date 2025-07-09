class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> duration(n);

        for (int i = 0; i < n; i++) {
            duration[i] = endTime[i] - startTime[i];
        }

        int maxFree = 0;

    
        for (int i = 0; i + k < n; i++) {
            int start = (i == 0) ? 0 : endTime[i - 1];
            int end = eventTime;
            if (i + k + 1 < n) {
                end = startTime[i + k + 1];
            }

            int totalDur = 0;
            for (int j = i; j <= i + k; j++) {
                totalDur += duration[j];
            }

            int availableTime = end - start;
            if (availableTime >= totalDur) {
                int freeTime = availableTime - totalDur;
                maxFree = max(maxFree, freeTime);
            }
        }

        maxFree = max(maxFree, startTime[0] - 0); 
        maxFree = max(maxFree, eventTime - endTime[n - 1]); 

        return maxFree;
    }
};
