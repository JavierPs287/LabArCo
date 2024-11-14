# Tarea 2: Anotación y análisis de tipo threading

Antes de realizar una modificación en un programa, con la complejidad que ello conlleva, resulta muy interesante poder realizar un análisis o profiling para ver los posibles puntos de mejora.
Estos análisis pueden variar en complejidad y en función de la cantidad de datos que se de a la herramienta la predicción de mejora será más o menos precisa.

Intel advisor posee la vista threading para este cometido. Una vez seleccionada esta vista aparecerá un nuevo análisis llamado "Suitability". Mediante este análisis podrás ver el rendimiento esperado en caso de paralelizar determinadas regiones de código.

Para que la herramienta pueda realizar este análisis requiere ayuda por parte del programador/a.
El programador deberá instrumentalizar el código mediante las herramientas que el programa de análisis provea. En el caso de intel advisor a este proceso se le llama "anotación de código".

Revisa el código y responde a las siguientes preguntas:

* ¿Qué bucles se han anotado?
  
  En el "Stage 1: Background":
  ![image](https://github.com/user-attachments/assets/636cae85-7568-496d-bbe4-1b14fa1e2aed)

  En el "Stage 2: Background Estimation":
  ![image](https://github.com/user-attachments/assets/21e23a99-7d70-4c7b-b0c0-28b99b16dc0a)

  En el "Stage 3: AD Map":
  ![image](https://github.com/user-attachments/assets/1fdcb79a-9d6a-4f54-9e07-b72b4b732782)


* ¿Qué estructura sigue una anotación? ¿En qué partes se descomponen?

  ANNOTATE_SITE_BEGIN y ANNOTATE_SITE_END: Estas anotacion indican el inicio y el final de los bucles.

  ANNOTATE_ITERATION_TASK: Se utiliza para indicar que el bucle se esta utilizando dentro de otro bucle.

  ANNOTATE_TASK_BEGIN y ANNOTATE_TASK_END: Indican el principio y el final de una tarea.
* Las anotaciones son como un pseudocódigo de cómo paralelizaríamos con OpenMP. ¿A qué equivale en OpenMP cada una de las partes de la anotación?
  
  ANNOTATE_SITE_BEGIN y ANNOTATE_SITE_END: #pragma omp parallel

  ANNOTATE_ITERATION_TASK: #pragma omp for

  ANNOTATE_TASK_BEGIN y ANNOTATE_TASK_END: #pragma omp task

Una vez ejecutado el análisis de tipo "Suitability" accede a la pestaña Suitability Report y contesta a las siguientes preguntas:

* ¿Qué significan cada una de las columnas de la tabla superior?

  Site Label: Indica el nombre del bloque de código que se ha analizado.
  
  Source Location: Muestra el archivo y la línea de código donde se encuentra cada sitio analizado.
  
  Impact to Program Gain: Representa la mejora estimada en el rendimiento total del programa si se paraleliza esa parte.
  
  Combined Site Metrics, All Instances
    - Total Serial Time: Tiempo total que tarda el programa en ejecutar es parte.
    - Total Parallel Time: Tiempo total estimado de ejecución en modo paralelo.
    - Site Gain: Indica la ganancia de rendimiento que se podría obtener al paralelizar una parte.
      
  Site Instance Metrics, Parallel Time: Muestra el tiempo estimado de paralelización para una instancia del sitio específico.
* ¿Qué diferencia existe entre Impact to Program Gain y "Site Gain"?

  Impact to Program Gain refleja el beneficio que la paralelización de esa región tendría en el rendimiento total del programa. Como una métrica global.

  Site Gain mide el beneficio de la paralelización de esa región específica sin considerar su impacto global. Como una métrica local.

* ¿Qué bucles paralelizarías? ¿Con qué bucle obtendrías un mayor rendimiento?
  ![image](https://github.com/user-attachments/assets/e4eadcea-93ee-414d-8687-f58a121f6b5b)
  "Third stage block for", "First stage block for" y "LBL_FAD_Stage2"
   El que mas rendimiento obtendría es: "Third stage block for"

* ¿Cómo afecta la duración y número de iteraciones al rendimiento esperado? Utiliza capturas de pantalla para apoyar el análisis
  
  La duración afecta de forma secuencial y a más duración mejor paralelización, y las iteraciones indican una mejor eficiencia en la paralelización, a mas iteraciones mejor es la eficiencia.
* ¿A qué corresponde el número de iteraciones en cada "site" en el código? ¿Qué explicación tienen dentro del algoritmo?
  
  El codigo está realizando operaciones independientes en cada iteración, esto favorece la paralelización, ya que cada iteración se puede asignar a diferentes hilos de forma segura y eficiente.

---

# Task 2: Annotation and threading analysis

**In this exercise, the -xCORE-AVX2 optimization should NOT be used as all SIMD vectorization will be explicitly indicated through pragmas**

Before making a modification to a program, with the complexity that entails, it is advisable to perform an analysis or profiling to see the possible points of improvement of the program.
These analyses can vary in complexity and, depending on the amount of data given to the tool, the quality of the prediction will be higher or lower.

Intel Advisor has the threading view for this purpose. Once this view is selected, a new analysis called "Suitability" will appear. Through this analysis, you can see the expected performance if certain regions of code are parallelized.

For the tool to perform this analysis, it requires help from the programmer.
The programmer must instrument the code using the tools provided by the analysis program. In the case of Intel Advisor, this process is called "code annotation."

Review the code and answer the following questions:

* Which loops have been annotated?
* What structure does an annotation follow? Into what parts is it decomposed?
* Annotations are like pseudocode of how we would parallelize with OpenMP. What does each part of the annotation correspond to in OpenMP?

Once the "Suitability" analysis is executed, go to the Suitability Report tab and answer the following questions:

* What do each of the columns in the top table mean?
* What is the difference between Impact to Program Gain and "Site Gain"?
* Which loops would you parallelize? With which loop would you achieve the highest performance?
* How do duration and number of iterations affect the expected performance? Use screenshots to support the analysis.
* What does the number of iterations in each "site" correspond to in the code? What is its function within the algorithm?
