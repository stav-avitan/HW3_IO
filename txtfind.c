#include<stdio.h>
#include<string.h>

#define LINE 256
#define WORD 30

int getline(char s[]);
int getword(char w[]);
int substring(char* str1, char* str2);
int similar(char* s, char* t, int n);
void print_lines(char* str);
void print_similar_words(char* str);


int main()
{
    char choise;
    char input[WORD] = { 0 };

    scanf("%c\n", &choise);

    if (choise == 'a')
    {
        print_lines(&input);
    }
    else if (choise == 'b')
    {
        print_similar_words(&input);
    }

    return 0;
}

int getline(char s[])
{

    int numOfLetters = 0;
    int index = 0;

    gets(s, sizeof(LINE), stdin);

    while (s[index] != NULL)
    {
        index++;
        numOfLetters++;
    }

    return numOfLetters;
}

int getword(char w[])
{
    int numOfLetters = 0;
    int index = 0;

    scanf("%s", w);

    while (w[index] != NULL)
    {
        index++;
        numOfLetters++;
    }

    return numOfLetters;
}

int substring(char* str1, char* str2)
{
    //remember to check if word ends with \n

    if (strstr(str1, str2) != NULL || strstr(str2, str1) != NULL) {
        return 1;
    }


    return 0;
}

int similar(char* s, char* t, int n)
{
    int len_s = strlen(s);
    int len_t = strlen(t);
    int temp;
    char* strTemp;
    int i, j = 0;
    int similar = 0;

    if (len_s > len_t) {
        strTemp = t;
        t = s;
        s = strTemp;
        temp = len_s;
        len_s = len_t;
        len_t = temp;
    }

    if ((len_t - len_s) > n) {
        return 0;
    }

    for (i = 0; i < len_s; i++) {
        for (j = 0; j < len_t; j++) {
            if (s[i] == t[j]) {
                i++;
                similar++;
            }
        }
    }
    if (similar+n < len_t)
    {
        return 0;
    }
    return 1;
}

void print_lines(char* str)
{
    char line[LINE];

    while (getline(&line) != 0)
    {
        if (substring(&line, str))
        {
            printf("%s", line);
        }
    }
}

void print_similar_words(char* str)
{
    char word[WORD];

    while (getword(&word) != 0)
    {
        if (similar(str, &word,1))
        {
            printf("%s", word);
        }
    }

}