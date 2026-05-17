class Solution {
public:
    bool possible_to_eat(vector<int>& piles, double per_hour, int hours) {
        int total_hours = 0;
        for(const auto& pile: piles) {
            total_hours += ceil((double)pile/per_hour);
        }
        return total_hours <= hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int largest {0};
        for(const auto& pile: piles) {
            largest = max(largest, pile);
        }
        int left = 1;
        int right = largest;
        int max_per_hour = largest;
        while(left <= right) {
            int mid = left + ((right - left)/2);
            if(possible_to_eat(piles, mid, h)) {
                max_per_hour = mid;
                right = mid - 1;
            }
            else 
                left = mid + 1;
        }
        return max_per_hour;
    }
};
// 24 + 10 = 35
// 35 + 23 = 58
// 58 + 4  = 62