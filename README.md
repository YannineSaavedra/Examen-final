# Examen-final
## Problema:
El problema requiere diseñar un programa en C++ para gestionar una base de datos de eventos asociados a fechas específicas, permitiendo la inserción, eliminación, búsqueda e impresión de eventos a través de comandos introducidos por el usuario en la entrada estándar. Las fechas deben seguir el formato AAAA-MM-DD, y los eventos deben ser cadenas sin espacios. Los comandos soportados son agregar evento (Add Fecha Evento), eliminar evento (Del Fecha Evento), eliminar todos los eventos en una fecha (Del Fecha), buscar eventos en una fecha (Find Fecha), e imprimir todos los eventos (Print). Se deben validar las fechas y comandos, manejando errores como formato incorrecto de la fecha, meses fuera del rango 1-12 y días fuera del rango 1-31, proporcionando mensajes claros de error, éxito y mensajes específicos para errores de formato y rango.

## Comparativa de base de datos existentes:
Los principales motores de bases de datos que existen se dividen en dos campos:

### 1. SQL / Relacional:
El modelo relacional que utiliza tiene un esquema fijo que consiste en un conjunto de tablas, las cuales a la hora de la consulta de información se relacionan entre sí para dar con el resultado, esta operación de relación o transacción se le llame JOIN.

    · Lenguaje: SQL, lenguaje estructurado de consulta.

    · Velocidad: A medida que el volúmen de datos crece o en un entorno concurrente, el sistema se relentiza.

    · Datos: Prioriza la integridad de los datos porque no permite la redundancia de los mismos ya que los organiza en tablas.

    · Escalabilidad: no tiene la capacidad para incrementar o ajustar los recursos de acorde con las demandas del negocio, sin la necesidad de reestructurar significativamente el sistema, debido a su estructura rígida.

    · Ambientes de uso: Coorporativo o financiero, porque en este contexto es indispensable la integridad de los datos.

    · Más utilizados: Oracle, MySQL, Microsoft SQL Server, PostgreSQL, Maria DB.

### 2. No SQL / No Relacional:
Son más bien un conjunto de tipos de motores de bases de datos, sin embargo comparten entre sí estas características:
(Es todo lo contrario a SQL, es decir que niega todos sus principios.)

    · Lenguaje: No requiere una estructura fija y tabular, porque no utiliza un lenguaje de consulta estructurado, como SQL, como lenguaje principal.

    · Velocidad: El incremento del volumen de datos o un entorno concurrente no afecta el rendimiento del sistema.

    · Datos: Permite la redundancia de datos, lo que provoca la no consistencia a la hora de almacenar los mismos, pero eventualmente a la hora de consulta se garantiza obtener lo requerido.

    · Escalabilidad: tiene la capacidad para incrementar o ajustar los recursos de acorde con las demandas del negocio, debido a su flexibiilidad en los cambios de información en el sistema. 

    · Ambientes de uso: con alta demanda de usuarios como Facebook o Amazon, que exigen rapidez de respuesta así como de almacenamiento de los datos.

#### 2.1 Clave valor:
Simples en cuanto a su implementación, almacenan datos como un conjunto de pares “clave/valor” (key-value). La clave representa un identificador único que puede retornar un objeto complejo y arbitrario de información, denominado valor. Por ejemplo, Redis y Amazon DynamoDB.

#### 2.2 Documental:
El concepto central de este tipo de almacenamiento es el documento. Una base de datos NoSQL documental, almacena, recupera y gestiona datos de documentos. Estos documentos encapsulan y codifican datos o información bajo algún formato estándar (XML, YAML, JSON, BSON). Por ejemplo, MongoDB y Apache CouchDB.

#### 2.3 Familia de Columnas:
Se encuentran organizados por columnas, en lugar de por filas. Las bases de datos que utilizan esta forma de almacenamiento tienden a ser un híbrido entre las clásicas bases de datos relaciónales y la tecnología orientada a columna. Por ejemplo, Cassandra y Apache HBase.

#### 2.4 Grafos:
Se representa la base de datos bajo el concepto de un grafo. Permite almacenar la información como nodos de un grafo y sus respectivas relaciones con otros nodos, y se aplica la teoría de grafos para recorrer la base de datos; son muy útiles para almacenar información en modelos con muchas relaciones entre distintas entidades o nodos. Por ejemplo, Neo4j y OrientDB.

Existen otros tipos de bases de datos noSQL, sin embargo estás son las principales o más utilizadas.

## Justificación:
Este ejercicio de gestión de una base de datos de eventos asociados a fechas específicas mediante comandos de entrada estándar es esencial para desarrollar varias habilidades clave en programación. En primer lugar, permite practicar la manipulación de datos y el uso de estructuras avanzadas como map y set, que son fundamentales para el almacenamiento y acceso eficiente de datos. Implementar operaciones CRUD (crear, leer, actualizar y eliminar) en este contexto es una práctica crucial para cualquier desarrollador, ya que estas operaciones son la base de la mayoría de las aplicaciones de software.
La validación de entrada y el manejo de errores son aspectos críticos que se abordan en este problema. Verificar la corrección del formato de fecha y el rango de los valores del mes y día, así como manejar comandos desconocidos, enseña a los estudiantes a escribir programas robustos y seguros. Proporcionar retroalimentación clara y específica al usuario mediante mensajes de error también mejora la experiencia del usuario y facilita la depuración del código.
Además, este ejercicio fomenta la modularidad y la buena organización del código mediante la descomposición en funciones y el uso de estructuras. La interacción con el usuario a través de una interfaz de línea de comandos es una habilidad práctica valiosa, especialmente para la creación de herramientas y scripts de automatización. En resumen, este problema es un ejercicio integral que abarca múltiples aspectos de la programación y es fundamental para el desarrollo de un programador competente y versátil.

## Estructura de repositorio
Trabajamos en respositorios individuales, por lo que no fue necesario crear otras ramas. Aún así ambas solo utilizamos la rama main para guardar lo necesario: el documento READ.ME y los archivos cpps y headers para el código.

## Descripcion de las estructuras y funciones
ESTRUCTURAS:
- Fecha:

FUNCIONES:
- Add:
- Find:
- Del:
- Print:

## Diagrama de flujos o Pseudocodigo. Debe estar embebido como imagen en le  README y dando una ligera explicacion de la imagen.


## Creditos
- Yannine Mary Saavedra Poma
- Camila Alison Catorceno Orellana

Fuente para la investigación: https://sedici.unlp.edu.ar/bitstream/handle/10915/91403/Documento_completo.pdf?sequence=1&isAllowed=y

## Herramientas utilizadas
- VisualStudioCode
- Programiz C++
- Github