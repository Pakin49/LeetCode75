#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) 
{
    int max=candies[0], index = 0;
    bool* ans = (bool*) malloc(candiesSize* sizeof(bool));
    // findmax
    for(int i=0;i<candiesSize;i++)
        if(candies[i]>max){
            max = candies[i];
            index = i;
        }
    for(int i=0;i<candiesSize;i++)
    {
        if(candies[i]+extraCandies >= max)
            ans[i] = true;
        else
            ans[i] = false;
    }
    *returnSize = candiesSize;
    return ans;
}

int main() {
    int candies[] = {2, 3, 5, 1, 3};
    int candiesSize = sizeof(candies) / sizeof(candies[0]);
    int extraCandies = 3;
    int returnSize;

    bool* result = kidsWithCandies(candies, candiesSize, extraCandies, &returnSize);

    // Print the results
    for (int i = 0; i < returnSize; i++) {
        printf("Kid %d: %s\n", i, result[i] ? "true" : "false");
    }

    // Free the allocated memory
    free(result);

    return 0;
}