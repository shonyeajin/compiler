%{
		extern int line_no;
%}
%start program
%token DOTDOTDOT OROR ANDAND EQUALEQUAL NOTEQUAL RIGHTSIGN LEFTSIGN RIGHTEQUALSIGN LEFTEQUALSIGN DIVID MOD AND EXCLAM MINUS PLUS SIZEOF_SYM LP LLP LLLP RP RRP RRRP DOT ARROW PLUSPLUS MINUSMINUS INTEGER_CONSTANT FLOAT_CONSTANT CHARACTER_CONSTANT STRING_LITERAL RETURN_SYM CONTINUE_SYM BREAK_SYM WHILE_SYM DO_SYM FOR_SYM IF_SYM ELSE_SYM SWITCH_SYM DEFAULT_SYM CASE_SYM COLON IDENTIFIER TYPE_IDENTIFIER SEMI_COLON COMMA EQUAL AUTO_SYM STATIC_SYM TYPEDEF_SYM STRUCT_SYM UNION_SYM ENUM_SYM STAR
%%
program: 
						translation_unit 
						;
translation_unit: 
						external_declaration 
						| translation_unit external_declaration 
						;
external_declaration: 
						function_definition 
						| declaration 
						;
function_definition: 
						declaration_specifiers declarator compound_statement
						| declarator compound_statement 
						;
declaration: 
						declaration_specifiers SEMI_COLON 
						| declaration_specifiers init_declarator_list SEMI_COLON 
						;
declaration_specifiers: 
						type_specifier 
						| storage_class_specifier 
						| type_specifier declaration_specifiers 
						| storage_class_specifier declaration_specifiers 
						;
storage_class_specifier:
						AUTO_SYM 
						| STATIC_SYM 
						| TYPEDEF_SYM 
						;
init_declarator_list:
						init_declarator 
						| init_declarator_list COMMA init_declarator 
						;
init_declarator : 
						declarator 
						| declarator EQUAL initializer 
						;
type_specifier : 
						struct_specifier 
						| enum_specifier 
						| TYPE_IDENTIFIER 
						;
struct_specifier : 
						struct_or_union IDENTIFIER LLP struct_declaration_list RRP
						| struct_or_union LLP struct_declaration_list RRP
						| struct_or_union IDENTIFIER 
						;
struct_or_union: 
						STRUCT_SYM 
						| UNION_SYM 
						;
struct_declaration_list: 
						struct_declaration 
						| struct_declaration_list struct_declaration 
						;
struct_declaration: 
						type_specifier struct_declarator_list SEMI_COLON 
						;
struct_declarator_list: 
						struct_declarator 
						| struct_declarator_list COMMA struct_declarator 
						;
struct_declarator: 
						declarator 
						;
enum_specifier: 
						ENUM_SYM IDENTIFIER LLP enumerator_list RRP 
						| ENUM_SYM LLP enumerator_list RRP
						| ENUM_SYM IDENTIFIER 
						;
enumerator_list: 
						enumerator 
						| enumerator_list COMMA enumerator 
						;
enumerator: 
						IDENTIFIER 
						| IDENTIFIER EQUAL constant_expression 
						;
declarator: 
						pointer direct_declarator 
						| direct_declarator 
						;
pointer: 
						STAR 
						| STAR pointer 
						;
direct_declarator: 
						IDENTIFIER 
						| LP declarator RP 
						| direct_declarator LLLP constant_expression_opt RRRP 
						| direct_declarator LP parameter_type_list_opt RP 
						;
constant_expression_opt: 
						constant_expression 
						;
parameter_type_list_opt: 
						parameter_type_list 
						;
parameter_type_list: 
						parameter_list 
						| parameter_list COMMA DOTDOTDOT 
						;
parameter_list:
						parameter_declaration 
						| parameter_list COMMA parameter_declaration 
						;
parameter_declaration: 
						declaration_specifiers declarator 
						| declaration_specifiers abstract_declarator
						| declaration_specifiers 
						;
abstract_declarator: 
						pointer 
						| direct_abstract_declarator 
						| pointer direct_abstract_declarator 
						;
direct_abstract_declarator: 
						LP abstract_declarator RP 
						| LLLP constant_expression_opt RRRP
						| LP parameter_type_list_opt RP 
						| direct_abstract_declarator LLLP constant_expression_opt RRRP
						| direct_abstract_declarator LP parameter_type_list_opt RP 
						;
