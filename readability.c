#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int get_index(string s);

int main()
{
    //prompt user to type paragraph
    string text = get_string("Text: ");

    //Calculate index
    int index = get_index(text);

    //Display index grade
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
    
    return 0;

}

int get_index(string s)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;

    //count number of letters in text
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        char ch = s[i];
        if (isalpha(ch))
        {
            letters++;
        }
    }
    
    //count number of words in text
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (s[i] == ' ' && s[i + 1] != ' ')
        {
            words++;
        }
    }

    //count number of sentences in text
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }
    
    //calculate equation
    float L = (letters * 100.00f) / words;
    float S = (sentences * 100.00f) / words;
    
    return round(0.0588 * L - 0.296 * S - 15.8);
}
