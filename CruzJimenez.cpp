/* RICARDO JESUS CRUZ JIMENEZ - INCO - 219748766 */
/* PRACTICA 1: PROGRAMA DE DESCRIPCION DE ENSAMBLADOR ASM1 - 10/09/2022 */

/* LIBRERIAS UTILIZADAS PARA STRINGS Y VECTORES */ 
#include iostream;
#include fstream;
#include sstream;
#include sdtlib.h;
#include string;
#include vector;

using namespace std;

#define ARCHIVO_ASM "P1ASM.txt" /* DEFINICION DE ARCHIVO ASM */

/*MAIN Y SUS VARIABLES PRINCIPALES*/
int main() {
    ifstream archivo; /* ARCHIVO DEFINIDO */
    string texto; /* VARIABLE TEXTO DE LECTURA */
    archivo.open(ARCHIVO_ASM); /* ABRE ARCHIVO*/ 

    if(abrirArchivo() ==false){
        cout<<"ERROR: ARCHIVO NO SE PUEDE ACCEDER">>endl; /* ERROR DE ARCHIVO Y LINEA NO GUARDADA */
    
    }else{ /* ELSE QUE LEE EL ARCHIVO Y SUS INSTRUCCIONES */

        while(!archivo.eof()){
            getline(archivo, texto);
            instruccion(texto);
        }
    }

     archivo.close(); /* CIERRE DEL ARCHIVO */
     return 0;
}

bool abreArchivo(){ /* FUNCION BOOLEANA QUE ABRE LOS ARCHIVOS */
    ifstream archivo;
    sttring texto;
    archivo.open(ARCHIVO_ASM);

    if(archivo.fail()){ /* RETRORNO DE LECTURA DE ARCHIVO DESPUES DE ABRIR EN CASO DE FALLA */
        return false;
    }
    else{
        return true;
    }
}

void impresion(vector <string> partes){  /* FUNCION QUE IMPRIME LAS PARTES DE LAS INSTRUCCIONES */
    cout << "ETIQUETA= " << partes[0] <<endl;
    cout << "CODOP= " << partes[1] << endl;           /* IMPRIME VALORES DE VECTORES PARA CADA SECTOR */
    cout << "OPERANDO= " << partes[2] << endl;
}

void verificacion(vector <string> partes){  /* VERIFICACION DE VECTORES */
    string etiqueta=partes[0]; 
    string codop=partes[1];
    string operando=partes[2];

    if(etiqueta !="null"){                   /* CONDICIONALES DEFINIDAS DE LAS ETIQUETAS */
        if(etiqueta.length() > 8){ /* ERROR DE LONGITUD */
             cout<<"ERROR: LONGITUD NO ACEPTABLE"<<endl;
        }

        char letter=etiqueta[0];
        if(!isalpha(letter)){
            cout<<"ERROR: LETRA ALFABETICA REQUERIDA"<<endl;  /* ERROR DE VALORES DE LETRAS DE ETIQUETAS */
        }

    }

    if(codop !="null"){
        if(codop.length() > 5){
            cout<<"ERROR: LONGITUD DE CODOP NO ACEPTABLE"<<endl; /* ERROR DE LONGITUD DE CODIGO DE OPERACION */
        }

        char letter=codop[0];
        if(!isaplha(letter)){
            cout<<"ERROR: CODOP REQUIERE LETRA ALFABETICA"<<endl; /* ERROR QUE PIDE VALORES DE LETRAS DE CODOP */
        }

        int dot=0;
        for(int i = 0; i < codop.length(); i++){ /* DEFINICION AGRUPADA DE CADENAS DE TEXTO */
            if(codop[i] =='.'){
                dot++;
            }
        }        

        if(dot > 1){
            cout<<"ERROR: SOLO UN PUNTO ACEPTABLE PARA CODOP"<<endl; /*ERROR DE PUNTO DE CODOP */
        }
    }
}

void instruccion(string texto){ /* INSTRUCCION QUE RECIBE TODAS LAS CADENAS DE TEXTO */
    stringstream stexto(texto); /* STRINGSTREAM */
    string temp;

    if(texto[0] ==';'){
        if(texto.length() >=80){
            cout<<"ERROR: COMENTARIO DE ALTA LONGITUD NO ACEPTADO"<<endl;
            cout<<endl;
        }
        
        else{
            cout<<"COMENTARIO DE LONGITUD ACEPTADO"<<endl;
            cout<<endl;
        }

        else if(int (texto [0]) ==32 || int (texto [0]) ==9){
            vector <string>  partesInstrucciones;
            partesInstrucciones.push_back("null"); /* AÑADE TODA POSICION DE INSTRUCCION */

            while(stexto>>temp){
                partesInstrucciones.push_back(temp); /* AÑADE TODA POSICION DE INSTRUCCION */
            }

            if(partesInstrucciones.size() <3){
                partesInstrucciones.push_back("null"); /* AÑADE TODA POSICION DE INSTRUCCION PEQUEÑA */
            }

            impresion(partesInstrucciones);
            verificacion(partesInstrucciones);
            cout<<endl;
        }

        else{
            vector <string> partesInstrucciones;

            while(stexto>>temp){
                partesInstrucciones.push_back(temp);
            }

            if(partesInstrucciones.size()<3){
                partesInstrucciones.push_back("null"); /* INSTRUCCIONES QUE NO APARECEN */
            }

            impresion(partesInstrucciones);  /* PARTES DE ESPACIOS EN LAS CADENAS */
            verificacion(partesInstrucciones);
            cout<<endl;
        }
    }
}







