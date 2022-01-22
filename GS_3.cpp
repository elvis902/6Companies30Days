/*Count the subarrays having product less than k

https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/
*/




int countSubArrayProductLessThanK(const vector<int>& nums, int n, long long k) {
         if(k == 0) return 0;
        long long pro = 1;
        int i = 0, j = 0;
        int res = 0;
        while(j < nums.size())
        {
            pro = pro * nums[j];
            if(pro < k)
            {
                res += (j-i+1);
            }
            else
            {
               while(pro >= k && i <= j)
               {
                   pro = pro / nums[i];
                   i++;
               }
               if(i <= j)
               {
                   res += (j-i+1);
               }
            }
            j++;
        }
        return res;
    
    }