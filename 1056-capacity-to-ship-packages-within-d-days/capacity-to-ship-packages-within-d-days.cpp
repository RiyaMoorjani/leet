class Solution {
public:

    bool isPossible(vector<int>& weights, int mid, int days) {

        int day = 1;
        int shipload = 0;

        for(int i = 0; i < weights.size(); i++) {

            // package fits
            if(shipload + weights[i] <= mid) {
                shipload += weights[i];
            }
            else {

                // next day
                day++;

                shipload = weights[i];

                // exceeded allowed days
                if(day > days) {
                    return false;
                }
            }
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int s = *max_element(weights.begin(), weights.end());

        int total = 0;

        for(int i = 0; i < weights.size(); i++) {
            total += weights[i];
        }

        int e = total;

        int ans = total;

        while(s <= e) {

            int mid = s + (e - s) / 2;

            if(isPossible(weights, mid, days)) {

                ans = mid;

                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }

        return ans;
    }
};