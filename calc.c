#include <stdio.h>
#include <math.h>
#include <gmp.h>

void ClearInputBuffer()
{
    int ch;
    ch = getchar();
    while (ch != '\n' && ch != EOF)
    {
       ch = getchar();
    }
}

double GetValidDouble(const char *prompt){
    int read;
    double num;
    while (1)
    {
    printf("%s", prompt);
    read = scanf("%lf", &num);
    ClearInputBuffer();

    if (read == 1)
    {
        return num;
    }
    else{
        printf("Invalid input, please enter a numerical value\n");
    }
    }
}

int main(int argc, char **agrv)
{
    //variables n shit
    mpf_t answer, number1, number2;
    double num1, num2;
    char operation;
    mpf_init(answer);
    mpf_init(number1);
    mpf_init(number2);


    // number 1 user input
    num1 = GetValidDouble("First Number: ");
    mpf_set_d(number1, num1);

    // number 2 user intput
    num2 = GetValidDouble("Second Number: ");
    mpf_set_d(number2, num2);
    
    
    //the MATH
        printf("Math operation: ");
        scanf(" %c", &operation);
        if (operation != '-' && operation != '+' && operation != '*' && operation !='/')
        {
            printf("Please input any of the following +, -, *, / \n");
        }

        else
        {
            switch (operation)
            {
                case '+':
                mpf_add(answer, number1, number2);
                gmp_printf("Result: %.12Ff\n", answer);
                break;

                case '-':
                mpf_sub(answer, number1, number2);
                gmp_printf("Result: %.12Ff\n", answer);
                break;

                case '*':
                mpf_mul(answer, number1, number2);
                gmp_printf("Result: %.12Ff\n", answer);
                break;

                case '/':
                if (num2 == 0){
                    printf("You cannot divide by 0\n");
                }
                else{
                mpf_div(answer, number1, number2);
                gmp_printf("Result: %.12Ff\n", answer);
                }
                break;
            }
            
        }
    
    mpf_clear(answer);
    mpf_clear(number1);
    mpf_clear(number2);

    return 0;
}