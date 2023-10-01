#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

const char* program_name;

void print_usage (FILE* stream, int exit_code)
{
fprintf(stream, "Usage: %s options [inputfile ...]\n", program_name);
fprintf(stream,
        "To play, use the keyboard arrows to move the snake.\n"
        "The objective is to collect all the golden apples, good luck!!\n"
        "\n -h --help               Display this message.\n"
        " -o --output filename    Redirect output to a file.\n"
        " -d --debug            Display detailed messages.\n"
        "-i --input               Add a custom map.\n");
  exit (exit_code);
}


