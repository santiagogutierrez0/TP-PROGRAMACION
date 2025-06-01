#include<stdio.h>
#include <stdbool.h>
#define INTENTOS 3

bool verificarClave(int num, int num2);
int main()
{
    int claveUsuario=1000, claveCajero; 
    int menu, opcionMenu;
    int saldo=15800;
    int opcion;

    printf("Ingrese su clave numerica de 4 digitos:\n");
    scanf("%d", &claveCajero);

    if (verificarClave(claveUsuario, claveCajero)){

        do
        {
            printf("1 - Sacar dinero\n2 - Depositar dinero\n3 - Consultar saldo\n4 - Cambiar clave\n5 - Salir");
            scanf("%d", &opcionMenu);

        } while (menu>5 || menu<1);

        switch (opcionMenu)
        {
        case 1:
            printf("Cuanto dinero desea retirar:\n");
            scanf("%d", &opcion);

            if (opcion>saldo)
            {
                do
                {
                    printf("ERROR.\nIngrese nuevamente la cantidad de dinero que desea retirar:\n");
                    scanf("%d", &opcion);
                } while (opcion<=saldo);
                
            }
            else{
                saldo=saldo-opcion;
            }
            
            break;

        case 2:

            //AGREGAR FUNCION PARA VERIFICAR POSITIVO
            printf("Ingrese la cantidad de dinero a depositar:\n");
            scanf("%d", &opcion);
            
            saldo=saldo+opcion;

            break;

        case 3:
                

            break;
        
        case 4:
            

            break;
        default:
            break;
        }
        
    }




    
    return 0;
}

bool verificarClave(int num, int num2){
    int cont=0;
    if (num2!=num)
    {
        do
        {
            printf("CLAVE INCORRECTA.\n Ingrese su clave numerica de 4 digitos:\n");
            scanf("%d", &num2);
            cont++;
        } while (num2!=num && cont<=INTENTOS);
        
    }
    
    return cont<=INTENTOS;
    
    
}
