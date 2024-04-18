//Proyecto biblioteca - programacion 1- Realizado por Jesus Cuesta Bartolome y Alejandro Riego Velasco

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <fstream>
#include "MenusBiblio.h"

using namespace std;

string nombreArchivo = "biblioteca.txt";
ofstream Escribirarchivo;
ifstream LeerArchivo (nombreArchivo.c_str());

struct libro{
    string ID;
    string titulo;
    vector<string> autores;
};

struct publicacion{
    string titulo;
    vector<string> autores;
    string congreso;
};

struct biblioteca{
    vector<libro> libros;
    vector <publicacion> publicaciones;
};

biblioteca LeerInfoTxt(){ //Abrimos el txt y volcamos su contenido en el programa
        biblioteca biblioteca;
        libro libroaux;
        publicacion publiaux;
        vector<string> lineas;
        string linea,aux,autor;
        int cont {0},ind {0},x{0};

        ifstream LeerArchivo (nombreArchivo);  //.c_str()
        if (!LeerArchivo.is_open()) {
            cout << "No se pudo abrir  - '"<<nombreArchivo << "'" << endl;
        }

        while (getline(LeerArchivo, linea)){
            lineas.push_back(linea);
        }

        //for (const auto &i : lineas)   //Esto muestra todo lo del txt por terminal
            //cout << i << endl;

        LeerArchivo.close(); //Cerramos el archivo

        for (auto elem:lineas){ //Recorremos el vector que contiene las lineas para buscar los libros y publicaciones

            if (elem=="LIBRO"){ //Si es un libro lleva esto delante

                libroaux.ID=lineas.at(cont+1);
                libroaux.titulo=lineas.at(cont+2);
                aux=lineas.at(cont+3);
                ind=0;

                for (auto elem:aux) //Separamos los autores para poder meterlos en el vector de autores
                {
                    if ( (elem==',') and !autor.empty())
                    {//si encuentro una coma y el autor no esta vacio ya tengo un autor
                        libroaux.autores.push_back(autor); //Lo anado a mi vector de autores
                        autor.clear(); //La borro para continuar con la siguiente
                    }
                    else if (ind==aux.size()-1)
                    {//Si se acaba la frase tambien anadimos el autor
                        autor.push_back(elem); //anadimos la ultima letra
                        libroaux.autores.push_back(autor);
                    }
                    else
                    {
                        autor.push_back(elem);
                    }

                    ind++;
                }
                biblioteca.libros.push_back(libroaux);
                libroaux.autores.clear();
                autor.clear();
                x++;
                //cout<<"Se ha introducido un libro desde la memoria"<<endl;
            }

            else if (elem=="PUBLICACION"){ //Si es una publiacion lleva esto delante

                publiaux.titulo=lineas.at(cont+1);
                publiaux.congreso=lineas.at(cont+3);
                aux=lineas.at(cont+2);
                ind=0;

                for (auto elem:aux) //Separamos los autores para poder meterlos en el vector de autores
                {
                    if ( (elem==',') and !autor.empty())
                    {//si encuentro una coma y el autor no esta vacio ya tengo un autor
                        publiaux.autores.push_back(autor); //Lo anado a mi vector de autores
                        autor.clear(); //La borro para continuar con la siguiente
                    }
                    else if (ind==aux.size()-1)
                    {//Si se acaba la frase tambien anadimos el autor
                        autor.push_back(elem); //anadimos la ultima letra
                        publiaux.autores.push_back(autor);
                    }
                    else
                    {
                        autor.push_back(elem);
                    }

                    ind++;
                }

                biblioteca.publicaciones.push_back(publiaux);
                publiaux.autores.clear();
                autor.clear();
                x++;
                //cout<<"Se ha introducido una publicacion desde la memoria"<<endl;
            }
            cont++;
        }

        cout<<"Se han cargado "<<x<<" elementos desde la memoria"<<endl;
        cout<<endl;

     return biblioteca;
}

function <void(string)> EscribirInfoTxt=[ ](string const&info){ //Escribir en el txt

    Escribirarchivo.open(nombreArchivo.c_str(),  fstream::out | fstream::app);
    Escribirarchivo <<info<<endl;
    Escribirarchivo.close();
};

