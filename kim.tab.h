/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_KIM_TAB_H_INCLUDED
# define YY_YY_KIM_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DOTDOTDOT = 258,
    OROR = 259,
    ANDAND = 260,
    EQUALEQUAL = 261,
    NOTEQUAL = 262,
    RIGHTSIGN = 263,
    LEFTSIGN = 264,
    RIGHTEQUALSIGN = 265,
    LEFTEQUALSIGN = 266,
    DIVID = 267,
    MOD = 268,
    AND = 269,
    EXCLAM = 270,
    MINUS = 271,
    PLUS = 272,
    SIZEOF_SYM = 273,
    LP = 274,
    LLP = 275,
    LLLP = 276,
    RP = 277,
    RRP = 278,
    RRRP = 279,
    DOT = 280,
    ARROW = 281,
    PLUSPLUS = 282,
    MINUSMINUS = 283,
    INTEGER_CONSTANT = 284,
    FLOAT_CONSTANT = 285,
    CHARACTER_CONSTANT = 286,
    STRING_LITERAL = 287,
    RETURN_SYM = 288,
    CONTINUE_SYM = 289,
    BREAK_SYM = 290,
    WHILE_SYM = 291,
    DO_SYM = 292,
    FOR_SYM = 293,
    IF_SYM = 294,
    ELSE_SYM = 295,
    SWITCH_SYM = 296,
    DEFAULT_SYM = 297,
    CASE_SYM = 298,
    COLON = 299,
    IDENTIFIER = 300,
    TYPE_IDENTIFIER = 301,
    SEMI_COLON = 302,
    COMMA = 303,
    EQUAL = 304,
    AUTO_SYM = 305,
    STATIC_SYM = 306,
    TYPEDEF_SYM = 307,
    STRUCT_SYM = 308,
    UNION_SYM = 309,
    ENUM_SYM = 310,
    STAR = 311
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_KIM_TAB_H_INCLUDED  */
