// bank account management using c
#include <stdio.h>

typedef struct {
    int accountNumber;
    char accountType;
    double balance;
    char name[100];
    char address[100];
    char contactNumber[20];
} Account;

void createAccount(Account* account) {
    static int accountCounter = 1000;
    account->accountNumber = accountCounter++;
    
    printf("Enter account type (S for Savings, C for Current): ");
    scanf(" %c", &account->accountType);
    
    printf("Enter initial balance: ");
    scanf("%lf", &account->balance);
    
    printf("Enter name: ");
    scanf(" %[^\n]s", account->name);

    printf("Enter address: ");
    scanf(" %[^\n]s", account->address);

    printf("Enter contact number: ");
    scanf(" %[^\n]s", account->contactNumber);
}

void deposit(Account* account, double amount) {
    account->balance += amount;
    printf("Deposited %.2lf. New balance: %.2lf\n", amount, account->balance);
}

void withdraw(Account* account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrawn %.2lf. New balance: %.2lf\n", amount, account->balance);
    } else {
        printf("Insufficient funds. Current balance: %.2lf\n", account->balance);
    }
}

void calculateInterest(Account* account) {
    double interestRate = (account->accountType == 'S') ? 0.05 : 0.02;
    double interest = account->balance * interestRate;
    account->balance += interest;
    printf("Interest of %.2lf applied. New balance: %.2lf\n", interest, account->balance);
}

void displayAccount(Account account) {
    printf("Account Number: %d\n", account.accountNumber);
    printf("Account Type: %c\n", account.accountType);
    printf("Name: %s\n", account.name);
    printf("Address: %s\n", account.address);
    printf("Contact Number: %s\n", account.contactNumber);
    printf("Balance: %.2lf\n", account.balance);
}

int main() {
    Account account;
    int choice;
    double amount;

    createAccount(&account);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Calculate Interest\n");
        printf("4. Display Account Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                deposit(&account, amount);
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                withdraw(&account, amount);
                break;
            case 3:
                calculateInterest(&account);
                break;
            case 4:
                displayAccount(account);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
