﻿#include <iostream>
#include <vector>
#include <algorithm>
#include <locale.h>
#include <string>
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
    if (a >= 18) {
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
        int user = -1;
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

    //MaxQP()
        cout << "maximum quantity of products for youre money is:" << '\n';
        int c = 0;
        int minPrice = money;
        for (int m = 0; money >= minPrice; m++) {
            int i = 0;
            int minBuy = 0;
            minPrice = money;
            --minPrice;
            for (int i = 0; i < shop.size(); i++) {
                if (minPrice >= shop[i].price && shop[i].quantity != 0) {
                    minPrice = shop[i].price;
                    c = i;
                }
            }
            if (shop[c].quantity != 0) {
                for (; money >= minPrice && shop[c].quantity != 0;) {
                    if (money >= minPrice) {
                        money -= minPrice;
                        shop[c].quantity -= 1;
                        minBuy += 1;
                    }
                }
            }
            if (shop[c].quantity == 0) {
                shop[c].price = 100; // ЭТОТ КОСТЫЛЬ МНЕ ОБОШЕЛСЯ ПОЛОМАНЫМ МАГАЗИНОМ ГДЕ ВСЕ ЦЕННИКИ = 100
            }
            if (minBuy != 0) {
                cout << shop[c].name << " " << minBuy << '\n';
            }
            if (money < minPrice || minBuy == 0) {
                cout << "remainder of youre money: " << money << '\n';
                break;
            }
        }

    /*
    
    cout << "Shopping list for maximum spending money:" << '\n';
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
    int buyw = 1;
    string want;

    for (int buy = 0; buy < buyw; buy++) {
        cout << "what u want buy?" << '\n';
        cin >> want;
        int take;
        cout << "how much u want take" << '\n';
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
            cout << "wrong name" << '\n';
        }
        if (!corr2) {
            cout << "wrong quantity" << '\n';
        }
        if (!corr3) {
            cout << "wrong money" << '\n';
        }
        money -= shop[prod].price * take;

        cout << "u buy " << take << " things " << want << " for " << shop[prod].price * take << '\n';
        cout << "remaining money " << money << '\n';

        string answer;
        cout << "u want buy more? y/n" << '\n';
        cin >> answer;
        if (answer == "y") {
            buyw += 1;
}
        else {
            return;
        }
    }
}

void RPG(){}

int main()
{
    setlocale(LC_ALL, "Russian");
    struct location {
        string name;
        string description;
        vector<int> door;
    };

    vector<location>MadMax;
    MadMax.push_back({ "Hangar king of deseret", "The chambers of the main man in the whole great desert"}); // локация 0 _ в которую записываются (name и description)
        MadMax[0].door.push_back(1); // локация0 _ дверь (0) _ ведет в лок1
    MadMax.push_back({ "Fortress",""});
        MadMax[1].door.push_back(0); // локация1 _ дверь (0) _ ведет в лок0
        MadMax[1].door.push_back(2); // локация1 _ дверь (1) _ ведет в лок2
        MadMax[1].door.push_back(3); // локация1 _ дверь (2) _ ведет в лок3
        MadMax[1].door.push_back(4); // локация1 _ дверь (3) _ ведет в лок4 и ТД
    MadMax.push_back({ "Gas station", ""});
        MadMax[2].door.push_back(1); // в крепость
        MadMax[2].door.push_back(3); // в бар
        MadMax[2].door.push_back(4); // в рцех
        MadMax[2].door.push_back(5); // на ворота
    MadMax.push_back({ "Bar", ""});
        MadMax[3].door.push_back(1); // в крепость
        MadMax[3].door.push_back(2); // на заправку
        MadMax[3].door.push_back(4); // в рцех
        MadMax[3].door.push_back(5);
    MadMax.push_back({ "Repair shop", ""});
        MadMax[4].door.push_back(1); // в крепость
        MadMax[4].door.push_back(2); // на заправку
        MadMax[4].door.push_back(3); // в бар
        MadMax[4].door.push_back(5); // на ворота
    MadMax.push_back({ "Main gate", ""});
        MadMax[5].door.push_back(2);
        MadMax[5].door.push_back(3);
        MadMax[5].door.push_back(4);
        MadMax[5].door.push_back(6);
    MadMax.push_back({ "Grand dune", ""});
        MadMax[6].door.push_back(5);
        MadMax[6].door.push_back(7);
        MadMax[6].door.push_back(8);
        MadMax[6].door.push_back(9);
    MadMax.push_back({ "Canibals", ""}); 
        MadMax[7].door.push_back(6);
    MadMax.push_back({ "DiselHeads", ""}); 
        MadMax[8].door.push_back(6);
    MadMax.push_back({ "MetalWars", ""});
        MadMax[9].door.push_back(6);

    int character = 4; // стартовая локация персонажа
    string GoTo;

    for(;;)
    {
        cout << "u in: " << MadMax[character].name << '\n';
        cout << "u can go to: " << '\n';
        for (int i = 0; i < MadMax[character].door.size(); i++) {
            auto destination = MadMax[character].door[i];
            cout << MadMax[destination].name << '\n';
        }
        cout << "where u go?" << '\n';

        getline(cin, GoTo);
        cout << '\n';
        for (int i = 0; i < MadMax[character].door.size(); i++) {
            auto doorNumber = i;
            auto destinationLocationNumber = MadMax[character].door[doorNumber];

            if (GoTo == MadMax[destinationLocationNumber].name) {
                character = MadMax[character].door[i];
            }
        }
    }

    /*for (int i=0; i<10;i++)
    {
        cout << "U here: " << MadMax[character].name << '\n' << MadMax[character].description << '\n' <<
            "U can go to: " << MadMax[character-1].name<< " or " << MadMax[character+1].name << '\n';
        cout << "go to "; cin >> GoTo;
        for (int j = 0; j < 10; j++)
        {
            if (GoTo == MadMax[character+1].name || GoTo == MadMax[character-1].name) {
                cout << "u come " << GoTo;
            }
        }

    }*/


}