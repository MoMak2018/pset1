#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //This program validates entered credit cards by using the Luhn Algorithim
    //num is the card number
    //digit_keep: keeps and adds up everyother digit starting (and including) the last digit
    //product_sum: algorithm will take everyother digit starting (not including) the last digit and
    //adds the product of the multiplycation
    //length measures the length of the card number 13, 15 or 16


    //variables used through out the program
    long long num = get_long_long("Enter Card Number: ");
    long long digit_keep = 0;
    long long product_sum = 0;
    long long d = num;
    int length = 0;
    int first_digit = 0;
    bool validation;

    //while loop for measuring length of card number
    while (d != 0)
    {
        d = (d / 10);
        length++;
    }
    
    //first_digit is another method of idententifying card type besides length
    first_digit += (num/(pow((long long) 10,length-1)));


    //Luhn algorithm for identifying validity
    for (int i = 0; i < length ; i++)
    {
        digit_keep += num % 10;
        num = num / 10;
        product_sum += (((num%10)*2)%10) + (((num%10)*2)/10);
        num = num / 10;
    }
    int final_sum = digit_keep + product_sum;
    printf("%i\n", first_digit);
    if (final_sum % 10 == 0)
    {
        printf("VALID\n");
        validation = true;
    }
    else
    {
        validation = false;
        printf("INVALID\n");
    }


    //if the validation process passes then it identifies type of card
    if (validation == true)
    {
        if (length == 15)
        {
            printf("American Express\n");
        }
        else if (length == 13)
        {
            printf("Visa\n");
        }
        else if (first_digit == 5)
        {
            printf("Master Card\n");
        }
        else if (first_digit == 4)
        {
            printf("Visa\n");
        }

    }


    //console prints used for debugging
    printf("%i\n", first_digit);
    printf("%i\n", length);
    printf("%lld\n", digit_keep);
    printf("%lld\n", product_sum);
    printf("%i\n", final_sum);

}
