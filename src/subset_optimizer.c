#include "../include/inventory.h"

float best_sum = 0;

int best_selected[MAX_ITEMS];

void printCombination(int selected[], float total)
{
    printf("\n======= OPTIMIZED COMBINATION =======\n");

    for (int i = 0; i < total_items; i++)
    {
        if (selected[i] == 1)
        {
            printf("%s | Cost: %.2f\n",
                   inventory[i].item_name,
                   inventory[i].unit_cost);
        }
    }

    printf("\nTotal Cost: %.2f\n", total);
}

void exactSubsetSum(
    int index,
    float current_sum,
    float target,
    int selected[])
{
    if (current_sum == target)
    {
        printCombination(selected, current_sum);
        return;
    }

    if (index >= total_items || current_sum > target)
    {
        return;
    }

    selected[index] = 1;

    exactSubsetSum(
        index + 1,
        current_sum + inventory[index].unit_cost,
        target,
        selected);

    selected[index] = 0;

    exactSubsetSum(
        index + 1,
        current_sum,
        target,
        selected);
}

void closestSubsetSum(
    int index,
    float current_sum,
    float target,
    int selected[])
{
    if (current_sum <= target &&
        current_sum > best_sum)
    {
        best_sum = current_sum;

        for (int i = 0; i < total_items; i++)
        {
            best_selected[i] = selected[i];
        }
    }

    if (index >= total_items ||
        current_sum > target)
    {
        return;
    }

    selected[index] = 1;

    closestSubsetSum(
        index + 1,
        current_sum + inventory[index].unit_cost,
        target,
        selected);

    selected[index] = 0;

    closestSubsetSum(
        index + 1,
        current_sum,
        target,
        selected);
}