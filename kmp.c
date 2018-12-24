#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int * get_partial_match_table(char *substr, char *source, int substr_len){
    int len = 0, i = 1;
    int *partial_match_table = malloc(sizeof(int) * (strlen(source) + 1));
    partial_match_table[0] = 0;

    while (i < substr_len){
        if (substr[i] == substr[len]){
            len++;
            partial_match_table[i] = len;
            i++;
        }else{
            if (len){
                len = partial_match_table[len - 1];
            }else{
                partial_match_table[i] = 0;
                i++;
            }
        }
    }
    return partial_match_table;
}

int kmp (char *substr, char *source){
    int j = 0,
        i = 0,
        num_occurences = 0,
        substr_len = strlen (substr),
        source_len = strlen (source);
    int *partial_match_table = get_partial_match_table (substr, source, substr_len);
    while (i < source_len){
        if (substr[j] == source[i]){
            j++;
            i++;
        }

        if (j == substr_len){
            /* We just had an occurence at index i - j */
            num_occurences++;
            j = partial_match_table[j - 1];
        }else if (substr[j] != source[i]){
            if (j != 0)
                j = partial_match_table[j - 1];
            else
                i = i + 1;
        }
    }

    free(partial_match_table);

    return num_occurences;
}

int kmp_bounded (char *substr, char *source, int end){
    int j = 0,
        i = 0,
        num_occurences = 0,
        substr_len = strlen (substr),
        source_len = end;
    int *partial_match_table = get_partial_match_table (substr, source, substr_len);
    while (i < source_len){
        if (substr[j] == source[i]){
            j++;
            i++;
        }

        if (j == substr_len){
            /* We just had an occurence at index i - j */
            num_occurences++;
            j = partial_match_table[j - 1];
        }else if (substr[j] != source[i]){
            if (j != 0)
                j = partial_match_table[j - 1];
            else
                i = i + 1;
        }
    }

    free(partial_match_table);

    return num_occurences;
}