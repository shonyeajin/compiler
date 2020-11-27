char *p1;
char **p2;
char ***p3;

void mallocFunc(){
		p1=malloc(sizeof(char *)*1000);
		*p2=malloc(sizeof(char **)+1000);
		**p3=malloc(sizeof(char ***)*1000);
}

