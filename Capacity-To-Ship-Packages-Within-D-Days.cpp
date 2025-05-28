class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int mini = *max_element(weights.begin(), weights.end()); // Minimum capacity is max of weights
        int maxi = accumulate(weights.begin(), weights.end(), 0); // Maximum capacity is sum of weights
        
        int low = mini, high = maxi;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int dayCount = 1;  // Start with day 1
            int sum = 0;

            for (int weight : weights) {
                if (sum + weight > mid) {
                    dayCount++; // New day
                    sum = 0;
                }
                sum += weight;
            }

            if (dayCount <= days) {
                high = mid - 1; // Try a smaller capacity
            } else {
                low = mid + 1; // Need more capacity
            }
        }
        return low;
    }
};
