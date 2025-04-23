#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int acc_no;
    char name[100];
    char phone[10];
    float balance;
} Account;

// Function prototypes
void create_account();
void display_account();
void deposit_money();
void withdraw_money();
void search_account();
void update_account();
void delete_account();

// Main function
int main() {
    int choice;
    while (1) {
        printf("\n\n=== BANK MANAGEMENT SYSTEM ===\n");
        printf("1. Create Account\n");
        printf("2. View All Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Search Account\n");
        printf("6. Update Account\n");
        printf("7. Delete Account\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create_account(); 
                    break;
            case 2: display_account(); 
                    break;
            case 3: deposit_money();
                    break;
            case 4: withdraw_money(); 
                    break;
            case 5: search_account();
                    break;
            case 6: update_account(); 
                    break;
            case 7: delete_account(); 
                    break;
            case 8: exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void create_account() {
    Account a;
    FILE *fp = fopen("accounts.dat", "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &a.acc_no);
    printf("Enter Name: ");
    scanf(" %[^\n]", a.name);
    printf("Enter the phone number: ");
    scanf(" %[^\n]", a.phone); 
    printf("Enter Initial Balance: ");
    scanf("%f", &a.balance);

    fwrite(&a, sizeof(Account), 1, fp);
    fclose(fp);
    printf("Account created successfully!\n");
}


// Function to display all accounts
void display_account() {
    Account a;
    FILE *fp = fopen("accounts.dat", "rb");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n--- All Accounts ---\n");
    while (fread(&a, sizeof(Account), 1, fp)) {
        printf("Acc No: %d, Name: %s, Balance: %.2f\n", a.acc_no, a.name, a.balance);
    }
    fclose(fp);
}

// Function to deposit money
void deposit_money() {
    int acc;
    float amount;
    Account a;
    FILE *fp = fopen("accounts.dat", "rb+");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acc);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    while (fread(&a, sizeof(Account), 1, fp)) {
        if (a.acc_no == acc) {
            a.balance += amount;
            fseek(fp, -sizeof(Account), SEEK_CUR);
            fwrite(&a, sizeof(Account), 1, fp);
            printf("Amount deposited successfully.\n");
            fclose(fp);
            return;
        }
    }
    printf("Account not found.\n");
    fclose(fp);
}

// Function to withdraw money
void withdraw_money() {
    int acc;
    float amount;
    Account a;
    FILE *fp = fopen("accounts.dat", "rb+");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acc);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    while (fread(&a, sizeof(Account), 1, fp)) {
        if (a.acc_no == acc) {
            if (a.balance >= amount) {
                a.balance -= amount;
                fseek(fp, -sizeof(Account), SEEK_CUR);
                fwrite(&a, sizeof(Account), 1, fp);
                printf("Amount withdrawn successfully.\n");
            } else {
                printf("Insufficient balance.\n");
            }
            fclose(fp);
            return;
        }
    }
    printf("Account not found.\n");
    fclose(fp);
}

// Function to search an account
void search_account() {
    int acc;
    Account a;
    FILE *fp = fopen("accounts.dat", "rb");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    while (fread(&a, sizeof(Account), 1, fp)) {
        if (a.acc_no == acc) {
            printf("Account found: %d, Name: %s, Balance: %.2f\n", a.acc_no, a.name, a.balance);
            fclose(fp);
            return;
        }
    }
    printf("Account not found.\n");
    fclose(fp);
}

// Function to update account
void update_account() {
    int acc;
    Account a;
    FILE *fp = fopen("accounts.dat", "rb+");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Account Number to update: ");
    scanf("%d", &acc);

    while (fread(&a, sizeof(Account), 1, fp)) {
        if (a.acc_no == acc) {
            printf("Enter new name: ");
            scanf(" %[^\n]", a.name);
            printf("Enter new balance: ");
            scanf("%f", &a.balance);

            fseek(fp, -sizeof(Account), SEEK_CUR);
            fwrite(&a, sizeof(Account), 1, fp);
            printf("Account updated successfully.\n");
            fclose(fp);
            return;
        }
    }
    printf("Account not found.\n");
    fclose(fp);
}

// Function to delete account
void delete_account() {
    int acc;
    Account a;
    FILE *fp = fopen("accounts.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (!fp || !temp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Account Number to delete: ");
    scanf("%d", &acc);

    int found = 0;
    while (fread(&a, sizeof(Account), 1, fp)) {
        if (a.acc_no != acc) {
            fwrite(&a, sizeof(Account), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove("accounts.dat");
    rename("temp.dat", "accounts.dat");

    if (found)
        printf("Account deleted successfully.\n");
    else
        printf("Account not found.\n");
}
