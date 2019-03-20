En la carpeta openmp se encuentra el archivo llamado "prueba.c" el cual se compila com

gcc pureba.c -o preuba -fopenmp 

para modificar el numero de threads se hace modificando una variable que indica el numero 
que se desea colocar 

-------

en el programa existen dos funciones 
el main y el buscarTexto 
donde en el main generamos un gran for que se encarga de obtener linea a linea el contenido 
de los archivos articles*  y este para cuando obtener mas lineas se haga nula
se crean los threads que van a ir obteniendo cada uno de las lineas y cada thread se encargara de contar
el numero de ocurrencias y el detalle de la linea (nombre,id,articulo),cada uno de los threads ira modificando 
la varaible que comparten indice para que asi cuando se llegue al final de el archivo articles* este pare
mas externamente hay un for que se encarga de cambair de archivo articles* una vez el anterior halla terminado.

para obtener el numero de ocurrencias buscamos y paramos cuando encontramos que el primer caracter de la palabra a buscar
esta en la linea y empezamos a recorrer desde ahi hasta que validemos que los sigueintes caracteres corresponden a la palabra que
queremos encontrar dentro de la linea 

para no tener que estar haciendo uso de mucha memoria y arreglo de apuntadores se creo la funcion buscarTexto
que se encarga principalmente de encontrar el titulo de la noticia una vez se vaya a imprimir la lista que queremos presentar
  