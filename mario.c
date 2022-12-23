#include<stdio.h>
#include<cs50.h>
int main()
{
int a,k;
    do
    {
        a=get_int("Enter Height:\t");

    }
    while (a<1 || a>8);//to specify the intervals given in question

for(k = 1;k <= a;k++)
{
    for(int i = 0; i < a-k;i++)//for printing spaces
    printf(" ");

for (int j=0;j<a-(a-k);j++)//for printing blocks
printf("#");
printf("\n");
}
}