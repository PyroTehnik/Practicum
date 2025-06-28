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
        int b = rand() % (1 - 10 + 1);
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

        std::string a[] = { "rock","paper","scissors" };
        int b = rand() % (0 - 2);
        a[b] < a[b+1];
        std::string c;
        std::cout << "Choise weapon (rock,paper,scissors) " << "(" << a[b] << ")" << '\n';
        std::cin >> c;

       


            if (c > a[b]) {
                std::cout << "uw " << '\n';
            }
            else {
                std::cout << "ul " << '\n';
                return;
            }
        
    }

        
}

int main()
{
    RPS();
}