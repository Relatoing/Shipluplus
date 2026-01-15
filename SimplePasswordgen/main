#include <iostream>
#include <cstdlib>
#include <ctime>
int main()
{
    /*
    This is a simple password generator, only has numbers and alphabet included on it
    */
    int random = 0;
    int userinp = 0;
    char senha[17] = {0};
    std::srand(std::time(nullptr));
    do{
        std::cout<<"Digite a quantidade de letras para a senha (máximo 16)";
        std::cin >> userinp;
    }while(userinp <= 0 || userinp > 16);
    for(int i = 0; i < userinp;i++){
        random = std::rand() % 62;
        if (random < 10) {
            senha[i] = char('0' + random);
        }
        else if (random < 36) {
            senha[i] = char('A' + (random - 10));
        }
        else {
            senha[i] = char('a' + (random - 36));
        }
    }
    std::cout << "Sua senha é:\n\n" << senha;
    
    return 0;
}