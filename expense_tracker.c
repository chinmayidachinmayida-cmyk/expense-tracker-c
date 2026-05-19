#include <stdio.h>
#include <stdlib.h>

struct Expense {
    char name[50];
    float amount;
};

void addExpense() {
    struct Expense e;

    FILE *file = fopen("expenses.txt", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Expense Name: ");
    scanf(" %[^\n]", e.name);

    printf("Enter Amount: ");
    scanf("%f", &e.amount);

    fprintf(file, "%s %.2f\n", e.name, e.amount);

    fclose(file);

    printf("Expense Added Successfully!\n");
}

void viewExpenses() {
    struct Expense e;

    FILE *file = fopen("expenses.txt", "r");

    if (file == NULL) {
        printf("No expenses found!\n");
        return;
    }

    printf("\n----- Expense List -----\n");

    while (fscanf(file, "%s %f", e.name, &e.amount) != EOF) {
        printf("Expense: %s | Amount: %.2f\n", e.name, e.amount);
    }

    fclose(file);
}

void totalExpense() {
    struct Expense e;
    float total = 0;

    FILE *file = fopen("expenses.txt", "r");

    if (file == NULL) {
        printf("No expenses found!\n");
        return;
    }

    while (fscanf(file, "%s %f", e.name, &e.amount) != EOF) {
        total += e.amount;
    }

    fclose(file);

    printf("\nTotal Expense: %.2f\n", total);
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Expense Tracker =====\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Total Expense\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;

            case 2:
                viewExpenses();
                break;

            case 3:
                totalExpense();
                break;

            case 4:
                printf("Exiting Program...\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}