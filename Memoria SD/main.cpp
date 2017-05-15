#include "mbed.h"
#include "SDFileSystem.h"

//localFileSystem local("Andrea");
 
//SDFileSystem sd( PTD2, PTD3, PTD1, PTD0, "SD"); //mosi, miso clk, cs
SDFileSystem sd( D11, D12, D13, D10, "SD"); //mosi, miso clk, cs
char arr[160];
char i;
int main() {
    printf("Escribiendo en memoria SD...\n\r");   

    FILE *fp = fopen("/SD/sd.txt", "w+");
    
    if(fp == NULL) {
        error("No se pudo abrir el archivo para escritura\n\r");
    }
    fprintf(fp, "Sinsel es mi pastor, nada me faltara\n\r");
    fclose(fp); 
    printf("Archivo Escrito Exitosamente\n\r");
    fp = fopen("/SD/sd.txt", "r");
    fgets(arr,160,fp);
    printf("Leyendo Archivo...\n\r");
    printf(arr);
    fclose(fp);
    printf("Programa terminado..\n\r");    
}
