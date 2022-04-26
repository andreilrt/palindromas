//Programa de palabras palindromas
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

bool palindroma(string palabra){
    string palabra1;
    int contador = 0;
    int longitud = palabra.length();
    for(int letra = longitud-1; letra>=0; letra--){
        palabra1[contador]=palabra[letra];
        contador++;
    }
    for(int letra = 0; letra<longitud; letra++){
        if(palabra[letra]!=palabra1[letra]){
            return false;
        }
    }
    return true;
}

string quitar_caracteres(string palabra){
    string palabra1;
    int longitud = palabra.length();
    int contador = 0;
    for(int letra = 0; letra<longitud; letra++){
        if(palabra[letra]>='a'){
            if(palabra[letra]<='z'){
                palabra[contador] = palabra[letra];
                contador++;
            }
        }
    }
    palabra1 = palabra.substr(0,contador);
    return palabra1;
}

string recibe_palabra(string pregunta){
    string palabra;
    cout<<pregunta;
    getline(cin,palabra);
    cout<<endl;
    return palabra;
}

string minuscula(string palabra){
    for(int letra = 0; letra<palabra.length(); letra++){
        if(palabra[letra]>='A'){
            if(palabra[letra]<='Z'){
                palabra[letra] = palabra[letra]+32;
            }
        }
    }
    return palabra;
}

void proceso(){
    bool control = true;
    cout<<" ---Este programa revisa si una palabra o frase es palindroma--- \n\n";
    string nombre = recibe_palabra("Por favor digita tu nombre: ");
    while(control){
        string palabra1 = recibe_palabra(nombre+" por favor ingresa tu palabra/frase: ");
        string palabra2 = minuscula(palabra1);
        string palabra = quitar_caracteres(palabra2);
        if(palindroma(palabra)){
            cout<<"La palabra/frase '"+palabra1+"' es palindroma :))\n"<<endl;
        }
        else{
            cout<<"La palabra/frase '"+palabra1+"' no es palindroma :((\n"<<endl;
        }
        string decision = recibe_palabra(nombre+" digita 'Si' para continuar verificando palabras: ");
        decision = minuscula(decision);
        if(decision!="si"){
            cout<<"Gracias "+nombre+" por usar nuestro servicio para verificar palindromas!!!\n"
            <<"Te esperamos de nuevo :))\n";
            control = false;
        }
    }
}

int main()
{
    proceso();
    return 0;
}
