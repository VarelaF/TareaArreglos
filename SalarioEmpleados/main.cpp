#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <string>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	int cedula=0;
	int Cod_empleado=0;
	string nombreEmpleado[3];
	float SalarioBruto=0;
	float SalarioNeto=0;
	float Salario_x_Hora=0;
	float SalarioOrdinario=0;
	float HorasLaboradas=0;
	float AumentoSalarial=0;
	float PorcDeduccionCCSS=0;
	float PrecioXhora=0;
	float DeduccionCCSS=9.17;
	
	int Cod_Operario=1;
	int Cod_Tecnico=2;
	int Cod_Profesional=3;
	
	int CantOperarios=0;
	int CantTecnicos=0;
	int CantProfesionales=0;
	
	float TotalSal_Operarios=0;
	float TotalSal_Tecnicos=0;
	float TotalSal_Profesionales=0;
	
	float PromSal_Operarios=0;
	float PromSal_Tecnicos=0;
	float PromSal_Profesionales=0;
	int contador=0;
	int op;
		do{
			
			system("cls");
			printf("\n==========================================");
			printf("\nSISTEMA DE CALCULO DE AUMENTOS SALARIALES\n", Cod_Operario);
			printf("==========================================\n\n\n\n");
			
			printf("-Opcion 1: Calcular salario\n");
			printf("-Opcion 2: Salir\n");
			printf("\nDigite una opcion: ");
			scanf("%i",&op);
			
			if(op==1)
			{
				printf("\n\nDigite su cedula: ");
				scanf("%i",&cedula);
				fflush(stdin);			
				printf("\nDigite su Nombre: ");
				getline(cin,nombreEmpleado[contador]);//lee una linea completa y lo guarda en el vector de string
				
				fflush(stdin);
				printf("\nDigite el tipo de empleado: ");
				scanf("%i",&Cod_empleado);
				fflush(stdin);
				printf("\nCantidad de horas laboradas: ");scanf("%f",&HorasLaboradas);fflush(stdin);
				printf("\nPrecio_x_hora: ");scanf("%f",&Salario_x_Hora);fflush(stdin);
								
			//-------------------calculo del salario-----------------------------------------
			
				SalarioOrdinario = Salario_x_Hora*HorasLaboradas;
				
				if(Cod_empleado==Cod_Operario)
				{
					AumentoSalarial=(SalarioOrdinario*15)/100;
					CantOperarios+=1;
				}
				else if(Cod_empleado==Cod_Tecnico)
				{
					AumentoSalarial=(SalarioOrdinario*10)/100;
					CantTecnicos+=1;
				}
				else if(Cod_empleado==Cod_Profesional)
				{
					AumentoSalarial=(SalarioOrdinario*5)/100;
					CantProfesionales+=1;
				}
			
			SalarioBruto=SalarioOrdinario+AumentoSalarial;
			PorcDeduccionCCSS=(SalarioBruto*DeduccionCCSS)/100;
			SalarioNeto=SalarioBruto-PorcDeduccionCCSS;
			
				if(Cod_empleado==Cod_Operario)
				{					
					TotalSal_Operarios+=SalarioNeto;
				}
				else if(Cod_empleado==Cod_Tecnico)
				{					
					TotalSal_Tecnicos+=SalarioNeto;
				}
				else if(Cod_empleado==Cod_Profesional)
				{
					TotalSal_Profesionales+=SalarioNeto;					
				}
			//-------------------------------------------------------------------------------
				system("cls");
				printf("\n\n +++++++++++++++++++++++++++++++++++++++++++");
				printf("\n\tDatos del trabajador\n");
				printf(" +++++++++++++++++++++++++++++++++++++++++++");
				printf("\n\tCédula: %i", cedula);
				printf("\n\tNombre: ");
				cout<<nombreEmpleado[contador];// muestra el nombre que contiene el vector
				printf("\n\tTipo de empleado: %i", Cod_empleado);
				printf("\n\tSalario por hora: %.2f", Salario_x_Hora);
				printf("\n\tCantidad de horas: %.2f", HorasLaboradas);
				printf("\n\tSalario Ordinario: %.2f", SalarioOrdinario);
				printf("\n\tAumento: %.2f", AumentoSalarial);
				printf("\n\tSalario bruto: %.2f", SalarioBruto);
				printf("\n\tDeducción CCSS 9.17%: %.2f", PorcDeduccionCCSS);
				printf("\n\tSalario Neto: %.2f", SalarioNeto);
				printf("\n\n+++++++++++++++++++++++++++++++++++++++++++");
				

				PromSal_Operarios=TotalSal_Operarios/CantOperarios;
				PromSal_Tecnicos=TotalSal_Tecnicos/CantTecnicos;
				PromSal_Profesionales=TotalSal_Profesionales/CantProfesionales;
				contador++;
			
			}
			else if(op==2)
			{
				system("cls");
				printf("\n________________________________________________________");
				printf("\n\tEstadísticas de los trabajadores");
				printf("\n________________________________________________________");
				printf("\n\n\t  Cantidad  \tAcumulado Salario\tPromedio\n");
				printf("\nOperarios:\t%i\t\t%.2f \t%.2f ",CantOperarios,TotalSal_Operarios,PromSal_Operarios);
				printf("\nTecnicos:\t%i\t\t%.2f \t%.2f ",CantTecnicos,TotalSal_Tecnicos,PromSal_Tecnicos);
				printf("\nProfesionales:\t%i\t\t%.2f \t%.2f ",CantProfesionales,TotalSal_Profesionales,PromSal_Profesionales);
				printf("\n\n__________________________________________________________");
				printf("\n\n\t  Empleados:\n");
			int LongVector=0;
			LongVector=(sizeof(nombreEmpleado), sizeof(nombreEmpleado[0]));// muestra el vector de nombres al final los cuales son ingresados
			for(int i=0;i<LongVector;i++ ){					
				if(nombreEmpleado[i]!="")
				{		
					cout<<"\n - ";			
					cout<<nombreEmpleado[i];
					
				}					
			}
			//	break;
			}
			
			else
			{
				printf("\nOpcion no valida");
			}
			
		getch();	
		}while((op !=2));
		
		
		getch();
	

	return 0;
}
