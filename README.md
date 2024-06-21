# Examen-final

## Estructura de repositorio
Trabajamos en respositorios individuales, por lo que no fue necesario crear otras ramas y fue utilizado solo la rama main en ambos casos. En esta rama guardamos todo lo necesario, por un lado en el READ.ME se encuentra todo lo requerido por el docente con respecto a la documentación y con respecto al código se tiene los archivos cpps y headers correspondientes.

INDICE README:
1. Problema
2. Comparativa de bases de datos existentes
3. Justificación
4. Descripción de estructuras y funciones
5. Diagramas
6. Herramientas utilizadas
7. Créditos

## 1. Problema
El problema requiere diseñar un programa en C++ para gestionar una base de datos de eventos asociados a fechas específicas, permitiendo la inserción, eliminación, búsqueda e impresión de eventos a través de comandos introducidos por el usuario en la entrada estándar. Las fechas deben seguir el formato AAAA-MM-DD, y los eventos deben ser cadenas sin espacios. Los comandos soportados son agregar evento (Add Fecha Evento), eliminar evento (Del Fecha Evento), eliminar todos los eventos en una fecha (Del Fecha), buscar eventos en una fecha (Find Fecha), e imprimir todos los eventos (Print). Se deben validar las fechas y comandos, manejando errores como formato incorrecto de la fecha, meses fuera del rango 1-12 y días fuera del rango 1-31, proporcionando mensajes específicos para errores de formato y rango.

## 2. Comparativa de bases de datos existentes
Los principales motores de bases de datos que existen se dividen en dos campos:

### 2.1 SQL / Relacional:
El modelo relacional que utiliza tiene un esquema fijo que consiste en un conjunto de tablas, las cuales a la hora de la consulta de información se relacionan entre sí para dar con el resultado, esta operación de relación o transacción se le llame JOIN.

    · Lenguaje: SQL, lenguaje estructurado de consulta.

    · Velocidad: A medida que el volúmen de datos crece o en un entorno concurrente, el sistema se relentiza.

    · Datos: Prioriza la integridad de los datos porque no permite la redundancia de los mismos ya que los organiza en tablas.

    · Escalabilidad: no tiene la capacidad para incrementar o ajustar los recursos de acorde con las demandas del negocio, sin la necesidad de reestructurar significativamente el sistema, debido a su estructura rígida.

    · Ambientes de uso: Coorporativo o financiero, porque en este contexto es indispensable la integridad de los datos.

    · Más utilizados: Oracle, MySQL, Microsoft SQL Server, PostgreSQL, Maria DB.

### 2.2 No SQL / No Relacional:
Son más bien un conjunto de tipos de motores de bases de datos, sin embargo comparten entre sí estas características:
(Es todo lo contrario a SQL, es decir que niega todos sus principios.)

    · Lenguaje: No requiere una estructura fija y tabular, porque no utiliza un lenguaje de consulta estructurado, como SQL, como lenguaje principal.

    · Velocidad: El incremento del volumen de datos o un entorno concurrente no afecta el rendimiento del sistema.

    · Datos: Permite la redundancia de datos, lo que provoca la no consistencia a la hora de almacenar los mismos, pero eventualmente a la hora de consulta se garantiza obtener lo requerido.

    · Escalabilidad: tiene la capacidad para incrementar o ajustar los recursos de acorde con las demandas del negocio, debido a su flexibiilidad en los cambios de información en el sistema. 

    · Ambientes de uso: con alta demanda de usuarios como Facebook o Amazon, que exigen rapidez de respuesta así como de almacenamiento de los datos.

#### 2.2.1 Clave valor:
Simples en cuanto a su implementación, almacenan datos como un conjunto de pares “clave/valor” (key-value). La clave representa un identificador único que puede retornar un objeto complejo y arbitrario de información, denominado valor. Por ejemplo, Redis y Amazon DynamoDB.

#### 2.2.2 Documental:
El concepto central de este tipo de almacenamiento es el documento. Una base de datos NoSQL documental, almacena, recupera y gestiona datos de documentos. Estos documentos encapsulan y codifican datos o información bajo algún formato estándar (XML, YAML, JSON, BSON). Por ejemplo, MongoDB y Apache CouchDB.

#### 2.2.3 Familia de Columnas:
Se encuentran organizados por columnas, en lugar de por filas. Las bases de datos que utilizan esta forma de almacenamiento tienden a ser un híbrido entre las clásicas bases de datos relaciónales y la tecnología orientada a columna. Por ejemplo, Cassandra y Apache HBase.

#### 2.2.4 Grafos:
Se representa la base de datos bajo el concepto de un grafo. Permite almacenar la información como nodos de un grafo y sus respectivas relaciones con otros nodos, y se aplica la teoría de grafos para recorrer la base de datos; son muy útiles para almacenar información en modelos con muchas relaciones entre distintas entidades o nodos. Por ejemplo, Neo4j y OrientDB.

Existen otros tipos de bases de datos noSQL, sin embargo estás son las principales o más utilizadas.

