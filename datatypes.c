#include <stdio.h>

int main()
{
    int i = 20;//int is datatype to declare integer variable 
    char ch = 'R'; // char is a datatype to declare character(It stores ascii equivalent of ch)
    float f = 1.5; // float is datatype used to store decimal values
    double d = 4.8; // double is a datatype used to store decimal values
    unsigned char ch1 = -1; // To store positive values range 0 to 255 for char
    
    printf("i = %d\t size = %ld\n", i, sizeof(i));
    printf("ch = %c\t size = %ld\n", ch, sizeof(ch));
    printf("f = %f\t size = %ld\n", f, sizeof(f));
    printf("d = %lf\t size = %ld\n", d, sizeof(d));
    printf("ch1 = %hhu\t size = %ld\n", ch1, sizeof(ch1)); //It prints positive equivalent(256-1) of -1

    return 0;
}
