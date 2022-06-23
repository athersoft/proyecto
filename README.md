
/***
 *      /$$$$$$  /$$                                                                  
 *     /$$__  $$| $$                                                                  
 *    | $$  \__/| $$$$$$$   /$$$$$$  /$$   /$$  /$$$$$$  /$$$$$$$  /$$$$$$$   /$$$$$$ 
 *    | $$      | $$__  $$ |____  $$| $$  | $$ |____  $$| $$__  $$| $$__  $$ /$$__  $$
 *    | $$      | $$  \ $$  /$$$$$$$| $$  | $$  /$$$$$$$| $$  \ $$| $$  \ $$| $$$$$$$$
 *    | $$    $$| $$  | $$ /$$__  $$| $$  | $$ /$$__  $$| $$  | $$| $$  | $$| $$_____/
 *    |  $$$$$$/| $$  | $$|  $$$$$$$|  $$$$$$$|  $$$$$$$| $$  | $$| $$  | $$|  $$$$$$$
 *     \______/ |__/  |__/ \_______/ \____  $$ \_______/|__/  |__/|__/  |__/ \_______/
 *                                   /$$  | $$                                        
 *                                  |  $$$$$$/                                        
 *                                   \______/                                         
 *      /$$$$$$                                  /$$                                  
 *     /$$__  $$                                | $$                                  
 *    | $$  \ $$ /$$   /$$  /$$$$$$   /$$$$$$$ /$$$$$$                                
 *    | $$  | $$| $$  | $$ /$$__  $$ /$$_____/|_  $$_/                                
 *    | $$  | $$| $$  | $$| $$$$$$$$|  $$$$$$   | $$                                  
 *    | $$/$$ $$| $$  | $$| $$_____/ \____  $$  | $$ /$$                              
 *    |  $$$$$$/|  $$$$$$/|  $$$$$$$ /$$$$$$$/  |  $$$$/                              
 *     \____ $$$ \______/  \_______/|_______/    \___/                                
 *          \__/                                                                      
 *                                                                                    
 *                                                                                    
 */


# Como compilar y ejecutar la tarea:

Para compilar es necesario GitBash y la herramienta "make", la cual puede ser instalada en el sig. sitio : [Descargar Make](https://sourceforge.net/projects/ezwinports/files/make-4.3-without-guile-w32-bin.zip/download).
~~Igual puede funcionar en el cmd, pero no cuenta con todas las caracteristicas que quisimos.~~ Agregada función [clrscr()](https://github.com/cykrr/tarea2/blob/d58cdbe62f4982770fefd75eb2d1d2e11775aec7/src/util.c#L26) para permitir
uso del comando especifico de cada sistema operativo.
     
El comando para compilar la tarea es el siguiente
```
make
```


# Opciones que funcionan y las que no:

* Importar libros funciona correctamente, se demora en importar libros muy largos

* Mostrar documentos ordenados funciona pero el orden está invertido

* Buscar libro solo muestra el primero que encuentra

* Mostrar palabras más frecuentes no muestra las palabras de forma ordenada

* Mostar palabras más relevantes no muestra las palabras de forma ordenada

* Mostar palabras en su contexto funciona correctamente

* Buscar palabras funciona

  
# Aspectos positivos y a mejorar de cada integrante:

* Bryam: 
     * '+' Participación y organización
     * '-' Código desordenado

* Matias: 
     * '+' Colaboración constante 
     * '-' Dificultad para manejar estructuras

* Nestor: 
     * '+' Efectividad al crear funciones, buena optimización de código
     * '-' Le dio poca prioridad a la tarea en comparacion a otros ramos

# Puntos premio/castigo a cada integrante según el trabajo hecho:

* Bryam: 3
* Matias: 0
* Nestor: -3

Nota extra: En git no aparece vinculada la cuenta de Bryam en los commit, pero si el nombre de la cuenta (athersoft)