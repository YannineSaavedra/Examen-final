# Examen-final
## Problema:
El problema requiere diseñar un programa en C++ para gestionar una base de datos de eventos asociados a fechas específicas, permitiendo la inserción, eliminación, búsqueda e impresión de eventos a través de comandos introducidos por el usuario en la entrada estándar. Las fechas deben seguir el formato AAAA-MM-DD, y los eventos deben ser cadenas sin espacios. Los comandos soportados son agregar evento (Add Fecha Evento), eliminar evento (Del Fecha Evento), eliminar todos los eventos en una fecha (Del Fecha), buscar eventos en una fecha (Find Fecha), e imprimir todos los eventos (Print). Se deben validar las fechas y comandos, manejando errores como formato incorrecto de la fecha, meses fuera del rango 1-12 y días fuera del rango 1-31, proporcionando mensajes específicos para errores de formato y rango.

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
Esta propuesta de un nuevo modelo de base de datos surge a partir de la necesidad de sencillez en las funciones que cumple la misma. Debido a que se requiere un procesamiento específico, es decir el de almacenar eventos en una fecha determinada, no le es necesario al usuario final todas las otras funcionalidades que ofrecen modelos más complejos, como los detallados arriba en la comparativa de bases de datos existentes. Entonces serían en todo caso funcionalidades no utilizadas para el problema que nos es planteado, porque solo se requiere del procesamiento de cuatro comandos y el manejo de ciertos errores entrada, por lo que este nuevo modelo es lo más adecuado para solventar el problema planteado.

## Estructura de repositorio
Trabajamos en respositorios individuales, por lo que no fue necesario crear otras ramas y fue utilizado solo la rama main en ambos casos. En esta rama guardamos todo lo necesario, por un lado en el READ.ME se encuentra todo lo requerido por el docente con respecto a la documentación y con respecto al código se tiene los archivos cpps y headers correspondientes.

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
su funcion y relevancia para el proyecto
- VisualStudioCode: es la herramienta utilizada para compilar el código el día del examen, por lo que su uso es indispensable a la hora de desarrollar el proyecto porque se debe verificar que compile correctamente en todo momento. Además es el medio por el cual subimos los avanzado del código al repositorio del github, para cumplir con los commits requeridos.
- Programiz C++: es la herramienta que más utilizamos a lo largo del desarrollo porque ofrece una forma de compilar más rápida y sencilla a comparación del VSCode. De esta manera optimizamos más el tiempo al momento de ir probando las distintas lógicas para abordar el problema.
- Github: ofrece un lugar seguro para guardar el desarrollo de un código y cualquier tipo de información en general, por lo que su uso fue indispensable porque de esta manera teniamos acceso a versiones anteriores que podiamos consultar de ser necesario.