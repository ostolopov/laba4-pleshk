#include "lab4_func.h"

int get_int(int *number, int min, int max){
        int check = 0, number_check, flag = 0;
        while(flag == 0){
                check = scanf("%d" , &number_check);
                switch(check){
                        case EOF:
                                printf("Работа программы прекращена.\n");
                                flag = 1;
                                break;
                        case 1 :
                                if (number_check < min || number_check > max)
                                {
                                    printf("Число вышло за разрешенный диапазон. Попробуйте еще раз!\n");
                                    scanf("%*[^\n]");
                                    flag = 0;
                                    break;
                                }
                                *number = number_check;
                                scanf("%*[^\n]");
                                flag = 1;
                                break;
                        case 0:
                                printf("Число неверно. Попробуйте еще раз!\n");
                                scanf("%*[^\n]");
                                flag = 0;
                                break;
                        
                }
        }
        return check;
}

void words_with_letters (void)
{
    int count = 0;
    char *str = readline(PROMPT);
    char *word = strtok(str, " ");
    while (word != NULL)
    {
        int word_size = (int) strlen(word);
        //printf("%s   %c   %c\n", word, word[0], word[word_size - 1]);
        if (word[0] == word[word_size - 1])
            count++;
        word = strtok(NULL, " ");
    }
    printf("%d\n", count);
    free(str);
}

/*
void words_with_letters1 (void)
{
    wchar_t buffer[100];
    wchar_t *saveptr;
    int count = 0;
    wchar_t *str = fgetws(buffer, sizeof(buffer)/sizeof(buffer[0]), stdin);
    static wchar_t delimiters[] = L" ";
    wchar_t *word = wcstok(str, delimiters, &saveptr);
    while (word != NULL)
    {
        int word_size = (int) wcslen(word);
        if (word[0] == word[word_size - 1])
            count++;
        word = wcstok(NULL, delimiters, &saveptr);
    }
    printf("%d\n", count);
    //free(str);
}
*/

void delete_words (void)
{
    int count = 0;
    int number = 0;
    printf("Введите: \n");
    int check = get_int(&number, 0, INT_MAX);
    if (check == EOF)
        return;
    char *str = readline(PROMPT);
    char *new_str = malloc((strlen(str) + 1) * sizeof(char));
    new_str[0] = '\0';
    char *word = strtok(str, " ");
    while (word != NULL)
    {
        if (strlen(word) != number)
        {
            if (count > 0)
                strcat(new_str, " ");
            strcat(new_str, word);
            count++;
        }
        word = strtok(NULL, " ");
    }
    printf("%s\n", new_str);
    free(str);
    free(new_str);
}

void mass_words (void)
{
    int arr_place = 0;
    int arr_size = 0;
    char *str = readline(PROMPT);
    char *str_copy = strdup(str);
    char *word = strtok(str_copy, " ");
    while (word != NULL)
    {
        arr_size++;
        word = strtok(NULL, " ");
    }
    char **arr = malloc(arr_size * sizeof(char*));
    word = strtok(str, " ");
    while (word != NULL)
    {
        int flag = 1;
        int word_size = (int)strlen(word);
        for (int i = 0; i < word_size; i++)
        {
            for (int j = i + 1; j < word_size; j++)
            {
                if (word[i] == word[j])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
                break;
        }
        if (flag == 1)
        {
            arr[arr_place] = strdup(word);
            arr_place++;
        }
        word = strtok(NULL, " ");
    }
    arr = realloc(arr, arr_place * sizeof(char*));
    for (int i = 0; i < arr_place; i++)
        printf("%s\n", arr[i]);
    for (int i = 0; i < arr_place; i++)
        free(arr[i]);
    free(str_copy);
    free(arr);
    free(str);
}


void mass_index (void)
{
    int count= 1;
    int arr_place = 0;
    int arr_size = 0;
    char *str = readline(PROMPT);
    char *str_copy = strdup(str);
    char *word = strtok(str_copy, " ");
    while (word != NULL)
    {
        arr_size++;
        word = strtok(NULL, " ");
    }
    int *arr = malloc(arr_size * sizeof(int));
    word = strtok(str, " ");
    while (word != NULL)
    {
        int flag = 1;
        int word_size = (int)strlen(word);
        for (int i = 0; i < word_size; i++)
        {
            for (int j = i + 1; j < word_size; j++)
            {
                if (word[i] == word[j])
                {
                    flag = 0;
                    arr[arr_place] = count;
                    arr_place++;
                    break;
                }
            }
            if (flag == 0)
                break;
        }
        count++;
        word = strtok(NULL, " ");
    }
    arr = realloc(arr, arr_place * sizeof(int));
    for (int i = 0; i < arr_place; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(str_copy);
    free(arr);
    free(str);
}

void replace_words_i_j (void)
{
    int count = 0;
    int arr_size = 0;
    int number1 = 0;
    int number2 = 0;
    char *str = readline(PROMPT);
    char *str_copy = strdup(str);
    char *word = strtok(str_copy, " ");
    while (word != NULL)
    {
        arr_size++;
        word = strtok(NULL, " ");
    }
    char **arr = malloc(arr_size * sizeof(char*));
    printf("Введите первое: \n");
    if (get_int(&number1, 0, arr_size) == EOF)
    {
        free(arr);
        free(str_copy);
        free(str);
        return;
    }
    printf("Введите второе: \n");
    if (get_int(&number2, 0, arr_size) == EOF)
    {
        free(arr);
        free(str_copy);
        free(str);
        return;
    }
    
    word = strtok(str, " ");
    while (word != NULL)
    {
        arr[count] = strdup(word);
        count++;
        word = strtok(NULL, " ");
    }
    
    char *temp = arr[number1 - 1];
    arr[number1 - 1] = arr[number2 - 1];
    arr[number2 - 1] = temp;

    for (int i = 0; i < arr_size; i++)
    {
        strcat(str_copy, arr[i]);
        strcat(str_copy, " ");
        //printf("%s\n", arr[i]);
    }
    printf("%s", str_copy);
    printf("\n");
    for (int i = 0; i < arr_size; i++)
    {
        free(arr[i]);
    }
    //free(temp);
    free(arr);
    free(str_copy);
    free(str);
}

void change_min_max (void)
{
    
}

void max_word_with_letters ()
{
    
}