## 3. Justificacion
Esta propuesta de un nuevo modelo de base de datos surge a partir de la necesidad de sencillez en las funciones que cumple la misma. Debido a que se requiere un procesamiento específico, es decir el de almacenar eventos en una fecha determinada, no le es necesario al usuario final todas las otras funcionalidades que ofrecen modelos más complejos, como los detallados arriba en la comparativa de bases de datos existentes. Entonces serían en todo caso funcionalidades no utilizadas para el problema que nos es planteado, porque solo se requiere del procesamiento de cuatro comandos y el manejo de ciertos errores entrada, por lo que este nuevo modelo es lo más adecuado para solventar el problema planteado. 

## 4. Descripcion de estructuras y funciones
ESTRUCTURAS:
- Fecha: esta estructura declara tres variables enteras de nombre: año, mes y dia respectivamente.

FUNCIONES:
- separar_input: Un bucle for para reescribir el input hasta encontrar un espacio porque significa que terminamos de reescribir el comando o bien la fecha y se los guarda en un vector. Sin embargo la ultima palabra no cuenta con un espacio después, por lo tanto se lo guarda después del loop. Por ejemplo: Si tenemos la entrada "Print", se reescribiría el comando en el for pero se lo guardaría al salir del bucle.

- validar_fecha: Dos bucles for para reescribir la fecha. En el primero se reescribe el año y la función termina si esta en formato incorrecto, de lo contrario se lo guarda en un vector. En el segundo es la misma dinámica solo que con el mes y el dia. Luego si la fecha no esta en formato año, mes y dia la función termina. De lo contrario sigue para verificar los valores del mes y dia si no estan en el rango aceptado termina la función, de lo contrario nuestra fecha paso todas las pruebas y devuelve true. Esta función es utilizada con todos los comandos que requieren de una fecha en la entrada, es decir todos menos el comando Print.

- comprobar_mes: Verifica que el mes este entre 1 y 12.
- comprobar_dia: Verifica que el dia este entre 1 y 31, estas dos funciones de verificación de rango son utilizados solo si en la función validar_fecha se pasaron todos los filtros de formato. Por ejemplo: si se tiene "1-1--1" en la entrada, esta fecha tiene formato correcto pero el dia es negativo (-1), por lo tanto si se llegaría a utilizar la función comprobar_dia.

- find: Un bucle for para imprimir todos los eventos de la fecha indicada en esa linea de comando. Un caso de uso de esta función es cuando se ingreso en comando "Find" en la entrada

- print: Un bucle for para ir iterando sobre la fecha del mapa y otro dentro para ir iterando e imprimiendo los eventos relacionados a esa fecha, al terminar se va a la siguiente fecha y se repite el proceso hasta imprimir toda nuestra base de datos. (En esta función queriamos hacer llamado de la función format_fecha_print, pero al intentar modificar la fecha que se encontraba en la clave del mapa, nos salía error. Otra opción era hacer el formateo cuando se agregarán eventos (comando Add), porque ahí se tiene a la fecha en formato string y se tiene acceso a todas las fechas de la base de datos, pero no pudimos hacer la modificación antes del examen).

- format_fecha_print: Modificar el formato de la fecha si es necesario a AAAA-MM-DD solo para el comando Print. Sin embargo, no tenemos ejemplos de uso ya que en ningún momento en el código presentado se llama a esta función.

## 5. Diagramas de flujo:
Diagrama del MAIN: es donde se procesan todas las entradas y sigue la lógica de tal forma que se ingresa solo una string como linea de comando, se divide la misma y según el comando se va llamando a las funciones necesarias para la misma. Al terminar de recibir las entradas se imprime lo necesario con respecto a Find y Print ya que no conseguimos que Del se imprima luego de recibir todas las lineas de comando.

[imagen](diagramas/MAIN.png)

Diagramas de FUNCIONES: explicadas en el subtítulo de arriba
- separar_input: [imagen](diagramas/separar_input.png)
- validar_fecha: [imagen](diagramas/validar_fecha.png)
- comprobar_mes y comprobar_dia: [imagen](diagramas/comprobar_mes_dia.png)
- find: [imagen](diagramas/find.png)
- print: [imagen](diagramas/print.png)
- format_fecha_print: [imagen](diagramas/format_fecha_print.png)

## 6. Herramientas utilizadas
- VisualStudioCode: es la herramienta utilizada para compilar el código el día del examen, por lo que su uso es indispensable a la hora de desarrollar el proyecto porque se debe verificar que compile correctamente en todo momento. Además es el medio por el cual subimos los avanzado del código al repositorio del github, para cumplir con los commits requeridos.

- Programiz C++: es la herramienta que más utilizamos a lo largo del desarrollo porque ofrece una forma de compilar más rápida y sencilla a comparación del VSCode. De esta manera optimizamos más el tiempo al momento de ir probando las distintas lógicas para abordar el problema.

- Github: ofrece un lugar seguro para guardar el desarrollo de un código y cualquier tipo de información en general, por lo que su uso fue indispensable porque de esta manera teniamos acceso a versiones anteriores que podiamos consultar de ser necesario.

## 7. Créditos
- Yannine Mary Saavedra Poma
- Camila Alison Catorceno Orellana

Fuente para la investigación: https://sedici.unlp.edu.ar/bitstream/handle/10915/91403/Documento_completo.pdf?sequence=1&isAllowed=y
