#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void clear_input_buffer()
{
    int c; 
    while((c= getchar()) != '\n' && c != EOF); 
}

int main()
{
    float balance= 0.0f; 
    unsigned int option; 
    const float CASH_LIMIT= 100000.00f;
    bool status= true;

    fprintf(stdout, "Welcome to Wallet!\n");

    do
    {
        fprintf(
            stdout, 
            "\nOptions:\n%-15s %-15s\n%-15s %-15s\n%s",
            "1. Deposit", 
            "2. Balance", 
            "3. Withdraw", 
            "4. Exit", 
            "Select Option: "
        );

        if(scanf("%u", &option) == 0)
        {
            fprintf(stderr, "Invalid Input. Try Again!\n");
            clear_input_buffer();
            continue;
        }

        switch(option)
        {
            case 1:
                fprintf(
                    stdout, 
                    "Deposit Option. \nEnter Deposit Amount: "
                );

                float deposit= 0.0f;

                if(scanf("%f", &deposit) == 0)
                {
                    fprintf(
                        stderr, 
                        "Invalid Input. \n"
                    );
                    clear_input_buffer();
                    continue;
                }
                else if(deposit <= 0)
                {
                    fprintf(
                        stderr, 
                        "Deposit Amount Should Be Greater Than 0.\n"
                    );
                    continue;
                }
                else if(deposit > CASH_LIMIT)
                {
                    fprintf(
                        stderr, 
                        "Invalid Deposit Amount. Deposit Amount Should Be Less Than %.2f\n",
                        CASH_LIMIT
                    );
                    continue;
                }

                balance += deposit; 

                fprintf(
                    stdout, 
                    "Balance Updated. \nNew Balance: %.2f\n",
                    balance
                );
            break;

            case 2: 
                fprintf(
                    stdout, 
                    "Balance Option. \nYour Balance: %.2f\n",
                    balance
                ); 
            break; 

            case 3: 
                fprintf(
                    stdout, 
                    "Withdraw Option\nEnter Withdraw Amount: "
                );

                float withdraw= 0.0f; 

                if(scanf("%f", &withdraw) == 0)
                {
                    fprintf(
                        stderr, 
                        "Invalid Input. \n"
                    );
                    clear_input_buffer(); 
                    continue;
                }
                else if(withdraw <= 0)
                {
                    fprintf(
                        stderr, 
                        "Withdraw Amount Should Be Greater Than 0.\n"
                    );
                    continue;
                }
                else if(withdraw > CASH_LIMIT)
                {
                    fprintf(
                        stderr, 
                        "Invalid Withdraw Amount. Withdraw Amount Should Be Less Than %.2f\n",
                        CASH_LIMIT
                    );
                    continue;
                }
                else if(balance < withdraw)
                {
                    fprintf(
                        stderr, 
                        "Insufficient Balance\n"
                    );
                    continue;
                }

                balance -= withdraw; 

                fprintf(
                    stdout, 
                    "%.2f Withdrawed succeffully.\nYour Balance: %.2f\n",
                    withdraw, 
                    balance
                );
            break; 

            case 4: 
                status= false; 
                fprintf(stdout, "Program Exited Successfully. \n");
            break; 

            default: 
                fprintf(stderr, "Invalid Option.\n");
            break;
        }

    } while (status);
    
    
    return 0;
}