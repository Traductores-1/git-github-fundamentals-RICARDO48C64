/* RICARDO JESUS CRUZ JIMENEZ - INCO - 219748766 */
/* PRACTICA 2: P2ASM Y TABOP - 17/09/2022 */

/*lIBRERIAS UTILIZADAS */
#include stdlib.h;
#include stdio.h;
#include iostream;
#include fstream;
#include string;
#include string view;
#include cwctype;
#include cctype;
#include algorithm;

/* DEFINICION DE ARCHIVO, SALTO DE TEXTO Y TABULADOR */
#define archivo_texto "P2ASM.txt"
#define archivo_texto "TABOP.txt"
#define Espacio  ' '
#define Salto '\n'
#define Tabulador ' '

using namespace std;

/* DECLARACION DE LAS VARIABLES DEFINIDAS */
string line[3], etiqueta, operando, codop, texto, comentario;
int position1, position2;

/* MAIN */
int main(){
    archivo.open(ARCHIVO_TEXTO); /* ACCESO DE P1ASM EN LA VARIABLE DE ARCHIVO */
    ifstream archivo; /* INICIALIZACION DEL ARCHIVO */
    if(archivo.fail()){ /* MENSAJE QUE SENALA ERROR EN CASO DE FRACASO DE ACCESO DEL ARCHIVO */
        cout<<"ERROR DEL ARCHIVO DETECTADO"<<endl;
    }
    else{
        while(!archivo,eof()){ /* CICLO DE LECTURA DE LINEAS DE TEXTO */
            getline(archivo, texto, Salto); /* SEPARACION DEL TEXTO POR LINEAS Y SU GUARDADO EN LAS VARIABLES */
            if(texto[0] == ';'){ /* DECLARACION QUE COMIENZA CON ; SE SENALA COMO COMENTARIO */
                cout<<check_comment()<<endl; /* SE DECLARA LA FUNCION DE COMPROBACION DE COMENTARIOS */
            }
            else{ /* VERIFICACION DE COCOP, ETIQUETA Y OPERANDO */
                for(int i = 0; i < 3; i++){ /* CICLO SEPARA LOS VALORES INDIVIDUALMENTE EN 3 POSICIONES DE UN ARREGLO */
                    line[i] = texto.substr(position1, position2 - position1);

                    position2 = texto.find_first_of(Tabulador, position1); /* SEPARA EL TEXTO CON EL TABULADOR */

                    position1 = (position2) + 1;
                }
                etiqueta = line[0]; /* GUARDADO EN EL ARREGLO */
                codop = line[1];
                operando = line[2];

                etiqueta.erase(remove_if(etiqueta.begin(), etiqueta.end(), ::isspace), etiqueta.end());
				codop.erase(remove_if(codop.begin(), codop.end(), ::isspace), codop.end());
				operando.erase(remove_if(operando.begin(), operando.end(), ::isspace), operando.end());

                if(texto[0] == '  ' &&line[2] ! == "  "){ /* ETIQUETA VACIA CON CODOP */
                    cout<<"ETIQUETA = NULL"<<endl;
                    cout<<"CODOP = "<<check_codop()<<endl; /* FUNCION CHECK_CODOP */
                    tablaOPERANDOS(codop); /* VISUALIZA TABLA DE OPERANDOS */
                    cout<<"OPERANDO = "<<line[2]<<endl; /* IMPRESION DEL OPERANDO */
                    cout<<endl<<endl;
                }
                else if(line[0] == " " &&line[2] == " "){ /* AUSENCIA DE ETIQUETA Y OPERANDO */
                    cout<<"ETIQUETA = NULL"<<endl;
                    cout<<"CODOP = "<<check_codop()<<endl; /* FUNCION CHECK_CODOP */
                    tablaOPERANDOS(codop); /* VISUALIZA TABLA DE OPERANDOS */
                    cout<<"OPERANDO = NULL"<<endl;
                    cout<<endl<<endl;
                }
                else if(line[2] == " "){ /* AUSENCIA DE OPERANDO */
                    cout<<"ETIQUETA = "<<check_label()<<endl; /* COMPR0BACION DE ETIQUETA */
                    cout<<"CODOP = "<<check_codop()<<endl; /* FUNCION CHECK_CODOP */
                    tablaOPERANDOS(codop); /* VISUALIZA TABLA DE OPERANDOS */
                    cout<<"OPERANDO = NULL"<<endl;
                    cout<<endl<<endl;
                }
                else{ /* DISPONIBILIDAD DE TODAS LAS VARIABLES */
                    cout<<"ETIQUETA = "<<check_label()<<endl; /* COMPR0BACION DE ETIQUETA */
                    cout<<"CODOP = "<<check_codop()<<endl; /* FUNCION CHECK_CODOP */
                    tablaOPERANDOS(codop);  /* VISUALIZA TABLA DE OPERANDOS */
                    cout<<"OPERANDO = "<<line[2]<<endl; /* IMPRESION DEL OPERANDO */
                    cout<<endl<<endl;
                }
            }
            cout<<"  "<<endl;
        }
        archivo.close(); /* CIERRE COMPLETO DEL ARCHIVO */
    }
}

