/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SINT_TAB_H_INCLUDED
# define YY_YY_SINT_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    NUMBER = 259,                  /* NUMBER  */
    STRING_LITERAL = 260,          /* STRING_LITERAL  */
    OP_ADD = 261,                  /* OP_ADD  */
    OP_SUB = 262,                  /* OP_SUB  */
    OP_MUL = 263,                  /* OP_MUL  */
    OP_DIV = 264,                  /* OP_DIV  */
    OP_ASSIGN = 265,               /* OP_ASSIGN  */
    OP_EQUAL = 266,                /* OP_EQUAL  */
    OP_NEQUAL = 267,               /* OP_NEQUAL  */
    OP_LESS = 268,                 /* OP_LESS  */
    OP_GREATER = 269,              /* OP_GREATER  */
    OP_ELESS = 270,                /* OP_ELESS  */
    OP_EGREATER = 271,             /* OP_EGREATER  */
    OP_AND = 272,                  /* OP_AND  */
    OP_OR = 273,                   /* OP_OR  */
    OP_NOT = 274,                  /* OP_NOT  */
    IF = 275,                      /* IF  */
    ELSE = 276,                    /* ELSE  */
    WHILE = 277,                   /* WHILE  */
    DO = 278,                      /* DO  */
    FOR = 279,                     /* FOR  */
    BREAK = 280,                   /* BREAK  */
    CONTINUE = 281,                /* CONTINUE  */
    RETURN = 282,                  /* RETURN  */
    LPAREN = 283,                  /* LPAREN  */
    RPAREN = 284,                  /* RPAREN  */
    LBRACKET = 285,                /* LBRACKET  */
    RBRACKET = 286,                /* RBRACKET  */
    LBRACE = 287,                  /* LBRACE  */
    RBRACE = 288,                  /* RBRACE  */
    SEMICOLON = 289,               /* SEMICOLON  */
    COMMA = 290,                   /* COMMA  */
    VOID = 291,                    /* VOID  */
    CHAR = 292,                    /* CHAR  */
    INT = 293,                     /* INT  */
    FLOAT = 294,                   /* FLOAT  */
    DOUBLE = 295                   /* DOUBLE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SINT_TAB_H_INCLUDED  */
