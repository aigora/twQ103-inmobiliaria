#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Piso
{
    char uso[20], tipoP[20], zona[20];
    int banos, habit, amue, metros, garaje;
	int precio;
};
struct Piso encontrados[20];
int totalEncontrados = 0;

void buscarpiso(struct Piso buscado) {
    FILE *prop;
    prop = fopen("Propiedades.txt", "r");
    struct Piso piso;
    char headers[20];

    if (prop == NULL) {
        printf("Error \n");
        exit(1);
    }

    fscanf(prop, "%s %s %s %s %s %s %s %s %s", headers, headers, headers, headers, headers, headers, headers, headers, headers);

    while (!feof(prop)) {
        fscanf(prop, "%s %s %d %d %d %d %d %s %d", piso.uso, piso.tipoP, &piso.banos, &piso.habit, &piso.amue, &piso.metros, &piso.garaje, piso.zona, &piso.precio);

        if (
            strcmp(piso.uso, buscado.uso) == 0 && strcmp(piso.tipoP, buscado.tipoP) == 0 && piso.banos == buscado.banos &&
            piso.habit == buscado.habit && piso.amue == buscado.amue && piso.garaje == buscado.garaje &&
            strcmp(piso.zona, buscado.zona) == 0 && piso.precio <= buscado.precio
        ) {
            encontrados[totalEncontrados] = piso;
            totalEncontrados++;
        }
    }
};

int main()
{
    enum TipoPiso {Piso, Casa, Local};
    enum TipoUso {Venta, Alquiler};
    enum Zona {Norte, Sur, Centro, Este, Oeste};
    
    struct Piso buscado;    

    int idUso;
    int idTipoP;
    int idZona;
    
    printf("Bienvenidos a la wInmobiliariaeb de la  ECA \n");

    printf("Seleccione la opcion 1 si desea comprar y la opcion 2 si desea aquilar \n");
    scanf("%d", &idUso);
    
    switch (idUso) {
        case 1:
            strcpy(buscado.uso, "venta");
            printf("Ha seleccionado la opcion de comprar \n");
            break;
        case 2:
            strcpy(buscado.uso, "alqu");
            printf("Ha seleccionado la opcion de alquilar \n");
            break;
        default:
            printf("Opcion no valida \n");
            exit(1);
            break;
    }
        
    printf("Seleccione ahora el tipo de propiedad 1-Piso 2-Casa 3-Local \n");
    scanf("%d", &idTipoP);
    
    switch (idTipoP) {
        case 1:
            strcpy(buscado.tipoP, "piso");
            printf("Ha seleccionado piso \n");
            break;
        case 2:
            strcpy(buscado.tipoP, "casa");
            printf("Ha seleccionado casa \n");
            break;
        case 3:
            strcpy(buscado.tipoP, "local");
            printf("Ha seleccionado local \n");
            break;
        default:
            printf("Opcion no valida \n");
            exit(1);
            break;
    }

    printf("numero de banos que desee \n");
    scanf("%d", &buscado.banos);
    
    printf("numero de habitaciones que desee \n");
    scanf("%d", &buscado.habit);
    
    printf("lo desea amueblado? pulse 1 si lo quiere amueblado, sino pulse 0 \n");
    scanf("%d", &buscado.amue);
    
    printf("numero de metros cuadrados \n");
    scanf("%d", &buscado.metros);

    printf("quiere garaje? si lo desea pulse 1 y si no pulse 0 \n");
    scanf("%d", &buscado.garaje);
    
    printf("zona: 1-centro, 2-norte, 3-este, 4-oeste \n");
    scanf("%d", &idZona);

    switch (idZona) {
        case 1:
            strcpy(buscado.zona, "centro");
            printf("has seleccionado centro \n");
            break;
        case 2:
            strcpy(buscado.zona, "norte");
            printf("has seleccionado norte \n");
            break;
        case 3:
            strcpy(buscado.zona, "este");
            printf("has seleccionado este \n");
            break;
        case 4:
            strcpy(buscado.zona, "oeste");
            printf("has seleccionado oeste \n");
            break;
        default:
            printf("Opcion no valida \n");
            exit(1);
            break;
    }
    
    printf("introduzca precio maximo \n");
    scanf("%d", &buscado.precio);
        

    buscarpiso(buscado);

    if (totalEncontrados == 0) {
        printf("\nNo se encontro ningun piso \n");
    } else {
        printf("\nSe encontraron los siguientes pisos: \n");
        int i;
        for (i = 0; i < totalEncontrados; i++) 
		{
            printf("%s en %s con %d banos, %d habitaciones, de %d metros en la zona %s. ", 
                encontrados[i].tipoP, encontrados[i].uso, encontrados[i].banos,
                encontrados[i].habit, encontrados[i].metros, encontrados[i].zona
            );
            if (encontrados[i].amue == 1) {
                printf("Amueblado ");
            }
            if (encontrados[i].garaje == 1) {
                printf("con garaje ");
            }
            printf("a un precio de %d\n", encontrados[i].precio);
        }
    }

    return 0;
}
