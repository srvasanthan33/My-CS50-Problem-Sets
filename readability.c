#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int letter_count(string a);
int words_count(string b);
int sent_count(string c);

int main(void)
{
    string text = get_string("Text: ");
    float letter = letter_count(text);
    float words = words_count(text);
    float sentences = sent_count(text);
   /* printf("%.0f \n",letter);
    printf("%.0f \n",words);
    printf("%.0f \n",sentences); */
    float L = (letter/words) *100;
    float S = (sentences/words) *100;
   /* printf("%.2f \n",L);
    printf("%.2f \n",S); */
    int index = round(0.0588 * L - 0.296 * S - 15.8) ;
    if (index>16)
    {
        printf("Grade 16+\n");
    }
    else if (index<1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n",index);
    }





}


// Letter Counting function
int letter_count(string a)
{
    int count = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
        {
            count++;
        }
    }
    return count;
}
// words counting
int words_count(string a)
{
    int count = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] == ' ' && a[i + 1] != ' ')
        {
            count++;
        }
    }
    return count + 1;
}
// sentences counting
int sent_count(string a)
{
    int count = 0 ;
    for (int i = 0; i < strlen(a); i++)
    {
        if ((a[i] == '.' && (a[i + 1] == ' ' || a[i + 1] == '\0')) || (a[i] == '!' && (a[i + 1] ==' ' || a[i + 1] == '\0'))
            || (a[i] == '?' && (a[i + 1] == ' ' || a[i + 1] == '\0')))
        {
            count++;
        }
    }
    return count;
}