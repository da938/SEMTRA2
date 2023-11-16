#include "tablaSimbolos.h"
#include "arbolSintactico.h"

char dimeTipo2(string simbolo){
		if (simbolo.compare("int") == 0)return 'i';
		if (simbolo.compare("float") == 0)return 'f';
		if (simbolo.compare("string") == 0)return 's';
		if (simbolo.compare("void") == 0)return 'v';
	}

void TablaSimbolos::agrega( DefVar *defVar){
	char tipo=defVar->tipo->dimeTipo();
	Identificador *p = defVar->listaVar;
	ElementoTabla *elem;
	string var[5];

	elem = new Variable(tipo,p->simbolo, Nodo::ambito);
	agrega(elem);

	while(p->sig != NULL){
		elem = new Variable(tipo,p->sig->simbolo, Nodo::ambito);
		agrega(elem);
		p->sig = p->sig->sig;
	}

	while(defVar->sig != NULL){
		cout << "----------------------------" <<endl;
		if(defVar->sig->esFuncion() == true){
			string par = " ";
			Nodo *actual;
			Nodo *parametros;
			actual = defVar->sig;
			string cadtipo = actual->regresatipo();
			char tipo2 = dimeTipo2(cadtipo);
			string variables = actual->regresaListaVar();
			p->simbolo = variables;
			parametros = defVar->sig->muestra3();
			if(parametros != NULL){
				//parametros->muestra();
				par = parametros->regresaParametros();
				//cout << par << endl;
			}

			elem= new Funcion(tipo2,p->simbolo,par);
			actual->TablaSimbolos->agrega(elem);
			actual = actual->muestra2();
			//actual->muestra();
			if(actual->esVariable() == true && actual->esAsignacion() == false){
				//cout << "variable" << endl;
				string cadtipo=actual->regresatipo();
				char tipo = dimeTipo2(cadtipo);
				string variables = actual->regresaListaVar();
				for(int i=1; i < variables.length() ; i++){
					p->simbolo = variables[i];
					ElementoTabla *elem;
					elem = new Variable(tipo,p->simbolo, " local ");
					agrega(elem); 
				}
			}
		}
		if(defVar->sig->esFuncion() == false){
			//cout << "variable" << endl;
			string cadtipo=defVar->sig->regresatipo();
			char tipo = dimeTipo2(cadtipo);
			string variables = defVar->sig->regresaListaVar();
			for(int i=0; i < variables.length() ; i++){
				p->simbolo = variables[i];
				ElementoTabla *elem;
				elem = new Variable(tipo,p->simbolo, Nodo::ambito);
				agrega(elem); 
			}
		}
		defVar->sig = defVar->sig->sig;
	}
}

void TablaSimbolos::agrega( Parametro *parametros){
	char tipo=parametros->tipo->dimeTipo();
	Identificador *p = parametros->id;
	ElementoTabla *elem;

	elem = new Variable(tipo,p->simbolo, "local");
	agrega(elem);
}


void TablaSimbolos::agrega( DefFunc *defFunc){
	char tipo = defFunc->tipo->dimeTipo();
	Identificador *i = defFunc->id;
	Parametro *varP = defFunc->parametros;
	defFunc->parametros->TablaSimbolos->agrega(varP);
	string p = defFunc->parametros->id->simbolo;
	ElementoTabla *elem;

	elem = new Funcion(tipo,i->simbolo,p);
	agrega(elem);

	while(varP->sig != NULL){
		string aux = varP->sig->regresaListaVar();
		i->simbolo = aux;
		varP->id=i;
		defFunc->parametros->TablaSimbolos->agrega(varP);
		varP->sig = varP->sig->sig;
	}
}

int TablaSimbolos::dispersion(string simbolo){
	unsigned int h=0, g;
	unsigned char c;
	unsigned char alfa= 4;
	
	for (int i=0; i<simbolo.length(); i++){
		c= simbolo[i];
//		h= (h << 4) + c;
		h += alfa*c;
		h= h % TAM;
	}

	return h%TAM;
}

void TablaSimbolos::agrega( ElementoTabla *elemento){
	int ind= dispersion(elemento->simbolo);
	tabla[ind].push_back(elemento);
}

void TablaSimbolos::muestra(){
	list<ElementoTabla*>::iterator it;
	ElementoTabla *elem;

	cout << endl << "*** Tabla de Simbolos ***" << endl;

	for (int i=0; i< TAM; i++){
		if (tabla[i].size() > 0){

			for (it= tabla[i].begin(); it != tabla[i].end(); it++){
				elem= (ElementoTabla *)*it;
				cout << "Lista= " << i << endl;
				elem->muestra();
			}
		}
	}
}

bool TablaSimbolos::funcionDefinida(string funcion){
	int ind= dispersion(funcion);
	list<ElementoTabla*>::iterator it;
	ElementoTabla *elem;

	for (it= tabla[ind].begin(); it != tabla[ind].end(); it++){
		elem= (ElementoTabla *)*it;
		if (elem->esFuncion()) {
			if (elem->simbolo.compare(funcion) == 0) return true;
		}
	}

	return false;
}

bool TablaSimbolos::varGlobalDefinida(string variable){
	int ind= dispersion(variable);
	list<ElementoTabla*>::iterator it;
	ElementoTabla *elem;

	for (it= tabla[ind].begin(); it != tabla[ind].end(); it++){
		elem= (ElementoTabla *)*it;
		if (elem->esVariable() && !elem->esVarLocal()) {
			if (elem->simbolo.compare(variable) == 0) return true;
		}
	}

	return false;
}

bool TablaSimbolos::varLocalDefinida(string variable, string funcion){
	int ind= dispersion(variable);
	list<ElementoTabla*>::iterator it;
	ElementoTabla *elem;

	for (it= tabla[ind].begin(); it != tabla[ind].end(); it++){
		elem= (ElementoTabla *)*it;
		if (elem->esVariable() && elem->esVarLocal()) {
			if (((Variable*)elem)->ambito.compare(funcion) ==0  && elem->simbolo.compare(variable) == 0) return true;
		}
	}

	return false;
}

void TablaSimbolos::buscaIdentificador(string simbolo){
	int ind= dispersion(simbolo);
	list<ElementoTabla*>::iterator it;
	ElementoTabla *elem;

	varGlobal= NULL;
	varLocal= NULL;
	funcion= NULL;

	for (it= tabla[ind].begin(); it != tabla[ind].end(); it++){
		elem= (ElementoTabla *)*it;

		if (elem->simbolo.compare(simbolo) == 0){
			if (elem->esVariable()){
				if (elem->esVarLocal()) varLocal= (Variable*)elem;
				else
					varGlobal= (Variable*)elem;
			}
			else
				funcion= (Funcion*)elem;
		}

	}
	
}


void TablaSimbolos::buscaFuncion(string simbolo){
	int ind= dispersion(simbolo);
	list<ElementoTabla*>::iterator it;
	ElementoTabla *elem;

	varGlobal= NULL;
	varLocal= NULL;
	funcion= NULL;

	for (it= tabla[ind].begin(); it != tabla[ind].end(); it++){
		elem= (ElementoTabla *)*it;

		if (elem->simbolo.compare(simbolo) == 0 && elem->esFuncion()){
				funcion= (Funcion*)elem;
				return;
		}
	}

}

