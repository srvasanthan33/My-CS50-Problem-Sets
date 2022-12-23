#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int rotate(int a, char planchr);


int main(int argc, string argv[])
{
    int flag = 0;
    if (argc == 2)
    {
        string ch = argv[1];
        for (int i=0; i < strlen(ch); i++)
        {
            if (isdigit(ch[i]))
            {
                // To check if argv[1] contains integer value
                flag = 1;

            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    // IF CLI VALUE IS NUMBER
    if (flag == 1)
    {
        //..........main prog....................................................................
        int key = atoi(argv[1]);// atoi function cnverts string to integer
        string plaintxt = get_string("Plain text:  ");
        string ciphertxt = plaintxt;
        char cont;
        for (int i = 0; i < strlen(plaintxt); i++)
        {
            cont = rotate(key, plaintxt[i]);
            ciphertxt[i] = cont;
        }

        printf("ciphertext: %s\n",ciphertxt);

        return 0;
    }

}

//ROTATE FUNCTION PROTOTYPE.............
int rotate(int key, char plnchr)
{

    int pint = plnchr;
    int cint;
    if ((plnchr >= 'a' && plnchr <= 'z') || (plnchr >= 'A' && plnchr <= 'Z'))
    {

        {
            int pi_key, final_key;

            if (plnchr >= 'a' && plnchr <= 'z')
            {
                //If key value exceeds the ascii value o lowercase[a-z]
                if (pint + key > 122)
                {
                    pi_key = pint + key;
                    pi_key = pi_key % 123;
                    final_key = pi_key % 26;
                    cint = 97 + final_key;
                    return cint;
                }
                else
                {
                    key = key % 26;
                    cint = pint + key;
                    return cint;
                }
            }
            else
            {
                //If key value exceeds the ascii value o uppercase[A-Z]
                if (pint + key > 90)
                {
                    pi_key = pint + key;
                    pi_key = pi_key % 91;
                    final_key = pi_key % 26;
                    cint = 65 + final_key;
                    return cint;
                }
                else
                {
                    key = key %26;
                    cint = pint + key;
                    return cint;
                }
            }
        }



    }
    else // if character is not alphabet
    {
        return pint;
    }
}
