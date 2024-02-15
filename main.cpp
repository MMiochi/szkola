#include <iostream>
#include "funkcje.hpp"
#include <cmath>
using namespace std;

void printTable(int table_size, int *table, const string& message){
  cout << message << " ";
  for(int i = 0; i < table_size; i++){
    cout << table[i] << ",";
  }
  cout << "\n";
}



int main() {
int table_size;
do{
  cout << "Podaj wielkość tablicy: ";
  cin >> table_size;
  if(table_size == false) { 
    cout << "Wprowadzona wartość nie jest liczbą całkowitą. Spróbuj ponownie."<<endl;
  } else {
    cout << "Git Gud"<<endl;
  }
} while (table_size == true);
  int * generated = tabela(table_size);
  printTable(table_size, generated, "Tablica przed sortowaniem --");
  int searched;
  cout <<"Podaj szukaną liczbę: ";
  cin >> searched;
  cout << "Napisz 1 dla wyszukiwania albo 2 dla sortowania\n";
  int menu;
  cin >> menu;
  if(menu == 2) {
    cout << "Wybierz sposób sortowania.\n";
    cout << "1. Sortowanie bąbelkowe\n";
    cout << "2. Sortowanie przez wstawianie\n";
    cout << "3. Sortowanie koktajlowe\n";
    cout << "4. Sortowanie szybkie\n";
    cout << "5. Sortowanie przez scalanie\n";
  int wybranaOpcjaWyszukiwania;
  cout << "Wybierz opcję: ";
  cin >> wybranaOpcjaWyszukiwania;
    switch(wybranaOpcjaWyszukiwania){
      case 1:
        sortowanie_babelkowe(table_size, generated);
        break;
      case 2:
        sortowanie_wstawianie(table_size, generated);
        break;
      case 3:
        sortowanie_koktajlowe(table_size, generated);
        break;
      case 4:
        sortowanie_szybkie(generated, 0, table_size-1);
        break;
      case 5:
        //szukanie_interpolacyjne(table_size, generated, searched);
        break; 
      default:
        cout << "Nie ma takiej opcji w menu.\n";
        break;

  return 0;
    }
    printTable(table_size, generated, "Zasortowana tablica:");
  }else if(menu == 1){
      cout << "Wybierz sposób szukania.\n";
      cout << "1. Szukanie binarne\n";
      cout << "2. Szukanie skokowe\n";
      cout << "3. Szukanie liniowe\n";
      cout << "4. Szukanie liniowe z wartownikiem\n";
      cout << "5. Szukanie interpolacyjne\n";
    int wybranaOpcjaWyszukiwania;
    cin >> wybranaOpcjaWyszukiwania;
      switch(wybranaOpcjaWyszukiwania){
        case 1:
          szukanie_binarne(table_size, generated, searched);
          break;
        case 2:
          szukanie_skokowe(table_size, generated, searched);
          break;
        case 3:
          szukanie_liniowe(table_size, generated, searched);
          break;
        case 4:
          szukanie_liniowe_z_wartownikiem(table_size, generated, searched);
          break;
        case 5:
          //szukanie_interpolacyjne(table_size, generated, searched);
          break; 
        default:
          cout << "Nie ma takiej opcji w menu.\n";
          break;

    return 0;
      }
    }






  delete[] generated; 
  return 0;
}
