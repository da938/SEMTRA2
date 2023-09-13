#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "lexico.h"
#include "pila.h"

using namespace std;

int tablaR1[5][4] = {
    2,0,0,1,
    0,0,-1,0,
    0,3,0,0,
    4,0,0,0,
    0,0,-2,0
};
int tablaR2[5][4] = {
    2,0,0,1,
    0,0,-1,0,
    0,3,-3,0,
    2,0,0,4,
    0,0,-2,0
};
Pila pila;
Pila memory;
int contadorinterno=0;
Lexico lexico;
vector <string>simbolo;
vector <int>tipo;
int fila, columna, accion;
bool aceptacion = false;
void r1(string c);
void pushR1();
void r2(string c);
string entrada1="hola+mundo";
string entrada2="a+b+c+d+e+f";

int main(int argc, char* argv[]) {
    
  //Responde a los dos ejercicios
  r1(entrada1);
  r2(entrada2);
 

    return 0;
}
void r1(string c) {
    int contadorinterno = 0;
  //Se inicia la pila que servirá de buffer
    Pila pila;
  ElementoPila* simbolo; 
  //Se introduce la entrada correspondiente
    lexico.entrada(entrada1);
  //Se aplica el $0
  pila.push(new Terminal("$")); 
  pila.push(new Estado("0")); 
  //Se empieza a recorrer la entrada
    lexico.sigSimbolo();
    //cout<<lexico.simbolo;

  
  simbolo=pila.top();
  fila = stoi(simbolo->regresar()); 
    columna=lexico.tipo;
    accion=tablaR1[fila][columna];
    //Se muestan los datos de la pila
    pila.muestra();
    cout<<"entrada: "<<lexico.simbolo<<endl;

    //contadorinterno++;
    //cout<< endl;
  //Basados en la regla de la tabla, se hace el recorrido por posiciones que no tienen E
    cout<<"accion: "<<accion<<endl;
    //lexico.sigSimbolo();
    //if(accion>0){
        //pushR1();
      while(contadorinterno!=3) {
      pila.push(new Terminal(lexico.simbolo));
      pila.push(new Estado(to_string(accion))); 
        lexico.sigSimbolo();
        
      simbolo=pila.top();
      fila = stoi(simbolo->regresar()); 
        columna=lexico.tipo;
        accion=tablaR1[fila][columna];
        
        pila.muestra();
        cout<<"entrada: "<<lexico.simbolo<<endl;
        cout<<"accion: "<<accion<<endl;
      contadorinterno++;
      }
    //}
  //En base a las acciones efectuadas se empiezan a hacer eliminaciones para completar el proceso
    if(accion<0){
        for(int i=0;i<6;i++){
            pila.pop();
        }
    }
    if(accion==0)
      cout << "Error"<<endl;
    else{
        pila.muestra(); 
      simbolo=pila.top(); 
      fila = stoi(simbolo->regresar()); 
        columna=3;
        accion=tablaR1[fila][columna];
      
        pila.push(new Noterminal("E"));
        pila.push(new Estado(to_string(accion)));
        pila.muestra();
      
        cout<<"entrada: "<<lexico.simbolo<<endl;
        cout<<"accion: "<<accion<<endl;
      
      simbolo=pila.top(); 
      fila = stoi(simbolo->regresar()); 
        columna=lexico.tipo;
        accion=tablaR1[fila][columna];
  }
    pila.muestra();
    cout<<"entrada: "<<lexico.simbolo<<endl;
    cout<<"accion: "<<accion<<endl;
  
    aceptacion=accion==-1;
    if(aceptacion)
        cout<<"Aceptacion"<<endl;
}

void r2(string c){
    contadorinterno= 0;
    cout<<endl<<endl<<endl;
  ElementoPila* simbolo;  
  //Se introduce la entrada correspondiente al proceso
    lexico.entrada("a + b + c + d + e + f");
  //Se introduce el $0
  pila.push(new Terminal("$")); 
  pila.push(new Estado("0")); 
  //Se empieza a recorrer la entrada
    lexico.sigSimbolo();
  simbolo = pila.top();
  fila = stoi(simbolo->regresar()); 
    columna=lexico.tipo;
    accion=tablaR2[fila][columna];

  
    pila.muestra();
    cout<<"entrada: "<<lexico.simbolo<<endl;
    cout<<"accion: "<<accion<<endl;
    //Se empiezan a recorrer todas las posiciones
    while(contadorinterno!=16){
    if(accion>0){
      pila.push(new Terminal(lexico.simbolo)); 
      pila.push(new Estado(to_string(accion))); 
        lexico.sigSimbolo();
      simbolo=pila.top(); 
      fila = stoi(simbolo->regresar()); 
        columna=lexico.tipo;
        accion=tablaR2[fila][columna];
        pila.muestra();
        cout<<"entrada: "<<lexico.simbolo<<endl;
        cout<<"accion: "<<accion<<endl; 
    }
    //En base a las acciones definidad se empizan a realizar operaciones específicas
    if(accion<0){
        if(accion==-3)
        
        {
            pila.pop();
            pila.pop();
          simbolo=pila.top(); 
          fila = stoi(simbolo->regresar());
            columna=3; 
          
            accion=tablaR2[fila][columna]; 
          pila.push(new Noterminal("E")); 
          pila.push(new Estado(to_string(accion)));
            pila.muestra();
            cout<<"entrada: "<<lexico.simbolo<<endl;
            cout<<"accion: "<<accion<<endl;
          
        }
        if(accion==4){
            while(accion==4){
              for(int y=0;y<6;y++){
                pila.pop();
              }
          simbolo=pila.top(); 
          fila = stoi(simbolo->regresar()); 
                columna=3;
                accion=tablaR2[fila][columna];
            
              pila.push(new Noterminal("E")); 
              pila.push(new Estado(to_string(accion)));
                pila.muestra();
                cout<<"entrada: "<<lexico.simbolo<<endl;
                cout<<"accion: "<<accion<<endl;
              }
          }
      }
    }
    

    aceptacion=accion==-1;
    if(aceptacion)
        cout<<"Aceptacion"<<endl;

}
