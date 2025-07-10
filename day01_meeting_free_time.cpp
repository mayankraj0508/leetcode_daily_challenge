class Solution {
public:
    int maxFreeTime(int eventtime, vector<int>& st, vector<int>& et) {   
        int n = st.size();
        vector<int> leftgap(n);
        vector<int> rightgap(n);
        int gap = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                leftgap[i] = 0;
            }
            else if (i == 1) {
                gap = max(gap, st[0] - 0);
                if (et[1] - st[1] <= gap) {
                    leftgap[i] = gap;
                } else {
                    leftgap[i] = 0;
                }
            }
            else {
                gap = max(gap, st[i - 1] - et[i - 2]);
                if (et[i] - st[i] <= gap) {
                    leftgap[i] = gap;
                } else {
                    leftgap[i] = 0;
                }
            }
        }

        gap = INT_MIN;

        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                rightgap[i] = 0;
            }
            else if (i == n - 2) {
                gap = max(gap, eventtime - et[n - 1]);
                if (et[i] - st[i] <= gap) {
                    rightgap[i] = gap;
                } else {
                    rightgap[i] = 0;
                }
            }
            else {
                gap = max(gap, st[i + 2] - et[i + 1]);
                if (et[i] - st[i] <= gap) {
                    rightgap[i] = gap;
                } else {
                    rightgap[i] = 0;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (leftgap[i] > 0 || rightgap[i] > 0) {
                int length = et[i] - st[i];
                if (i == 0) {
                    ans = max(ans, st[1]);
                   
                }
                else if (i == n - 1) {
                    ans = max(ans, eventtime - et[n - 2]);
                }
                else {
                    ans = max(ans, st[i + 1] - et[i - 1]);
                }
            }
            else {
                if (i == 0) {
                    int length = et[0] - st[0];
                    int adjr = st[1] - et[0];
                    int adjl = st[0] - 0;
                        ans = max(ans, st[1] - length);
                        ans = max(ans, st[1] -(length));
                   
                }
                else if (i == n - 1) {
                    int length = et[i] - st[i];
                    int adjr = eventtime - et[i];
                    int adjl = st[i] - et[i - 1];
                
                        ans = max(ans, (eventtime - length) - et[i - 1]);
            
                        ans = max(ans, eventtime - (et[i - 1] + length));
                
                }
                else {
                    int length = et[i] - st[i];
                    int adjr = st[i + 1] - et[i];
                    int adjl = st[i] - et[i - 1];

                        ans = max(ans, st[i + 1] - length - et[i - 1]);
                  
                 
                        ans = max(ans, st[i + 1] - (et[i - 1] + length));
                   
                }
            }
        }

        return ans;
    }
};
