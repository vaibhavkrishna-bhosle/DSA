#include<stdio.h>

char string[50], pattern[20], replace[20], result[50];
int main_m = 0, str_m = 0, pat_m = 0, res_m = 0, flag = 0;
void stringmatch()
{
    while (string[main_m] != '\0')
    {
        if (string[str_m] == pattern[pat_m])
        {
            pat_m++;
            str_m++;
            if (pattern[pat_m] == '\0')
            {
                flag = 1;
                for (int k = 0; replace[k] != '\0'; k++, res_m++)
                {
                    result[res_m] = replace[k];
                }
                main_m = str_m;
                pat_m = 0;
            }
        }
        else
        {
            result[res_m] = string[main_m];
            res_m++;
            main_m++;
            str_m = main_m;
            pat_m = 0;
        }
    }
    result[res_m] = '\0';
}
void main()
{
    printf("Enter the main string:");
    gets(string);
    printf("\nEnter the pat string:");
    gets(pattern);
    printf("\nEnter the replace string:");
    gets(replace);
    printf("\nThe string before pattern match is:\n %s", string);
    stringmatch();
    if (flag == 1)
        printf("\nThe string after pattern match and replace is: \n %s ", result);
    else
        printf("\nPattern string is not found");
}