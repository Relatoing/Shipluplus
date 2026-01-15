#include <string>
#include <fstream>
#include <iostream>
#include <vector>
int main(){
    std::string linha;
    int index = 0;
    int iRem = 0;;
    std::vector<std::string> linhas;
    while(true){
        linhas.clear();
        index = 0;
        std::ifstream input("list.txt");
        if(!input.is_open()){
            std::cout << "Arquivo não encontrado";
            return 1;
        }
        while(std::getline(input, linha)){ 
            if(linha == "" || linha == "-Listinha-"){
                continue;
            }
            ++index;
            linhas.push_back(linha);
            std::cout<< index << " = " << linha << "\n";
        }
        input.close();
        
        int choice = 0;
        do{
            std::cout << "Digite 1 para adicionar um item à lista\nDigite 2 para excluir um item da lista\nDigite 3 para sair";
            std::cin >> choice;
            if(choice < 1 || choice > 3){
                std::cout << "\nOpção inválida, tente novamente!\n";
            }
        }while(choice < 1 || choice > 3);
        
        if(choice == 1){
            std::ofstream output("list.txt", std::ios::app);
            std::cout << "Digite o que deseja deixar na linha " << ++index;    
            std::cin >> linha;
            output << "\n"<< linha << "\n";
            output.close();
        }else{
            if(choice == 3){
                return 0;
            }
            std::ofstream output("list.txt");
            do{
                std::cout << "Digite o número do item a ser excluído: ";
                std::cin >> iRem;
                if(iRem < 0 || iRem > index){
                    std::cout << "\nNúmero inválido!\n";
                }
            }while(iRem < 0 || iRem > index);
            iRem--;
            linhas.erase(linhas.begin() + iRem);
            for(auto & l : linhas){
                output << l << "\n";
            }
            output.close();
        }//remover   
    }
}