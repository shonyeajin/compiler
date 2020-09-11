#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


double expression();
void get_token();
double term();
double factor();
void error();


char num;
enum Token {_NULL,PLUS,MINUS,DIV,DOT,STAR,NUMBER,LP,RP,END};
enum Token token;
char numbuf[100];
int numIdx=0;
int isInt=1;

void  main(){
		double result;
		memset(numbuf,0,sizeof(numbuf));
		get_token();
		result=expression();
		if(token!=END)
				error(3);
		else{
				if(isInt)
						printf("%d\n",(int)result);
				else
						printf("%f\n",result);

		}

}





double expression(){
		double result;
		result=term();
		while(token==PLUS){
				get_token();
				result=result+term();
		}
		return(result);


}



void get_token(){
//token 이면 token에 num이면 num에
//next token-->token
//number value-->num
//token=next token of input
//한 글자 가져와서 그게 enum의 어디에 속하는지 검사하고 그거를 token에 값 대입
char c;
c=getchar();
switch(c){
		case 48 ... 57:
			   num=c;
			   token=NUMBER;
			   break;
		case '+':
			   token=PLUS;
			   break;
		case '-':
			   token=MINUS;
			   break;
		case '*':
			   token=STAR;
			   break;
		case '/':
			   token=DIV;
			   break;
		case '(':
			   token=LP;
			   break;
		case ')':
			   token=RP;
			   break;
		case EOF:
			   token=END;
			   break;
		case '.':
			   token=DOT;
			   break;
		case '\n':
			   token=END;
			   break;
		default:
			   token=_NULL;




}




}

double term(){
		double result;
		result=factor();
		while(token==STAR){
				get_token();
				result=result*factor();
		}
		return(result);
}

double factor(){
		double result;

		//result=num;
		//get_token();
		//한자리 이상 숫자 처리
		if(token==NUMBER){
				numbuf[numIdx]=num;
				get_token();
				
				while(token==NUMBER){
						numbuf[++numIdx]=num;
						get_token();
				}
				if(token==DOT){
						isInt=0;
						numbuf[++numIdx]='.';
						get_token();

						while(token==NUMBER){
								numbuf[++numIdx]=num;
								get_token();
						}

				}
				result=atof(numbuf);
				memset(numbuf,0,sizeof(numbuf));
				numIdx=0;

				



		}else if(token==LP){
				get_token();
				result=expression();
				if(token==RP){
						get_token();

				}else{
						error(2);

				}


		}else{
				error(1);
		}

		return(result);
}


void error(int i){
//error handling
		switch(i){
				case 1: printf("error 1\n");
						break;
				case 2: printf("error 2\n");
						break;
				case 3: printf("error 3\n");
						break;
		}
		exit(1);



}
