#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    char word[100];
    int i = 0;
    char ch;

    fp = fopen("input.c", "r");

    if (!fp)
    {
        printf("Error in opening the file\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isalpha(ch)) // ✅ No extra fgetc() here
        {
            word[i++] = ch;

            while (isalnum(ch = fgetc(fp)))
            {
                word[i++] = ch;
            }

            word[i] = '\0';
            printf("Identifier: %s\n", word);
            i = 0;
        }
    }

    fclose(fp); // ✅ Closed file outside the loop

    return 0;
}
