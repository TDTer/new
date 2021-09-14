#include <stdio.h>
#include <string.h>

char* screen(char *c)
{
    strcat(c, "world");
    return c;
}

int main()
{
    char b[20] = "Hallo ";
    screen(b);
    printf("%s",b);

    return 0;
}
