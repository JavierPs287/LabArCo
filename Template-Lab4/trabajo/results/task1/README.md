# Tarea 1: Análisis de la máquina y rendimiento del código

Esta tarea requiere la compilación y ejecución del código para la detección de anomalías. Para ello dispones de un fichero makefile que automatiza ambos procesos.
Teclea **make** para realizar la compilación, y **make run** para ejecutarlo (todo esto dentro del directorio src).
La ejecución requiere de un fichero de datos de entrada que previamente deberás descargar del siguiente [enlace](https://mega.nz/folder/x4gRhLJJ#GRdxQc1Hnw3Lk_-9JC3Uew). El fichero se debe insertar en src, si quieres usar otro directorio deberás modificar la línea 7 del fichero Configurations.h

**En este ejercicio NO debe utilizarse la optimización -xCORE-AVX2 ya que toda la vectorización SIMD se indicará de manera explícita a través de pragmas**

## Preguntas
* Antes de comenzar a realizar ningún análisis sobre el código es interesante conocer las características de la arquitectura sobre la que estás ejecutando el programa, para ello contesta a las siguientes preguntas:

    * Indica tu modelo de procesador, la arquitectura y de cuantos núcleos e hilos de procesamiento dispones
      Modelo: Intel(R) Core(TM) i7-9750HF CPU @ 2.60GHz.
      Arquitectura: x86_64.
      6 núcleos y 12 hilos.
    * ¿Cuantos hilos pueden ser ejecutados por núcleo?
      12/6 = 2 hilos por núcleo.

* Realiza un análisis completo desde la vista de CPU/Roofline. Desde la pestaña de "Survey & Roofline" analiza el resultado Top Down.
    * ¿Qué función de nuestra lógica de negocio consume más tiempo?
      La función main es la que consume todo el tiempo, pues es la que ejecuta todo el programa, depués la funcion "runDetector" que consume un 67.5% del tiempo.
      ![WhatsApp Image 2024-11-07 at 11 10 48](https://github.com/user-attachments/assets/3fd44d5d-fd9f-4809-bd0f-d8fa6504b89a)
    * ¿Qué etapas son las más costosas?
      ![WhatsApp Image 2024-11-06 at 20 46 10](https://github.com/user-attachments/assets/38afe674-b8e2-4610-bc77-4423edfa74f9)

    * ¿Qué operaciones (entendemos operaciones como las funciones definidas en LBL_FAD_Transform_Operations.h/.cpp) son las más complejas y requieren de un mayor tiempo?
      La operacion mas compleja es la LBL_FAD_Stage3_4.
      ![image](https://github.com/user-attachments/assets/c049dcc9-7b13-4003-8ee7-a643bb9e3aee)

Realiza un análisis completo y muestra una captura de pantalla del gráfico roofline.
* ¿Cuáles son los tres bucles más complejos? ¿Por qué están limitados? ¿Cómo los mejorarías?
  Una de las técnicas para mejorar es el desenrollado de bucle.
  ![image](https://github.com/user-attachments/assets/3b31b42a-d009-4b5c-9800-9129e812bb6c)


Finalmente resulta interesante ver el patron de acceso de memoria que se realiza en el código con el objetivo de valorar la vectorización o mejorar los accesos a memoria para hacer un mejor uso de la jerarquía de memoria.

Realiza un análisis de tipo "refinement" añadiendo el paso de Memory Access Patterns y selecciona los dos bucles que más tiempo
consumen realizando cálculos internos.

* Indica que dos bucles son
  Linea 150 en Main_Detector y linea 95 en Main_Detector
* ¿Qué tipos de acceso a memoria se está realizando? ¿cuáles existen?
  Son de tipo mixed strides, además de este tipo existen otros tres más, Acceso Secuencial, Acceso Aleatorio y Acceso No UNiforme a la Memoria.

![image](https://github.com/user-attachments/assets/5b5277cd-8c74-4285-83bb-937f3faa1ef3)


Para cada pregunta analiza y aporta las capturas de pantalla que veas conveniente para apoyar la explicación.

----

# Task 1: Machine Analysis and Code Performance

This task requires the compilation and execution of the code for anomaly detection. For this, you have a makefile that automates both processes.
Type **make** to compile, and **make run** to execute it (all within the src directory).
The execution requires an input data file that you must download from the following [link](https://mega.nz/folder/x4gRhLJJ#GRdxQc1Hnw3Lk_-9JC3Uew). The file should be placed in src, if you want to use another directory you must modify line 7 of the Configurations.h file.

**In this exercise, the -xCORE-AVX2 optimization should NOT be used as all SIMD vectorization will be explicitly indicated through pragmas**

## Questions
* Before starting any analysis on the code, it is interesting to know the characteristics of the architecture on which you are running the program, so answer the following questions:

    * Indicate your processor model, architecture, and how many cores and processing threads you have.
    * How many threads can be executed per core?

* Perform a complete analysis from the CPU/Roofline view. From the "Survey & Roofline" tab, analyze the Top Down result.
    * Which function of our business logic consumes the most time?
    * Which stages are the most costly?
    * Which operations (we understand operations as the functions defined in LBL_FAD_Transform_Operations.h/.cpp) are the most complex and require the most time?

Perform a complete analysis and show a screenshot of the roofline graph.
* What are the three most complex loops? Why are they limited? How would you improve them?

Finally, it is interesting to see the memory access pattern performed in the code to evaluate vectorization or improve memory accesses to make better use of the memory hierarchy.

Perform a "refinement" analysis by adding the Memory Access Patterns step and select the two loops that consume the most time performing internal calculations.

* Indicate which two loops they are.
* What types of memory access are being performed? Which ones exist?

For each question, analyze and provide screenshots that you deem appropriate to support the explanation.
