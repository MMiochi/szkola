#include <cstdlib>
#include <iostream>
using namespace std;

const int x = 12;
const int n = 25;


void
wypelnij_tablice (int tablica[])
{
  const int y = 25;
  for (int i = 0; i < x; i++)
    {
      tablica[i] = (rand () % x) + y;
    }
}

int main ()
{
  int tablica[x];


  wypelnij_tablice (tablica);


  for (int i = 0; i < x; i++)
    {
      cout << tablica[i] << " ";
    }

  return 0;
}
