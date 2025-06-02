#include<stdio.h>
#include<stdbool.h>
#define INTENTOS 3

int mostrarMenu(int saldo, int saldoCorriente, int clave);
bool verificarClave(int clave, int usuario);
int sacarDinero(int saldo);
int depositarDinero(int saldo);
void consultarSaldo(int saldo, int saldoCorriente);
int cambiarClave(int clave);
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
        mostrarMenu(saldoCajaAhorro, saldoCuentaCorriente, claveCorrecta);
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
    
    if (cont>=INTENTOS && usuario!=clave){
        return false;
    }
    else{
        return true;
    }

}

int mostrarMenu(int saldo, int saldoCorriente, int clave){
    int opcion;

    do
    {
        printf("1 - Sacar Dinero\n2 - Depositar Dinero\n3 - Consultar Saldo\n4 - Cambiar la Clave\n5 - Salir\n");
        scanf("%d", &opcion);

        if(opcion<1 || opcion>5){
            printf("Ingrese un numero entre 1 - 5\n");
            scanf("%d", &opcion);
        }

        switch (opcion)
        {
        case 1:
            saldo=sacarDinero(saldo);
            break;

        case 2:
            saldo=depositarDinero(saldo);
            break;
        case 3:
            consultarSaldo(saldo, saldoCorriente);
            break;
        case 4:
            clave=cambiarClave(clave);
            break;

        case 5:
            break;
        
        default:
            break;
        }
    } while (opcion!=5);

    return saldo;

}

int sacarDinero(int saldo){

    int monto;

    printf("Cuanto dinero desea retirar:\n");
    scanf("%d", &monto);

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

    saldo+=monto;

    return saldo;

}

void consultarSaldo(int saldo, int saldoCorriente){
    int opcion;
    do
    {
        printf("Elija una opcion para consultar el saldo de sus cuentas:\n1 - Caja de Ahorro\n2 - Cuenta Corriente\n");
        scanf("%d", &opcion);
    } while (opcion<1 || opcion>2);

    switch (opcion)
    {
    case 1:
        printf("Su saldo es de: $%d\n", saldo);
        break;
    case 2:
        printf("Su saldo es de: $%d\n", saldoCorriente);
        break;
    
    default:
        break;
    }
    
}

int cambiarClave(int clave){
    int claveNueva;

    printf("ingrese la clave actual:\n");
    scanf("%d", &claveNueva);

    do
    {
        printf("Clave incorrecta. Vuelva a ingresar la clave:\n");
        scanf("%d", &claveNueva);
    } while (claveNueva!=clave);

    printf("Ingrese su nueva clave:\n");
    scanf("%d", &claveNueva);

    do
    {
        printf("Ingrese una clave diferente a la actual:\n");
        scanf("%d", &claveNueva);
    } while (claveNueva==clave);
    
    printf("Su clave fue cambiada exitosamente.\n");

    return claveNueva;
    
}
