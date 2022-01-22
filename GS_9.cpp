/* 
Find Missing And Repeating

https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/#

PS: There are other ways also to do the problem. Here I did by using XOR method.
*/








int *findTwoElement(int *arr, int n) {
        int x = 0;
        for(int i = 0; i < n; i++)
        {
            x ^= arr[i];
        }
        for(int i = 1; i <= n; i++)
            x ^= i;
        
        int rsb = (x & (-x));
        
        int buc1 = 0, buc2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(rsb & arr[i])
                buc1 ^= arr[i];
            else
                buc2 ^= arr[i];
        }
        for(int i = 1; i <= n; i++)
        {
            if(rsb & i)
                buc1 ^= i;
            else
                buc2 ^= i;
        }
        
        int rep = -1, mis = -1;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == buc1)
            {
                rep = buc1; mis = buc2;
                break;
            }
            if(arr[i] == buc2)
            {
                rep = buc2; mis = buc1;
                break;
            }
        }
        int *res = new int[2];
        res[0] = rep;
        res[1] = mis;
        return res;
    }