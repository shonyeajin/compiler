#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char * argv[]){

		char numbuf[100];
		memset(numbuf,0,sizeof(numbuf));
		printf("%s\n",numbuf);
		

		numbuf[0]='1';
		numbuf[1]='2';
		numbuf[2]='.';
		numbuf[3]='2';
		printf("%ld\n",strlen(numbuf));
		
		printf("%*.*f\n",(int)(strlen(numbuf)-1),0,atof(numbuf));




/*		char c;
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
*/


		return 0;


}
