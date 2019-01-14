#include <iostream>
#include <locale>
#include <windows.h>
#include <string>

using namespace std;

#define strlimit 200

void menu();

string Suma(string x, string y)
{
    char sumastr[strlimit];
    char auxx[strlimit];
    char auxy[strlimit];

    for(int i=0;i<strlimit;i++){
        sumastr[i] = '\0';
        auxx[i] = '\0';
        auxy[i] = '\0';
    }

    strcpy(auxx,x.c_str());
    strcpy(auxy,y.c_str());

    int i=0;
    while(auxx[i] != '\0'){
        sumastr[i] = auxx[i];
        i++;
    }
    int j=0;
    while(auxy[j] != '\0'){
        sumastr[i+j] = auxy[j];
        j++;
    }

    string aux3 = sumastr;

    return aux3;
}

string Resta(string x, string y)
{
    char auxx[strlimit];
    char auxy[strlimit];

    for(int i=0;i<strlimit;i++){
        auxx[i] = '\0';
        auxy[i] = '\0';
    }

    strcpy(auxx,x.c_str());
    strcpy(auxy,y.c_str());

    string aux3;

    int i=0;
    while(auxx[i] != '\0')
        i++;

    int j=0;
    while(auxy[j] != '\0')
        j++;

    if(i >= j){
        int w = 0;
        while(auxy[w] != '\0'){
            auxx[i-w-1] = '\0';
            w++;
        }
        if(auxx[0] == '\0')
            return "#";
        else{
            aux3 = auxx;
            return aux3;
        }
    }
    else{
        int z = 0;
        while(auxx[z] != '\0'){
            auxy[j-z-1] = '\0';
            z++;
        }
        auxy[0] = '-';
        aux3 = auxy;
        aux3+='|';
        return aux3;
    }
}

string Multiplicar(string x, string y)
{
    char auxx[strlimit];
    char auxy[strlimit];
    char aux2[strlimit];

    for(int i=0;i<strlimit;i++){
        auxx[i] = '\0';
        auxy[i] = '\0';
    }

    strcpy(auxx,x.c_str());
    strcpy(auxy,y.c_str());

    string aux3;

    int i = 0;
    int j = 0;
    int cont = 0;

    while(auxx[i] != '\0'){
        j = 0;
        while(auxy[j] != '\0'){
            aux2[cont] = auxy[j];
            cont++;
            j++;
        }
        i++;
    }

    aux2[cont] = '\0';
    aux3 = aux2;
    return aux3;
}

string Division(string x, string y)
{
    int i = 0;
    int mayor = 0;

    while(x[i] != '#'){
        if(x[i] == '\0' && y[i] == '\0'){
            mayor = 0;
            break;
        }
        if(x[i] == '\0'){
            mayor = 2;
            break;
        }
        if(y[i] == '\0'){
            mayor = 1;
            break;
        }
        i++;
    }

    char aux[strlimit];

    if(mayor == 0){
        return "|";
    }
    if(mayor == 1){
        int j = 0;
        while(x[0] != '-'){
            x = Resta(x,y);
            aux[j] = '|';
            j++;
            if(x.compare("#") == 0){
                aux[j] = '\0';
                return aux;
            }
        }
        aux[j-1] = '\0';
        return aux;
    }
    else
        return "#";
}

bool comprobarStrings(string x, string y)
{
    int i=0;
    int j=0;
    while(x[i] != '\0'){
        if(x[i] != '|')
            return false;
        i++;
    }
    while(y[j] != '\0'){
        if(y[j] != '|')
            return false;
        j++;
    }
    return true;
}

void ingresarStrings(string &str1, string &str2)
{
    cout << "\n\nIngrese String 1: ";
    cin >> str1;
    cout << "\n\nIngrese String 2: ";
    cin >> str2;
    if(comprobarStrings(str1,str2)){
        cout << "\n\n";
    }
    else{
        cout << "\n\nHay un ERROR en los datos Ingresados. ";
        system("PAUSE");
        cout << "\n\n";
        menu();
    }
}

void menu()
{
    system("CLS");
    int opt = 0;
    string str1 = "";
    string str2 = "";
    cout << "\n***************** MENU *****************\n\n";
    cout << "1.- Sumar.\n2.- Re:been1976star.\n3.- Multiplicar.\n4.- Dividir.\n5.- Salir\n\nIngrese Opcion: ";
    cin >> opt;

    switch(opt)
    {
    case 1:
        ingresarStrings(str1,str2);
        cout << "Resultado : " << Suma(str1,str2) << "\n\n";
        system("PAUSE");
        cout << "\n\n";
        menu();
    case 2:
        ingresarStrings(str1,str2);
        cout << "Resultado : " << Resta(str1,str2) << "\n\n";
        system("PAUSE");
        cout << "\n\n";
        menu();
    case 3:
        ingresarStrings(str1,str2);
        cout << "Resultado : " << Multiplicar(str1,str2) << "\n\n";
        system("PAUSE");
        cout << "\n\n";
        menu();
    case 4:
        ingresarStrings(str1,str2);
        cout << "Resultado : " << Division(str1,str2) << "\n\n";
        system("PAUSE");
        cout << "\n\n";
        menu();
    case 5:
        exit(0);
    default:
        cout << "\nOpcion Ingresada Invalida.\n\n";
        system("PAUSE");
        cout << "\n\n";
        menu();
    }
}

int main()
{
    menu();
    return 0;
}
