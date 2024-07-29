#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* gcdOfStrings(char* str1, char* str2) 
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int minlen = (len1 < len2) ? len1 : len2;
    
    char str12[len1 + len2 + 1];
    char str21[len1 + len2 + 1];
    
    strcpy(str12, str1);
    strcat(str12, str2);
    
    strcpy(str21, str2);
    strcat(str21, str1);
    
    if (strcmp(str12, str21) != 0)
    {
        char* emptyString = (char*)malloc(1);
        emptyString[0] = '\0';
        return emptyString;
    }
    else
    {
        int i;
        for (i = 1; i <= minlen; i++)
        {
            if (strncmp(str1, str2, i) != 0)
                break;
        }
        
        char* ans = (char*)malloc(i); // Allocate space for i characters plus null terminator
        strncpy(ans, str1, i - 1);    // Copy i-1 characters from str1 to ans
        ans[i - 1] = '\0';            // Ensure the string is null-terminated
        
        return ans;
    }
}

int main(int argc, char** argv)
{
    char a[] = "ABCABC";
    char b[] = "ABC";
    char* result = gcdOfStrings(a, b);
    printf("%s\n", result);
    
    free(result); // Don't forget to free the allocated memory
    return 0;
}
