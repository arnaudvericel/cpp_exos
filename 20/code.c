#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
Reverses inStr and puts the result into outStr.
The function assumes that outStr has enough memory allocated.
*/
void ReverseString(const char* inStr, char* outStr)
{
    strcpy(outStr, inStr);
    size_t lenStr = strlen(inStr);

    for (size_t i = 0; i < lenStr; i++)
    {
        outStr[lenStr - i - 1] = inStr[i];
    }

    printf("Input: %s\n", inStr);
    printf("Reversed: %s\n", outStr);
}

int main()
{
    char inStr[] = "2-Bit says: I Love Arkane Studios!";
    size_t lenStr = strlen(inStr);
    char* outStr = (char*)malloc((lenStr + 1) * sizeof(char)); // +1 for '\0'

    ReverseString(inStr, outStr);

    free(outStr);
    return 0;
}

/*
Output:
--
Input: 2-Bit says: I Love Arkane Studios!
Reversed: !soidutS enakrA evoL I :syas tiB-2
--
*/
