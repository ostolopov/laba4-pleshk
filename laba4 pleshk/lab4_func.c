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

void change_min_max1 (void)
{
    char *str = readline(PROMPT);
    char *str_copy = strdup(str);
    int arr_size = 0;
    
    //char *max_word = NULL;
    //char *min_word = NULL;
    int min_word_size = 0;
    int max_word_size = 0;
    char *word = strtok(str_copy, " ");
    while (word != NULL)
    {
        arr_size++;
        word = strtok(NULL, " ");
    }
    
    
    
    
    free(str);
}



void change_min_max(void)
{
    char *str = readline(PROMPT);
    char *str_copy = strdup(str);
    char *min_word = NULL;
    char *max_word = NULL;
    int min_length = INT_MAX;
    int max_length = 0;

    char *word = strtok(str_copy, " ");
    while (word != NULL)
    {
        int word_length = (int)strlen(word);
        if (word_length < min_length)
        {
            min_length = word_length;
            min_word = word;
        }
        if (word_length > max_length)
        {
            max_length = word_length;
            max_word = word;
        }
        word = strtok(NULL, " ");
    }

    if (min_word && max_word)
    {
        char *temp = strdup(max_word);
        char *new_str = malloc((strlen(str) + 1) * sizeof(char));
        new_str[0] = '\0';
        word = strtok(str, " ");
        while (word != NULL)
        {
            if (strcmp(word, max_word) == 0)
            {
                strcat(new_str, min_word);
            }
            else if (strcmp(word, min_word) == 0)
            {
                strcat(new_str, temp);
            }
            else
            {
                strcat(new_str, word);
            }
            strcat(new_str, " ");
            word = strtok(NULL, " ");
        }
        printf("%s\n", new_str);
        free(new_str);
        free(temp);
    }
    free(str_copy);
    free(str);
}

void max_word_with_letters(void)
{
    char *str = readline(PROMPT);
    char *str_copy = strdup(str);
    char *max_word = NULL;
    int max_length = 0;
    char *word = strtok(str_copy, " ");
    while (word != NULL)
    {
        int flag = 1;
        int word_length = (int)strlen(word);
        for (int i = 0; i < word_length; i++)
        {
            for (int j = i + 1; j < word_length; j++)
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
        if (flag == 1 && word_length > max_length)
        {
            max_length = word_length;
            max_word = word;
        }
        word = strtok(NULL, " ");
    }
    if (max_word)
        printf("%s\n", max_word);
    free(str_copy);
    free(str);
}


void vowel_letter(void)
{
    char *str = readline(PROMPT);
    char *str_copy = strdup(str);
    char vowels[] = "eyuioaEYUIOA";
    char *word = strtok(str_copy, " ");
    while (word != NULL)
    {
        int vowel_count = 0;
        for (int i = 0; i < (int)strlen(word); i++)
        {
            if (strchr(vowels, word[i]) != NULL)
            {
                vowel_count++;
            }
        }
        if (vowel_count > 2)
        {
            printf("%s\n", word);
        }
        word = strtok(NULL, " ");
    }
    free(str_copy);
    free(str);
}

void palinom_index(void)
{
    char *str = readline(PROMPT);
    char *str_copy = strdup(str);
    int max_length = 0;
    int max_index = -1;
    int index = 1;
    char *word = strtok(str_copy, " ");
    while (word != NULL)
    {
        int word_length = (int)strlen(word);
        int is_palindrome = 1;

        for (int i = 0, j = word_length - 1; i < j; i++, j--)
        {
            if (word[i] != word[j])
            {
                is_palindrome = 0;
                break;
            }
        }
        if (is_palindrome && word_length > max_length)
        {
            max_length = word_length;
            max_index = index;
        }

        word = strtok(NULL, " ");
        index++;
    }
    if (max_index != -1)
        printf("%d\n", max_index);
    else
        printf("Такова нетъ");
    free(str_copy);
    free(str);
}


void delete_palinom(void)
{
    char *str = readline(PROMPT);
    char *str_copy = strdup(str);
    int max_length = 0;
    char *word = strtok(str_copy, " ");
    while (word != NULL)
    {
        int word_length = (int)strlen(word);
        int is_palindrome = 1;
        for (int i = 0, j = word_length - 1; i < j; i++, j--)
        {
            if (word[i] != word[j])
            {
                is_palindrome = 0;
                break;
            }
        }
        if (is_palindrome && word_length > max_length)
        {
            max_length = word_length;
        }
        word = strtok(NULL, " ");
    }
    char *result = strdup(str);
    result[0] = '\0';
    word = strtok(str, " ");
    while (word != NULL)
    {
        int word_length = (int)strlen(word);
        int is_palindrome = 1;

        for (int i = 0, j = word_length - 1; i < j; i++, j--)
        {
            if (word[i] != word[j])
            {
                is_palindrome = 0;
                break;
            }
        }
        if (!(is_palindrome && word_length == max_length))
        {
            strcat(result, word);
            strcat(result, " ");
        }
        word = strtok(NULL, " ");
    }
    printf("%s\n", result);
    free(str_copy);
    free(result);
    free(str);
}

