#include <stdio.h>

int main()
{
    char buffer[100];
    char *username= "@isuru";
    unsigned int id= 3034; 

    int snprintf_result= snprintf(buffer, sizeof(buffer), 
                                    "Def/common%s/%d", 
                                    username, id);
    
    if(snprintf_result < sizeof(buffer))
    {
        printf(buffer, "\n");
    }
    else if(snprintf_result >= sizeof(buffer))
    {
        printf("Warning: Message Truncated.");
    }
    else if(snprintf_result < 0)
    {
        printf("Error: Encoding error.");
    }

    return 0;
}