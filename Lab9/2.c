#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

int fillArray(char *s, int *v, int capacity)
{   
    int lenght = strlen(s);
    int nElem = 0;
    char vowels[] = "aeiouAEIOU";

    for(int i = 0; i < lenght && nElem < capacity; ++ i)
    {
        //if it's either digit or a consonant
        if(isdigit(s[i]) || (isalpha(s[i]) && !strchr(vowels, s[i])))
        {
            v[nElem++] = i;
        }
    }

    return nElem;
}

int main()
{
    int cap = 5;

    int v[cap];

    char s[] = "ana are mere 69 69 foarte mari 69 69";
    
    int n =  fillArray(s, v, cap);

    for(int i = 0; i < n; ++ i)
    {
        printf("%d ", v[i]);
    }

    return 0;
}
