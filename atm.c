#include <stdio.h>
int main()
{
    // Account number for 10 different users
    int a_acc = 1001, b_acc = 1002, c_acc = 1003, d_acc = 1004, e_acc = 1005;
    int f_acc = 1006, g_acc = 1007, h_acc = 1008, i_acc = 1009, j_acc = 1010;
    // PIN numbers for 10 different users
    int a_pin = 4827, b_pin = 7319, c_pin = 1654, d_pin = 9082, e_pin = 3461;
    int f_pin = 6275, g_pin = 8193, h_pin = 2548, i_pin = 5706, j_pin = 2094;
    // Initial balance for each user
    float a_balance = 12450, b_balance = 8760, c_balance = 25320;
    float d_balance = 5875, e_balance = 18940, f_balance = 31500;
    float g_balance = 7240, h_balance = 42180, i_balance = 15630;
    float j_balance = 9415;
    // Variables used for login, menu and transactions
    int account, pin, n;
    float balance, withdraw = 0, deposit = 0;
    // Variables for Change PIN
    int current_pin, new_pin, confirm_pin;
    // Variables for ATM and user session
    int atm = 1;
    int session;
    // ---------------- ATM LOOP ----------------
    while (atm == 1)
    {
        // Reset attempts for every new login
        int attempts = 3;
        // ---------------- ACCOUNT NUMBER ----------------
        printf("\n================================\n");
        printf("          BANK LOGIN\n");
        printf("================================\n");
        printf("Enter your Account Number: ");
        scanf("%d", &account);
        // Check whether account exists
        if (account != a_acc && account != b_acc &&
            account != c_acc && account != d_acc &&
            account != e_acc && account != f_acc &&
            account != g_acc && account != h_acc &&
            account != i_acc && account != j_acc)
        {
            printf("Account not found!\n");
            continue;
        }
        // ---------------- PIN VERIFICATION ----------------
        while (attempts > 0)
        {
            printf("Enter your PIN: ");
            scanf("%d", &pin);
            // Check PIN belonging to the selected account
            if ((account == a_acc && pin == a_pin) ||
                (account == b_acc && pin == b_pin) ||
                (account == c_acc && pin == c_pin) ||
                (account == d_acc && pin == d_pin) ||
                (account == e_acc && pin == e_pin) ||
                (account == f_acc && pin == f_pin) ||
                (account == g_acc && pin == g_pin) ||
                (account == h_acc && pin == h_pin) ||
                (account == i_acc && pin == i_pin) ||
                (account == j_acc && pin == j_pin))
            {
                printf("PIN accepted!\n");
                break;
            }
            else
            {
                attempts--;

                printf("Incorrect PIN!\n");
                printf("Attempts remaining: %d\n", attempts);
            }
        }
        // If all three PIN attempts are used
        if (attempts == 0)
        {
            printf("Too many incorrect attempts.\n");
            printf("Your session has been terminated.\n");
            return 0;
        }
        // ---------------- FIND USER BALANCE ----------------
        if (account == a_acc)
        {
            balance = a_balance;
            printf("Welcome, User %d!\n", a_acc);
        }
        else if (account == b_acc)
        {
            balance = b_balance;
            printf("Welcome, User %d!\n", b_acc);
        }
        else if (account == c_acc)
        {
            balance = c_balance;
            printf("Welcome, User %d!\n", c_acc);
        }
        else if (account == d_acc)
        {
            balance = d_balance;
            printf("Welcome, User %d!\n", d_acc);
        }
        else if (account == e_acc)
        {
            balance = e_balance;
            printf("Welcome, User %d!\n", e_acc);
        }
        else if (account == f_acc)
        {
            balance = f_balance;
            printf("Welcome, User %d!\n", f_acc);
        }
        else if (account == g_acc)
        {
            balance = g_balance;
            printf("Welcome, User %d!\n", g_acc);
        }
        else if (account == h_acc)
        {
            balance = h_balance;
            printf("Welcome, User %d!\n", h_acc);
        }
        else if (account == i_acc)
        {
            balance = i_balance;
            printf("Welcome, User %d!\n", i_acc);
        }
        else if (account == j_acc)
        {
            balance = j_balance;
            printf("Welcome, User %d!\n", j_acc);
        }
        // ---------------- ATM SESSION ----------------
        session = 1;
        while (session == 1)
        {
            printf("\n===== ATM MENU =====\n");
            printf("1. Check Balance\n");
            printf("2. Withdraw Money\n");
            printf("3. Deposit Money\n");
            printf("4. Change PIN\n");
            printf("5. Logout\n");
            printf("6. Exit ATM\n");
            printf("Enter your choice: ");
            scanf("%d", &n);
            switch (n)
            {
                // ---------------- CHECK BALANCE ----------------
                case 1:
                    printf("Your balance is ₹%.2f\n", balance);
                    break;
                // ---------------- WITHDRAW MONEY ----------------
                case 2:
                    printf("Enter amount to withdraw: ");
                    scanf("%f", &withdraw);
                    if (withdraw <= 0)
                    {
                        printf("Invalid amount!\n");
                    }
                    else if (withdraw > 20000)
                    {
                        printf("Maximum withdrawal is ₹20,000.\n");
                    }
                    else if (withdraw > balance)
                    {
                        printf("Insufficient balance!\n");
                    }
                    else if (balance - withdraw < 500)
                    {
                        printf("Transaction declined.\n");
                        printf("You must maintain a minimum balance of ₹500.\n");
                    }
                    else
                    {
                        int confirm;
                        printf("You are about to withdraw ₹%.2f\n", withdraw);
                        printf("1. Confirm\n");
                        printf("2. Cancel\n");
                        printf("Enter your choice: ");
                        scanf("%d", &confirm);
                        if (confirm == 1)
                        {
                            balance -= withdraw;
                            printf("Withdrawal successful!\n");
                            printf("Your current balance is ₹%.2f\n", balance);
                            printf("\n================================\n");
                            printf("       TRANSACTION RECEIPT\n");
                            printf("================================\n");
                            printf("Transaction : Withdrawal\n");
                            printf("Amount      : ₹%.2f\n", withdraw);
                            printf("Balance     : ₹%.2f\n", balance);
                            printf("Status      : SUCCESS\n");
                            printf("================================\n");
                            if (balance < 1000)
                            {
                                printf("WARNING: Your account balance is low!\n");
                            }
                        }
                        else if (confirm == 2)
                        {
                            printf("Transaction cancelled.\n");
                        }
                        else
                        {
                            printf("Invalid choice. Transaction cancelled.\n");
                        }
                    }
                    break;
                // ---------------- DEPOSIT MONEY ----------------
                case 3:
                    printf("Enter amount to deposit: ");
                    scanf("%f", &deposit);
                    if (deposit <= 0)
                    {
                        printf("Invalid amount!\n");
                    }
                    else
                    {
                        balance += deposit;
                        printf("You have deposited ₹%.2f\n", deposit);
                        printf("Your current balance is ₹%.2f\n", balance);
                        printf("\n================================\n");
                        printf("       TRANSACTION RECEIPT\n");
                        printf("================================\n");
                        printf("Transaction : Deposit\n");
                        printf("Amount      : ₹%.2f\n", deposit);
                        printf("Balance     : ₹%.2f\n", balance);
                        printf("Status      : SUCCESS\n");
                        printf("================================\n");
                    }
                    break;
                // ---------------- CHANGE PIN ----------------
                case 4:
                    printf("Enter your current PIN: ");
                    scanf("%d", &current_pin);
                    if (current_pin != pin)
                    {
                        printf("Incorrect current PIN!\n");
                    }
                    else
                    {
                        printf("Enter your new PIN: ");
                        scanf("%d", &new_pin);
                        if (new_pin < 1000 || new_pin > 9999)
                        {
                            printf("PIN must contain 4 digits!\n");
                        }
                        else if (new_pin == pin)
                        {
                            printf("New PIN must be different from your current PIN!\n");
                        }
                        // Check whether another user already has this PIN
                        else if (new_pin == a_pin && account != a_acc)
                        {
                            printf("This PIN is already in use!\n");
                        }
                        else if (new_pin == b_pin && account != b_acc)
                        {
                            printf("This PIN is already in use!\n");
                        }
                        else if (new_pin == c_pin && account != c_acc)
                        {
                            printf("This PIN is already in use!\n");
                        }
                        else if (new_pin == d_pin && account != d_acc)
                        {
                            printf("This PIN is already in use!\n");
                        }
                        else if (new_pin == e_pin && account != e_acc)
                        {
                            printf("This PIN is already in use!\n");
                        }
                        else if (new_pin == f_pin && account != f_acc)
                        {
                            printf("This PIN is already in use!\n");
                        }
                        else if (new_pin == g_pin && account != g_acc)
                        {
                            printf("This PIN is already in use!\n");
                        }
                        else if (new_pin == h_pin && account != h_acc)
                        {
                            printf("This PIN is already in use!\n");
                        }
                        else if (new_pin == i_pin && account != i_acc)
                        {
                            printf("This PIN is already in use!\n");
                        }
                        else if (new_pin == j_pin && account != j_acc)
                        {
                            printf("This PIN is already in use!\n");
                        }
                        else
                        {
                            printf("Confirm your new PIN: ");
                            scanf("%d", &confirm_pin);
                            if (new_pin != confirm_pin)
                            {
                                printf("PINs do not match!\n");
                            }
                            else
                            {
                                // Update the correct user's PIN
                                if (account == a_acc)
                                {
                                    a_pin = new_pin;
                                }
                                else if (account == b_acc)
                                {
                                    b_pin = new_pin;
                                }
                                else if (account == c_acc)
                                {
                                    c_pin = new_pin;
                                }
                                else if (account == d_acc)
                                {
                                    d_pin = new_pin;
                                }
                                else if (account == e_acc)
                                {
                                    e_pin = new_pin;
                                }
                                else if (account == f_acc)
                                {
                                    f_pin = new_pin;
                                }
                                else if (account == g_acc)
                                {
                                    g_pin = new_pin;
                                }
                                else if (account == h_acc)
                                {
                                    h_pin = new_pin;
                                }
                                else if (account == i_acc)
                                {
                                    i_pin = new_pin;
                                }
                                else if (account == j_acc)
                                {
                                    j_pin = new_pin;
                                }
                                pin = new_pin;
                                printf("PIN changed successfully!\n");
                            }
                        }
                    }
                    break;
                // ---------------- LOGOUT ----------------
                case 5:
                    // Save balance using ACCOUNT NUMBER
                    if (account == a_acc)
                    {
                        a_balance = balance;
                    }
                    else if (account == b_acc)
                    {
                        b_balance = balance;
                    }
                    else if (account == c_acc)
                    {
                        c_balance = balance;
                    }
                    else if (account == d_acc)
                    {
                        d_balance = balance;
                    }
                    else if (account == e_acc)
                    {
                        e_balance = balance;
                    }
                    else if (account == f_acc)
                    {
                        f_balance = balance;
                    }
                    else if (account == g_acc)
                    {
                        g_balance = balance;
                    }
                    else if (account == h_acc)
                    {
                        h_balance = balance;
                    }
                    else if (account == i_acc)
                    {
                        i_balance = balance;
                    }
                    else if (account == j_acc)
                    {
                        j_balance = balance;
                    }
                    printf("Logging out...\n");
                    printf("Thank you, User %d!\n", account);
                    session = 0;
                    break;
                // ---------------- EXIT ATM ----------------
                case 6:
                    // Save balance using ACCOUNT NUMBER
                    if (account == a_acc)
                    {
                        a_balance = balance;
                    }
                    else if (account == b_acc)
                    {
                        b_balance = balance;
                    }
                    else if (account == c_acc)
                    {
                        c_balance = balance;
                    }
                    else if (account == d_acc)
                    {
                        d_balance = balance;
                    }
                    else if (account == e_acc)
                    {
                        e_balance = balance;
                    }
                    else if (account == f_acc)
                    {
                        f_balance = balance;
                    }
                    else if (account == g_acc)
                    {
                        g_balance = balance;
                    }
                    else if (account == h_acc)
                    {
                        h_balance = balance;
                    }
                    else if (account == i_acc)
                    {
                        i_balance = balance;
                    }
                    else if (account == j_acc)
                    {
                        j_balance = balance;
                    }
                    printf("Thank you for choosing our bank!\n");
                    atm = 0;
                    session = 0;
                    break;
                // ---------------- INVALID CHOICE ----------------
                default:
                    printf("Invalid choice!\n");
            }
            printf("\n");
        }
    }
    return 0;
}