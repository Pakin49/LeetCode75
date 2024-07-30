#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) 
{   
    if(flowerbedSize == 1)
    {
        if(flowerbed[0]==1 && n==1)
            return false;
        return true;
    }
    int plant = 0;
    for(int i=0;i<flowerbedSize;i++)
    {   
        if(i==0)
        {   
            if(flowerbed[i]==0 && flowerbed[i+1]==0)
            {
                plant++;
                flowerbed[i] = 1;
            }
        }
        else if(i==flowerbedSize-1)
        {
            if(flowerbed[i]==0 && flowerbed[i-1]==0)
            {
                plant++;
                flowerbed[i] = 1;
            }
        }
        else if(flowerbed[i]==0 && flowerbed[i+1]==0 && flowerbed[i-1]==0)
        {
            plant++;
            flowerbed[i] = 1;
        }
    }
    if (plant>=n)
        return true;
    return false;
}
int main()
{
    int flowerbed[] = {1,0,0,0,1};
    int flowerbedSize = sizeof(flowerbed)/sizeof(flowerbed[0]);
    int n = 1;
    if(canPlaceFlowers(flowerbed,flowerbedSize,n))
        printf("True\n");
    else
        printf("False\n");
    return 0;
}
