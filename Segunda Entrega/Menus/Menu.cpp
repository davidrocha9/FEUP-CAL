#include <iostream>
#include <vector>
#include "Menu.h"
#include "Utils.h"
#include "../Files/FileReader.h"

struct user{
    int maxTime, experience;
} user;

bool changeReturn(bool& return_menu) {
    string n;
    //cin.ignore(1000, '\n');
    std::cout << endl << endl << "Deseja realizar mais alguma operacao? (S/N)" << endl;
    do {
        std::cout << "Introduza uma opcao:";
        cin.clear();
        cin >> n;
        if ((n != "S" && n != "s" && n != "N" && n != "n") || cin.fail()){
            cin.clear();
            cin.ignore();
            std::cout << "Opcao invalida! Tente Novamente." << endl;
        }
    } while (n != "S" && n != "s" && n != "N" && n != "n");

    if (n == "N" || n == "n")
        return_menu = false;
    return return_menu;
}

int answer(int range){
    unsigned int opt = 0;
    cout << endl;
    do {
        cout << "Introduza uma opcao:"; cin >> opt;
        if (opt < 1 || opt > range || cin.fail()) {
            cin.clear();
            cout << "Opcao invalida! Introduza um numero entre 1 e " << range << "." << endl;
            cin.ignore(1000, '\n');
        }
    } while (opt < 1 || opt > range || cin.fail());

    return opt;
}

void start(){
    //system("cls");
    logo();
    unsigned opt;
}

void mainMenu(){
    bool return_menu = true;
    unsigned int opt;
    createGraph();
    do{
        logo();
        cout << " 1 - Escolher Trilho" << endl;
        cout << " 2 - Sair" << endl;

        opt = answer(2);
        cin.ignore(1000, '\n');

        switch(opt){
            case 1:
                start();
                break;
            case 2:
                leave();
                return;
        }

        changeReturn(return_menu);
    } while (return_menu);
}
