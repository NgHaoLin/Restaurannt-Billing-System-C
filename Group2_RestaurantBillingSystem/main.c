#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaration of function
void display_MainMenu();
void display_OrderMenu();
void display_ComboMeal();
void display_ALaCarte();
void display_beverage();
void display_deleteAllOrder();
void display_deleteOrder();
void display_deleteSelectedItem();
void display_viewOrder();
void display_payment();
void mainMenu();
void addOrder();
void order_comboMeal();
void order_beverage();
void order_aLaCarte();
void clearAll();
void deleteSelectedItem();
void deleteAllOrder();
void deleteOrder();
void display_guestCheck();
void viewOrder();
void payment();
void closeApplication();

//Array to store menu Item
char comboMeal[7][20] = {"",
                         "Family 5-pc Combo ",
                         "Family 9-pc Combo ",
                         "Snack Plate       ",
                         "Dinner Plate      ",
                         "Zinger Burger     ",
                         "Colonel Burger    "};

char aLaCarte[9][20] =  {"",
                         "2-Piece Chicken   ",
                         "5-Piece Chicken   ",
                         "9-Piece Chicken   ",
                         "15-Piece Chicken  ",
                         "Cheesy Wedges     ",
                         "Fries             ",
                         "Whipped Potato    ",
                         "Coleslaw          "};

char beverage[5][20] = { "",
                         "Pepsi             ",
                         "Ice Lemon Tea     ",
                         "Milo              ",
                         "Mineral Water     "};
//Menu price
double comboMeal_price[7] = {0, 30.90, 52.80, 15.00, 19.30, 12.90, 9.70};
double aLaCarte_price[9] = {0, 10.10, 25.20, 44.30, 72.10, 5.90, 5.20, 6.90, 6.90};
double beverage_price[5] = {0, 3.50, 4.10, 4.50, 3.00};

//total price of order
double total=0;

//initialize customer order list and price
char orderList[50][20];     //to record customer order in string
double priceList[50];       //to record food price
int order_count=0;          //to record the amount of item

//Method to check the length of order list
int orderList_length()
{
    int length=0;
    for(int i=0; i<50; i++)
    {
        //count the number of order item
        //by checking the orderList and price
        if(priceList[i] != 0 && orderList[i] != NULL)
        {
            length++;
        }
    }
    return length;
}

//Method to display main menu
void display_MainMenu()
{
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\t|| FAST CHICKEN RESTAURANT ||\n");
    printf("\t\t||     <Main Menu>         ||\n");
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\tWelcome to FAST CHICKEN RESTAURANT!\n\n");
    printf("\tPress[1] Add Order\n");
    printf("\tPress[2] Delete Order\n");
    printf("\tPress[3] View Order\n");
    printf("\tPress[4] Payment\n");
    printf("\tPress[5] Close Applications\n");
}

//Method to display order menu
void display_OrderMenu()
{
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\t|| FAST CHICKEN RESTAURANT ||\n");
    printf("\t\t||     <Add Order>         ||\n");
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\tWelcome to FAST CHICKEN RESTAURANT.\n");
    printf("\tPlease select the meal that you would like to choose.\n\n");
    printf("\tPress[1] Combo Meal\n");
    printf("\tPress[2] A La-Carte\n");
    printf("\tPress[3] Beverage\n");
    printf("\tPress[4] Back to Main Menu\n");
}

//Method to display Combo Meal Menu
void display_ComboMeal()
{
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\t|| FAST CHICKEN RESTAURANT ||\n");
    printf("\t\t||     <Add Order>         ||\n");
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\tPlease select the meal that you would like to choose.\n\n");
    printf("\tCombo Meal:\n");
    printf("\t-----------\n");
    printf("\t[1]Family 5-pc Combo - RM30.90\n");
    printf("\t   <5-pc Chicken, 1 Coleslaw (L), 1 Whipped Potato (L), 2 Pepsi>\n\n");
    printf("\t[2]Family 9-pc Combo - RM52.80\n");
    printf("\t   <9-pc Chicken, 1 Coleslaw (L), 1 Whipped Potato (L), 1 Pepsi (1.5L)>\n\n");
    printf("\t[3]Snack Plate       - RM15.00\n");
    printf("\t   <2-pc Chicken, 1 Coleslaw (R), 1 Whipped Potato (R), 1 Pepsi>\n\n");
    printf("\t[4]Dinner Plate      - RM19.30\n");
    printf("\t   <3-pc Chicken, 1 Coleslaw (R), 1 Whipped Potato (R), 1 Pepsi>\n\n");
    printf("\t[5]Zinger Burger Set - RM12.90\n");
    printf("\t   <1 Zinger Burger, 1 Fried, 1 Peps>\n\n");
    printf("\t[6]Colonel Burger Set- RM9.70\n");
    printf("\t   <1 Colonel Burger, 1 Fired, 1 Pepsi>\n\n");
    printf("\t[7]Back\n\n");
}

