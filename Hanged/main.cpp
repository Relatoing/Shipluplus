#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>
#include <windows.h>
#include <cctype>
//Made by Relat
void clean(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int tries;
    std::string guess = "";
    char Guess;
    std::string answers[12] = {"Banana", "Mango", "Pineapple", "Dragonfruit", "Apple", "JuiceMelon", "MangoJuice", "Pie", "Dog", "Personnal", "Bell", "Hot"};
    std::srand(std::time(NULL));
    int random = std::rand() % 12;
    std::string ans = {answers[random]};
    tries = (ans.length() / 2) + 2;
    if(tries < 4){
        tries = 4;
    }
    std::string guessed(ans.length(), '_');
    
    int choice = 0;
    int win = 0;
    int countR = 0; //Count Right, the other count is below
    int countL;
    clean();
    std::cout << "Boas vindas ao jogo da forca!\nSua palavra é:\n"<<guessed<<"\n";
    do{
        do{
            std::cout << "Digite 1 se deseja tentar advinhar com uma palavra (se errar perdeu)\nDigite 2 se deseja tentar adivinhar com uma letra\nDigite 3 para sair\n";
            std::cin >> choice;
            if(choice < 1 || choice > 3){
                std::cout << "Opção inválida!\n";
            }
        }while(choice < 1 || choice > 3);
        //
        //
        if(choice == 3){
            std::cout << "Adeus!";
            break;
        }
        else{
            choice--;
        }
        
        
        // choice = 0 or 1 (True or false)
        if(!choice){
            std::cin >> guess;    
        }else{
            std::cin >> Guess;
        }
        
        clean();
        countL = 0; //Count Line
        
        for(int i = 0;i < ans.length();i++){
            if(!choice){ //if word
                if(guess[i] == ans[i] || std::toupper(guess[i]) == ans[i]){
                    guessed[i] = guess[i];
                    countR++;
                }else{
                    countR = 0;
                    tries = 0;
                    break;
                }
            
            }else{ //if char
                if(Guess == ans[i] && guessed[i] == '_'){
                    guessed[i] = Guess;
                    countR++;
                }else if(ans[i] == Guess - 32 && guessed[i] == '_'){
                    guessed[i] = Guess - 32;
                    countR++;
                }
            }
            if(guessed[i] == '_'){
                countL++;
            }
        }
        if(!countR){
            std::cout << "Errou! Menos uma tentativa!\n";
            --tries;
        }
        if(countL == 0 && countR == ans.length()){
            win = true;
        }else if(win == false && tries > 0){
            std::cout<< "Sua palavra: \n" << guessed << "\n\nApenas " << tries << " tentativas restantes\n\nL: "<<ans.length()<<"\nR: "<< countR;
        }
        if(tries <= 0){break;}
    }while(win == false);
    if(win){
        std::cout << "Você ganhou com " << tries << " tentativas restantes!";
    }else{
        std::cout << "Boa sorte na próxima!";
    }
    
    return 0;
}
//Made by who?