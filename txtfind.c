#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LINE 256
#define WORD 30

int getLine(char s[]);
int getWord(char w[]);
int substring(char* str1, char* str2);
int similar(char* s, char* t, int n);
void print_lines(char* str);
void print_similar_words(char* str);


int main()
{
    char choise;
    char input[WORD] = { 0 };
    getWord(input);

    scanf("%c\n",&choise);
	
	//printf("test::::::::::%c\n",choise);

    if (choise == 'a')
    {
        print_lines(input);
		//printf("test:::::::::END\n");
    }
    else if (choise == 'b')
    {
        print_similar_words(input);
    }

    return 0;
}

int getLine(char s[])
{
	int i = 0;
	for(i=0; i<LINE; i++)
	{
		if(scanf("%c",&s[i]))
		{
			//printf("test::::::::::%s\n",s);
			if(s[i] == '\n')
			{
				s[i]='\0';
				break;
			}
		}
	}

	if(i == LINE)
	{
		s[LINE-1] = '\0';
	}
	
	
	//printf("test::::::::::%sEND_OF_LINE\n",s);
	return i;
}

int getWord(char w[])
{
	int i = 0;
	for(i=0; i<WORD; i++)
	{
		scanf("%c",&w[i]);
		
		if(w[i] == '\t' || w[i] == ' ' || w[i] == EOF || w[i] == '\n' || w[i] == '\r')
		{
			w[i]='\0';
			break;
		}
	}
	
	if(i == WORD)
	{
		w[WORD-1] = '\0';
	}
	
	//printf("test::::::::::&&&&&&&&&&&&&&&&endofword");
    return i;
}

int substring(char* str1, char* str2)
{
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
    char line[LINE] = {0};
	
	//printf("test::::::::::BEFORE_READING_LINE\n");
    while (getLine(line) != LINE)
    {
		//printf("test::::::::::%s:::::::%s:::::::%d:::eof?%c:::s?%c:\n", line,str,getLine(line),line[strlen(line-1)],line[0]);
		if(line[strlen(line-1)] != EOF && line[0]!='\n')
		{
			
			if (substring(line, str) == 1)
			{
				//printf("test::::::::::&&&&&&&&&&&&&&&&\n");
				//printf("test::::::::::%s", line);
				//printf("test::::::::::$$$$$$$$$$$$$$$$$$$");

				printf("%s\n", line);

			}
		}
		else
		{
			break;
		}
    }
	
	
	//printf("test::::::::::&&&&&&&&&&&&&&&&");
}

void print_similar_words(char* str)
{
    char word[WORD] = {0};
    while (getWord(word) != 30)
    {
		//printf("test::::::::::%s:::::similar?%d:::::::", word, similar(str, word,1));
        if (similar(str, word,1) == 1)
        {			
			//printf("PRINT$$$");
			//word[strcspn(word, "\n")] = 0;
            printf("%s\n", word);
        }
    }
	
	//printf("&&&&&&&&&&&&&&&&");
}