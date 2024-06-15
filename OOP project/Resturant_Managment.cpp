#include<iostream>
#include<conio.h>

using namespace std;

class Restaurant {
private:
	// Purchased quantities
    int purchasedPizza = 0, purchasedBurger = 0, purchasedSandWich = 0, purchasedIceCream = 0;
    int  purchasedCake = 0, purchasedBiryani = 0, purchasedChickenKarahi = 0;
    // Sales quantities
    int soldPizza = 0, soldBurger = 0, soldSandWich = 0, soldIceCream = 0, soldCake = 0;
    int  soldBiryani = 0, soldChickenKarahi = 0;
    // Total Sales
    int totalPizzaPrice = 0, totalBurgerPrice = 0, totalSandWichPrice = 0, totalIceCreamPrice = 0;
    int  totalCakePrice = 0, totalBiryaniPrice = 0, totalChickenKarahiPrice = 0;
    // Prices for each item
    int pizzaPrice = 0, burgerPrice = 0, sandWichPrice = 0, iceCreamPrice = 0, cakePrice = 0, biryaniPrice = 0, chickenKarahiPrice = 0;

public:
    void purchaseItems() {

        cout << "\n\t\t\tPurchase Items";
        cout << "\n\n Number of Pizza : ";
        cin >> purchasedPizza;
        cout << "\n\n Number of Burger : ";
        cin >> purchasedBurger;
        cout << "\n\n Number of Sandwich : ";
        cin >> purchasedSandWich;
        cout << "\n\n Number of Ice-Cream : ";
        cin >> purchasedIceCream;
        cout << "\n\n Number of Cake : ";
        cin >> purchasedCake;
        cout << "\n\n Number of Biryani : ";
        cin >> purchasedBiryani;
        cout << "\n\n Number of Chicken Karahi : ";
        cin >> purchasedChickenKarahi;
        cout << "\n\n Price of Pizza : ";
        cin >> pizzaPrice;
        cout << "\n\n Price of Burger : ";
        cin >> burgerPrice;
        cout << "\n\n Price of Sandwich : ";
        cin >> sandWichPrice;
        cout << "\n\n Price of Ice-Cream : ";
        cin >> iceCreamPrice;
        cout << "\n\n Price of Cake : ";
        cin >> cakePrice;
        cout << "\n\n Price of Biryani : ";
        cin >> biryaniPrice;
        cout << "\n\n Price of Chicken Karahi : ";
        cin >> chickenKarahiPrice;
    }

    void showDetails() {
        system("cls");
        cout << "\n\t\t\tDetails Panel";
        cout << "\n\n Purchase Pizza Quantity : " << purchasedPizza;
        cout << "\n Sales Pizza Quantity : " << soldPizza;
        cout << "\n Remaining Pizza Quantity : " << purchasedPizza - soldPizza;
        cout << "\n Total Pizza Price in a Day : " << totalPizzaPrice;


        cout << "\n\n Purchase Burger Quantity : " << purchasedBurger;
        cout << "\n Sales Burger Quantity : " << soldBurger;
        cout << "\n Remaining Burger Quantity : " << purchasedBurger - soldBurger;
        cout << "\n Total Burger Price in a Day : " << totalBurgerPrice;

        cout << "\n\n Purchase Cake Quantity : " << purchasedCake;
        cout << "\n Sales Cake Quantity : " << soldCake;
        cout << "\n Remaining Cake Quantity : " << purchasedCake - soldCake;
        cout << "\n Total Cake Price in a Day : " << totalCakePrice;

        cout << "\n\n Purchase Ice Cream Quantity : " << purchasedIceCream;
        cout << "\n Sales Ice Cream Quantity : " << soldIceCream;
        cout << "\n Remaining Ice Cream Quantity : " << purchasedIceCream - soldCake;
        cout << "\n Total Ice Cream Price in a Day : " << totalIceCreamPrice;

        cout << "\n\n Purchase Sand Wich Quantity : " << purchasedSandWich;
        cout << "\n Sales Sand Wich Quantity : " << soldSandWich;
        cout << "\n Remaining Ice Cream Quantity : " << purchasedSandWich - soldSandWich;
        cout << "\n Total Ice Cream Price in a Day : " << totalSandWichPrice;

        cout << "\n\n Purchase Chicken Karahi Quantity : " << purchasedChickenKarahi;
        cout << "\n Sales Chicken Karahi Quantity : " << soldChickenKarahi;
        cout << "\n Remaining Chicken Karahi Quantity : " << purchasedChickenKarahi - soldChickenKarahi;
        cout << "\n Total Chicken Karahi Price in a Day : " << totalChickenKarahiPrice;


        cout << "\n\n\n Total Day Price : " << totalPizzaPrice + totalBurgerPrice + totalSandWichPrice + totalIceCreamPrice + totalCakePrice + totalBiryaniPrice + totalChickenKarahiPrice;
    }
    void showMenu() {
    system("cls"); // for clearing screen

        cout << "\n\t\t\tControl Panel";
        cout << "\n\n 1. Pizza";
        cout << "\n 2. Burger";
        cout << "\n 3. Cake";
        cout << "\n 4. Ice-Cream";
        cout << "\n 5. Sandwich";
        cout << "\n 6. Biryani";
        cout << "\n 7. Chicken Karahi";
        cout << "\n 8. Details";
        cout << "\n 9. Exit";
        cout << "\n\n Enter Your Choice : ";
    }