//Method to display A La Carte Menu
void display_ALaCarte()
{
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\t|| FAST CHICKEN RESTAURANT ||\n");
    printf("\t\t||     <Add Order>         ||\n");
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\tPlease select the meal that you would like to chose.\n\n");
    printf("\tA-La Carte:\n");
    printf("\t-----------\n");
    printf("\t[1]2-Piece Chicken  - RM10.10\n");
    printf("\t[2]5-Piece Chicken  - RM25.20\n");
    printf("\t[3]9-Piece Chicken  - RM44.30\n");
    printf("\t[4]15-Piece Chicken - RM72.10\n");
    printf("\t[5]Cheesy Wedges    - RM5.90\n");
    printf("\t[6]Fries            - RM5.20\n");
    printf("\t[7]Whipped Potato   - RM6.90\n");
    printf("\t[8]Coleslaw         - RM6.90\n");
    printf("\t[9]Back\n\n");
}

//Method to display Beverage Menu
void display_beverage()
{
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\t|| FAST CHICKEN RESTAURANT ||\n");
    printf("\t\t||     <Add Order>         ||\n");
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\tPlease select the meal that you would like to chose.\n\n");
    printf("\tBeverage:\n");
    printf("\t---------\n");
    printf("\t[1]Pepsi         - RM3.50\n");
    printf("\t[2]Ice Lemon Tea - RM4.10\n");
    printf("\t[3]Milo          - RM4.50\n");
    printf("\t[4]Mineral Water - RM3.00\n");
    printf("\t[5]Back\n\n");

}

//Method to display Delete All Order Screen
void display_deleteAllOrder()
{
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\t|| FAST CHICKEN RESTAURANT ||\n");
    printf("\t\t||     <Delete Order>      ||\n");
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("\t    Are you sure you want to clear all item?\n");
    printf("\t        Yes?        |      No?\n\n");

}

//Method to display Delete Order Menu
void display_deleteOrder()
{
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\t|| FAST CHICKEN RESTAURANT ||\n");
    printf("\t\t||     <Delete Order>      ||\n");
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("\tPress[1] Delete All Item\n");
    printf("\tPress[2] Delete Selected Item\n");
    printf("\tPress[3] Back to Main Menu\n");

}

//Method to display Delete Selected Item Screen
void display_deleteSelectedItem()
{
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\t|| FAST CHICKEN RESTAURANT ||\n");
    printf("\t\t||     <Delete Order>      ||\n");
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("\t------------ Current Order ------------\n");

}

//Method to display View Order Screen
void display_viewOrder()
{
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\t|| FAST CHICKEN RESTAURANT ||\n");
    printf("\t\t||     <View Order>        ||\n");
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("\t------------- Guest Check -------------\n");

}

//Method to Display Payment Screen
void display_payment()
{
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\t|| FAST CHICKEN RESTAURANT ||\n");
    printf("\t\t||        <Payment>        ||\n");
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("\t\tITEMS           PRICE(in RM.)\n");
    printf("\t--------------------------------------------\n");
}

//Main Menu Method
void mainMenu()
{
    int mainMenu_choice;
    printf("\n\tEnter Menu Number Here: ");
    scanf("%d", &mainMenu_choice);

    switch(mainMenu_choice)
    {
        case 1:
            system("cls");      // to clear the console screen
            display_OrderMenu();
            addOrder();
            break;
        case 2:
            system("cls");
            display_deleteOrder();
            deleteOrder();
            break;
        case 3:
            system("cls");
            display_viewOrder();
            viewOrder();
            break;
        case 4:
            //check total price to avoid user enter payment without order
            if(total==0)
            {
                printf("\n\tYour Order list is empty. Please order before payment.\n\n");
                mainMenu();
            }
            else
            {
                system("cls");
                payment();
            }
            break;
        case 5:
            closeApplication();
            break;
        default:
            printf("\n\tInvalid input. Please try again.\n");
            mainMenu();
    }
}

