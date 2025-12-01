#include <stdio.h>
#include <string.h>

#define MAX 100

// ---------------------------------------------------------------------
// Structure to store item details
// ---------------------------------------------------------------------
struct Item {
    int id;                 // unique ID
    char name[50];          // item name
    int quantity;           // quantity in stock
    float price;            // price per item
};

// Global array
struct Item stock[MAX];
int count = 0;

// ---------------------------------------------------------------------
// Function Prototypes
// ---------------------------------------------------------------------
void addItem();
void displayItems();
void searchItem();
void updateItem();
void deleteItem();
void generateBill();
void menu();

// ---------------------------------------------------------------------
// MAIN FUNCTION
// ---------------------------------------------------------------------
int main() {
    int choice;

    while (1) {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: displayItems(); break;
            case 3: searchItem(); break;
            case 4: updateItem(); break;
            case 5: deleteItem(); break;
            case 6: generateBill(); break;
            case 7: 
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}

// ---------------------------------------------------------------------
// MENU FUNCTION
// ---------------------------------------------------------------------
void menu() {
    printf("\n---------------- STOCK MANAGEMENT SYSTEM ----------------");
    printf("\n1. Add Item");
    printf("\n2. Display All Items");
    printf("\n3. Search Item");
    printf("\n4. Update Item");
    printf("\n5. Delete Item");
    printf("\n6. Generate Bill");
    printf("\n7. Exit");
    printf("\n---------------------------------------------------------\n");
}

// ---------------------------------------------------------------------
// ADD ITEM FUNCTION
// ---------------------------------------------------------------------
void addItem() {
    if (count >= MAX) {
        printf("\nStock Full! Cannot add more items.\n");
        return;
    }

    printf("\nEnter Item ID: ");
    scanf("%d", &stock[count].id);

    printf("Enter Item Name: ");
    scanf("%s", stock[count].name);

    printf("Enter Quantity: ");
    scanf("%d", &stock[count].quantity);

    printf("Enter Price: ");
    scanf("%f", &stock[count].price);

    count++;

    printf("\nItem Added Successfully!\n");
}

// ---------------------------------------------------------------------
// DISPLAY ALL ITEMS
// ---------------------------------------------------------------------
void displayItems() {
    int i;

    if (count == 0) {
        printf("\nNo items available!\n");
        return;
    }

    printf("\n------------------ STOCK DETAILS ------------------\n");
    printf("ID\tName\tQuantity\tPrice\n");
    printf("---------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n",
               stock[i].id,
               stock[i].name,
               stock[i].quantity,
               stock[i].price);
    }
}

// ---------------------------------------------------------------------
// SEARCH ITEM
// ---------------------------------------------------------------------
void searchItem() {
    int id, i, found = 0;

    printf("\nEnter Item ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (stock[i].id == id) {
            printf("\nItem Found!\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",
                   stock[i].id,
                   stock[i].name,
                   stock[i].quantity,
                   stock[i].price);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nItem Not Found!\n");
}

// ---------------------------------------------------------------------
// UPDATE ITEM
// ---------------------------------------------------------------------
void updateItem() {
    int id, i, found = 0;

    printf("\nEnter Item ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (stock[i].id == id) {
            printf("\nEnter new name: ");
            scanf("%s", stock[i].name);

            printf("Enter new quantity: ");
            scanf("%d", &stock[i].quantity);

            printf("Enter new price: ");
            scanf("%f", &stock[i].price);

            printf("\nItem Updated Successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nItem Not Found!\n");
}

// ---------------------------------------------------------------------
// DELETE ITEM
// ---------------------------------------------------------------------
void deleteItem() {
    int id, i, j, found = 0;

    printf("\nEnter Item ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (stock[i].id == id) {
            for (j = i; j < count - 1; j++) {
                stock[j] = stock[j + 1];
            }
            count--;
            printf("\nItem Deleted Successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nItem Not Found!\n");
}

// ---------------------------------------------------------------------
// GENERATE BILL
// ---------------------------------------------------------------------
void generateBill() {
    int id, qty, i;
    float total = 0;

    if (count == 0) {
        printf("\nNo items available for billing!\n");
        return;
    }

    printf("\nEnter Item ID to buy: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (stock[i].id == id) {
            printf("Enter quantity to buy: ");
            scanf("%d", &qty);

            if (qty > stock[i].quantity) {
                printf("\nNot enough stock available!\n");
                return;
            }

            total = qty * stock[i].price;
            stock[i].quantity -= qty;

            printf("\n------- BILL --------\n");
            printf("Item: %s\n", stock[i].name);
            printf("Qty: %d\n", qty);
            printf("Price: %.2f\n", stock[i].price);
            printf("Total Amount: %.2f\n", total);
            printf("----------------------\n");

            return;
        }
    }

    printf("\nItem Not Found!\n");
}
