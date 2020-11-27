//parameter passing test
void func(int a, char *b, char **c){
		printf("first argument is %d\n",a);
		printf("second argument is %s\n",b);
		printf("third argument is %s\n",*c);
}

int main(){
		int a=2;
		char *b="hello";
		char *c[10];
		int i;
		for(i=0;i<10;i++)
				c[i]=malloc(sizeof(char));
				*c[i]='a';
		func(a,b,c);
}