//Add order method
//Select combo meal, ala carte, beverage
void addOrder()
{
    int choice;
    printf("\n\tEnter your choice here: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            system("cls");
            display_ComboMeal();
            order_comboMeal();
            break;
        case 2:
            system("cls");
            display_ALaCarte();
            order_aLaCarte();
            break;
        case 3:
            system("cls");
            display_beverage();
            order_beverage();
            break;
        case 4:
            system("cls");
            display_MainMenu();
            mainMenu();
            break;
        default:
            printf("\n\tInvalid input. Please try again.\n");
            addOrder();
    }
}

//Method to order combo meal
/*
    -add selected combo meal to order list
    -add selected combo meal's price to price list
    -sum all price to total
    -count number of order item
*/
void order_comboMeal()
{
    int choice;
    printf("\tEnter your choice here:");
    scanf("%d", &choice);

    if(choice > 0 && choice <= 6)
    {
        total = total + comboMeal_price[choice];
        strcpy(orderList[order_count], comboMeal[choice]);
        priceList[order_count] = comboMeal_price[choice];
        order_count++;
        order_comboMeal();
    }
    else if(choice == 7){
        system("cls");
        display_OrderMenu();
        addOrder();
    }
    else{
        //error message pop out if user input is out of the menu number
        printf("\n\tInvalid input. Please try again.\n\n");
        order_comboMeal();
    }
}

//Method to order ala carte
/*
    -add selected ala carte to order list
    -add selected combo meal's price to price list
    -sum all price to total
    -count amount of order
*/
void order_aLaCarte()
{
    int choice;
    printf("\tEnter your choice here:");
    scanf("%d", &choice);

    if(choice > 0 && choice <= 8)
    {
        total = total + aLaCarte_price[choice];
        strcpy(orderList[order_count], aLaCarte[choice]);
        priceList[order_count] = aLaCarte_price[choice];
        order_count++;
        order_aLaCarte();
    }
    else if(choice == 9)
    {
        system("cls");
        display_OrderMenu();
        addOrder();
    }
    else
    {
        //error message pop out if user input is out of the menu number
        printf("\n\tInvalid input. Please try again.\n\n");
        order_aLaCarte();
    }
}

//Method to order beverage
/*
    -add selected beverage to order list
    -add selected beverage's price to price list
    -sum all price to total
    -count amount of orders
*/
void order_beverage()
{
    int choice;
    printf("\tEnter your choice here:");
    scanf("%d", &choice);

    if(choice > 0 && choice <= 4)
    {
        total = total + beverage_price[choice];
        strcpy(orderList[order_count], beverage[choice]);
        priceList[order_count] = beverage_price[choice];
        order_count++;
        order_beverage();
    }
    else if(choice == 5){
        system("cls");
        display_OrderMenu();
        addOrder();
    }
    else{
        //error message pop out if user input is out of the menu number
        printf("\n\tInvalid input. Please try again.\n\n");
        order_beverage();
    }
}

//Method to reset
/*
    reset order list and price list array to null
    reset total and order count to 0
*/
void clearAll()
{
    total = 0;
    order_count = 0;
    memset(orderList, 0, sizeof(orderList));
    memset(priceList, 0, sizeof(priceList));
}

//Method to delete selected item
/*
    delete selected item from order list array
    delete price of selected item from price list array
*/
void deleteSelectedItem()
{
    int choice;
    int length = orderList_length();

    display_deleteSelectedItem();
    display_guestCheck();
    printf("\n\tPress 0 to go back main menu: ");
    printf("\n\tEnter index of elements that you wish to delete: ");
    scanf("%d", &choice);

    //input is out of menu number
    if(choice <0 || choice > orderList_length())
    {
        system("cls");
        printf("\n\n\tInvalid Input. Please enter a valid index.\n\n");
        deleteSelectedItem();
    }
    //to return main mennu
    else if(choice == 0)
    {
        system("cls");
        display_MainMenu();
        mainMenu();
    }
    //delete selected item
    else
    {
        total = total - (priceList[choice-1]);

        //rearrange order list and price list after deletion
        for(int i=choice-1; i<length; i++)
        {
            strcpy(orderList[i], orderList[i+1]);
            priceList[i] = priceList[i+1];
        }
        order_count = order_count - 1;  //delete 1 from order_count
        priceList[length] = 0;          //set the previous last item of price list to 0
        system("cls");
        deleteSelectedItem();
    }
}

