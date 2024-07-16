#include <stdio.h>

void largestSum3x3(int matrix[3][3], int *maxSum, int *topLeftRow, int *topLeftCol) {
    int rows = 3;
    int cols = 3;
    *maxSum = -1000; // Initialize with a very small value
    *topLeftRow = 0;
    *topLeftCol = 0;

    // Find the maximum sum and its location
    for (int i = 0; i <= rows - 3; i++) {
        for (int j = 0; j <= cols - 3; j++) {
            int currentSum = 0;
            for (int k = i; k < i + 3; k++) {
                for (int l = j; l < j + 3; l++) {
                    currentSum += matrix[k][l];
                }
            }
            if (currentSum > *maxSum) {
                *maxSum = currentSum;
                *topLeftRow = i;
                *topLeftCol = j;
            }
        }
    }
}

int main() {
    int matrix[3][3] = {
        {1, 2, 3, 6, 7},
        {4, 5, 6, 5, 1},
        {7, 8, 9, 8 ,8}
    };

    int maxSum, topLeftRow, topLeftCol;
    largestSum3x3(matrix, &maxSum, &topLeftRow, &topLeftCol);

    printf("The largest sum in a 3x3 submatrix is: %d\n", maxSum);
    printf("Location of the submatrix's top-left corner: (%d, %d)\n", topLeftRow, topLeftCol);

    return 0;
}
