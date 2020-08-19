#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <algorithm>

using namespace std;

struct rubros{
  int numeroZona;
  char nombreComercio [30] = "";
  int rubro;
}negocios;

void guardarDatos(rubros negocios, FILE *f);
void hayComerciosEnTodaZona(int hayComercios[][4]);
void comerciosEntodos(int hayComercios[][4]);

int main() {
  FILE *f;
  int respuesta, hayComercios[6][4];

  cout << "Ingreso de datos? (1 para si/0 para no): " << endl;
  cin >> respuesta;

  while (respuesta != 0) {

    cout << "Nombre de comercio:" << endl;
    cin.ignore();
    cin.getline (negocios.nombreComercio, 30);


    cout << "Seleccionar numero de rubro: 1- heladeria, 2- pizzeria, 3- bebidas, 4- parrilla (si excede los 10 en la zona, no se ingresa el dato):" << endl;
    cin >> negocios.rubro;

    while (negocios.rubro < 1 || negocios.rubro > 4){
        if (negocios.rubro < 1 || negocios.rubro > 4){
            cout << "Rubro incorrecto"<< endl;
            cout << "Seleccionar numero de rubro: 1- heladeria, 2- pizzeria, 3- bebidas, 4- parrilla (si excede los 10 en la zona, no se ingresa el dato):" << endl;
            cin >>negocios.rubro;
        }
    }
    cout << "Numero de zona (1-6): " << endl;
    cin >> negocios.numeroZona;

    while (negocios.numeroZona < 1 || negocios.numeroZona > 6){
        if (negocios.numeroZona < 1 || negocios.numeroZona > 6){
            cout<< "Zona incorrecta"<< endl;
            cout << "Especifique la zona (1 - 6)"<< endl;
            cin >> negocios.numeroZona;
        }
    }

    cout << "Ingreso de datos? (1 para si/0 para no): " << endl;
    cin >> respuesta;

    guardarDatos(negocios, f);
    hayComerciosEnTodaZona(hayComercios);
  }
  comerciosEntodos(hayComercios);

  getch();
return 0;
}

    void guardarDatos(rubros negocios, FILE *f)
    {
      switch (negocios.rubro){
        case 1:
          f = fopen("Heladeria.dat", "a");
          fprintf(f, "Comercio: %s\n", negocios.nombreComercio);
          fprintf(f, "Zona: %d\n", negocios.numeroZona);
          fclose(f);
          break;
        case 2:
          f = fopen("Pizzeria.dat", "a");
          fprintf(f, "Comercio: %s\n", negocios.nombreComercio);
          fprintf(f, "Zona: %d\n", negocios.numeroZona);
          fclose(f);
          break;
        case 3:
          f = fopen("Bebidas.dat", "a");
          fprintf(f, "Comercio: %s\n", negocios.nombreComercio);
          fprintf(f, "Zona: %d\n", negocios.numeroZona);
          fclose(f);
          break;
        case 4:
          f = fopen("Parrilla.dat", "a");
          fprintf(f, "Comercio: %s\n", negocios.nombreComercio);
          fprintf(f, "Zona: %d\n", negocios.numeroZona);
          fclose(f);
          break;
      }
    }

  void hayComerciosEnTodaZona(int hayComercios[][4])
  {
    for (int i = 0; i < 6; i++) {
      if (negocios.numeroZona == i+1){
        for (int j = 0; j < 4; j++) {
          if(negocios.rubro == j+1){
            hayComercios[i][j]= 1;
          }
          else if(negocios.rubro == j+2){
            hayComercios[i][j] = 1;
          }
          else if(negocios.rubro == j+ 3){
            hayComercios[i][j] = 1;
          }
          else if(negocios.rubro == j+4){
            hayComercios[i][j] = 1;
          }
        }
      }
    }
  }

  void comerciosEntodos(int hayComercios[][4])
  {
    for (int i = 0; i < 6; i++) {
      if (hayComercios[i][0] == 1 && hayComercios[i][1] == 1 && hayComercios[i][2] == 1 && hayComercios[i][3] == 1){
        cout << "Hay comercios en todos lados en la zona " << i+1 << endl;
      }
      if (hayComercios[i][0] == 0 ) {
        cout <<"No hay comercios en el rubro heladeria en la zona " << i+1  << endl;
      }
      else if (hayComercios[i][1] == 0 ){
        cout <<"No hay comercios en el rubro pizzeria en la zona " << i+1  << endl;
      }
      else if (hayComercios[i][2] == 0 ){
        cout <<"No hay comercios en el rubro bebidas en la zona " << i+1  << endl;
      }
      else if (hayComercios[i][3] == 0 ){
        cout <<"No hay comercios en el rubro parrilla en la zona " << i+1  << endl;
      }
    }
  }