libro IntroducirLibro () { //Crear libro y guaradarlo en el txt
    libro libro;
    string aux,autor;
    int ind{0};

    cin.ignore();
    cout<<"Introduzca un ID para su libro: ";
    getline(cin,libro.ID);
    cout<<endl;
    cout<<"Introduzca el titulo de su libro: ";
    getline(cin,libro.titulo);
    cout<<endl;
    cout<<"Introduzca el/los autores de su libro (separados con comas) : ";
    getline(cin,aux);
    cout<<endl;

        for (auto elem:aux)
        {
            if ( (elem==',') and !autor.empty())
            {//si encuentro una coma y el autor no esta vacio ya tengo un autor
                libro.autores.push_back(autor); //Lo anado a mi vector de autores
                autor.clear(); //La borro para continuar con la siguiente
            }
            else if (ind==aux.size()-1)
            {//Si se acaba la frase tambien anadimos el autor
                autor.push_back(elem); //anadimos la ultima letra
                libro.autores.push_back(autor);
            }
            else
            {
                autor.push_back(elem);
            }

            ind++;
        }

        EscribirInfoTxt("LIBRO");
        EscribirInfoTxt(libro.ID);
        EscribirInfoTxt(libro.titulo);
        EscribirInfoTxt(aux);
        EscribirInfoTxt("==========");

    return libro;
}

void MostrarLibro(biblioteca const& biblioteca,int posicion){ //Funcion generica que imprime un libro

    cout<<"Se le mostraran los datos del libro seleccionado"<<endl;
    cout<<"ID: "<<biblioteca.libros.at(posicion).ID<<endl;
    cout<<"Titulo: "<<biblioteca.libros.at(posicion).titulo<<endl;
    cout<<"Autores: ";
    for (auto elem:biblioteca.libros.at(posicion).autores){
        cout<<elem<<", ";
    }
    cout<<endl;
    cout<<endl;
}

void MostrarPublicacion(biblioteca const& biblioteca,int posicion){

    //cout<<"Se le mostraran los datos de la publicacion cientifica "<<endl;
    cout<<"Titulo: "<<biblioteca.publicaciones.at(posicion).titulo<<endl;
    cout<<"Autores: ";
    for (auto elem:biblioteca.publicaciones.at(posicion).autores){
        cout<<elem<<", ";
    }
    cout<<endl;
    cout<<"Congreso: "<<biblioteca.publicaciones.at(posicion).congreso<<endl;
    cout<<endl;

}

publicacion IntroducirPublicacion () { //Crear publicacion y guardarla en el txt
    publicacion publicacion;
    string aux,autor;
    int ind{0};

    std::cin.ignore();
    cout<<"Introduzca el titulo de su publicacion: ";
    getline(cin,publicacion.titulo);
    cout<<endl;
    cout<<"Introduzca el nombre del congreso donde ha sido publicado: ";
    getline(cin,publicacion.congreso);
    cout<<endl;
    cout<<"Introduzca el/los autores de su publicacion (separados con comas) : ";
    getline(cin,aux);
    cout<<endl;

    for(auto elem:aux)
    {
        if ( (elem==',') and !autor.empty())
        {//si encuentro una coma y el autor no esta vacio ya tengo un autor
            publicacion.autores.push_back(autor); //Lo anado a mi vector de autores
            autor.clear(); //La borro para continuar con la siguiente
        }
        else if (ind==aux.size()-1)
        {//Si se acaba la frase tambien anadimos el autor
            autor.push_back(elem); //anadimos la ultima letra
            publicacion.autores.push_back(autor);
        }
        else
        {
            autor.push_back(elem);
        }

        ind++;
    }

    EscribirInfoTxt("PUBLICACION");
    EscribirInfoTxt(publicacion.titulo);
    EscribirInfoTxt(aux);
    EscribirInfoTxt(publicacion.congreso);
    EscribirInfoTxt("==========");

    return publicacion;
}

void BuscarPublicacionAutor(biblioteca const& biblioteca){ //Busca una publicacion por su autor

    std::cin.ignore();
    string intro;
    int cont{0},coincidencias{0};
    cout<<"Introduzca el nombre del autor de la publicacion cientifica que desea buscar: ";
    getline(cin,intro);
    cout<<endl;

    for (auto publis:biblioteca.publicaciones){
        for (auto autor:publis.autores){
            if (autor==intro){
                coincidencias++;
                cout<<"Coincidencia n "<<coincidencias<<" "<<endl;
                MostrarPublicacion(biblioteca,cont);
            }
        }
        cont++;
    }
    if (coincidencias==0){
        cout<<"No se han encontrado coincidencias con el parametro introducido"<<endl<<endl;
    }

}

void BuscarLibroAutor(biblioteca const& biblioteca){ //Busca un libro por su autor

    std::cin.ignore();
    string intro;
    int cont{0},coincidencias{0};
    cout<<"Introduzca el nombre del autor del libro que desea buscar: ";
    getline(cin,intro);
    cout<<endl;

    for (auto libro:biblioteca.libros){
        for (auto autor:libro.autores){
            if (autor==intro){
                coincidencias++;
                cout<<"Coincidencia n "<<coincidencias<<" "<<endl;
                MostrarLibro(biblioteca,cont);
            }
        }
        cont++;
    }
    if (coincidencias==0){
        cout<<"No se han encontrado coincidencias con el parametro introducido"<<endl<<endl;
    }

}

