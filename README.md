# ⠀⠀⠀⠀⠀⠀⠀⠀⠀      Trabajo Práctico Nro. 1
## ⠀⠀⠀⠀⠀⠀      Algoritmos y Estructuras de Datos
## - Curso: K1101
## - Profesor: Ing. Diego Juan
## - Año 2025
⠀
### Condición de aprobación del TP

Para aprobar el trabajo práctico se deben realizar correctamente todos los requerimientos
propuestos, utilizando el lenguaje C/C++. Se deben cumplir las fechas de entrega, no
cumplirlas significa quedar fuera de la carrera por la Aprobación Directa. Una vez realizada
la entrega, se citará al equipo para hacer un coloquio individual sobre la entrega. El coloquio
debe aprobarse.
Se debe entregar una carpeta al docente del curso (1 por equipo) que cuente con:
Una carátula con los integrantes del equipo y el código de grupo asignado.
Los algoritmos deben ser escritos en código fuente.

### Contexto del proyecto

El Gobierno de la Ciudad de Buenos Aires, en el marco de su programa “Plan Verde”, ha
realizado un relevamiento en domicilios que participan del proyecto de Huertas Urbanas. Se
requiere una aplicación para procesar la información recolectada y mostrar ciertos
resultados estadísticos.

### Requerimientos

Se debe desarrollar una aplicación en lenguaje C/C++ que despliegue un menú con las
siguientes opciones:
1. Cargar y procesar datos de huertas
2. Mostrar resultados
3. Salir

### Descripción funcional

Si el usuario elige Cargar y procesar datos de huertas, la aplicación deberá invocar a un
módulo o función encargada de realizar esta tarea. A su vez, este módulo puede llamar a
otros para efectuar tareas específicas. Un código modular es más fácil de leer y mantener.
Se debe proceder a solicitar los datos conforme al formulario de datos del relevamiento.
Asimismo, los datos deben procesarse en la medida que los usuarios los vayan ingresando.

Si el usuario elige Mostrar resultados, la aplicación deberá invocar a una función que reciba
los resultados (datos procesados) por parámetro, los vuelva a procesar si fuese necesario, y
los muestre por pantalla:
- Cantidad total de huertas registradas.
- Producción mensual promedio por huerta (en kg).
- Porcentaje de huertas que usan fertilizantes.
- El tipo de cultivo más frecuente.
- Superficie promedio por huerta (en metros cuadrados).
- Cantidad de huertas por barrio.

Si el usuario elige la opcion Salir, finaliza la aplicación.

Formulario de datos del relevamiento:
* De cada huerta se conoce:
    * Identificador de la huerta (número entero)
    * Barrio (cadena de texto)
    * Tipo de cultivo principal ('H': hortalizas, 'F': frutas, 'A': aromáticas, 'L': legumbres, 'O': otros)
    * Superficie cultivada (en metros cuadrados, float)
    * Producción mensual (en kilogramos, float)
    * Uso de fertilizante ('S': sí, 'N': no)

Los datos finalizan cuando el identificador de huerta sea igual a cero.

Consideraciones técnicas:
Para el desarrollo del proyecto se deben usar funcionalidades disponibles en la Biblioteca Estándar STL, en particular iostream, que es un componente utlizado para operaciones de entrada/salida.
