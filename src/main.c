#include "../include/inventory.h"

int main()
{
    int choice;

    float target_budget;

    int selected[MAX_ITEMS] = {0};

    loadDataset("../data/inventory_data.csv");

    do
    {
        printf("\n====================================\n");

        printf(" SMART MEDICAL SUPPLY OPTIMIZER\n");

        printf("====================================\n");

        printf("1. Display Inventory\n");

        printf("2. Low Stock Alerts\n");

        printf("3. Exact Budget Optimization\n");

        printf("4. Closest Budget Optimization\n");

        printf("5. Emergency Optimization\n");

        printf("6. Generate Report\n");

        printf("7. Exit\n");

        printf("====================================\n");

        printf("Enter Choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                displayInventory();

                break;

            case 2:

                lowStockAlert();

                break;

            case 3:

                printf("\nEnter Target Budget: ");

                scanf("%f", &target_budget);

                exactSubsetSum(
                    0,
                    0,
                    target_budget,
                    selected);

                break;

            case 4:

                printf("\nEnter Target Budget: ");

                scanf("%f", &target_budget);

                closestSubsetSum(
                    0,
                    0,
                    target_budget,
                    selected);

                printf("\n======= CLOSEST MATCH =======\n");

                printCombination(
                    best_selected,
                    best_sum);

                break;

            case 5:

                emergencyOptimization();

                break;

            case 6:

                generateReport();

                break;

            case 7:

                printf("\nExiting System...\n");

                break;

            default:

                printf("\nInvalid Choice.\n");
        }

    } while (choice != 7);

    return 0;
}