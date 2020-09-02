
# include <stdio.h>
#include<math.h>
# define A 10
int a,b;

void intro(int matriz[][A]);
void simetrica(int matriz[][A],int *aux);
void positiva(int matriz[][A],int *pro);
void descom(int matriz[][A],float ml[][A],float ml2 [][A],int pro,int aux);


int main(){
	int aux,pro;
	int matriz[A][A];
    float ml[A][A];
    float ml2[A][A];
    
intro(matriz);
simetrica(matriz,&aux);
positiva(matriz,&pro);
 descom(matriz,ml,ml2,pro,aux);
 
	return 0;
	
		
}
// funcion descomposicion
void descom(int matriz[][A],float ml[][A],float ml2[][A],int pro, int aux){
	
	if(pro>0 && aux==pow(a,2)){
	int i,j;
	
		for(i=0;i<a;i++)
	{
		for(j=0;j<a;j++){
			
			if(i==j){//para los valores  de la diagonal principal
			float suma;int k;
			suma=0;
				if(i>0){
				
		    	for(k=0;k<i;k++){//j se matendra fijo mientras termina el ciclo y K sera la que esta cambiando en pasos de 1
		    	suma+= pow(ml[i][k],2);}
		    	ml[i][j]=sqrt(matriz[i][j]-suma);}
		
			    else {
		    	ml[i][j]=sqrt(matriz[i][j]);} }
		    	
		// para los valores de la diagonal inferior
			if (i>j){
				float suma2;int k;
		        	suma2=0;
			      if(j>0){
				  for (k=0;k<j;k++){
					
		      	suma2+=ml[j][k]*(ml[i][k]);}
		     	ml[i][j]=(matriz[i][j] -suma2)/(ml[j][j]);}
			
		      	else{
			ml[i][j]=matriz[i][j]/(ml[j][j]);	}//para los valores de la primera columna de coheficientes distintos
		}
		      	
		// para la diagonal superior	
			if(i<j) {
			ml[i][j]=0;}
			}
	}
			
	// inpresion matriz l	
	 printf("la matriz l es:\n");
    for(i=0;i<a ;i++){
       for(j=0;j<a ;j++) {
	        printf("%.5f ",ml[i][j]);
        }
        printf("\n");}
        
        for(i=0;i<a ;i++){
       for(j=0;j<a ;j++) {
	        ml2[j][i]=ml[i][j];
       
		
			}} printf("\n");
			 printf("la matriz l^t es:");
			  printf("\n");
			
			for(i=0;i<a ;i++){
       for(j=0;j<a ;j++) {
	        printf("%.5f ",ml2[i][j]);
        }
        printf("\n");}
		
			}
        
        else { printf("error no cumple las condiciones anteriores");}
		
    }
   

// funcion si la matriz es simetrica

void simetrica(int matriz[][A],int *aux){
	int i,j ;
	
	*aux=0;
	for(i=0;i<a  ;i++){
       for(j=0;j<a ;j++) {
       	
	  if (matriz[j][i] == matriz[i][j]){
	  *aux+=1;
		   }
        }
       	
   }  printf("\n");
		
		   if(*aux==pow(a,2)){       	
	        printf("la matriz  es simetrica");}
	        
	        else{
			 printf("la matriz no  es simetrica");}
			 printf("\n");
			 
	
}
// matriz positiva
void positiva(int matriz[][A],int *pro){
	int i,j ;
	
	*pro=1;
	for(i=0;i<a  ;i++){
       for(j=0;j<a ;j++) {
       	
	  if (i==j){
	  *pro*=matriz[i][j];
		   }
        }
       	
   }  printf("\n");
		
		   if(*pro>0){       	
	        printf("la matriz  es definida positiva");}
	        
	        else{
			 printf("la matriz no  es definida positiva");}
			 printf("\n");
			 
	
}


//entrada de datos a la matriz
void intro(int matriz[][A]) {
		
	printf("introdusca el numero de filas ");
	scanf("%i",&a);
	
	
	int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<a;j++){
			printf("ingrese el numero con posicion: [%i][%i] ",i+1,j+1);
			scanf ("%i",&matriz[i][j]);
		}
	} 
    for(i=0;i<a ;i++){
       for(j=0;j<a ;j++) {
	        printf("%i ",matriz[i][j]);
        }
        printf("\n");	
   }

	
}
	

	
