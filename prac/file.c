#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    FILE *fp=fopen("one.txt", "r");
    char ch;
    ch=fgetc(fp);
    while(ch!=EOF)
    {
        printf("%c",ch);
        ch=fgetc(fp);

    }
    fclose(fp);

    return 0;
}
