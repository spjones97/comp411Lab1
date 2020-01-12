#include <stdio.h>
#define PI 3.14159

int main ()
{
    float q, a, r, b;
    printf("Which example would you like to try? 1 2 or 3:\n");
    scanf("%f", &q);
    if (q == 1) {
        printf("Enter radius (in cm):\n");
        scanf("%f", &r);
        r /= 2.54;

        a = PI * r * r;

        printf("Circle's area is %3.2f (sq in).\n", a);
        return 0;
    } else if (q == 2) {
        printf("Enter radius (in cm):\n");
        scanf("%f", &r);
        r /= 2.54;

        a = PI * r * r;
        b = PI * (2 * r);

        printf("Circle's area is %3.2f (sq in).\n", a);
        printf("Its circumference is %3.2f (in).\n", b);
    } else {
        do
        {
            printf("Enter radius (in cm):\n");
            scanf("%f", &r);
            r /= 2.54;

            a = PI * r * r;
            b = PI * (2 * r);

            printf("Circle's area is %3.2f (sq in).\n", a);
            printf("Its circumference is %3.2f (in).\n", b);
        } while (r != 0);
    }
}