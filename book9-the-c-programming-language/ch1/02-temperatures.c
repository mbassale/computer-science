#include <stdio.h>

#define FAHRENHEIT_LOWER 0
#define FAHRENHEIT_UPPER 300
#define FAHRENHEIT_STEP 20;

#define CELSIUS_LOWER -20
#define CELSIUS_UPPER 150
#define CELSIUS_STEP 10

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = FAHRENHEIT_LOWER; /* lower limit */
    upper = FAHRENHEIT_UPPER; /* upper limit */
    step = FAHRENHEIT_STEP;   /* step size */

    fahr = lower;
    printf("Fahrenheit Celcius\n");
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%10.0f %7.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    printf("\n");

    printf("Celcius Fahrenheit\n");
    lower = CELSIUS_LOWER;
    upper = CELSIUS_UPPER;
    step = CELSIUS_STEP;
    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (9.0 / 5.0) * celsius + 32;
        printf("%7.0f %10.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}