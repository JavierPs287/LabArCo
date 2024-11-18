# Paralelización con OpenMP

En base al análisis realizado en las dos tareas anteriores es momento de realizar las paralelizaciones que consideres oportunas en el código.

Para cada paralelización completa la siguiente plantilla de resultados:

## Paralelización X

### Análisis previo
Indica en qué te has basado para paralelizar esta región de código, apoya tu argumentación con capturas de Intel Advisor.

### Paralelización
Explica las modificaciones realizadas sobre el código original

¿Has tenido que modificar cómo se calcula alguna variable para evitar dependencias de tipo inter-loop?

### Análisis posterior
Compara el código original con el mejorado y realiza tablas de comparación aumentando el número de hilos.

| Hilos                  | Site label                          | Total Serial Time(s) | Total Parallel Time (s) |  Site Gain  |
|------------------------|-------------------------------------|--------------------- |-----------------------  |-------------|
| 2                      | First stage block for               | 0,643                | 0,323                   |  1,99x      |
|                        | LDL_FAD_Stage2                      | 0,004                | 0,004                   |  1,00x      |
|                        | Third stage block for               | 4,595                | 2,300                   |  2,00x      |
| 4                      | First stage block for               | 0,643                | 0,163                   |  3,95x      |
|                        | LDL_FAD_Stage2                      | 0,004                | 0,004                   |  1,00x      |
|                        | Third stage block for               | 4,595                | 1,152                   |  3,99x      |
| 8                      | First stage block for               | 0,643                | 0,085                   |  7,53x      |
|                        | LDL_FAD_Stage2                      | 0,004                | 0,004                   |  1,00x      |
|                        | Third stage block for               | 4,595                | 0,576                   |  7,98x      |
| 16                     | First stage block for               | 0,643                | 0,046                   |  13,91x     |
|                        | LDL_FAD_Stage2                      | 0,004                | 0,004                   |  0,99x      |
|                        | Third stage block for               | 4,595                | 0,299                   |  15,36x     |
| 32                     | First stage block for               | 0,643                | 0,028                   |  22,81x     |
|                        | LDL_FAD_Stage2                      | 0,004                | 0,004                   |  0,99x      |
|                        | Third stage block for               | 4,595                | 0,161                   |  28,56x     |
| 64                     | First stage block for               | 0,643                | 0,016                   |  39,74x     |
|                        | LDL_FAD_Stage2                      | 0,004                | 0,004                   |  0,99x      |
|                        | Third stage block for               | 4,595                | 0,092                   |  50,11x     |


* ¿Coinciden los resultados con el valor predecido por la herramienta?
  No coinciden, en la que mas se asemejan es en el LDL_FAD_Stage2
* ¿Cómo has comparado los resultados para verificar la correción del programa paralelo?
  Con la herramienta de Suitability

### Resultados
Por cada mejora guarda los resultados y el código junto a su makefile en results/task3/vX donde X indica el orden en que has paralelizado.

Cada carpeta de resultados tiene que ser ejecutable, es decir, el profesor podrá realizar un make y make run en dichas carpetas
para comprobar cada mejora parcial.

## Mejora combinada
Una vez paralelizado cada región por separado, combina los resultados y completa la plantilla anterior.

---

# Parallelization with OpenMP

Based on the analysis carried out in the previous two tasks, it is time to perform the parallelizations you consider appropriate in the code.

For each parallelization, complete the following results template:

## Parallelization X

### Preliminary Analysis
Indicate what you based your decision on to parallelize this region of code, support your argument with screenshots from Intel Advisor.

### Parallelization
Explain the modifications made to the original code.

Did you have to modify how any variable is calculated to avoid inter-loop dependencies?

### Post Analysis
Compare the original code with the improved one and create comparison tables by increasing the number of threads.

* Do the results match the value predicted by the tool?
* How did you compare the results to verify the correctness of the parallel program?

### Results
For each improvement, save the results and the code along with its makefile in results/task3/vX where X indicates the order in which you parallelized.

Each results folder must be executable, meaning the professor should be able to run make and make run in those folders to check each partial improvement.

## Combined Improvement
Once each region has been parallelized separately, combine the results and complete the previous template.
