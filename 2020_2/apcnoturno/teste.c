#include <stdio.h>

char *my_itoa(int num, char *str)
{
        if(str == NULL)
        {
                return NULL;
        }
        sprintf(str, "%d", num);
        return str;
}

int main()
{
        int num = 2016;
        char str[20];
        if(my_itoa(num, str) != NULL)
        {
                printf("aaaa %s\n", str);
        }
}