//Method to delete all order
//call clearAll() method
void deleteAllOrder()
{
    char choice;
    printf("\n\tEnter your choice (Y/N): ");
    scanf(" %c", &choice);

    if(choice == 'Y')
    {
        //call clearAll to reset all data
        clearAll();
        system("cls");
        display_MainMenu();
        mainMenu();
    }
    else if(choice == 'N'){
        printf("\n\tDeletion cancelled.\n");
        system("cls");
        display_MainMenu();
        mainMenu();
    }
    else{
        printf("\n\tInvalid input. Please try again.\n");
        deleteAllOrder();
    }

}

//Method delete order menu
void deleteOrder()
{
    int choice;
    printf("\n\tEnter your choice here:");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            system("cls");
            display_deleteAllOrder();
            deleteAllOrder();
            break;
        case 2:
            system("cls");
            deleteSelectedItem();
            break;
        case 3:
            system("cls");
            display_MainMenu();
            mainMenu();
            break;
        default:
            printf("\n\tInvalid input. Please try again.\n");
            deleteOrder();
    }
}

//Method to list out customer order item and price
void display_guestCheck()
{
    for(int i=0; i<orderList_length(); i++)
    {
        //print menu item and price
        printf("\t[%d] %s\t\tRM%.2f\n", i+1, orderList[i], priceList[i]);
    }
    printf("\n\t\t\tTotal :\t\tRM%.2f\n", total);
}

//Method to view customer order
//call display_guestheck() method
void viewOrder()
{
    int back;
    display_guestCheck();
    printf("\n\tPress 0 to go back main menu: ");
    scanf("%d", &back);
    while(back!= 0){
        //print error message until 0 is pressed
        printf("\n\tInvalid input. Please press 0: ");
        scanf("%d", &back);
    }
    system("cls");
    display_MainMenu();
    mainMenu();
}

//Payment method
/*
    display customer order list
    display total price
    calculate the change
    print order reciept
*/
void payment()
{
    double amountPaid;
    double totalAmountPaid;
    double change;
    char newOrder;

    //display payment screen
    display_payment();
    display_guestCheck();
    printf("\t--------------------------------------------\n");
    printf("\t\t\tTotal:\t\tRM%.2f\n", total);
    printf("\n\tAmount Paid: RM");
    scanf("%lf", &totalAmountPaid);

    while(totalAmountPaid < total)
    {
        //printing the remaining amount to paid
        printf("\tUnable to complete transaction. You need to pay more RM%.2f\n", total-totalAmountPaid);
        printf("\tAmount Paid: RM");
        scanf("%lf", &amountPaid);
        totalAmountPaid = totalAmountPaid + amountPaid;
    }

    //Printing customer receipt
    change = totalAmountPaid - total;
    system("cls");
    printf("\n\t----------------RECEIPT---------------------\n");
    display_payment();
    display_guestCheck();
    printf("\t--------------------------------------------\n");
    printf("\t\t\tTotal :\t\tRM%.2f\n", total);
    printf("\t\t\tCash  :\t\tRM%.2f\n", totalAmountPaid);
    printf("\t\t\tChange:\t\tRM%.2f\n", change);
    printf("\n\t-----------THANK YOU FOR VISITING-----------\n");

    //reset all data
    clearAll();

    //to start a new order
    printf("\n\tStart a new order? (Y/N):  ");
    scanf(" %c", &newOrder);

    while(newOrder != 'Y' && newOrder != 'N'){
        printf("\n\tInvalid input. Please press Y/N: ");
        scanf(" %c", &newOrder);
    }

    if(newOrder == 'Y')
    {
        system("cls");
        display_MainMenu();
        mainMenu();
    }
    else if(newOrder == 'N'){
        closeApplication();
    }
}

//Method to exit program
void closeApplication()
{
    printf("\n\t-----------------APPLICATION CLOSED------------------");
    exit(0);
}

//Main Method
int main()
{
    display_MainMenu();
    mainMenu();
    return 0;
}
