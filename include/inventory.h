#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 500
#define NAME_LEN 100

typedef struct
{
    char date[20];
    int item_id;
    char item_type[50];
    char item_name[100];

    int current_stock;
    int min_required;
    int max_capacity;

    float unit_cost;

    int avg_usage_per_day;
    int restock_lead_time;

    char vendor_id[50];

} MedicalSupply;

extern MedicalSupply inventory[MAX_ITEMS];

extern int total_items;

void loadDataset(const char *filename);

void displayInventory();

void lowStockAlert();

void exactSubsetSum(
    int index,
    float current_sum,
    float target,
    int selected[]
);

void closestSubsetSum(
    int index,
    float current_sum,
    float target,
    int selected[]
);

void emergencyOptimization();

void generateReport();

extern float best_sum;

extern int best_selected[MAX_ITEMS];

void printCombination(
    int selected[],
    float total
);

#endif