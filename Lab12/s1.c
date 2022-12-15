#include <stdio.h>
#include <string.h>

int strcmp_redefined(const char *ptr1, const char *ptr2)
{
    /* we cast the 2 pointers to unsigned char pointers
        Some systems have the char type as signed
         Others, char is unsigned. 
        Presenting the sign of the comparison is good for all users.
    */
    const unsigned char *s1 = (const unsigned char *) ptr1;
   
    const unsigned char *s2 = (const unsigned char *) ptr2;

    // take two unsigned chars to compute the comparision
    // character by character of the 2 strings

    unsigned char character_s1 = (unsigned char) *s1++;
    
    unsigned char character_s2 = (unsigned char) *s2++;

    if(character_s1 == '\0')
    {
        /* 
            returns less, or equal, or greater than 0
            if the first string is in lexicographical order
            less, or equal, or greater 
        */
        return character_s1 - character_s2;
    }

    while(character_s1 == character_s2)
    {
        character_s1 = (unsigned char) *s1++;

        character_s2 = (unsigned char) *s2++;

        if(character_s1 == '\0')
        {
            return character_s1 - character_s2;
        }
    }

    return character_s1 - character_s2;
}

int strncmp_redefined(const char *ptr1, const char *ptr2, size_t n)
{
    const unsigned char *s1 = (const unsigned char *) ptr1;

    const unsigned char *s2 = (const unsigned char *) ptr2;

    for (; n-- && *s1; ++s1, ++s2)
    {
        if(*s1 != *s2)
        {
            return (unsigned char) *s1 - (unsigned char) *s2;
        }
    }

    switch (n)
    {
    case 0:
    {
        return 0;
        break;
    }
    
    default:
    {
        return ((unsigned char) *s1 - (unsigned char) *s2);
        break;
    }
    }
}

int main()
{
    char p1[] = "AnaAC1", p2[] = "AnaAC";

    printf("Strcmp of the strings: %s, %s is equal to: %d\n", p1, p2, strcmp_redefined(p1, p2));

    printf("Strcmp %d\n", strncmp_redefined(p1, p2, 10));
}
