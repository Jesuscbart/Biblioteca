//Proyecto biblioteca - programacion 1- Realizado por Jesus Cuesta Bartolome y Alejandro Riego Velasco

#ifndef MENUSBIBLIO_H
#define MENUSBIBLIO_H
#endif // MENUSBIBLIO_H
#include <iostream>

using namespace std;

int menu(void){ //Primer menu

    int opcion= 0;
    cout<<"============================================================="<<endl;
    cout<<endl<<"Bienvenido a la biblioteca, seleccione una opcion"<<endl<<endl;
    cout<<"1. Introducir un libro o publicacion"<<endl;
    cout<<"2. Buscar un libro"<<endl;
    cout<<"3. Buscar una publicacion"<<endl;
    cout<<"4. Listar coleccion de libros"<<endl;
    cout<<"5. Listar coleccion de publicaciones cientificas"<<endl;
    cout<<"6. Salir de la biblioteca"<<endl<<endl;
    cout<<"============================================================="<<endl;
    cout<<endl;
    cin>>opcion;
    cout<<endl;

    return opcion;
}

int menuIntroducir(void){ //Menu de untroducir

    int opcion= 0;
    cout<<"============================================================="<<endl;
    cout<<endl<<"Seleccione una opcion"<<endl<<endl;
    cout<<"1. Introducir un libro"<<endl;
    cout<<"2. Introducir una publicacion cientifica"<<endl;
    cout<<"3. No desea introducir nada"<<endl<<endl;
    cout<<"============================================================="<<endl;
    cout<<endl;
    cin>>opcion;
    cout<<endl;

    return opcion;
}

int menuBuscar(void){ //Menu de buscar

    int opcion= 0;
    cout<<"============================================================="<<endl;
    cout<<endl<<"Seleccione una opcion"<<endl<<endl;
    cout<<"1. Buscar por titulo"<<endl;
    cout<<"2. Buscar por autor"<<endl;
    cout<<"3. No quiere buscar nada"<<endl<<endl;
    cout<<"============================================================="<<endl;
    cout<<endl;
    cin>>opcion;
    cout<<endl;

    return opcion;
}
