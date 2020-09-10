#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

enum {NULL,PLUS,STAR,NUMBER,LPAREN,RPAREN,END} token;
void get_token(){
//token=next token of input
}

void expression(){
		term();
		while(token==PLUS){
				get_token();
				term();

		}


}
void term(){
		factor();
		while(token==STAR){
				get_token();
				factor();

		}


}
void factor(){
		if(token==NUMBER){
				get_token();

		}else if(token==LRAREN){
				get_token();
				expression();
				if(token==RPAREN){
						get_token();

				}else{
						error();

				}


		}else{
				error();
		}

}
int main(){
		get_token();
		expression();
		if(token!=END)
				error();

}

error(){
//error handling
}
