#include<stdio.h>
#include<stdbool.h>
#define INTENTOS 3

bool verificarClave(int clave, int usuario);
int sacarDinero(int saldo);
int depositarDinero(int saldo);
void consultarSaldo(int saldo, int saldoCorriente);
int cambiarClave(int clave);
void mostrarMenu();

int main()
{
    int claveCorrecta=1000, claveIngresada; 
    int saldoCajaAhorro=15000, saldoCuentaCorriente=20000;
    int opcion, cuenta;

    printf("Ingrese su clave numerica de 4 digitos:\n");
    scanf("%d", &claveIngresada);

    if (!verificarClave(claveCorrecta, claveIngresada)){
        printf("Clave incorrecta. Dirijase a su banco emisor");
    }
    else{

            mostrarMenu();
            scanf("%d", &opcion);

            while (opcion < 1 || opcion > 5)
            {
                printf("Opcion invalida. Ingrese un numero entre 1 y 5: ");
                scanf("%d", &opcion);
            }
        
        }

        while (opcion!=5)
        {
            switch (opcion) {
                    case 1:
                        printf("Seleccione cuenta para extraer: 1-Caja de Ahorro, 2-Cuenta Corriente: ");
                        scanf("%d", &cuenta);
                        while (cuenta != 1 && cuenta != 2) {
                            printf("Opcion invalida. Ingrese 1 o 2: ");
                            scanf("%d", &cuenta);
                        }
                        if (cuenta == 1){

                            saldoCajaAhorro = sacarDinero(saldoCajaAhorro);
                        }
                        else{

                            saldoCuentaCorriente = sacarDinero(saldoCuentaCorriente);
                        }
                        break;
                        
                    case 2:
                        printf("Seleccione cuenta para depositar: 1-Caja de Ahorro, 2-Cuenta Corriente: ");
                        scanf("%d", &cuenta);
                        while (cuenta != 1 && cuenta != 2) {
                            printf("Opcion invalida. Ingrese 1 o 2: ");
                            scanf("%d", &cuenta);
                        }
                        if (cuenta == 1)
                            saldoCajaAhorro = depositarDinero(saldoCajaAhorro);
                        else{

                            saldoCuentaCorriente = depositarDinero(saldoCuentaCorriente);
                        }
                        break;
                    case 3:
                        consultarSaldo(saldoCajaAhorro, saldoCuentaCorriente);
                        break;
                    case 4:
                        claveCorrecta = cambiarClave(claveCorrecta);
                        break;
                    case 5:
                        printf("Gracias por usar el cajero. Hasta luego!\n");
                        break;

                }
                mostrarMenu();
                scanf("%d", &opcion);
                while (opcion < 1 || opcion > 5) {
                printf("Opcion invalida. Ingrese un numero entre 1 y 5: ");
                scanf("%d", &opcion);
                }
        }
        
    return 0;
}

bool verificarClave(int clave, int usuario){
    int cont=1;
    while (usuario!=clave && cont<INTENTOS)
    {
        printf("Clave Incorrecta.\nIngrese su clave correctamente:\n");
        scanf("%d", &usuario);
        cont++;
    }
    
    if (usuario!=clave){
        return false;
    }
    else{
        return true;
    }

}


int sacarDinero(int saldo){

    int monto;

    printf("Cuanto dinero desea retirar:\n");
    scanf("%d", &monto);

    while (monto <= 0) {
        printf("Monto invalido. Ingrese un monto positivo:\n");
        scanf("%d", &monto);
    }

    if (monto>saldo)
    {
        printf("Saldo insuficiente. Intente otra vez:\n");
    }
    else{
        saldo-=monto;
        printf("Operacion exitosa. Saldo actual: $%d\n", saldo);
    }
    return saldo;
}

int depositarDinero(int saldo){
    int monto;

    printf("Cuanto dinero desea depositar:\n");
    scanf("%d", &monto);

    while (monto <= 0) {
        printf("Monto invalido. Ingrese un monto positivo:\n");
        scanf("%d", &monto);
    }

    saldo+=monto;

    printf("Deposito exitoso. Saldo actual: $%d\n", saldo);

    return saldo;

}

void consultarSaldo(int saldo, int saldoCorriente){
    int opcion;
    printf("Elija una opcion para consultar el saldo de sus cuentas:\n1 - Caja de Ahorro\n2 - Cuenta Corriente\n");
        scanf("%d", &opcion);
    while (opcion < 1 || opcion > 2) {
        printf("Opcion invalida. Ingrese 1 o 2:\n");
        scanf("%d", &opcion);
    }

    if (opcion == 1) {
        printf("Su saldo de Caja de Ahorro es: $%d\n", saldo);
    } else {
        printf("Su saldo de Cuenta Corriente es: $%d\n", saldoCorriente);
    }
    
}

int cambiarClave(int clave){
    int claveCorrecta, claveNueva;

    printf("ingrese la clave actual:\n");
    scanf("%d", &claveCorrecta);

    while (claveCorrecta != clave) {
        printf("Clave incorrecta. Vuelva a ingresar la clave actual:\n");
        scanf("%d", &claveCorrecta);
    }
    

    printf("Ingrese su nueva clave:\n");
    scanf("%d", &claveNueva);


    while (claveNueva == clave) {
        printf("Ingrese una clave diferente a la actual:\n");
        scanf("%d", &claveNueva);
    }
    
    printf("Su clave fue cambiada exitosamente.\n");

    return claveNueva;
    
}

void mostrarMenu(){
    printf("\nSeleccione una opcion:\n");
    printf("1 - Sacar Dinero\n");
    printf("2 - Depositar Dinero\n");
    printf("3 - Consultar Saldo\n");
    printf("4 - Cambiar la Clave\n");
    printf("5 - Salir\n");
}
