#include <cs50.h>
#include <stdio.h>


int main(void)
{

    long int num = get_long("Number: ");

    long int quo , r1 , r2;
    //sum1 = even sums
    //sum2 = odd sums
    int sum1 = 0, sum2 = 0 ;
    int count=0;
    quo = num;
    //Luhn's Algo
    while (quo > 0)
    {
        r1  = quo % 10;
        quo = quo / 10;
        r2  = quo % 10;
        quo = quo / 10;
        // odd no sums
        sum2 = sum2 + r1;
        // even no sums
        sum1 = sum1 + (r2 * 2) % 10;
        sum1 = sum1 + (r2 * 2) / 10;
        count+=2;
        // to correct the digit if its odd
        if (quo ==0 && r1 > 0 && r2 <=0)
        {
            count--   ;
        }




    }
    // Luhn Answer
    int checksum = sum1 + sum2;
    //checking the starting digits for identifying card name
    long int checker = num ;
    do
    {
        checker = checker/10;
    }
    while (checker > 100);

    if (checksum % 10 == 0 && (count>12 && count<17) )
    {

        if (count==15 && (checker == 34 || checker == 37))
        {
            printf("AMEX\n");
        }
        else if ((checker / 10 == 5) && (0< checker % 10 && checker %10 <6))
        {
            printf("MASTERCARD\n");
        }
        else if (checker / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }


    }
    else
    {
        printf("INVALID\n");
    }



}