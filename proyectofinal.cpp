#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
using namespace std;

using std::left;
using std::right;
	//estructura para los datos 
	struct Prestamo
	{	
		int id;
		char nombre[30];	
		int valor_prestamo;
		int saldo;
		int ultimo_abono;
		int registro;
		char fecha_prestamo[35];
		char fecha_entrega[35];
	}prestamo, *puntero_prestamo = &prestamo;

//prototipos de funciones
void mostrarprestamo(Prestamo *);
void buscarprestamo();
//prototipos
void menu();
void prestamos();
void nuevo_prestamo();
void prestamos_activos();
void historial();
void crear_usuarios();
	
//variables globales
int encontrado=0,opcionmenu=0,regresarmenu=0,contador=1;//contador la variable para los prestamos guardados en memoria
float efectivo=0,cambio=0, totalpagar=0;
char nombre[50], direccion[50],nit[50];
int comprarotro,ingresarotro,opcion_pres, abono;

//variables globales para fecha....--------------
char cant[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *meses[13]={"","Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
char espacio;
int d,m,a;
char usuario[50],pas[50];

//funcion que busca si el usuario y contraseña coincide
   bool us=false;
   bool entra=false;
int eusuario(char usu[50], char pasw[25], char usuario[50],char pas[50] ){

   if(strcmp(usuario, usu )==0 && strcmp(pas , pasw )==0 ){
   	cout<<"\n\tBIENVENIDO A NUESTRO SISTEMA"<<endl<<endl;
        us=true;
        entra=false;}
        return 0;
}
int usuar(char usu[50], char pasw[25], char usuario[50],char pas[50] ){

   if(strcmp(usuario, usu )==0 && strcmp(pas , pasw )==0 ){
   	cout<<"\n\tBIENVENIDO A NUESTRO SISTEMA"<<endl<<endl;
        //us=true;
        entra=true;}
        return 0;
}
//funcion para mostrar los usuarios
void usuarios(char login2[30],char pasword2[30])
{
	cout<<"USUARIO: "<<login2<<endl;
   cout<<"CONTRASENA: "<<pasword2<<endl<<endl;
}
// funcion fecha que puede ser llamada en cualquier momento
void fecha()
{
   //incio el bucle do-while
   do
   {
   //solicitamos los datos para llenar las variables
   cout<<"\n\t Ingrese la fecha del prestamo : ";
   cin>>d>>espacio>>m>>espacio>>a;

   //si la cantidad del mes de febrero que no la pase solo cuando sea cada 4 años despues del inicio de los años
   if (!(a%4)) cant[2] = 29;
   //de lo contrario que si es asi cada 4 años que tome el valor cantidad como 28
	else cant[2] = 28;
   //que salga del bucle hasta que se cumplan las cantidades que alli tienen

   }while(m<=0 || m>12 || d<=0 || d > cant[m] || a<=0);
   //ofstream fout("Datos_de_prestamos.txt",ios::app);
   cout<<"\n\t Fecha_de_prestamo: "<<d<<" de "<<meses[m]<<" de "<<a<<endl;
   //fout<<"\nFecha_de_prestamo: "<<d<<" de "<<meses[m]<<" de "<<a<<endl;
   if (d+7<=24){
	cout<<"\n\t Fecha_de_entrega___:"<<((d+7)-(cant[m]))<<" de "<<meses[m+1]<<" de "<<a<<endl;
   //fout<<"\nFecha_de_entrega___:"<<((d+7)-(cant[m]))<<" de "<<meses[m+1]<<" de "<<a<<endl;
   }else if(d+7>24){
   cout<<"\n\t Fecha_de_entrega___:"<<((d+7)-(cant[m]))<<" de "<<meses[m+1]<<" de "<<a<<endl;
   //fout<<"\nFecha_de_entrega___:"<<((d+7)-(cant[m]))<<" de "<<meses[m+1]<<" de "<<a<<endl;
   }else{
   cout<<"\n\t Fecha_de_entrega___:"<<d+7<<" de "<<meses[m]<<" de "<<a<<endl;
   //fout<<"\nFecha_de_entrega___:"<<d+7<<" de "<<meses[m]<<" de "<<a<<endl;
	}
	getch();
return ;

}

//funcion principal
int main()
{		
	ret:
system("cls");
system ("Color 5a");
cout<<"\n        ===================================================";
cout<<"\n                 ---REGISTRO Y CONTROL DE PRESTAMOS---";
cout<<"\n 		             ALGORITMOS";
cout<<"\n **--Luis Francisco ramirez === Anahi Montiel--**";
cout<<"\n ....usuario1 = frank     contraseña..= 1234 ";
cout<<"\n       ===================================================="<<endl;

//pedimos que inicie secion
cout<<endl<<"\t Ingrese su nombre de usuario: " ; gets(usuario);
cout<<endl<<"\t Ingrese  contraseña---******: " ; gets(pas);
//abrimos el archivo usuarios
ifstream archivousuario("usuarios.txt", ios::in);
char a[50], b[25];
while(archivousuario >> a >> b) //captura los datos de cada registro del archivo usuario
eusuario(a,b, usuario, pas);//pasamos los valores a la funcion capturados por el while
if(us==false){
	cout<<"ERROR... usuario o contraseña ingresados incorrectamente"<<endl;
   cout<<"INTENTE DE NUEVO";
    getch();
   goto ret ;
}
   archivousuario.close();
   					
	menu();
	//delete [] puntero_prestamo;
		
	return 0;
	
	//puntero_venta = new (puntero_venta) Venta[contadorventas];
}

void prestamos(){
	int optionprestamo;
	
	do{
	
		system("cls");
		cout<<"\n **--.. PRESTAMOS ..---** ";
		cout<<"\n 1.  Nuevo Prestamo ";
		cout<<"\n 2.  Prestamos activos ";
		cout<<"\n 3.  Buscar ";
		cout<<"\n 4.  Salir ";
		cout<<"\n\t Seleccione una opcion "; cin>>optionprestamo;
		switch(optionprestamo){
				case 1:
						nuevo_prestamo();
						break;
				case 2:
						system("cls");
					    mostrarprestamo(puntero_prestamo);
						break;
						
				case 3:
						system("cls");
						buscarprestamo();
						break;
						
		}//cerramos el switch
	
	}while(optionprestamo !=4);
}

//funcion para el menu principal
void menu()
{
	int opcion_menu;
	do {
	system("cls");
	cout<<"\n\t  Bienvenidos a prestamos el mejor "<<endl;
	cout<<"\n\t  1. Ver usuarios--** ";
	cout<<"\n\t  2. Realizar prestamos ";
	cout<<"\n\t  3. Salir ";
	cout<<"\n\n\t Escriba una opcion : ";	cin>>opcion_menu;
	
	switch(opcion_menu){//abrimos el switch del menu principal
		case 1: 
			 
			 crear_usuarios();
			 getch();
			 break;
		case 2: 
			 system("cls");
			 prestamos();
			 getch();
			 break;
		
	}//cerramos el switch del menu principal
	}while(opcion_menu != 3);
}

void nuevo_prestamo()
{		
			int contadorventas=0,totalpagar=0;cambio=0;
		system("cls");			
			int productoencontrado,codigo2;
			cout<<"\t\t\t\t REALIZAR PRESTAMO "<<endl;		
			puntero_prestamo = new (puntero_prestamo) Prestamo[contador];		
		do {	
					cout<<"\n\t Registro numero "<<contador<<endl<<endl;
					(puntero_prestamo+contador)->registro = contador;
					cout<<"\t Ingrese el No. de DPI : "; cin>>(puntero_prestamo+contador)->id; 
					cout<<"\t Ingrese el Nombre : "; 	fflush(stdin); 
						cin.getline((puntero_prestamo+contador)->nombre ,30,'\n'); 					
					cout<<"\t Valor del prestamo : "; cin>>(puntero_prestamo+contador)->valor_prestamo;	
					fecha();	
							
				contador++;
				cout<<"Desea Realizar Otra Compra 1)SI 2)NO: "; cin>>comprarotro;
							
		}while(comprarotro==1);// fin while	

		
}

void buscarprestamo(){
	int buscarregistro,valor_prestamista;
			cout<<"\n\tIngrese el numero de registro a abonar : ";	cin>>buscarregistro;
				for(int c=0; c<contador;c++){
					
					if(buscarregistro==(puntero_prestamo+c)->registro){
					encontrado = 1;
					valor_prestamista = c;
					break;
				}else {
					encontrado =4;
					}
			}
		
			if(encontrado == 1){
							
					
					cout<<left<<setw(10)<<"REGISTRO"<<setw(15)<<"DPI"<<setw(15)<<"Nombre"<<setw(15)<<"Valor_prestamo"<<endl;
					cout<<left<<setw(10)<<(puntero_prestamo+valor_prestamista)->registro<<setw(15)<<(puntero_prestamo+valor_prestamista)->id<<setw(15)<<(puntero_prestamo+valor_prestamista)->nombre<<setw(15)
					<<(puntero_prestamo+valor_prestamista)->valor_prestamo<<endl;
					
					cout<<"\n\n\t AGREGUE LA CANTIDAD A ABONAR ";
					cin>>abono;
					cout<<"\n\n\t El valor anterior es de : "<<(puntero_prestamo+valor_prestamista)->valor_prestamo;
					(puntero_prestamo+valor_prestamista)->valor_prestamo =  (((puntero_prestamo+valor_prestamista)->valor_prestamo) - abono);
					
					cout<<"\n\n\t El valor ahora es de : "<<(puntero_prestamo+valor_prestamista)->valor_prestamo;
					
				}else{
					cout<<"\n El codigo no existe intente mas tarde ";
			}
		getch();
}

void mostrarprestamo(Prestamo *puntero_prestamo)
{
	cout<<"\t\t\t\t Prestamo Realizados"<<endl;
	cout<<left<<setw(10)<<"REGISTRO"<<setw(15)<<"DPI"<<setw(15)<<"Nombre"<<setw(15)<<"Valor_prestamo"<<setw(15)<<"Fecha Prestamo"<<endl;//"Costo"<<endl;
	for(int verprestamo=1; verprestamo<contador; verprestamo++)
	{
		cout<<left<<setw(10)<<(puntero_prestamo+verprestamo)->registro<<setw(15)<<(puntero_prestamo+verprestamo)->id<<setw(15)<<(puntero_prestamo+verprestamo)->nombre<<setw(15)
		<<(puntero_prestamo+verprestamo)->valor_prestamo<<setw(15)<<(puntero_prestamo+verprestamo)->fecha_prestamo<<endl;//<<right<<(puntero_venta+mostrarventas)->costov<<endl;					
	}
	cout<<"----------------------------------------------"<<endl;
	getch();
}

void crear_usuarios(){
	system("cls");
	system("color 5b");
	cout<<"\n        ====================================================";
	cout<<"\n                 ---REGISTRO Y CONTROL DE PRESTAMOS---";
	cout<<"\n 		  **USUARIOS**";
	cout<<"\n       ===================================================="<<endl;
	cout<<"\n\t\n     *********----ELIGA UNA OPCION----********";
   cout<<"\n\t\n    1. REGISTRAR UN NUEVO USUARIO-----****";
   cout<<"\n\t\n    2. VER TODOS LOS USUARIOS------****";
   cout<<"\n\t\n    3. SALIR---------****";
   int op4=0;
   cout<<"\n\n  ESCRIBA UNA OPCION--***: "; cin>>op4;
   switch(op4){
   	case 1:
   	{
   	//pedimos que inicie secion
		cout<<endl<<"Ingrese su nombre de usuario: " ; gets(usuario);
		cout<<endl<<"Ingrese contraseña-------****: " ; gets(pas);
		//abrimos el archivo usuarios
		ifstream archivousuario("usuarios.txt", ios::in);
	char a[50], b[25];
		while(archivousuario >> a >> b) //captura los datos de cada registro del archivo usuario
		usuar(a,b, usuario, pas);//pasamos los valores a la funcion capturados por el while
		if(entra==true){

    //INCIAMOS EL NUEVO REGISTRO DE USUARIO.
    char op45[1];
    ofstream fout("usuarios.txt", ios::app);
    do{
    cout<<"\n INGRESE EL NUEVO USUARIO..:"; cin>>usuario;
    cout<<"\n INGRESE LA NUEVA PASWORD..:"; cin>>pas;
    fout <<endl<< usuario <<' ' << pas<<endl;
    cout<<"\N DESEA INGRESAR OTRO USUARIO S/N : "; cin>>op45[0];
    }while(op45[0]!='n');
    	}else if (entra==false){
    		cout<<"ERROR... usuario o contraseña ingresados incorrectamente"<<endl;
   			cout<<"INTENTE DE NUEVO";
    		getch();
   		exit(0);
  	 }  //cerramos el else del if
  	 archivousuario.close();
   	 break;
   	 }//finalizamos el case 1 de usuarios.......
   	case 2:
   	{ //iniciamos el case 2 de usuarios...
   	ifstream ausus;
   	ausus.open("usuarios.txt", ios::app);
  	 while(ausus >>usuario >>pas)
   	usuarios(usuario,pas);
  	 }  //cerramos el case 2 de usuarios.....
   		break;
  	case 3:
  	{  exit(0); }
  	default :
  {
  	cout<<"\n\n El numero que selecciono no esta en las opciones...";
   }
   }

getch();
}
