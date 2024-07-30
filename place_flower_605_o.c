#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int prev=0;
    int i;
    for(i=0; i<flowerbedSize-1; i++){
        if(flowerbed[i]==0 && prev==0 && flowerbed[i+1]==0){
            n--;
            prev=1;
        }
        else prev=flowerbed[i];
    }
    //last
    if(flowerbed[i]==0 && prev==0) n--;

    return n<=0;
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
