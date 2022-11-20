/* front.c - a lexical analyzer system for simple
 arithmetic expressions */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

class LexAnalyzer
{
public:
    /* Global declarations */
    /* Variables */
    int charClass;
    char lexeme[100];
    char nextChar;
    int lexLen;
    int token;
    int nextToken;
    FILE *in_fp;

/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNDERSCORE 2
#define UNKNOWN 99

/* Token codes */
#define INT_LIT 10
#define IDENT 11
#define WHILE 13
#define IF 14
#define ELSE 15
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26
#define MODULUS 27
#define LESS_THAN 28
#define GREATER_THAN 29
#define LESS_EQUAL 30
#define GREATER_EQUAL 31
#define EQUAL_TO 32
#define NOT_EQUAL 33
#define EOL 35
#define SPACE 36
#define BEGIN 37
#define END 38
#define LEFT_BRACE 40
#define RIGHT_BRACE 41
#define VARIABLE 42

#define BYTE 43
#define INT 44
#define FLOAT 45
#define DOUBLE 46

    /******************************************************/
    /* lookup - a function to look up operators and
     parentheses and return the token */
    int lookup(char ch)
    {
        switch (ch)
        {
        case '(':
            addChar();
            nextToken = LEFT_PAREN;
            break;
        case ')':
            addChar();
            nextToken = RIGHT_PAREN;
            break;
        case '{':
            addChar();
            nextToken = LEFT_BRACE;
            break;
        case '}':
            addChar();
            nextToken = RIGHT_BRACE;
            break;
        case '+':
            addChar();
            nextToken = ADD_OP;
            break;
        case '-':
            addChar();
            nextToken = SUB_OP;
            break;
        case '*':
            addChar();
            nextToken = MULT_OP;
            break;
        case '/':
            addChar();
            nextToken = DIV_OP;
            break;
        case '%':
            addChar();
            nextToken = MODULUS;
            break;
        case '=':
            addChar();
            nextToken = ASSIGN_OP;
            break;
        case '<':
            addChar();
            nextToken = LESS_THAN;
            break;
        case '>':
            addChar();
            nextToken = GREATER_THAN;
            break;
        case '!': // not equal to
            addChar();
            nextToken = NOT_EQUAL;
            break;
        case '#': // less than equal to
            addChar();
            nextToken = LESS_EQUAL;
            break;
        case '^': // greater than equal to
            addChar();
            nextToken = GREATER_EQUAL;
            break;
        case '@': // equal to
            addChar();
            nextToken = EQUAL_TO;
            break;
        case ';': // end of line
            addChar();
            nextToken = EOL;
            break;
        default:
            addChar();
            nextToken = EOF;
            break;
        }
        return nextToken;
    }

    /******************************************************/
    /* addChar - a function to add nextChar to lexeme */
    void addChar(void)
    {
        if (lexLen <= 98)
        {
            lexeme[lexLen++] = nextChar;
            lexeme[lexLen] = '\0';
        }
        else
            printf("ERROR - lexeme is too long \n");
    }

    /******************************************************/
    /* getChar - a function to get the next character of
     input and determine its character class */
    void getChar(void)
    {
        if ((nextChar = getc(in_fp)) != EOF)
        {
            if (isalpha(nextChar))
                charClass = LETTER;
            else if (nextChar == '_')
                charClass = UNDERSCORE;
            else if (isdigit(nextChar))
                charClass = DIGIT;
            else
                charClass = UNKNOWN;
        }
        else
            charClass = EOF;
    }

    /******************************************************/
    /* getNonBlank - a function to call getChar until it
     returns a non-whitespace character */
    void getNonBlank(void)
    {
        while (isspace(nextChar))
            getChar();
    }

    /******************************************************/
    /* lex - a simple lexical analyzer for arithmetic
     expressions */
    int lex(void)
    {
        lexLen = 0;
        getNonBlank();
        switch (charClass)
        {
        case UNDERSCORE:
            addChar();
            getChar();
            break;
            /* Identifiers */
        case LETTER:
            addChar();
            getChar();
            while (charClass == LETTER || charClass == UNDERSCORE && (lexLen >= 6 || lexLen <= 8))
            {
                addChar();
                getChar();
            }
            if (!strcmp(lexeme, "whale"))
                nextToken = WHILE;
            else if (!strcmp(lexeme, "iguana"))
                nextToken = IF;
            else if (!strcmp(lexeme, "elephant"))
                nextToken = ELSE;
            else if (!strcmp(lexeme, "begin"))
                nextToken = BEGIN;
            else if (!strcmp(lexeme, "end"))
                nextToken = END;
            else if (!strcmp(lexeme, "temp"))
                nextToken = VARIABLE;
            else if (lexLen >= 6 && lexLen <= 8)
                nextToken = IDENT;
            else
                nextToken = UNKNOWN;
            break;

        /* Integer literals */
        case DIGIT:
            addChar();
            getChar();
            while (charClass == DIGIT || charClass == LETTER || charClass == UNDERSCORE)
            {
                addChar();
                getChar();
            }
            if (lexeme[strlen(lexeme) - 1] == 'b')
                nextToken = BYTE;
            else if (lexeme[strlen(lexeme) - 1] == 'i')
                nextToken = INT;
            else if (lexeme[strlen(lexeme) - 1] == 'f')
                nextToken = FLOAT;
            else if (lexeme[strlen(lexeme) - 1] == 'd')
                nextToken = DOUBLE;
            else if (charClass == UNKNOWN)
                nextToken = UNKNOWN;
            break;
        /* Parentheses and operators */
        case UNKNOWN:
            lookup(nextChar);
            getChar();
            break;
            /* EOF */
        case EOF:
            nextToken = EOF;
            lexeme[0] = 'E';
            lexeme[1] = 'O';
            lexeme[2] = 'F';
            lexeme[3] = '\0';
            break;
        } /* End of switch */
        if (nextToken == 99 || (nextToken == -1 && charClass != -1))
            printf("ERROR - Token is not recognized within the language.\n");
        else
            printf("Next token is: %d, Next lexeme is %s\n",
                   nextToken, lexeme);
        return nextToken;
    } /* End of function lex */
};
/******************************************************/
/* main driver */
int main(void)
{
    LexAnalyzer lexObject;
    /* Open the input data file and process its contents */
    if ((lexObject.in_fp = fopen("front4.in", "r")) == NULL)
        printf("ERROR - cannot open front.in \n");
    else
    {
        lexObject.getChar();
        do
        {
            lexObject.lex();
        } while (lexObject.nextToken != EOF && lexObject.nextToken != UNKNOWN);
    }
    return 0;
}