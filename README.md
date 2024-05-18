# JSON-Generator-Practica-MongoDB
A simple generator for a MongoDB lab project for university, written in C. Nothing fancy this time.
The objective is to generate automatically some data for a MongoDB database to perform some queries.
It was required to have over 100 entries for that lab, and I didn't feel like manually generating them, so I did a little automation.

# Compilation
To use this, you simply need to compile the program "generador.c"
``gcc generador.c -o generator`` will compile the program to the executable file "generator".

# Usage
To use this program, you simply need to run it from the command line and specify the amount of JSON files you want to generate.

There is also a flag to specify whether you want to store each generated entry within its own individual file, or if you want to store all entries within the same file. This option is added for ease of importing within other software, making it easier to batch import data. The flag takes the values 0 (1 file for each entry) and 1 (all entries within the same file).


Example command to generate 100 entries and store them each within their own JSON file:
``./generator 100 0`` will generate 100 JSON files within the folders ``./jugadores`` and ``./partidos``. These folders are relative to the path from which you execute the program.
