//parameter passing test
void func(int a, char *b, char **c){
		a++;
}

int main(){
		int a=2;
		char *b;
		char *c[10];
		func(a,b,c);
}
