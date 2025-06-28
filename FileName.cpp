#include <iostream>

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
        std::string weapon[] = {"rock","paper","scissors"}; //create array weapon

        std::string result[3][3]{ // create results
            {"draw","win","lose"},
            {"lose","draw","win"},
            {"win","lose","draw"}
        };
        
        std::string userStr;
        int user=-1;
        int enemy = rand() % 2;
        std::cout << "Choise weapon (rock,paper,scissors) " << "(" << weapon[enemy] << ")" << '\n';
        std::cin >> userStr;

        bool correct = false; // selection check & assigment "user" value on which was confirmed choice
        for (int i = 0; i < 3; i++)
        {
            if (userStr == weapon[i]) {
                correct = true;               
                user = i;
            }
        }

        if (!correct) { //if the selection check is not confirmed

            std::cout << "Error. Choise correct weapon " << '\n';
        }
        else
        {

            std::cout << result[enemy][user] << '\n'; //appeal to std::string resulStr to choose the result
        }
    }       
}
void Store()
{   //list of product in store with price
    std::cout << "Products that are currently in the store" << '\n'; 
    std::string banana;
    std::cout << "Banana x3 on 1$ each" << '\n';
    std::cout << "Apple x2 on 2$ each"  << '\n';
    std::cout << "Lemon x4 on 3$ each"  << '\n';

    //how much money does the user have
    std::cout << "How much money do you have?" << '\n';
    int money;
    std::cin >> money;

    //the user enters the product he wants to buy
    std::cout << "What u want buy?" << '\n';
    std::string products_to_buy;
    std::cin >> products_to_buy;

    //calculating the price of all the products the user wants to buy & how much money is left

}

int main()
{
    Store();
}