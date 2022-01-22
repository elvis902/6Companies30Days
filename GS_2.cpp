/*Overlapping rectangles

https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/
*/


class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        int start_X1 = L1[0];
        int end_X1 = R1[0];
        int start_Y1 = R1[1];
        int end_Y1 = L1[1];
        
         int start_X2 = L2[0];
        int end_X2 = R2[0];
        int start_Y2 = R2[1];
        int end_Y2 = L2[1];
     
        if(end_X2 < start_X1 || start_X2 > end_X1 || start_Y2 > end_Y1 || 
        end_Y2 < start_Y1)
            return 0;
        else 
            return 1;

        
    }
};