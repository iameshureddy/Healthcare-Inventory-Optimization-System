#include "../include/inventory.h"

void displayInventory()
{
    printf("\n=========== INVENTORY ===========\n");

    for (int i = 0; i < total_items; i++)
    {
        printf("\nItem %d\n", i + 1);

        printf("Item ID           : %d\n", inventory[i].item_id);

        printf("Item Name         : %s\n", inventory[i].item_name);

        printf("Item Type         : %s\n", inventory[i].item_type);

        printf("Current Stock     : %d\n", inventory[i].current_stock);

        printf("Minimum Required  : %d\n", inventory[i].min_required);

        printf("Maximum Capacity  : %d\n", inventory[i].max_capacity);

        printf("Unit Cost         : %.2f\n", inventory[i].unit_cost);

        printf("Daily Usage       : %d\n",
               inventory[i].avg_usage_per_day);

        printf("Restock Lead Time : %d\n",
               inventory[i].restock_lead_time);

        printf("Vendor ID         : %s\n",
               inventory[i].vendor_id);
    }
}

void lowStockAlert()
{
    printf("\n======= LOW STOCK ALERTS =======\n");

    int found = 0;

    for (int i = 0; i < total_items; i++)
    {
        if (inventory[i].current_stock <
            inventory[i].min_required)
        {
            found = 1;

            printf("\nWARNING\n");

            printf("Item Name : %s\n",
                   inventory[i].item_name);

            printf("Current Stock : %d\n",
                   inventory[i].current_stock);

            printf("Minimum Required : %d\n",
                   inventory[i].min_required);
        }
    }

    if (!found)
    {
        printf("\nNo Low Stock Items Found.\n");
    }
}