#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

#include "lexico.h"
#include "pila.h"
#include "lexico.cpp"
#include "pila.cpp"

using namespace std;
string reglas[53];
int cont = 0, fil = 0, col = 0;
int tablaLR[95][46];
string rreglaactual[3];

void arrange2(string str){
    int posicion = 0;
    string w = "";
    for (auto x : str) 
    {
        if (x == ' ')
        {
            rreglaactual[posicion] = w;
            posicion ++;
            w = "";
        }
        else {
            w = w + x;
        }
    }
    rreglaactual[posicion] = w;
    posicion ++;
}

void arrange(string str){ 
    int num;
    string w = "";
    col = 0;
    for (auto x : str) {
        if (x == ' '){
            stringstream ss;
            ss << w;  
            ss >> num;
            tablaLR[fil][col] = num;
            col ++;
            w = "";
        }
        else{
            w = w + x;
        }
    }
    stringstream ss;
    ss << w;  
    ss >> num;
    tablaLR[fil][col] = num;
    col ++;
    fil ++;
}

int main(){
    int estadoact;
    fstream newfile;
    newfile.open("compilador.lr",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        string tp;
        while(getline(newfile, tp)){ //read data from file object and put it into string.
            if (cont <= 52){
                reglas[cont] = tp;
            }if(cont >= 54){
                arrange(tp);
            }
            cont ++;
        }
        newfile.close(); //close the file object.
    }

    int contador = 0;
    int idReglas[2] = {3,2}; 
    int IonReglas[2] = {3,0};
    int idE = 3; 
    int E;
    Pila pila;
    ElementoPila *elemento;
    int fila, columna, accion;
    bool aceptacion= false;
    Lexico lexico("int hola ; ");//cadena a analizar

    elemento = new Terminal(2,"$");
    pila.push( elemento); //Entra signo de pesos que inicializa la cadena
    elemento = new Estado(0);
    pila.push( elemento );                 
    lexico.sigSimbolo();    //analizamos el primer simbolo de la cadena

    fila= pila.top();   //para la fila tomamos en cuenta en top de la pila
    columna= lexico.tipo;//para la columna tomamos en el id del siguente simbolo en la cadena
    cout << "Fila: " << fila << endl;
    cout << "Columna: " << columna << endl;
    accion= tablaLR[fila][columna];//la accion es el valor que se encuentre etre la fila y la columna

    pila.muestra();//mostramos la pila
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl;

    while(accion != -1){//mientras la accion sea diferente de aceptacion repetimos el proceso

        if(accion > 0){//si la accion es mayor a 0 hacemos un desplazo
            cout << endl;
            cout << "Desplazamiento" << endl;
            elemento = new Terminal(lexico.tipo,lexico.c);
            pila.push( elemento );
            elemento = new Estado(accion);
            pila.push( elemento );
            lexico.sigSimbolo();

            fila= pila.top();
            columna= lexico.tipo;
            cout << "Fila: " << fila << endl;
            cout << "Columna: " << columna << endl;
            accion= tablaLR[fila][columna];

            pila.muestra();
            cout << "entrada: " << lexico.simbolo << endl;
            cout << "accion: " << accion << endl;
        }
        if(accion < 0){//Si la accion es menor a 0 hacemos una reduccion
            cout << endl;
            cout << "REDUCCION" << endl;
            int reglaapp = abs(accion) - 1;
            cout << "REGLA: " << reglaapp<< endl;
            int numborrados;
            stringstream ss;
            char reglastr = reglas[reglaapp][3];
            ss << reglastr;  
            ss >> numborrados;
            numborrados = numborrados * 2;
            if (accion == -1)break;//si es -1 es aceptacion

            for(int i=0; i<numborrados; i++){//reducimos la pila el numero de veces que nos indica la regla
                pila.pop();
            }

            pila.muestra();
            arrange2(reglas[reglaapp]);
            string prueba= rreglaactual[2];
            prueba = prueba+ " ";
            Lexico lexico2(prueba);
            lexico2.sigSimbolo();
            elemento = new NoTerminal(lexico2.tipo,lexico2.c);
            estadoact = tablaLR[pila.top()][lexico2.tipo];
            pila.push( elemento ); //el 3 es el entero que representa el no terminal E*
            elemento = new Estado(estadoact);
            pila.push( elemento );

            fila= pila.top();
            columna= lexico.tipo;
            cout << "Fila: " << fila << endl;
            cout << "Columna: " << columna << endl;
            accion= tablaLR[fila][columna];
            pila.muestra();
            cout << "entrada: " << lexico.simbolo << endl;
            cout << "accion: " << accion << endl << endl;
            //system("pause");
        }
        if(accion == 0)break;
    }
    cout << "Automata terminado" << endl;
    aceptacion= accion == -1;
    if (aceptacion) cout << "aceptacion" << endl;
    else cout << "No aceptacion" << endl;
}
