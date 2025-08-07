#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <locale.h>
#include <string>
using  namespace std;

//https://docs.google.com/document/d/12zQMTrmwqXlbEfedsrYkyymqYattGrjmOqQ_tgM3sKc/edit?tab=t.0#heading=h.x4u1bxtik54

void input2(string& a)
{
     getline(cin, a);
    transform(a.begin(), a.end(), a.begin(), tolower);
    transform(a.begin(), a.begin() + 1, a.begin(), toupper);
}

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
    Rooms.push_back({ "Exit","Out of bounds" });
    Rooms.push_back({ "Main hall" });
    Rooms.push_back({ "Bathroom" });
    Rooms.push_back({ "Bedroom" });

    //Массив названий предметов
    vector<item>Item;
    Item.push_back({ "Sword" });
    Item.push_back({ "Armor" });
    Item.push_back({ "Health potion" });

    /*Item[0].Class.push_back(Class[0])

    vector<string> Class;
    Class.push_back("takeble");
    Class.push_back("puteble");*/

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

    
    int character = 1; // стартовая локация персонажа | ОТЛАДКА int = 0 -------------------------------------------------------------------------------

    for (;;)
    {
        //стартовый интерфейс
        cout << "u in: " << Rooms[character].name << '\n';
        cout << "- Go" << '\n';
        cout << "- Look around" << '\n';
        cout << "- Check inventory" << '\n';
        string ansver;
        cout << "What do?" << '\n';

        //input2(ansver); | ОТЛАДКА вынести из комента ------------------------------------------------------------
        ansver = "Look around"; // | ОТЛАДКА удалить строку------------------------------------------------------------

        // перемещение ГОТОВО
        if (ansver == "Go") {
            cout << "u can go to: " << '\n';

            for (int i = 0; i < Rooms[character].door.size(); i++) {
                cout << Rooms[Rooms[character].door[i]].name << '\n';
            }
            cout << "-Back-" << '\n';

            string GoTo;
            input2(GoTo);

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

        //предметы в локации В РАЗРАБОТКЕ
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

            input2(ansver);
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
                arg += word[i];
                if (i < word.size() - 1) { //КОСТЫЛЬ
                    arg += ' ';
                }
                //Получилось сделать без добавления классов, но все же тема интересная стоит придумать куда заюзать
            }

            // отладка
            for (int i = 0; i < word.size(); i++)
            {
                cout << "Word " << i << ": " << word[i] << '\n';
            }
            cout << "command " << word[0] << '\n';
            transform(arg.begin(), arg.begin() + 1, arg.begin(), toupper); // КОСТЫЛЬ? преобразование аргумента к виду "Бм м"
            cout << "argument " << arg << '\n';  //DOTO 4 Вернуться сюда когда разберешься с классами

            if (word[0] == "Take") {
                //cout << arg;
                for (int i = 0; i < Rooms[character].inventory.size(); i++) {
                    if (Rooms[character].inventory[i] == arg) {
                        Inv.push_back({ Rooms[character].inventory[i] });
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

        //НПС в локации NULL
        if (ansver == "Look around") {

        }

        //инвентарь ЗАМОРОЖЕНО
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

        cout << '\n';
    }
}