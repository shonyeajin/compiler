#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char * argv[]){



		int c;
		while(1){

				c=getchar();

				switch(c){
						case 48 ... 57:
							   printf("number\n");
							   printf("%d\n",c-'0');
							   break;
						case '+':
							   printf("plus\n");
							   break;
						case '*':
							   printf("star\n");
							   break;
						case '(':
							   printf("LP\n");
							   break;
						case ')':
							   printf("RP\n");
							   break;
						case EOF:
							   printf("eof\n");
							   break;
						case '\n':
							   break;
						default:
							   printf("null\n");
							   break;


				}



		}

		return 0;


}
