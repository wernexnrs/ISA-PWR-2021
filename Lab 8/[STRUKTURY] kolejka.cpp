//Windows 10 x64
//Visual Studio 2022
// /std:c++latest

/*Zaimplementuj wybraną przez siebie dynamiczną strukturę danych: 
    - listę wskaźnikową, 
    - kolejkę, 
    - kolejkę priorytetową,
    - drzewo. 
Program prześlij najpóźniej dzień przed kolejnymi zajęciami i omów go w trakcie trwania zajęć.*/

#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
#include <chrono>

int liczba_elementow{ 0 };

using namespace std;

struct kolejka {
    string element{};
    kolejka* next;
};

kolejka* glowa = NULL;
kolejka* ogon = NULL;

void show(){
    kolejka* wsk = glowa;
    
    cout << "-------------------\n" <<
            "ZAWARTOŚĆ KOLEJKI:\n"
            "-------------------\n";

    while (wsk != NULL){
        cout << wsk -> element;
        wsk = wsk -> next;
    }
    cout << "\n-------------------\n";
}

void push() {
    string zawartosc;
    kolejka* dyn_str = new kolejka;
    
    cout << "Podaj zawartość do wstawienia: ";
    cin >> zawartosc;

    dyn_str -> element = zawartosc;
    liczba_elementow++;

    if(glowa == NULL){
        dyn_str -> next = NULL;
        glowa = ogon = dyn_str;
    }else {
        dyn_str -> next = NULL;
        ogon -> next = dyn_str;
        ogon = dyn_str;
    }
}

void empty() {
    if (glowa == NULL) cout << "Kolejka jest pusta\n";
    else cout << "Kolejka nie jest pusta\n";    
    this_thread::sleep_for(chrono::milliseconds(1500));
}

void pop() {
    if (glowa != NULL) {
        cout << "Usuwam element z początku kolejki.";

        if (glowa == ogon) {
            glowa = ogon = NULL;
        }else glowa = glowa -> next;
        liczba_elementow--;
    }else cout << "Kolejka jest pusta\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
}

void size() {
    cout << liczba_elementow;
    this_thread::sleep_for(chrono::milliseconds(1000));
}


int main(){
    int wybor{ 0 };

    SetConsoleCP(852);
    setlocale(LC_ALL, "");

    while (1) {
        system("cls");
        show();
        cout << "\n\n";

        cout << "\n\nImplementacja kolejki\n\n" <<
            "||| MENU |||\n" <<
            "1. Dodaj do kolejki (push())\n" <<
            "2. Usuń z kolejki (pop())\n" <<
            "3. Sprawdź czy kolejka jest pusta (empty())\n" <<
            "4. Sprawdź rozmiar kolejki (size())\n" <<
            "5. Wyjdź\n"
            "Wybór: ";

        cin >> wybor;
        cin.clear();
        cin.ignore(1000, '\n');

        switch (wybor) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            empty();
            break;
        case 4:
            size();
            break;
        case 5:
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}
