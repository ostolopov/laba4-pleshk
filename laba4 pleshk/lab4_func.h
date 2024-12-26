#ifndef lab4_func_h
#define lab4_func_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <wchar.h>
#include <readline/readline.h>
#include <limits.h>


#define PROMPT "> "

int get_int(int *number, int min, int max);
void words_with_letters (void);
void delete_words (void);
void mass_words (void);
void mass_index (void);
void replace_words_i_j (void);

#endif
