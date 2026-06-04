#include "../include/inventory.h"

MedicalSupply inventory[MAX_ITEMS];

int total_items = 0;

void loadDataset(const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("\nERROR: Unable to open dataset file.\n");
        return;
    }

    char line[1024];

    // Skip CSV header
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file))
    {
        if (total_items >= MAX_ITEMS)
        {
            break;
        }

        MedicalSupply item;

        char *token;

        token = strtok(line, ",");
        if (token)
            strcpy(item.date, token);

        token = strtok(NULL, ",");
        if (token)
            item.item_id = atoi(token);

        token = strtok(NULL, ",");
        if (token)
            strcpy(item.item_type, token);

        token = strtok(NULL, ",");
        if (token)
            strcpy(item.item_name, token);

        token = strtok(NULL, ",");
        if (token)
            item.current_stock = atoi(token);

        token = strtok(NULL, ",");
        if (token)
            item.min_required = atoi(token);

        token = strtok(NULL, ",");
        if (token)
            item.max_capacity = atoi(token);

        token = strtok(NULL, ",");
        if (token)
            item.unit_cost = atof(token);

        token = strtok(NULL, ",");
        if (token)
            item.avg_usage_per_day = atoi(token);

        token = strtok(NULL, ",");
        if (token)
            item.restock_lead_time = atoi(token);

        token = strtok(NULL, ",");
        if (token)
        {
            token[strcspn(token, "\n")] = '\0';
            strcpy(item.vendor_id, token);
        }

        inventory[total_items] = item;

        total_items++;
    }

    fclose(file);

    printf("\nDataset Loaded Successfully.\n");
    printf("Total Records Loaded: %d\n", total_items);
}