#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


int parser_EmployeeFromText(FILE* pArchivo, LinkedList* pEmpleadosLista)
{
    Employee* pEmpleados;

    char idAux[20];
    char nombreAux[50];
    char horasTrabajadasAux[20];
    char sueldoAux[30];

    int ret = 1;
    int flag = 0;

    if(pArchivo != NULL)
    {
        while(!feof(pArchivo))
        {
            if(flag)
            {
                fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
                flag = 1;
            }

            fscanf(pArchivo, "%[^,], %[^,], %[^,], %[^\n]\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
            printf("%s - %s - %s - %s\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
            pEmpleados = new_Employee_Parametros(idAux, nombreAux, horasTrabajadasAux, sueldoAux);

            if(pEmpleados != NULL)
            {
                ll_add(pEmpleadosLista, pEmpleados);
                ret = 0;
            }
        }
    }
    return ret;
}



int parser_EmployeeFromBinary(FILE* pArchivo, LinkedList* pEmpleadoLista)
{
    Employee* pEmpleado;
    int ret = 1;

    if(pArchivo != NULL)
    {
        while(!feof(pArchivo))
        {
            pEmpleado = new_Employee();
            fread(pEmpleado,sizeof(Employee),1,pArchivo);
            ll_add(pEmpleadoLista,pEmpleado);
        }
        ret = 0;
    }
    return ret;
}
