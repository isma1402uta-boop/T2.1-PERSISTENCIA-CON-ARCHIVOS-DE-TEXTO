# T2.1 PERSISTENCIA CON ARCHIVOS DE TEXTO

# 🎓 Proyecto de Consolidación: Algoritmos y Persistencia de Datos

![Carrera](https://img.shields.io/badge/Carrera-Software-blue)
![Nivel](https://img.shields.io/badge/Nivel-Primero%20%22B%22-green)
![Institución](https://img.shields.io/badge/Universidad-T%C3%A9cnica%20de%20Ambato-red)

Este repositorio documenta el desarrollo técnico y práctico realizado en la asignatura de **Algoritmos y Lógica de Programación**. El proyecto abarca desde la gestión de persistencia en archivos físicos hasta la optimización de algoritmos de reorganización de datos con complejidad $O(n)$.

---

## 📑 Resumen de Actividades

El proyecto se divide en dos fases fundamentales que garantizan un sistema robusto y eficiente:

### 1. Persistencia con Archivos de Texto (Trabajo 2.1)
Se implementó un sistema capaz de interactuar con el almacenamiento físico para garantizar que la información trascienda el ciclo de vida de la ejecución del programa.
* **Manejo de Streams:** Uso avanzado de la clase `ifstream` para la extracción segura de datos.
* **Ciclo de Vida del Archivo:** Control estricto desde la apertura (`.open()`), validación de estado (`.is_open()`), hasta el cierre y liberación de recursos.
* **Robustez:** Implementación de bloques `try-catch` y manejo de excepciones para prevenir errores críticos durante la lectura de recursos externos.

### 2. Estructuras de Datos y Reorganización Estable (Trabajo 2.3)
Desarrollo de una solución algorítmica bilingüe (**C++** y **Java**) para el procesamiento de colecciones numéricas.
* **Algoritmo de Clasificación:** Segmentación de elementos en positivos y negativos manteniendo la **estabilidad** (orden relativo original).
* **Intercalado Eficiente:** Reconstrucción del arreglo alternando signos y gestionando residuos de forma dinámica.
* **Complejidad Temporal:** El algoritmo ha sido diseñado para operar en tiempo lineal **$O(n)$**, asegurando escalabilidad.

---

## 🛠️ Especificaciones Técnicas

### Requisitos del Entorno
* **Lenguajes:** C++ (Estándar 11 o superior) y Java (JDK 11+).
* **IDE:** Visual Studio Code / IntelliJ IDEA / CLion.
* **Compiladores:** GCC para C++ y Javac para Java.

### Estructura de la Solución
```text
├── Persistencia/
│   ├── main.cpp            # Implementación de flujos de lectura
│   └── datos.txt           # Archivo de persistencia de datos
├── Reorganizacion/
│   ├── C++/                # Código fuente en C++ (Punteros y Memoria)
│   └── Java/               # Código fuente en Java (POO)
└── Docs/                   # Informes técnicos detallados
