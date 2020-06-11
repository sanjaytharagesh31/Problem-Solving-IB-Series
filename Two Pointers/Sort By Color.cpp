void Solution::sortColors(vector<int> &nums) {
    int n = nums.size();
    int i = -1;
    int j = n;
    int k = 0;
    while(k < n && k < j) {
        if(nums[k] == 1) {
            k++;
            continue;
        }
        else if(nums[k] == 0) {
            swap(nums[k], nums[i+1]);
            i++;
            k++;
        }
        else {
            swap(nums[k], nums[j-1]);
            j--;
        }
    }
}
