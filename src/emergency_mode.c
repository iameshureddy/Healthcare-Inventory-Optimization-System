#include "../include/inventory.h"

void emergencyOptimization()
{
    printf("\n======= EMERGENCY PRIORITY MODE =======\n");

    for (int i = 0; i < total_items; i++)
    {
        float priority_score;

        priority_score =
            (inventory[i].avg_usage_per_day *
             inventory[i].restock_lead_time)
            /
            (inventory[i].current_stock + 1.0);

        printf("\nItem: %s\n",
               inventory[i].item_name);

        printf("Priority Score: %.2f\n",
               priority_score);

        if (priority_score > 5)
        {
            printf("STATUS: HIGH PRIORITY\n");
        }
        else
        {
            printf("STATUS: NORMAL\n");
        }
    }
}