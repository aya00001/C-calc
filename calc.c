#include <stdio.h>
#include <math.h>
#include <mpfr.h>

// 128 bits is overkill but needed for extreme precision
// despite me only priting 12 digits
#define PrecisionLevel 128

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
    mpfr_t answer, number1, number2;
    double num1, num2;
    char operation;
    mpfr_init2(answer, PrecisionLevel);
    mpfr_init2(number1, PrecisionLevel);
    mpfr_init2(number2, PrecisionLevel);

    // TO DO - receive fractional input such as "1/3"
    // and possibly even output fractionary values

    // number 1 user input
    num1 = GetValidDouble("First Number: ");
    mpfr_set_d(number1, num1, MPFR_RNDN);

    // number 2 user intput
    num2 = GetValidDouble("Second Number: ");
    mpfr_set_d(number2, num2, MPFR_RNDN);
    
    //the MATH
        printf("Math operation: ");
        scanf(" %c", &operation);
        if (operation != '-' && operation != '+' && operation != '*' && operation !='/' && operation !='^' && operation != 'r')
        {
            printf("Please input any of the following +, -, *, /, ^, r \n");
        }

        else
        {
            switch (operation)
            {
                case '+':
                mpfr_add(answer, number1, number2, MPFR_RNDN);
                mpfr_printf("Result: %.12Rf\n", answer);
                break;

                case '-':
                mpfr_sub(answer, number1, number2, MPFR_RNDN);
                mpfr_printf("Result: %.12Rf\n", answer);
                break;

                case '*':
                mpfr_mul(answer, number1, number2, MPFR_RNDN);
                mpfr_printf("Result: %.12Rf\n", answer);
                break;

                case '/':
                if (number2 == 0){
                    printf("You cannot divide by 0\n");
                }
                else{
                mpfr_div(answer, number1, number2, MPFR_RNDN);
                mpfr_printf("Result: %.12Rf\n", answer);
                }
                break;

                case '^':
                mpfr_pow(answer, number1, number2, MPFR_RNDN);
                mpfr_printf("Result: %.12Rf\n", answer);
                break;

                // TO DO - implement negative bases
                case 'r':
                mpfr_t exponent;
                mpfr_init2(exponent, PrecisionLevel);
                mpfr_set_ui(exponent, 1, MPFR_RNDN);
                mpfr_div(exponent, exponent, number2, MPFR_RNDN);
                mpfr_pow(answer, number1, exponent, MPFR_RNDN);
                mpfr_printf("Result: %.12Rf\n", answer);
                mpfr_clear(exponent);
                
        }
    
    mpfr_clear(answer);
    mpfr_clear(number1);
    mpfr_clear(number2);
    return 0;
}
}