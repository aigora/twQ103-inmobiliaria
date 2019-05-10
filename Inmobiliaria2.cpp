#include <stdlib.h>
#include <stdio.h>

int main()
{

	int opcion,banos, propiedad,habitacion,amueblado,garaje,zona,precio,si,no;
	float metros;
	printf("Bienvenidos a la wInmobiliariaeb de la  ECA\n");
	printf("Seleccione la opcion 1 si desea comprar y la opcion 2 si desea aquilar\n");
	
	scanf("%i",&opcion);
	
	if(opcion==1)
	
	    printf("Ha seleccionado la opcion de comprar\n");
	
	else if(opcion==2)
	   
	    printf ("has seleccionado la opcion de alquilar");
	   
	else    
	    printf("Opcion no valida\n");
	    
	do
	{
		printf("Seleccione ahora el tipo de propiedad 1-Piso 2-Casa 3-Local\n");
		
		scanf("%i",&propiedad);
          
    }
    while(propiedad!=1 && propiedad!=2);
    
	switch (propiedad)
	{
		case 1:
			printf("Ha seleccionado piso\n");
		
			break;
		case 2:
			printf("Ha seleccionado casa\n");
		
			break;
		case 3:
			printf("Ha seleccionado local\n");
			
			break;
	}

    do
    {
    	printf("numero de baños que desee\n");
    	scanf("%d",&banos);
    	
    	printf("numero de habitaciones que desee\n");
    	scanf("%d",&habitacion);
    	printf("numero de metros cuadrados\n");
    	scanf("%d",&metros);
    
    	printf("¿lo desea amueblado? pulse 1 si lo quiere amueblado, sino puelse 0\n");
    	amueblado=(si||no)?1:0;
    	scanf("%d",&amueblado);
    	
    	printf("¿quiere garaje?si lo desea pulse 1 y sino pulse 0\n");
    	garaje=(si||no)?1:0;
    	scanf("%d",&garaje);
    	
    	printf("zona: 1-centro, 2-norte,3-este,4-oeste\n");
    	 scanf("%d",&zona);
    
    
    	  switch (zona)
    	  {
    	  	case 1:
    	  		printf("has seleccionado centro\n");
    	  		break;
    	  	case 2:
    	  		printf("has seleccionado norte\n ");
    	  		break;
    	  	case 3:
    	  		printf("has seleccionado este\n");
    	  		break;
    	    case 4:
    	    	printf("has seleccionado oeste");
    	    	break;
    	    	
		  }

		
		
		 do
		 {
		 printf("introduzca precio maximo:");
		 scanf("%d",&precio);
	    }
		while (precio<=400);
		 system("clear");
	}
	while(propiedad!=1 && propiedad!=2 && propiedad!=3);
    	
    	printf("estamos buscando tu piso ideal\n");
	


return 0;

}
