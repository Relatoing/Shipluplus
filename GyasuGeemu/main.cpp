#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <string>
#include "neemu.h"
#include <vector>
#include <windows.h>
//Made by Relat :)
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
    int satisfied = 0;
    int input;
    std::string name;
    std::string sobrename;    
    std::cout << "Jogador, digite qualquer número para receber um nome aleatório\nDigite 2 para sair\n";
    std::cin >> input;
    if(input == 2){return 0;}
    do{
        clean();
        std::srand(static_cast<unsigned>(std::time(nullptr)));    
        name = nome[std::rand() % nome.size()] + surname[std::rand() % surname.size()] +"_"+ std::to_string(std::rand() % 15000);
        std::cout << name;
        std::cout << "\n\nDigite 0 se está satisfeito\nDigite qualquer número se deseja continuar\n";
        std::cin >> input;
        if(!input){
            satisfied++;
        }
    }while(!satisfied);
    clean();
    while(input <1 || input > 3){
        std::cout << "Digite 1 para jogar no Fácil (1 a 100, 5 tentativas)\nDigite 2 para jogar no Médio(1 a 1000, 6 tentativas)\nDigite 3 para jogar no Difícil(1 a 2500, 8 tentativas)" << std::endl;
        std::cin >> input;
        if(input < 1 || input > 3){
            clean();
        }
    }
    int guess;
    int tries;
    int closeright;
    int win = 0;
    int lose = 0;
    switch(input){
        case 1: guess = (rand() % 100) + 1; tries = 9; closeright = 100;
        break;
        case 2: guess = (rand() % 1000) + 1; tries = 10; closeright = 1000;
        break;
        case 3: guess = (rand() % 2500 + 1); tries = 12; closeright = 2500;
        break;
    }
    int closeleft = 1;
    do{
        std::cout << "Digite um número entre " << closeleft << " e " << closeright << "\nFaltam " << tries << " tentativas!" << std::endl;
        std::cin >> input;
        if(input <= guess){
            if(input > closeleft){
                closeleft = input;
            }
            if(input == guess){
                win++;
            }else{
                tries--;
            }
        }else{
            if(input < closeright){
                closeright = input;
            }
            if(input == guess){
                win++;
            }else{
                tries--;
            }
        }
        if(!tries){
            lose++;
        }
        clean();
    }while(!win && !lose);
    clean();
    if(win){
       std::cout << "Parabéns " << name << ", você ganhou!" << std::endl; 
    }else{
        std::cout << "Boa sorte na próxima, " << name << "!\nSeu número era: " << guess << std::endl;
    }
    //Made by who?
}