void BuscarPublicacionTitulo(biblioteca const& biblioteca){ //Busca una publicacion por su titulo

    std::cin.ignore();
    string intro;
    int cont{0},coincidencias{0};

    cout<<"Introduzca el titulo de la publicacion cientifica que desea buscar: ";
    getline(cin,intro);
    cout<<endl;

    for (auto publis:biblioteca.publicaciones){
            if (publis.titulo==intro){
                coincidencias++;
                cout<<"Coincidencia n "<<coincidencias<<" "<<endl;
                MostrarPublicacion(biblioteca,cont);
            }
             cont++;
        }
    if (coincidencias==0){
        cout<<"No se han encontrado coincidencias con el parametro introducido"<<endl<<endl;
    }
}

void BuscarLibroTitulo(biblioteca const& biblioteca){ //Busca una publicacion por su titulo

    std::cin.ignore();
    string intro;
    int cont{0},coincidencias{0};

    cout<<"Introduzca el titulo del libro que desea buscar: ";
    getline(cin,intro);
    cout<<endl;

    for (auto libro:biblioteca.libros){
            if (libro.titulo==intro){
                coincidencias++;
                cout<<"Coincidencia n "<<coincidencias<<" "<<endl;
                MostrarLibro(biblioteca,cont);
            }
             cont++;
        }
    if (coincidencias==0){
        cout<<"No se han encontrado coincidencias con el parametro introducido"<<endl<<endl;
    }
}

void ListarPublicaciones(biblioteca const& biblioteca){

    int cont{0},respuesta{0},num{0};
    cout<<"Se le mostrara un listado de las publicaciones cientificas segun su titulo: "<<endl;
    for (auto publis:biblioteca.publicaciones){
          cout<<cont<<". "<<publis.titulo<<endl;
          cont++;
    }
    cout<<"Desea ver los datos de alguna? (1=Si , 0=No) ";
    cin>>respuesta;
    cout<<endl;
    if (respuesta==1){
        cout<<"Introduzca el numero de la publicacion: ";
        cin>>num;
        MostrarPublicacion(biblioteca,num);
    }

}

void ListarLibros(biblioteca const& biblioteca){
    int cont{0},respuesta{0},num{0};
    cout<<"Se le mostrara un listado de los libros segun su titulo: "<<endl;
    for (auto libro:biblioteca.libros){
          cout<<cont<<". "<<libro.titulo<<endl;
          cont++;
    }
    cout<<"Desea ver los datos de algun libro? (1=Si , 0=No) ";
    cin>>respuesta;
    cout<<endl;
    if (respuesta==1){
        cout<<"Introduzca el numero del libro: ";
        cin>>num;
        MostrarLibro(biblioteca,num);
    }


}

int main(){
            biblioteca biblioteca;
            biblioteca=LeerInfoTxt();
            int opcion=0;
            libro introlibro;
            publicacion intropubli;

            do {
            opcion=menu();
            std::cin.ignore();

            switch (opcion){

            case 1 :                                                                    //INTRODUCIR FUNCIONA CORRECTAMENTE
                switch (menuIntroducir()){

                    case 1:

                            introlibro=IntroducirLibro();
                            biblioteca.libros.push_back(introlibro);

                    break;
                    case 2:

                            intropubli=IntroducirPublicacion();
                            biblioteca.publicaciones.push_back(intropubli);

                    break;
                    case 3:

                    break;
                    default :
                    cout<<"Seleccione una opcion valida"<<endl;
                    break;
                     }


            break;

            case 2:                                                                    //BUSCAR LIBRO

                    switch (menuBuscar()){

                        case 1:                                                       //BUSCAR POR TITULO

                        BuscarLibroTitulo(biblioteca);

                        break;
                        case 2:                                                     //BUSCAR POR AUTOR

                        BuscarLibroAutor(biblioteca);

                        break;
                        case 3:

                        break;
                        default :
                        cout<<"Seleccione una opcion valida"<<endl;
                        break;
                         }

            break;

            case 3 :                                                               //BUSCAR PUBLICACION
                switch (menuBuscar()){

                    case 1:                                                       //BUSCAR POR TITULO

                    BuscarPublicacionTitulo(biblioteca);

                     break;
                    case 2:                                                     //BUSCAR POR AUTOR

                     BuscarPublicacionAutor(biblioteca);

                     break;
                    case 3:

                    break;
                    default :
                    cout<<"Seleccione una opcion valida"<<endl;
                    break;
                     }


            break;

            case 4:

                    ListarLibros(biblioteca);

            break;

            case 5 :

                    ListarPublicaciones(biblioteca);

            break;

            case 6:

            cout<<"Apagando..."<<endl;

            break;

            default :
            cout<<"Seleccione una opción valida"<<endl;
            break;
            }

            }
            while (opcion!=6);

        return 0;
    }