    void processChoice(int choice) {
        int quantity;
        switch (choice) {
            case 1:
                cout << "\n\n Enter Pizza Quantity : ";
                cin >> quantity;
                if (purchasedPizza - soldPizza >= quantity) {
                    soldPizza += quantity;
                    totalPizzaPrice += quantity * pizzaPrice;
                    cout << "\n\n\n\t\t\t" << quantity << " Pizza Sales Thank You!!!";
                    cout << "\n\n\n\t\t\t  Your total bill is " << quantity * pizzaPrice;
                } else
                    cout << "\n\n\n\t\t\tSorry " << purchasedPizza - soldPizza << " Pizza Remaining in Restaurant...";
                system("pause");
				break;
            case 2:
                cout << "\n\n Enter Burger Quantity : ";
                cin >> quantity;
                if (purchasedBurger - soldBurger >= quantity) {
                    soldBurger += quantity;
                    totalBurgerPrice += quantity * burgerPrice;
                    cout << "\n\n\n\t\t\t" << quantity << " Burger Sales Thank You!!!";
                    cout << "\n\n\n\t\t\t  Your total bill is " << quantity * burgerPrice;
                } else
                    cout << "\n\n\n\t\t\tSorry " << purchasedBurger - soldBurger << " Burger Remaining in Restaurant...";
                break;
            case 3:
                cout << "\n\n Enter Cake Quantity : ";
                cin >> quantity;
                if (purchasedCake - soldCake >= quantity) {
                    soldCake += quantity;
                    totalCakePrice += quantity * cakePrice;
                    cout << "\n\n\n\t\t\t" << quantity << " Cake Sales Thank You!!!";
                    cout << "\n\n\n\t\t\t  Your total bill is " << quantity * cakePrice;
                } else
                    cout << "\n\n\n\t\t\tSorry " << purchasedCake - soldCake << " Cake Remaining in Restaurant...";
                break;

            case 4:
                cout << "\n\n Enter Ice-Cream Quantity : ";
                cin >> quantity;
                if (purchasedIceCream - soldIceCream >= quantity) {
                    soldIceCream += quantity;
                    totalIceCreamPrice += quantity * iceCreamPrice;
                    cout << "\n\n\n\t\t\t" << quantity << " Ice-Cream Sales Thank You!!!";
                    cout << "\n\n\n\t\t\t  Your total bill is " << quantity *iceCreamPrice;
                } else
                    cout << "\n\n\n\t\t\tSorry " << purchasedIceCream - soldIceCream << " Ice-Cream Remaining in Restaurant...";
                break;
            case 5:
                cout << "\n\n Enter Sandwich Quantity : ";
                cin >> quantity;
                if (purchasedSandWich - soldSandWich >= quantity) {
                    soldSandWich += quantity;
                    totalSandWichPrice += quantity * sandWichPrice;
                    cout << "\n\n\n\t\t\t" << quantity << " Sandwich Sales Thank You!!!";
                    cout << "\n\n\n\t\t\t  Your total bill is " << quantity * sandWichPrice;
                } else
                    cout << "\n\n\n\t\t\tSorry " << purchasedSandWich - soldSandWich << " Sandwich Remaining in Restaurant...";
                break;
            case 6:
                cout << "\n\n Enter Biryani Quantity : ";
                cin >> quantity;
                if (purchasedBiryani - soldBiryani >= quantity) {
                    soldBiryani += quantity;
                    totalBiryaniPrice += quantity * biryaniPrice;
                    cout << "\n\n\n\t\t\t" << quantity << " Biryani Sales Thank You!!!";
                    cout << "\n\n\n\t\t\t  Your total bill is " << quantity * biryaniPrice;
                } else
                    cout << "\n\n\n\t\t\tSorry " << purchasedBiryani - soldBiryani << " Biryani Remaining in Restaurant...";
                break;
            case 7:
                cout << "\n\n Enter Chicken Karahi Quantity : ";
                cin >> quantity;
                if (purchasedChickenKarahi - soldChickenKarahi >= quantity) {
                    soldChickenKarahi += quantity;
                    totalChickenKarahiPrice += quantity * chickenKarahiPrice;
                    cout << "\n\n\n\t\t\t" << quantity << " Chicken Karahi Sales Thank You!!!";
                    cout << "\n\n\n\t\t\t  Your total bill is " << quantity * chickenKarahiPrice;
                } else
                    cout << "\n\n\n\t\t\tSorry " << purchasedChickenKarahi - soldChickenKarahi << " Chicken Karahi Remaining in Restaurant...";
                break;
            case 8:
                showDetails();
                break;
            case 9:
                exit(0);
            default:
                cout << "\n\n Invalid Value...Please Try Again...";
        }
    }

};

int main() {


    Restaurant restaurant;
    int choice;

    restaurant.purchaseItems();

    while (true) {
        restaurant.showMenu();
        cin >> choice;
        restaurant.processChoice(choice);
       // getch();
    }

    return 0;
}
//02:41 PM

