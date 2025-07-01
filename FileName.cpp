#include <iostream>
#include <vector>
#include <algorithm>
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
        bool correct = false;
        for (int i = 0; i < 3; i++)
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
{
    struct product {
        string name;
        int price;
        int quantity;
    };

    vector<product>shop;
    shop.push_back({ "banana",10,9 });
    shop.push_back({ "apple",8,7 });
    shop.push_back({ "lemon",6,5 });

    cout << "How much money do you have?" << '\n';
    int money;
    cin >> money;

    /*cout << "Shopping list for maximum spending money:" << '\n';
    for (int a = 0; a < 3; a++)
    {;
    cout << "max: " << *max_element(begin(shop[a].price), end(shop[a].price)) << '\n';
    }
    {
        int maxwell = -1;
        for (int a = 0; a < shop.size(); a++)
        {
            maxwell = max(shop[a].price, maxwell);
        }
        std::cout << "max price is: " << maxwell << std::endl;
    }

    cout << "Maximum quantity purchase list" << '\n';*/
    
    for (int i = 0; i < shop.size(); i++) {
        cout << i+1 << " " << shop[i].name << " price " << shop[i].price << " quantity " << shop[i].quantity<< '\n';
    }

    int prod = 0;
    int buyW = 1;
    string want;

    for (int buy = 0; buy < buyW; buy++) {
        cout << "What u want buy?" << '\n';
        cin >> want;
        int take;
        cout << "How much u want take" << '\n';
        cin >> take;

        bool corr1 = false;
        bool corr2 = false;
        bool corr3 = false;
        for (int i1 = 0; i1 < shop.size(); i1++) {
            if (want == shop[i1].name) {
                corr1 = true;
                prod = i1;
            }
            if (take <= shop[prod].quantity) {
                corr2 = true;
            }
            if (money >= shop[prod].price * take) {
                corr3 = true;
            }
        }
        if (!corr1) {
            cout << "Wrong name" << '\n';
        }
        if (!corr2) {
            cout << "Wrong quantity" << '\n';
        }
        if (!corr3) {
            cout << "Wrong money" << '\n';
        }
        money -= shop[prod].price * take;

        cout << "U buy " << take << " things " << want << " for " << shop[prod].price * take << '\n';
        cout << "Remaining money " << money << '\n';

        string answer;
        cout << "U want buy more? y/n" << '\n';
        cin >> answer;
        if (answer == "y") {
            buyW += 1;
        }
        else {
            return;
        }
    }
}

int main()
{
    Store();
}