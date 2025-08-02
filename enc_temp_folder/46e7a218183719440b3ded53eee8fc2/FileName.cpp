#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <locale.h>
#include <string>
using  namespace std;

//https://docs.google.com/document/d/12zQMTrmwqXlbEfedsrYkyymqYattGrjmOqQ_tgM3sKc/edit?tab=t.0#heading=h.x4u1bxtik54
    

void Calc()
{
    int a = 10;
    int b = 7;
    cout << "A = " << a << '\n';
    cout << "B = " << b << '\n';
    cout << "A + B = " << a + b << '\n';
    cout << "A - B = " << a - b << '\n';
    cout << "A * B = " << a * b << '\n';
    cout << "A / B = " << a / b << '\n';
}
void AgeC()
{
    int a;
    cout << "Enter age" << '\n';
    cin >> a;
    if (a >= 18) {
        cout << "Welcome";
    }
    else {
        cout << "Access denide";
    }
}
void RandomN()
{
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int a;
        int b = rand() % (10 + 1);
        cout << "Enter number " << "(" << b << ")" << '\n';
        cin >> a;
        if (a == b) {
            cout << "You win" << '\n';
        }
        else {
            cout << "You lose" << '\n';
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
        string weapon[] = {"rock","paper","scissors"}; 

        // create results
        string result[3][3]{
            {"draw","win","lose"},
            {"lose","draw","win"},
            {"win","lose","draw"}
        };

        string userStr;
        int user = -1;
        int enemy = rand() % 2;
        cout << "Choise weapon (rock,paper,scissors) " << "(" << weapon[enemy] << ")" << '\n';
        cin >> userStr;

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
            cout << "Error. Choise correct weapon " << '\n';
        }
        else
        {
            //appeal to string result to choose the result
            cout << result[enemy][user] << '\n';
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
        cout << "max price is: " << maxwell << endl;
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

void RPG();

int main()
{
    struct location {
        string name;
        string description;
        vector<int> door;
        vector<string>inventory;
    };

    struct item {
        string name;
        string description;
        vector<string> Class;
    };

    struct player {
        string inventory;
        int HP = 50;
        int Armor = 0;
        int Damage = 10;
    };

    //Массив названий локаций
    vector<location>Rooms;
    Rooms.push_back({ "Exit" });
    Rooms.push_back({ "Main hall" });
    Rooms.push_back({ "Bathroom" });
    Rooms.push_back({ "Bedroom" });

    vector<item>Item;
    Item.push_back({ "Sword" });
    Item.push_back({ "Armor" });
    Item.push_back({ "Health potion" });

    vector<player>Inv;

    //Вектор дверей в локациях
    Rooms[0].door.push_back(1);
    Rooms[1].door.push_back(0);
    Rooms[1].door.push_back(2);
    Rooms[1].door.push_back(3);
    Rooms[2].door.push_back(1);
    Rooms[3].door.push_back(1);

    //Вектор предметов в локациях
    Rooms[1].inventory.push_back(Item[0].name); //меч в холле
    Rooms[1].inventory.push_back(Item[2].name); //хилл в холле
    Rooms[2].inventory.push_back(Item[1].name); //броня в ванной
    Rooms[3].inventory.push_back(Item[2].name); //хилл в спальне
    
    int character = 0; // стартовая локация персонажа

    for(;;) 
        //DO 1. Вне зависимости от регистра, должен преобразовывать к "Бммм ммм"
    {
        //стартовый интерфейс
        cout << "u in: " << Rooms[character].name << '\n';
        cout << "- Go" << '\n';
        cout << "- Look around" << '\n';
        cout << "- Check inventory" << '\n';
        string ansver;
        cout << "What do?" << '\n';
        getline(cin, ansver);
       
        // перемещение
        if (ansver == "Go") {
            cout << "u can go to: " << '\n';

            for (int i = 0; i < Rooms[character].door.size(); i++) {
                cout << Rooms[Rooms[character].door[i]].name << '\n';
            }
            cout << "-Back-"<< '\n';

            string GoTo;
            getline(cin, GoTo);

            for (int i = 0; i < Rooms[character].door.size(); i++) {

                auto destLoc = Rooms[character].door[i];
                auto roomName = Rooms[destLoc].name;

                if (GoTo == roomName) {
                    character = Rooms[character].door[i];
                    break;
                }
                else if (GoTo == "Back") {
                    break;
                }
                else if (i + 1 == Rooms[character].door.size()) {
                    cout << "Error" << '\n';
                }
            }
        }

        //предметы в локации
        if (ansver == "Look around") {
            if (Rooms[character].inventory.empty()) {
                cout << "Location is empty" << '\n';
            }
                for (int i = 0; i < Rooms[character].inventory.size(); i++) {
                    cout << "- " << Rooms[character].inventory[i] << '\n';
                    auto NumItem = i;
                }
                cout << "What do?" << '\n' << "Take _" << '\n' << "Put" << '\n' << "-Back-" << '\n';
                
                // getline команда и "сложный" аргумент для take/put
                string ansver;
                vector<string>word;
                string arg;
                int counterW = 0;

                getline(cin, ansver);
                cout << "ansver.length: " << ansver.length() << '\n';


                for (int i = 0; i < ansver.length(); i++) {

                    // отладка
                    cout << "i " << i << '\n';
                    cout << "counterW " << counterW << '\n';
                    cout << "word.size " << word.size() << '\n';

                    if (ansver[i] != ' ')
                    {
                        for (; isalnum(ansver[i]); i++)
                        {
                            if (counterW >= word.size())
                                word.push_back("");
                            word[counterW].push_back({ ansver[i] });
                        }
                        counterW++;
                    }
                }

                for (int i = 1; i < word.size(); i++)
                {
                    arg += word[i] + " ";
                }

                // отладка
                for (int i = 0; i < word.size(); i++)
                {
                    cout << "Word " << i << ": " << word[i] << '\n';
                }
                cout << "command " << word[0] << '\n';
                cout << "argument " << arg;;


                /*string ansver21;
                string ansver22;
                string ansver23;*/

                //взять предмет с локации

                /*string ansver;
                vector<string>word;
                int a = 0;*/

                /*getline(cin, ansver);
                cout << ansver.length() << '\n';*/

                /*for (int i = 0; i < ansver.length(); i++) {
                    if (ansver[i] == ' ') {
                        a = a + 1;
                        continue;
                    }
                    else {
                        if (a >= word.size()) word.push_back("");
                        word[a].push_back({ ansver[i] });
                    }
                }
                for (int i = 0; i < word.size(); i++)
                {
                    cout << word[i] << '\n';
                    string ItemTake = word[2], word[3];
                    cout << ItemTake;
                
                }*/


                if (word[0] == "Take") {
                    cout << arg;
                    for (int i = 0; i < Rooms[character].inventory.size(); i++) {
                        if (Rooms[character].inventory[i] == arg) {
                            Inv.push_back({ Rooms[character].inventory[i]});
                            cout << "u take " << Rooms[character].inventory[i];
                            Rooms[character].inventory.erase(Rooms[character].inventory.begin() + i);
                        }
                    }
                }
                if (word[1] == "Put") {

                }
                else if (word[1] == "Back") {
                }
                
        }
        //НПС в локации
        if (ansver == "Look around") {

        }

        //инвентарь
        if (ansver == "Check inventory") {

            if (Inv.empty()) {
                cout << "Inventory is empty" << '\n';
            }
            else {
                cout << "U have:" << '\n';
                for (int i = 0; i < Inv.size(); i++) {
                    cout << Inv[i].inventory << '\n';
                }
            }
        }

           /* }
            for (int i = 0; i < Inv[PlIt].inventory.size(); i++) {
                cout << Inv[i].inventory << '\n';
                emp2 = i; 
            }
        }
        if (emp2 == -1) {
            cout << " ";
        }*/
        cout << '\n';
    }
}