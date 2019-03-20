#include <stdio.h>
#include "omp.h"
#include <time.h>
#include <stdlib.h>
#include<string.h>

#define SIZE 20
#define bufSize 20024
#include <stdio.h>


char * BuscarTexto(char *articulo,int id){

  char line_buf[bufSize] ;
  char result[6];
  int numeroLineas,i,j,o,indice;
  FILE *fp;
  char name[100];
  int contadorComas=0;
  char* articles1="articles1.csv";
  char* articles2="articles2.csv";
  char* articles3="articles3.csv";
  int numeroHilos;
  o=0;
  fp = fopen(articulo,"r");

  sprintf(result, "%d", id);


  result[5]=',';


  if(articulo==articles1){
    numeroLineas=50495;
  }
  if(articulo==articles2){
    numeroLineas=80371;
  }
  if(articulo==articles3){
    numeroLineas=54204;
  }
  char *p;
  //printf("numeroLineas = %d\n",numeroLineas);                                                                                                                                  
  for(i=0;i<numeroLineas;i++){
    fgets(line_buf, sizeof(line_buf), fp);
    p = strstr (line_buf,result);
    // printf("Hizo el fgets --- %s \n",line_buf);                                                                                                                                    
    if(p){
      for(j=0;j<20;j++){
        if(line_buf[j]==','){
          contadorComas++;
        }
        if(contadorComas==2){
          if(line_buf[j+1]=='"'){                                                                                                                                                               
            j++;                                                                                                                                                                                
            for(indice=j+1;indice<100;indice++){                                                                                                                                             

              if(line_buf[indice]!='"'){                                                                                                                                                        
                name[o]=line_buf[indice];                                                                                                                                                       
                o++;                                                                                                                                                                            
                                                                                                                                                                                                
              }else{
                indice=100;                                                                                                                                    
              i=numeroLineas;
                //      printf("-> %s \n ",name); 
	      }                                                                                                                                                                                 
            }


          }

          else{                                                                                                                                                                                 
            j++;                                                                                                                                                                                
            for(indice=j;indice<100;indice++){                                                                                                                                                  
                                                                                                                                                                                                
              if(line_buf[indice]!=','){                                                                                                                                                        
                name[o]=line_buf[indice];                                                                                                                                                       
                o++;                                                                                                                                                                            
              }else
		{                                                                                                                                                                             
                  indice=100;
                  i=numeroLineas;
                  //              printf("-> %s \n ",name);                                                                                                                                   
                }
            }

          }                                                                                                                                                                        
	  break; 
	}

      }
    }
  }

  fclose(fp);
  printf("-> %s \n ",name);
  memset(result,0,sizeof(result));
  memset(name,0,sizeof(name));
  return 0;

}
