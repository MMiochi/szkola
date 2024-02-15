#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int * tabela(int table_size) {
  int *tablica = new int[table_size];
  srand(time(NULL));
  for(int i = 0; i <table_size; i++) {
    int losowa = rand() % 100;
    tablica[i]=losowa;
  }
  return tablica;
}

int * sortowanie_babelkowe(int table_size, int * table){
  for(int j = 0; j < table_size; j++){
    for(int i = 0; i < table_size - 1; i++){
      if (table[i] > table[i+1]){
        int temp = table[i];
        table[i] = table[i+1];
        table[i+1] = temp;  
      }
    }
  }
  return table;
}
int * sortowanie_wstawianie(int table_size, int * table) {
  for(int i = 1; i < table_size; i++) {
    int key = table[i];
    int j = i - 1;
    while(j >= 0 && table[j] > key) {
      table[j + 1] = table[j];
      j = j - 1;
    }
    table[j + 1] = key;
  }
  return table;
}
void szukanie_liniowe(int table_size, int * table, int searched) {
  bool found = false; 
  for(int i = 0; i < table_size; i++) {
    if(searched == table[i]) {
      cout << "Liczba " << searched << " znajduje się pod indeksem " << i << "\n";
      found = true;
      break; 
    }
  }

  if(!found) {
    cout << "Liczba nieznaleziona\n";
  }
}

void szukanie_liniowe_z_wartownikiem(int table_size, int * table, int searched) {
    int* array = new int[table_size + 1];
    for (int i = 0; i < table_size; i++) {
        array[i] = table[i];
    }
    array[table_size] = searched; 
    int i = 0;

    while (array[i] != searched) {
        i++;
    }

    if (i < table_size) {
        cout << "Liczba " << searched << " znajduje się pod indeksem " << i << "\n";
    } else {
        cout << "Liczba nieznaleziona\n";
    }
}
int * sortowanie_koktajlowe(int table_size, int * table) {
  int bottom = 0;
  int top = table_size - 1;
  bool change = true;

  while (change) {
    change = false;


    for (int i = bottom; i < top; i++) {
      if (table[i] > table[i + 1]) {
        swap(table[i], table[i + 1]); 
        change = true;
      }
    }
    top--;


    for (int i = top; i > bottom; i--) {
      if (table[i] < table[i - 1]) {
        swap(table[i], table[i - 1]); 
        change = true;
      }
    }
    bottom++;
  }

  return table;
}
int szukanie_binarne(int table_size, int * table, int searched) {

  int left = 0;
  int right = table_size - 1;
  int index;

  while (left <= right) {
    index = (left + right) / 2; 

    if (table[index] < searched) {
      left = index + 1;
    } else if (table[index] > searched) {
      right = index - 1;
    } else {
      cout << "Indeks równy: " << index << endl;
      return index;
    }
  }

  cout << "Element nieznaleziony" << endl;
  return -1; 
}
void sortowanie_szybkie(int* table, int leftIndex, int rightIndex) {
    int i = leftIndex;
    int j = rightIndex;
    int pivot = table[(leftIndex + rightIndex) / 2]; 
    while (i <= j) {
        while (table[i] < pivot) {
            i++;
        }
        while (table[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = table[i];
            table[i] = table[j];
            table[j] = temp;
            i++;
            j--;
        }
    }

    if (leftIndex < j) {
        sortowanie_szybkie(table, leftIndex, j);
    }
    if (i < rightIndex) {
        sortowanie_szybkie(table, i, rightIndex);
    }
}
void szukanie_skokowe(int table_size, int* table, int searched) {
  int block = (int)(sqrt(table_size));
  int index = 0;


  while (table[min(block, table_size) - 1] < searched) {
    index = block;
    block += (int)(sqrt(table_size));
    if (index >= table_size)
      return; 
  }


  while (table[index] < searched) {
    index++;
    if (index == min(block, table_size)) {
      return; 
    }
  }


  if (table[index] == searched) {
    cout << "Szukana liczba znajduje się pod indeksem: " << index << endl;
    return;
  }


  cout << "Nie znaleziono szukanej liczby." << endl;
  return;
}
