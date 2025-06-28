#include <iostream>
using  namespace std;

//https://docs.google.com/document/d/12zQMTrmwqXlbEfedsrYkyymqYattGrjmOqQ_tgM3sKc/edit?tab=t.0#heading=h.x4u1bxtik54

void Calc()
{
    int a = 10;
    int b = 7;
    std::cout << "A = " << a << '\n';
    std::cout << "B = " << b << '\n';
    std::cout << "A + B = " << a + b << '\n';
    std::cout << "A - B = " << a - b << '\n';
    std::cout << "A * B = " << a * b << '\n';
    std::cout << "A / B = " << a / b << '\n';
}
void AgeC()
{
    int a;
    std::cout << "Enter age" << '\n';
    std::cin >> a;
    if (a>=18) {
        std::cout << "Welcome";
    }
    else {
        std::cout << "Access denide";
    }
}
void RandomN()
{
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int a;
        int b = rand() % (10 + 1);
        std::cout << "Enter number " << "(" << b << ")" << '\n';
        std::cin >> a;
        if (a == b) {
            std::cout << "You win" << '\n';
        }
        else {
            std::cout << "You lose" << '\n';
            return;
        }
    }   
}
void RPS()
{
    srand(time(0));
    for (int i = 0; i < 3; i++)
    {
        //create array weapon
        std::string weapon[] = {"rock","paper","scissors"}; 

        // create results
        std::string result[3][3]{ 
            {"draw","win","lose"},
            {"lose","draw","win"},
            {"win","lose","draw"}
        };
        
        std::string userStr;
        int user=-1;
        int enemy = rand() % 2;
        std::cout << "Choise weapon (rock,paper,scissors) " << "(" << weapon[enemy] << ")" << '\n';
        std::cin >> userStr;

        // selection check & assigment "user" value on which was confirmed choice
        bool correct = false; for (int i = 0; i < 3; i++)
        {
            if (userStr == weapon[i]) {
                correct = true;               
                user = i;
            }
        }

        //if the selection check is not confirmed
        if (!correct) {
            std::cout << "Error. Choise correct weapon " << '\n';
        }
        else
        {
            //appeal to std::string result to choose the result
            std::cout << result[enemy][user] << '\n'; 
        }
    }       
}

void Store()
{   //list of product in store with price
    cout << "Products that are currently in the store" << '\n';
    string product[] = {"Banana","Apple","Lemon"};
    int BananaQ = 3;
    int AppleQ = 2;
    int LemonQ = 1;
    int price[] = {1,2,3};
    string priceD[] = { "1$","2$","3$" };
    cout << product[0] << " " << BananaQ << " on " << priceD[0] << " each" << '\n';
    cout << product[1] << " " << AppleQ << " on " << priceD[1] << " each" << '\n';
    cout << product[2] << " " << LemonQ << " on " << priceD[2] << " each" << '\n';

    //how much money does the user have
    cout << "How much money do you have?" << '\n';
    int money;
    cin >> money;

    //the user enters the product he wants to buy
    cout << "What u want buy?" << '\n';
    for (int i = 0; i < 2; i++)
    {
        cin >> product;
        if (product[i]);
    }
    string Qproduct;
    cout << "How much " << "(" << Qproduct << ")" << '\n';
    cin >> quantity;

    //calculating the price of all the products the user wants to buy & how much money is left

}

int main()
{
    Store();
}