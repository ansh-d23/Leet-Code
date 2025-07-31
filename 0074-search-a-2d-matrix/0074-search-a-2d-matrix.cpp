class Solution {
public:
    // bool binaryOnRow(int row, vector<vector<int>>& matrix, int target) {
    //     int start = 0;
    //     int end = matrix[row].size() - 1;
    //     while (start <= end) {
    //         int mid = (start + end) / 2;
    //         if (matrix[row][mid] == target) {
    //             return true;
    //         } else if (matrix[row][mid] < target) {
    //             start = mid + 1;
    //         } else {
    //             end = mid - 1;
    //         }
    //     }
    //     return false;
    // }

    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int n = matrix.size();
    //     if (n == 0) return false;
    //     int m = matrix[0].size();
    //     int start = 0;
    //     int end = m - 1;
    //     if (n == 1) {
    //         return binaryOnRow(0, matrix, target);
    //     }
    //     while (start <= end) {
    //         int mid = (start + end) / 2;
    //         if (target >= matrix[mid][0] && target <= matrix[mid][m - 1]) {
    //             return binaryOnRow(mid, matrix, target);
    //         } else if (target < matrix[mid][0]) {
    //             end = mid - 1;
    //         } else {
    //             start = mid + 1;
    //         }
    //     }
    //     return false;
    // }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row= matrix.size();
        int col= matrix[0].size();
        int start=0;
        int end= (row*col)-1;

        while(start<=end){
            int mid = start + (end-start)/2;
            int indexVal = matrix[mid/col][mid%col];
            if(indexVal==target) return true;
            else if(indexVal>target) end=mid-1;
            else start=mid+1;
        }
        return false;
    }
};
