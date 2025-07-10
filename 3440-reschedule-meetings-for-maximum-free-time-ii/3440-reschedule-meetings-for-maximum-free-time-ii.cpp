class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps;

        gaps.push_back(startTime[0]);
        for (int i = 1; i < n; ++i) {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }
        gaps.push_back(eventTime - endTime.back());

        int k = gaps.size();

        vector<int> suff(k, 0);
        for (int i = k - 2; i >= 0; --i) {
            suff[i] = max(suff[i + 1], gaps[i + 1]);
        }

        vector<int> pref(k, 0);
        for (int i = 2; i < k; ++i) {
            pref[i] = max(pref[i - 1], gaps[i - 2]);
        }

        int ans = 0;
        for (int i = 1; i < k; ++i) {
            int meetingTime = endTime[i - 1] - startTime[i - 1];
            if (meetingTime <= max(pref[i], suff[i])) {
                ans = max(ans, gaps[i - 1] + gaps[i] + meetingTime);
            }
            ans = max(ans, gaps[i - 1] + gaps[i]);
        }

        return ans;
    }
};
