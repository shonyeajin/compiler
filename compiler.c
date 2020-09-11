#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int expression();
void get_token();
int term();
int factor();
void error();


int num;
enum Token {_NULL,PLUS,STAR,NUMBER,LP,RP,END};
enum Token token;


void  main(){
		int result;
		get_token();
		result=expression();
		if(token!=END)
				error(3);
		else
				printf("%d\n",result);

}





int expression(){
		int result;
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
int c;
c=getchar();
switch(c){
		case 48 ... 57:
			   num=c-'0';
			   token=NUMBER;
			   break;
		case '+':
			   token=PLUS;
			   break;
		case '*':
			   token=STAR;
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
		case '\n':
			   token=END;
			   break;
		default:
			   token=_NULL;




}




}

int term(){
		int result;
		result=factor();
		while(token==STAR){
				get_token();
				result=result*factor();
		}
		return(result);
}

int factor(){
		int result;

		if(token==NUMBER){
				result=num;
				get_token();

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