initializer: 
						constant_expression 
						| LLP initializer_list RRP 
						;
initializer_list:
						initializer 
						| initializer_list COMMA initializer 
						;
statement:
						labeled_statement 
						| compound_statement 
						| expression_statement 
						|selection_statement
						| iteration_statement 
						| jump_statement 
						;
labeled_statement: 
						CASE_SYM constant_expression COLON statement
						| DEFAULT_SYM COLON statement
						| IDENTIFIER COLON statement 
						;
compound_statement: 
						LLP declaration_list statement_list RRP 
						;
declaration_list: 
						declaration_list declaration 
						;
statement_list:
						statement_list statement 
						;
expression_statement:
						SEMI_COLON 
						| expression SEMI_COLON 
						;
selection_statement: 
						IF_SYM LP expression RP statement
						| IF_SYM LP expression RP statement ELSE_SYM statement
						| SWITCH_SYM LP expression RP statement 
						;
iteration_statement: 
						WHILE_SYM LP expression RP statement
						| DO_SYM statement WHILE_SYM LP expression RP SEMI_COLON
						| FOR_SYM LP expression_opt SEMI_COLON expression_opt SEMI_COLON expression_opt RP statement 
						;
expression_opt:
						expression 
						;
jump_statement:
						RETURN_SYM expression_opt SEMI_COLON
						| CONTINUE_SYM SEMI_COLON
						| BREAK_SYM SEMI_COLON 
						;
primary_expression:
						IDENTIFIER 
						| INTEGER_CONSTANT 
						| FLOAT_CONSTANT 
						| CHARACTER_CONSTANT 
						| STRING_LITERAL
						| LP expression RP 
						;
postfix_expression:
						primary_expression 
						| postfix_expression LLLP expression RRRP
						| postfix_expression LP arg_expression_list_opt RP
						| postfix_expression DOT IDENTIFIER
						| postfix_expression ARROW IDENTIFIER
						| postfix_expression PLUSPLUS
						| postfix_expression MINUSMINUS 
						;
arg_expression_list_opt:
						arg_expression_list 
						;
arg_expression_list: 
						assignment_expression 
						| arg_expression_list COMMA assignment_expression 
						;
unary_expression: 
						postfix_expression
						| PLUSPLUS unary_expression
						| MINUSMINUS unary_expression
						| AND cast_expression
						| STAR cast_expression
						| EXCLAM cast_expression
						| MINUS cast_expression
						| PLUS cast_expression
						| SIZEOF_SYM unary_expression
						| SIZEOF_SYM LP type_name RP 
						;
cast_expression: 
						unary_expression 
						| LP type_name RP cast_expression 
						;
type_name:
						declaration_specifiers 
						| declaration_specifiers abstract_declarator 
						;
multiplicative_expression:
						cast_expression 
						| multiplicative_expression STAR cast_expression
						| multiplicative_expression DIVID cast_expression
						| multiplicative_expression MOD cast_expression 
						;
additive_expression:
						multiplicative_expression
						| additive_expression PLUS multiplicative_expression
						| additive_expression MINUS multiplicative_expression 
						;
relational_expression: 
						additive_expression
						| relational_expression RIGHTSIGN additive_expression
						| relational_expression LEFTSIGN additive_expression		
						| relational_expression RIGHTEQUALSIGN additive_expression
						| relational_expression LEFTEQUALSIGN additive_expression 
						;
equality_expression: 
						relational_expression
						| equality_expression EQUALEQUAL relational_expression 
						| equality_expression NOTEQUAL relational_expression 
						;
logical_and_expression: 
						equality_expression
						| logical_and_expression ANDAND equality_expression 
						;
logical_or_expression: 
						logical_and_expression
						| logical_or_expression OROR logical_and_expression 
						;
assignment_expression: 
						logical_or_expression 
						| unary_expression EQUAL assignment_expression 
						;
constant_expression: 
						expression 
						;
expression: 
						assignment_expression 
						;
%%

extern char *yytext;
yyerror(char *s){
		printf("line %d: %s near %s\n",line_no,s,yytext);
}
main(){
		yyparse();
}

