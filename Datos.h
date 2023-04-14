#ifndef DATOS_H
#define DATOS_H
#include <vector>
#include <iostream>

using namespace std;

class Datos {
    vector <string> Sitios;
    vector <string> Plantillas; 
    vector <string> Imagenes_Menu;   
      
    public:
        Datos(){    
            Sitios.push_back("Sport site,12,4,5,C");
            Sitios.push_back("Server General,18,2,3,C");
            Sitios.push_back("Funauta,10,2,2,P,Fundacion del nino");
            Sitios.push_back("Tachira Center,18,4,3,C");
            //---------------------------
            Plantillas.push_back("Mambo-1024800");
            Plantillas.push_back("Fiesta-615056");
            Plantillas.push_back("Goolan-820352");
            //---------------------------
            Imagenes_Menu.push_back("4#c:\xampp\htdocs\sport#15#imagen1.jpg#100#250");
            Imagenes_Menu.push_back("3#c:\xampp\htdocs\sport#20#imagen8.jpg#300#150");
            Imagenes_Menu.push_back("2#c:\xampp\htdocs\sport#6#logo.jpg#1#1");
            Imagenes_Menu.push_back("1#c:\xampp\htdocs\sport#10#imagen2.jpg#70#20");
            Imagenes_Menu.push_back("5#Exit#4");
            Imagenes_Menu.push_back("4#About us#1");
            Imagenes_Menu.push_back("3#Products#1");
            Imagenes_Menu.push_back("2#News#3");
            Imagenes_Menu.push_back("1#Home#3");
            Imagenes_Menu.push_back("6#c:\xampp\htdocs\sergen#10#img01.jpg#110#270");
            Imagenes_Menu.push_back("5#c:\xampp\htdocs\sergen#30#img05.png#25#50");
            Imagenes_Menu.push_back("8#Salir");
            Imagenes_Menu.push_back("7#Servicios");
            Imagenes_Menu.push_back("6#Inicio");
            Imagenes_Menu.push_back("8#c:\xampp\htdocs\funauta#30#fun01.gif#100#300");
            Imagenes_Menu.push_back("7#c:\xampp\htdocs\funauta#400#fun02.gif#180#230");
            Imagenes_Menu.push_back("10#Registrar Me");
            Imagenes_Menu.push_back("9#Inicio");
            Imagenes_Menu.push_back("12#c:\xampp\htdocs\taccen#19#1tc.gif#20#20");
            Imagenes_Menu.push_back("11#c:\xampp\htdocs\taccen#20#2tc.gif#500#700");
            Imagenes_Menu.push_back("10#c:\xampp\htdocs\taccen#21#3tc.gif#260#120");
            Imagenes_Menu.push_back("9#c:\xampp\htdocs\taccen#22#4tc.gif#522#80");
            Imagenes_Menu.push_back("13#Mis Ordenes");
            Imagenes_Menu.push_back("12#Registrarme");
            Imagenes_Menu.push_back("11#Inicio");                        
        } 
        
        char * getSitio(int n){
            return (char *)Sitios[n].c_str();
        } 
        int getCantSitios(){ 
            return Sitios.size(); 
        }
        
        char * getPlantilla(int n){
            return (char *)Plantillas[n].c_str();
        } 
        int getCantPlantillas(){ 
            return Plantillas.size(); 
        }
        
        char * getImagenesMenu(int n){
            return (char *)Imagenes_Menu[n].c_str();
        } 
        int getCantImagenesMenu(){ 
            return Imagenes_Menu.size(); 
        }    
      
};
#endif
