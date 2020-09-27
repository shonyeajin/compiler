#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define NUMBER 256
#define STAR 258
#define RPAREN 260
#define EXPRESSION 0
#define FACTOR 2
#define PLUS 257
#define LPAREN 259
#define END 261
#define TERM 1
#define ACC 999


int yyparse();
void shift(int);
void push(int);
void reduce(int);
void yyerror();
int yylex();
void lex_error();

int action[12][6]={
		{5,0,0,4,0,0},{0,6,0,0,0,ACC},{0,-2,7,0,-2,-2},
		{0,-4,-4,0,-4,-4},{5,0,0,4,0,0},{0,-6,-6,0,-6,-6},
		{5,0,0,4,0,0},{5,0,0,4,0,0},{0,6,0,0,11,0},
		{0,-1,7,0,-1,-1},{0,-3,-3,0,-3,-3},{0,-5,-5,0,-5,-5}
		};

int go_to[12][3]={
		{1,2,3},{0,0,0},{0,0,0},{0,0,0},{8,2,3},{0,0,0},
		{0,9,3},{0,0,10},{0,0,0},{0,0,0},{0,0,0},{0,0,0}
		};

int prod_left[7]={0,EXPRESSION,EXPRESSION,TERM,TERM,FACTOR,FACTOR};
int prod_length[7]={0,3,1,3,1,3,1};

typedef enum {INT_VAL,ADD,MUL} NODE_NAME;
typedef struct node {
		NODE_NAME name;
		int val;
		struct node *llink,*rlink;
} NODE;
NODE *value[1000];
NODE *makenode(NODE_NAME name, int v, NODE *p, NODE *q){
		NODE *n;
		n=malloc(sizeof(NODE));
		n->name=name;
		n->val=v;
		if(p!=NULL)
				n->llink=p;
		if(q!=NULL)
				n->rlink=q;
		return n;
}

int stack[1000];
//int value[1000];
int top=-1;
int sym;
char yytext[32];
int  yylval;

void print_postfix(NODE *n);

void main(){
		yyparse();
		

}

int yyparse(){
		int i;
		stack[++top]=0;		//initial state
		sym=yylex();
		do{
				i=action[stack[top]][sym-256];	//get relation
				if(i==ACC)
						printf("success !\n");
				else if(i>0) shift(i);		//shift
				else if(i<0) reduce(-i);	//reduce
				else yyerror();
		}
		while (i!=ACC);
		
		print_postfix(value[top]);
		printf("\n");

}

void print_postfix(NODE *n){
		if(n->val==0){
				print_postfix(n->llink);
				print_postfix(n->rlink);
				char opt[10];
				switch(n->name){
						case 0:
								strcpy(opt,"INT_VAL");
								break;
						case 1:
								strcpy(opt,"ADD");
								break;
						case 2:
								strcpy(opt,"MUL");
								break;
				}
				printf("%s ",opt);

		}else{
				printf("%d ",n->val);
		}

}

void push(int i){
		stack[++top]=i;
}

void shift(int i){
		push(i);
		value[top]=makenode(INT_VAL,yylval,NULL,NULL);
		//value[top]=yylval;
		sym=yylex();
}

void reduce(int i){
		int old_top;
		top-=prod_length[i];
		old_top=top;
		push(go_to[stack[old_top]][prod_left[i]]);

		switch(i){//생성 규칙번호에 따른 수식 값 계산
				case 1:
						value[top]=makenode(ADD,0,value[old_top+1],value[old_top+3]);
						break;
				case 2:
						value[top]=value[old_top+1];
						break;
				case 3:
						value[top]=makenode(MUL,0,value[old_top+1],value[old_top+3]);
						break;
				case 4:
						value[top]=value[old_top+1];
						break;
				case 5:
						value[top]=value[old_top+2];
						break;
				case 6:
						value[top]=makenode(INT_VAL,value[old_top+1]->val,NULL,NULL);
						break;
				default:
						yyerror("parsing table error\n");
						break;

		}
}

void yyerror(){
		printf("syntax error\n");
		exit(1);
}

int yylex(){

		static char ch=' ';
		int i=0;
		while(ch==' '||ch=='\t'){
				ch=getchar();
		}
		if(isdigit(ch)){
				do{
						yytext[i++]=ch;
						ch=getchar();
				}while(isdigit(ch));
				yytext[i]=0;
				yylval=atoi(yytext);
				return(NUMBER);
		}
		else if(ch=='+'){ch=getchar(); return(PLUS);}
		else if(ch=='*'){ch=getchar(); return(STAR);}
		else if(ch=='('){ch=getchar(); return(LPAREN);}
		else if(ch==')'){ch=getchar(); return(RPAREN);}
		else if(ch=='\n'){return(END);}
		else lex_error();

}


void lex_error(){
		printf("illegal token\n");
		exit(1);
}