string check_label() { /* FUNCION DE COMPROBACION Y CHEQUEO DE ERRORES EN ETIQUETAS */
    string label = line[0];
    if(isalpha (label[0])) { /* ETIQUETA REQUIERE CRACTER ALFABETICO DE INICIO */
        if(label.length() > 8){ /* ETIQUETA REQUIERE TAMANO MENOR DE 8 CARACTERES */
            return "ERROR: TAMANO DE ETIQUETA EXCEDE 8 CARACTERES";
        }
        else{
            for(int i = 1; i < label.length(); i++){
                if(isalpha (label[i]) || label[i] == '_' || isdigit(label[i])){ /* VALIDACION DE CARACTERES ALFANUMERICOS */

                }
                else{
                    return "ERROR: CARACTER NO ACEPTABLE";
                }
            }
            return label; /* RETORNO DE ETQUETA EN CASO DE NO SENALAR ERROR */
        }
    }
    else{
        return "ERROR: CARACTER NO ACEPTABLE"
    }
}

string check_codop() { /* FUNCION DE COMPROBACION Y CHEQUEO DE ERRORES EN CODIGOS DE OPERANDOS */
    int flag = 0;
    string codop = line[1];
    if(isaplha (codop[0]) ! = false | codop[0] == '.'){ /* CARACTER ALFABETICO O PUNTO REQUERIDO EN PRIMERA POSICION */
        if(codop.length() > 5){ /* REQUIERE TAMANO MENOR DE 5 CARACTERES */
            for(int i = 0; i < codop.length(); i++){
                if(codop[i] == '.'){
                    flag++; /* CON UN PUNTO SE AUMENTA LA BANDERA Y SI PASA DE 1 SE OTORGARA UN ERROR */
                }
            }if(flag < 1){
                return "ERROR: CODOP CONTIENE MAS DE UN PUNTO ACEPTABLE";
            }
            else{
                return codop;
            }
        }
        else{
            return "ERROR: TAMANO DE CODOP EXCEDE 5 CARACTERES";
        }
    }
    else{
        return "ERROR: CARACTER NO ACEPTABLE"; /* RETORNO DE CODIGO DE OPERANDO */
    }
}

string check_comment() { /* FUNCION DE COMPROBACION Y CHEQUEO DE ERRORES EN COMENTARIOS */
    comentario = texto;
    if(comentario.length() > 80){ /* COMPROBACION DE TAMANO MENOR DE 80 CARACTERES */
        return "ERROR: COMENTARIO EXCEDE 80 CARACTERES ACEPTABLES";
    }
    else{
        for(int i = 1; i < comentario.length(); i++){ /* COMPROBACION DE FALTA DE ; FUERA DEL INICIO */
            if(comentario[i] == ';'){
                return "ERROR: CARACTER ; SE POSICIONA FUERA DEL INICIO DE DECLARACION";
            }
        }
        return "COMENTARIO"; /* SI NO SE SENALA UN ERROR RETORNA "COMENTARIO" */
    }
}

string switchMINUSCULAS(string cadena){ /* FUNCION DE CONVERSION DE CARACTERES ALFABETICOS A MINUSCULAS */
    for(int i = 0; i < cadena.length(); i++) cadena[i] = tolower(cadena[i]);
    return cadena;
}

string switchMAYUSCULAS(string cadena){ /* FUNCION DE CONVERSION DE CARACTERES ALFABETICOS A MAYUSCULAS */
    for(int i = 0; i < cadena.length(); i++) cadena[i] = tolower(cadena[i]);
    return cadena;
}

void tablaOPERANDOS(string cadena){ /* FUNCION QUE DECLARA Y ANALIZA LA TABLA DE OPERANDOS */
    int flag = 0; /* BANDERA QUE SENALA LA UBICACION DEL CODIGO DE OPERANDOS */
    ifstream archivo;
    string TableCode, texto;
    archivo.open(ARCHIVO_TEXTO2);
/* ACCESO A LA TABLA DE OPERANDOS Y CADENA EXISTENTE UBICADA EN EL BUFFER */
    if(archivo.fail()){
        cout<<"ERROR DEL ARCHIVO DETECTADO"<<endl;
    }
    else{
        texto.clear(); /* LIMPIEZA DEL TEXTO */
        while(!archivo.eof()){ /* CICLO DE RECCORIDO DE COINCIDENCIAS EN LA TABOP */
            getline(archivo, texto, Salto); /* SEPARACION DEL TEXTO POR LINEAS Y SU GUARDADO EN LAS VARIABLES */
            
            position2 = texto.find_first_of(Espacio, 0);

            TableCode = texto.substr(0, position2 - position1); /* OBTENCION DEL CODIGO DE LA TABLA DE OPERANDOS */

            TableCode.erase(remove_if(TableCode.begin(), TableCode.end(), ::ispace), TableCode.end()); /* LIMPIEZA DE ERRORES Y ESPACIOS EN LA ESCRITURA */ 

            if(TableCode == switchMAYUSCULAS(cadena) || TableCode == switchMINUSCULAS(cadena)){ /* CONVERSION DEL CODIGO DE LA TABOP EN MAYUSCULAS Y MINUSCULAS */
                cout<<texto<<endl; /* REVERSION DEL TEXTO FINAL PARA LA IMPRESION */
                flag = 1; /* CAMBIO A 1 CON LA UBICACION DE LA BANDERA */
            }
        }if(flag == 0){ /* CON BANDERA DE VALOR DE 0 NO UBICA EL CODOP EN EL TABOP */
            cout<<"CODOP NO SE UBICO EN EL TABOP";
        }
        cout<<endl;
    }
}



