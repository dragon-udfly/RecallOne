#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() 
{
    char name[100];
    char country[100];
    unsigned int age; 
    int fprintf_result, scanf_result;

    fprintf_result= fprintf(stdout, "Enter Name: "); 
    if(fprintf_result < 0)
    {
        perror("stdout fails to print");
        return 1;
    }
    if(fgets(name, sizeof(name), stdin) == NULL)
    {
        perror("stdin fails to take input");
        return 1;
    }
    name[strcspn(name, "\n")]= 0; 

    fprintf_result= fprintf(stdout, "Enter Age: ");
    scanf_result= scanf("%u", &age); // result should be 1
    if(scanf_result < 0)
    {
        perror("stdin fails to take input");
        return 1;
    }
    else if(scanf_result == 0)
    {
        fprintf_result= fprintf(stderr, "Invalid Input.\n");
        if(fprintf_result < 0)
        {
            perror("stdout fails to print output.");
            return 1;
        }
        return 1;
    }

    fprintf_result= fprintf(stdout, "Enter Country: ");
    if(fprintf_result < 0)
    {
        perror("stdout fails to print output");
        return 1;
    }
    if(fgets(country, sizeof(country), stdin) == NULL)
    {
        perror("stdin fails to take input.");
        return 1;
    }
    country[strcspn(country, "\n")]= 0;

    fprintf_result= fprintf(stdout, "Name: %s, Age: %u, Country: %s\n", name, age, country); 
    if(fprintf_result < 0)
    {
        perror("stdout fails to print output");
        return 1;
    }

    return 0;
}