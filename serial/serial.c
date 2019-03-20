#include <stdio.h>
#include "omp.h"
#include <time.h>
#include <stdlib.h>
#include<string.h>

#define SIZE 20
#define bufSize 20024
#include <stdio.h>


int main(int argc, char *argv[])
{

  char *fileArray[]={"articles1.csv","articles2.csv","articles3.csv"};
  FILE *fp;



  char ch;
  int h;



  char toSearch[15];
  char line_buf[bufSize] ;
  size_t line_buf_size = 0;
  ssize_t line_size;

  char nombre[20];

  int i, k,j;
  int stringLen, searchLen;
  int count=0;

  int listaid[11];
  int listacount[11];
  char *articulo[11];
  int id;
  int contador=0;
  int aux;
  int auxIndice;
  char *auxArticulo;
  // LEAMOS LA PLABRA                                                                                                                                                                            

  printf("Introduce una palabra: ");
  scanf("%s",toSearch);

  // Open file in read-only mode                         
  for(h=0;h<3;h++){
    fp = fopen(fileArray[h],"r");
    printf("%s",fileArray[h]);
    if ( fp )
      {

	line_size = fgets(line_buf, sizeof(line_buf), fp);


	while ( fgets(line_buf, sizeof(line_buf), fp)!=NULL )
	  {
	    contador++;

	    count=0;

	    line_buf[strlen(line_buf) - 1] = '\0';
	    // printf("%s",line_buf);                                                                                                                                                              

            stringLen = strlen(line_buf);      // length of string                                                                                                                              \
                                                                                                                                                                                                 
            searchLen = strlen(toSearch);


            int o=0;

            for(i=0;i<stringLen;i++){
	      if(line_buf[i]==','){
                for(j=i+1;j<stringLen;j++){
                  if(line_buf[j]==','){j=stringLen;}
                  nombre[o]=line_buf[j];
                  o++;
                }
              }


            }





            //printf("DOCUMENTO ID : %s: \n",nombre);                                                                                                                                            







            for(i=0; i <= stringLen; i++)
	      {


                //     cuando encuentro un H                                                                                                                                                     
		if(line_buf[i]==toSearch[0]){
		  //empieso a recorrer                                                                                                                                                         

		  for(k=0;k<searchLen;k++){

		    if( line_buf[i+k]==toSearch[k]){
		      //      printf("%d --- /%c/ ----- /%c/\n",i,line_buf[i+k],toSearch[k]);                                                                                                 \
                                                                                                                                                                                                 

		      if(k==searchLen-1){



			if(line_buf[i+k+1]==' '|| line_buf[i+k+1]==',' || line_buf[i+k+1]=='.'|| line_buf[i+k+1]=='\n' ){
			  //  printf("\n-------SE ENCONTRO UNA COINCIDENCIA ");                                                                                                                

			  count=count+1;

			  i=i+k;
			  break;
			}
		      }
		      break;

		    }


		  }else{
		    i=i+k;

		    break;
		  }

		}
	      }


	  }
	//       printf("SE ECNONTRARON %d coincidencias \n" , count);                                                                                                                       
                                                                                                                                                                                                \
	memset(line_buf, 0, sizeof(line_buf));

                                                                                                                                                                                                \
	//  ORDENAR Y GUARDAR EN EL ARREGLO -----------------------------------------------------------  
	id=atoi(nombre);                                                                                                                                                                    \
	memset(nombre, 0, sizeof(nombre));

                                                                                                                                                                                                \
	//  printf("SE CONVIRITIO  %d  \n" , id);                                                                                                                                            
	if(contador>11){
	  listaid[10]=id;
	  //      printf("SE CONVIRITIO  %d  \n" , listaid[10]);                                                                                                                              
	  listacount[10]=count;
	  articulo[10]=fileArray[h];
                                                                                                                                                                                                \
	  for (i = 0;i < 11; i++){
                                                                                                                                                                                                \
	    for (j = 0; j< 11; j++){
                                                                                                                                                                                                \
	      if (listacount[j] < listacount[j+1]){ // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor                                                    
                                                                                                                                                                                                \
		aux = listacount[j];
                                                                                                                                                                                                \
		auxIndice=listaid[j];                                                                                                                                                         \
		auxArticulo=articulo[j];
		listacount[j] =listacount[j+1];
                                                                                                                                                                                                \
		listaid[j]=listaid[j+1];
                                                                                                                                                                                                \
		articulo[j]=articulo[j+1];
                                                                                                                                                                                                \
		listacount[j+1] = aux;
                                                                                                                                                                                                \
		listaid[j+1]=auxIndice;
                                                                                                                                                                                                \
		articulo[j+1]=auxArticulo;
                                                                                                                                                                                                \
	      }
                                                                                                                                                                                                \
	    }
                                                                                                                                                                                                \
	  }
	}else{
                                                                                                                                                                                                \
	  for(i=0;i<11;i++){
                                                                                                                                                                                                \
            if(listacount[i]=='\0'){
                                                                                                                                                                                                \
	      listacount[i]=count;
                                                                                                                                                                                                \
	      listaid[i]=id;
                                                                                                                                                                                                \
	      articulo[i]=fileArray[h];
                                                                                                                                                                                                \
	      // printf("SE guardara  %d   \n" , listaid[i]);                                                                                                                                     
                                                                                                                                                                                                \
	      break;                                                                                                                                                                           \
	    }
                                                                                                                                                                                                \
	  }
                                                                                                                                                                                                \
	}

	//-------------------------------------------------------------------------                                                                                                          
      }                                                                                                                                                                                       \

                                                                                                                                                                                                \



  }
  fclose(fp);
}


printf("\nimprimira la lista ----- \n");
for(i=0;i<10;i++){
  printf("%d -> articulo= %s ------ ID=  %d ---- Cantidad %d \n",i,articulo[i],listaid[i],listacount[i]);
 }




return 0;
}

