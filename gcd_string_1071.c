#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* gcdOfStrings(char* str1, char* str2) 
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int minlen,maxlen;
    if (len1<len2)
        minlen = len1;
    else
        minlen = len2;
    char str12[len1+len2+1];
    char str21[len1+len2+1];
    strcpy(str12,str1);
    strcat(str12,str2);
    strcpy(str21,str2);
    strcat(str21,str1);
    
    printf("%s\n",str12);
    printf("%s\n",str21);

    if(strcmp(str12,str21)!=0)
    {
        char* empty_string ="\0";
        return empty_string;
    }
    else
    {
        int i = 0, j=1;
        for(j;j<=minlen;j++)
        {
            if(strncmp(str1,str2,j)==0 && len1%j==0 && len2%j==0)
                i=j;
        }
        char *ans = (char*)malloc((i+1)*sizeof(char));
        printf("%d\n",i);
        strncpy(ans,str1,i);
        ans[i] = '\0';
        printf("%s\n",ans);
        return ans;
    }
}

int main(int argc, char**argv)
{
    char a[] = "ABABAB";
    char b[] = "ABAB";
    char *result = gcdOfStrings(a,b);
    printf("%s",result);
    free(result);
}