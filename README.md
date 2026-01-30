# 🧩 BuscaminasGame

## 📌 Objetivo
Recrear el videojuego **Buscaminas**, inspirado en un trabajo práctico de la materia **Tópicos de Programación**.

El objetivo principal del proyecto es combinar **rendimiento y modularidad**, utilizando distintos lenguajes para cumplir roles específicos dentro del sistema.

---

## 🛠️ Tecnologías utilizadas

- **C**
  - Implementación de toda la lógica del juego.
  - Manejo de estructuras, reglas y estado del tablero.
  - Compilación de la lógica en una **librería dinámica (.dll)** para maximizar el rendimiento.

- **Python**
  - Consumo de la librería `.dll` generada en C.
  - Desarrollo de la interfaz gráfica del juego.

- **Pygame**
  - Biblioteca utilizada para la creación de la interfaz gráfica.
  - Manejo de eventos, renderizado del tablero y la interacción del usuario.

---

## 🧠 Arquitectura del proyecto

El proyecto está dividido en dos capas principales:

- **Capa lógica (C)**
  - Contiene toda la lógica del Buscaminas.
  - Es independiente de la interfaz gráfica.
  - Puede ser reutilizada en otros lenguajes o interfaces.

- **Capa gráfica (Python + Pygame)**
  - Se encarga únicamente de la visualización y los eventos.
  - Consume la lógica del juego a través de la librería `.dll`.

Esta separación permite:
- Mejor rendimiento.
- Código más mantenible.
- Facilidad para cambiar la interfaz sin modificar la lógica.

---

## 🚀 Estado del proyecto
Proyecto en desarrollo con enfoque educativo y experimental, orientado a reforzar conceptos de:
- Programación en C
- Integración entre lenguajes
- Arquitectura modular
- Desarrollo de videojuegos simples

---

## 📚 Contexto académico
Este proyecto surge a partir de un trabajo práctico de la materia **Tópicos de Programación**, con el objetivo de aplicar conocimientos teóricos en un desarrollo práctico y funcional.

---

## 👤 Autor
**Nahuel Cejas**

