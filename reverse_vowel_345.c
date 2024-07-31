#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_vowel(char c)
{
     char vowel_list[] = "aeiouAEIOU";
    for(int i=0;i<strlen(vowel_list);i++)
    {
        if(c == vowel_list[i])
            return 1;
    }
    return 0;
}
char* reverseVowels(char* s) 
{   
    int size = strlen(s);
    char vowel[size];
    memset(vowel,'\0',size);
    int i,j;
    int vowel_count = 0;
    for(i=0;i<size;i++)
        if(is_vowel(s[i]))
            vowel[vowel_count++]=s[i];
    for(i=0;i<size;i++)
        if(is_vowel(s[i]))
            s[i] = vowel[--vowel_count];
    return(s);
}

int main()
{
    char test[] = "LEET CODE";
    printf("%s\n",reverseVowels(test));
}