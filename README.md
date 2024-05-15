# JSON-Generator-Practica-MongoDB
A simple generator for a MongoDB lab project for university, written in C. Nothing fancy this time.
The objective is to generate automatically some data for a MongoDB database to perform some queries.
It was required to have over 100 entries for that lab, and I didn't feel like manually generating them, so I did a little automation.

# Compilation
To use this, you simply need to compile the program "generador.c"
``gcc generador.c -o generator`` will compile the program to the executable file "generator".

# Usage
To use this program, you simply need to run it from the command line and specify the amount of JSON files you want to generate.
``./generator 100`` will generate 100 JSON files within the folders ``./jugadores`` and ``./partidos``.
