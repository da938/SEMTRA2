#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <string>
#include <bits/stdc++.h>

#include "arbolSintactico.h"
#include "stdio.h"
#include "semantico.h"
#include "tablaSimbolos.h"
#include "tablaSimbolos.cpp"

#include "lexico.h"
#include "pila.h"
#include "lexico.cpp"
#include "pila.cpp"

#include <vector>

using namespace std;

Semantico semantico;
int Nodo::sangria= 0;
TablaSimbolos *Nodo::TablaSimbolos = NULL;
string Nodo::ambito = "";

string tipo;
string tipoparam;
string parameros;
string iden;
string idenparam;
vector <int> expresion;

string reglas[53];
int cont = 0, fil = 0, col = 0;
int tablaLR[95][46];
string rreglaactual[3];

int suma( int $a, int $b ){
    int $result;
    __asm__ __volatile__(
        "movl %1, %%eax;"
        "movl %2, %%ebx;"
        "addl %%ebx,%%eax;"
        "movl %%eax, %0;" : "=g" ( $result ) : "g" ( $a ), "g" ( $b )
    );
    return $result ; 
}

int declara_int(int $a){
    int $result;
    __asm__ __volatile__(
        "movl %1, %%eax;"
        "movl %%eax, %0;" : "=g" ( $result ) : "g" ( $a )
    );
    return $result ;
}

char declara_char(char $a){
    char result;
    __asm__ __volatile__(
        "" : "=r" ($a)
    );
    return $a;
}

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

string regla (string reglaactual){
    int longitud = reglaactual.length();
    string nombre;
    for( int i=5; i<=longitud; i++){
        nombre += reglaactual[i];
    }
    cout << nombre << endl;
    return nombre;
}

void comprobar(string nueva,Pila pila,int reglaapp){
    string literales;
    string palabra;
    string palabra1;
    int i = 0;
    if (nueva == "45 3 Expresion"){
        if(reglaapp == 47){
            for(auto ir = expresion.rbegin(); ir != expresion.rend(); ++ir){
                cout << *ir << " ";
            } cout << endl;
            auto j = expresion.rbegin();
            int num1 = *j;
            ++j;
            int num2 = *j;
            cout << "suma: " << num1 << " + " << num2 << " = " << suma(num1,num2) << endl;
            system("pause");
        }
        if(reglaapp == 49){
            system("pause");
        }
    }
    if (nueva == "27 4 DefVar"){
        literales = pila.buscador();
        cout << literales << endl;
        while(i < literales.length()){
            if(literales[i] != ' '){
                palabra += literales[i];
                //cout << palabra << endl;
            }else {
                //cout << palabra << endl;
                palabra1 = palabra + " ";
                Lexico lex(palabra1);
                lex.sigSimbolo();
                if(lex.tipo == 4){
                    tipo = palabra;
                    //cout << tipo << endl;
                }else if(lex.tipo == 0){
                    iden = palabra;
                    //cout << iden << endl;
                }
                palabra = "";
            }
            i++;
        }
        Nodo * arbol = new DefVar(new Tipo(tipo), new Identificador(iden, NULL), NULL);
        cout << endl;
        cout << "Arbol: " << endl;
        arbol->muestra();
        cout << endl;
        cout << "Analisis: ";
        semantico.analiza(arbol);
        cout << endl << endl;

        if(tipo == "int"){
            cout << declara_int(0) << endl;
        }
        if(tipo == "char"){
            cout << declara_char('a') << endl;
        }
        system("pause");
    }
    if (nueva == "30 3 Parametros"){
        literales = pila.buscador();
        cout << literales << endl;
        while(i < literales.length()){
            if(literales[i] != ' '){
                palabra += literales[i];
                //cout << palabra << endl;
            }else {
                //cout << palabra << endl;
                palabra1 = palabra + " ";
                Lexico lex(palabra1);
                lex.sigSimbolo();
                if(lex.tipo == 4){
                    tipoparam = palabra;
                    //cout << tipo << endl;
                }else if(lex.tipo == 0){
                    idenparam = palabra;
                    //cout << iden << endl;
                }
                palabra = "";
            }
            i++;
        }
    }
    else if (nueva == "29 6 DefFunc"){
        literales = pila.buscador();
        cout << literales << endl;
        while(i < literales.length()){
            if(literales[i] != ' '){
                palabra += literales[i];
                //cout << palabra << endl;
            }else {
                //cout << palabra << endl;
                palabra1 = palabra + " ";
                Lexico lex(palabra1);
                lex.sigSimbolo();
                //cout << lex.tipo << " Tipo " << endl; 
                if(lex.tipo == 4){
                    tipo = palabra;
                    //cout << tipo << endl;
                }if(lex.tipo == 0){
                    iden = palabra;
                    //cout << iden << endl;
                }
                else if(lex.tipo == 30){
                    parameros = palabra;
                    //cout << iden << endl;
                }
                palabra = "";
            }
            i++;
        }
        Nodo * arbol = new DefFunc( new Tipo(tipo), new Identificador(iden, NULL), new Parametro( new Tipo(tipoparam), new Identificador(idenparam), NULL), NULL, NULL);
        cout << endl;
        cout << "Arbol: " << endl;
        arbol->muestra();
        cout << endl;
        cout << "Analisis: ";
        semantico.analiza(arbol);
        cout << endl << endl;
    }
}

int main(){
    string guardar;
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
    Lexico lexico("int x ( int y ) { int j ; j = 7 ; char letra ; return 7 + 8 ; } ");//cadena a analizar

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

        if(accion >= 0){//si la accion es mayor a 0 hacemos un desplazo
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

            if(lexico.tipo == 1){
                string sim= lexico.simbolo;
                expresion.push_back(stoi(sim));
            }
        }
        if(accion < 0){//Si la accion es menor a 0 hacemos una reduccion
            cout << endl;
            cout << "REDUCCION" << endl;
            int reglaapp = abs(accion) - 1;
            cout << "REGLA: " << reglaapp << " " << reglas[reglaapp] << endl;
            guardar = regla(reglas[reglaapp]);
            comprobar(reglas[reglaapp],pila,reglaapp);
            
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
