#include "../include/inventory.h"

void generateReport()
{
    FILE *report;

    report = fopen(
        "../reports/optimization_report.txt",
        "w");

    if (report == NULL)
    {
        printf("\nUnable To Generate Report.\n");
        return;
    }

    fprintf(report,
            "====================================\n");

    fprintf(report,
            "MEDICAL SUPPLY OPTIMIZATION REPORT\n");

    fprintf(report,
            "====================================\n\n");

    fprintf(report,
            "Total Inventory Items: %d\n\n",
            total_items);

    for (int i = 0; i < total_items; i++)
    {
        fprintf(report,
                "Item Name : %s\n",
                inventory[i].item_name);

        fprintf(report,
                "Unit Cost : %.2f\n",
                inventory[i].unit_cost);

        fprintf(report,
                "Current Stock : %d\n",
                inventory[i].current_stock);

        fprintf(report,
                "Minimum Required : %d\n\n",
                inventory[i].min_required);
    }

    fclose(report);

    printf("\nReport Generated Successfully.\n");
}