#include <stdio.h>

int main() {
    int prices[5] = {50, 30, 80, 120, 60};   
    char items[5][20] = {"Coffee", "Tea", "Sandwich", "Burger", "Pastry"};
    int qtySold[5] = {0, 0, 0, 0, 0};
    int customers, i, j, itemNo, qty;
    int totalRevenue = 0, totalItemsSold = 0;

    printf("========= Café Order Management System =========\n");
    printf("Menu:\n");
    printf("Item No.\tItem Name\tPrice (₹)\n");
    for (i = 0; i < 5; i++) {
        printf("%d\t\t%-10s\t₹%d\n", i + 1, items[i], prices[i]);
    }

    printf("-----------------------------------------------\n");
    printf("Enter total number of customers (max 10): ");
    scanf("%d", &customers);

    if (customers > 10 || customers < 1) {
        printf("Invalid number of customers! Exiting...\n");
        return 0;
    }

    
    for (i = 0; i < customers; i++) {
        int numItems;
        int customerTotal = 0;

        printf("\n--- Customer %d ---\n", i + 1);
        printf("Enter number of items: ");
        scanf("%d", &numItems);

        
        for (j = 0; j < numItems; j++) {
            printf("Enter item number and quantity: ");
            scanf("%d %d", &itemNo, &qty);

            if (itemNo < 1 || itemNo > 5 || qty < 1) {
                printf("Invalid item number or quantity! Skipping...\n");
                continue;
            }

            customerTotal += prices[itemNo - 1] * qty;
            qtySold[itemNo - 1] += qty;
            totalItemsSold += qty;
        }

        printf("Total Bill for Customer %d: ₹%d\n", i + 1, customerTotal);
        totalRevenue += customerTotal;
    }

    
    int maxQty = qtySold[0], minQty = qtySold[0];
    int mostItemIndex = 0, leastItemIndex = 0;

    for (i = 1; i < 5; i++) {
        if (qtySold[i] > maxQty) {
            maxQty = qtySold[i];
            mostItemIndex = i;
        }
        if (qtySold[i] < minQty) {
            minQty = qtySold[i];
            leastItemIndex = i;
        }
    }

   
    printf("\n========= Café Summary =========\n");
    printf("Total Revenue: ₹%d\n", totalRevenue);
    printf("Total Items Sold: %d\n", totalItemsSold);
    printf("Most Ordered Item: %s\n", items[mostItemIndex]);
    printf("Least Ordered Item: %s\n", items[leastItemIndex]);
    printf("================================\n");

    return 0;
}
