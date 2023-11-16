#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

#include "lexico.h"
#include "sintactico.h"
#include "semantico.h"
#include "codigoasm.h"
#include "stdio.h"


int main()
{
        setlocale(LC_CTYPE,"Spanish");
        int op;
        int a,b;
        bool procede;
        string prototype;
        float x,y;
        while(true)
        {
            system("cls");
            procede=false;
            declaraciones.clear();
            cout<<"\t----Generaci�n de Codigo----";
            cout<<"\n\nOperaci�n a realizar: "<<endl<<endl;
            cout<<"\n1.Suma (+).";
            cout<<"\n2.Resta (-).";
            cout<<"\n3.Multiplicaci�n (*).";
            cout<<"\n4.Divisi�n (/).";
            cout<<"\n5.Potencia (^).";
            cout<<"\n6.Ra�z Cuadrada. (V��)";
            cout<<"\n7.Seno.";
            cout<<"\n8.Coseno.";
            cout<<"\n9.Tangente.";
            cout<<"\n10.Tangente Hiperb�lica.";
            cout<<"\n0.Salir.";
            cout<<"\n\nIngresa una opci�n (n�mero): "; fflush(stdin); 
			cin>>op;
            if(op==1){
                cout<<"\nSuma (+).";
                prototype=buscaFuncion(op);
                procede=analizarArchivo("prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nSuma (+).";
                        cout<<endl<<endl<<"Ingresa el primer n�mero: "; cin>>a;
                        cout<<"Ingresa el segundo n�mero: "; cin>>b;
                        cout<<"\nResultado = "<<suma(a,b)<<endl;
                    }
                    else {
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                }
            }
            else if(op==2){
                cout<<"\nResta (-).";
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nResta (-).";
                        cout<<endl<<endl<<"Ingresa el primer n�mero: "; cin>>a;
                        cout<<"Ingresa el segundo n�mero: "; cin>>b;
                        cout<<"\nResultado = "<<resta(a,b)<<endl;
                    }
                    else {
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                }
            }
            else if(op==3){
                cout<<"\nMultiplicaci�n (*)."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nMultiplicaci�n (*)."<<endl;
                        cout<<endl<<endl<<"Ingresa el primer n�mero: "; cin>>x;
                        cout<<"Ingresa el segundo n�mero: "; cin>>y;
                        cout<<"\nResultado = "<<multiplicacion(x,y)<<endl;
                    }
                    else {
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                }
            }
            else if(op==4){
                cout<<"\nDivisi�n (/)."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nDivisi�n (/)."<<endl;
                        cout<<endl<<endl<<"Ingresa el dividendo: "; cin>>x;
                        cout<<"Ingresa el divisor: "; cin>>y;
                        if(y==0){
                            cout<<"\nERROR: Division por cero";
                        }
                        else{
                            cout<<"\nResultado = "<<division(x,y)<<endl;
                        }
                    }
                    else {
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                }
            }
            else if(op==5){
                cout<<"\nPotencia (^)."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nPotencia (^)."<<endl;
                        cout<<endl<<endl<<"Ingresa un primer n�mero: "; cin>>a;
                        cout<<"Ingresa la potencia: "; cin>>b;
                        if(b>=0){
                            cout<<"\nResultado = "<<potencia(a,b)<<endl;
                        }
                        else{
                            b=b*-1;
                            cout<<"\nResultado = "<<division(1,potencia(a,b))<<endl;
                        }
                    }
                    else {
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                }
            }
            else if(op==6){
                cout<<"\nRa�z Cuadrada (V��)."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nRa�z Cuadrada (V��)."<<endl;
                        cout<<endl<<endl<<"Ingresa un n�mero: "; cin>>x;
                        if(x<0){
                            cout<<"\nERROR: Las ra�ces negativas no forman parte de los reales.";
                        }
                        else{
                            cout<<"\nResultado = "<<raiz(x)<<endl;
                        }
                    }
                    else {
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                }
            }
            else if(op==7){
                cout<<"\nSeno."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nSeno."<<endl;
                        cout<<endl<<endl<<"Ingresa un n�mero: "; cin>>x;
                        if (x == 90 ){
                        	cout<<"\nResultado = 1"<<endl;
						}
						else if (x == 270){
							cout<<"\nResultado = -1"<<endl;
						}
						else if (x == 180 or x == 360){
							cout<<"\nResultado = 0"<<endl;
						}
						else{
							cout<<"\nResultado = "<<seno(x)<<endl;
						}
                        
                    }
                    else {
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                }
            }
            else if(op==8){
                cout<<"\nCoseno."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nCoseno."<<endl;
                        cout<<endl<<endl<<"Ingresa un n�mero: "; cin>>x;
                        if (x == 90 or x==270){
                        	cout<<"\nResultado = 0"<<endl;
						}
						else if (x == 180){
							cout<<"\nResultado = -1"<<endl;
						}
						else if (x == 360){
							cout<<"\nResultado = 1"<<endl;
						}
						else{
							cout<<"\nResultado = "<<coseno(x)<<endl;
						}
                        
                    }
                    else {
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                }
            }
            else if(op==9){
                cout<<"\nTangente."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nTangente."<<endl;
                        cout<<endl<<endl<<"Ingresa un n�mero: "; cin>>x;
                        if (x == 90 or x==270){
                        	cout<<"\nResultado = indefinido"<<endl;
						}
						else if (x == 180 or x == 360){
							cout<<"\nResultado = 0"<<endl;
						}
						else{
							cout<<"\nResultado = "<<seno(x)/coseno(x)<<endl;
						}
                        
                    }
                    else {
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                }
            }
            /*else if(op==10){
                float euler_pos,euler_neg;
                cout<<"\nSeno Hiperb�lico."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nSeno Hiperb�lico."<<endl;
                        cout<<endl<<endl<<"Ingresa el n�mero en grados: "; cin>>x;
                        euler_pos=potencia_euler(M_E,x);
                        euler_neg=division(1,euler_pos);
                        cout<<"\nResultado = "<<seno_hiperbolico(euler_pos,euler_neg)<<endl;
                    }
                    else {
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                }
            }
            else if(op==11){
                float euler_pos,euler_neg;
                cout<<"\nCoseno Hiperb�lico."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nCoseno Hiperb�lico."<<endl;
                        cout<<endl<<endl<<"Ingresa el n�mero en grados: "; cin>>x;
                        euler_pos=potencia_euler(M_E,x);
                        euler_neg=division(1,euler_pos);
                        cout<<"\nResultado = "<<coseno_hiperbolico(euler_pos,euler_neg)<<endl;
                    }
                    else {
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                }
            }*/
            else if(op==10){
                float euler_pos,euler_neg;
                long double grado;
                cout<<"\nTangente Hiperb�lica."<<endl;
                prototype=buscaFuncion(op);
                procede=analizarArchivo("Prototipo.txt",prototype);
                if(procede==true){
                    procede=false;
                    procede=analizarArchivo("Funciones.txt",prototype);
                    if(procede==true){
                        cout<<"\nTangente Hiperb�lica."<<endl;
                        cout<<endl<<endl<<"Ingresa el n�mero en grados: "; cin>>grado;
                        euler_pos=potencia_euler(M_E,grado);
                        euler_neg=1/euler_pos;
                        //cout<<"\nResultado = "<<division(seno_hiperbolico(euler_pos,euler_neg),coseno_hiperbolico(euler_pos,euler_neg))<<endl;
                        cout<<"\nResultado = "<<sinh(grado)/cosh(grado)<<endl;
                    }
                    else {
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                    }
                }
                else{
                    cout<<"\nERROR: No se encontr� la funci�n del lenguaje.";
                }
            }
            else if(op==0){
             break;
            }
         getch();
        }
	return 0;
}

