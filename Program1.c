#include <stdio.h>

int main() 
{
    printf("Name: %s, Age: %d, Weight: %f", "Kamal", 23, 63.3);
    printf("\n");

    int age= 34;
    float weight= 56.93f; 
    char buffer[50];

    // sprintf(buffer, "Age: %d | Weight: %.2f ", age, weight);
    snprintf(buffer, sizeof(buffer), "Age: %d | Weight: %.2f ", age, weight);

    printf(buffer);

    return 0;
}