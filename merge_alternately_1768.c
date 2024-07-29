#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *mergeAlternately(char *word1, char *word2) {
    char *word3 = (char *)malloc((strlen(word1) + strlen(word2) + 1) * sizeof(char));
    char *w1 = word1, *w2 = word2, *w3 = word3;

    while (*w1 != '\0' && *w2 != '\0') 
    {
        *w3 = *w1;
        w3++, w1++;
        *w3 = *w2;
        w3++, w2++;
    }
    while (*w1 != '\0') 
    {
        *w3 = *w1;
        w3++, w1++;
    }
    while (*w2 != '\0') 
    {
        *w3 = *w2;
        w3++, w2++;
    }
    *w3 = '\0';
    return word3;
}

int main(){
    char *a = "abc";
    char *b = "pdf";
    char *ans = mergeAlternately(a, b);
    printf("%s\n", ans);
    free(ans); // Free the allocated memory
    return 0;
}
