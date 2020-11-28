//struct member reference
typedef struct person{
		char *name;
		int age;
}p;


int main(){
	p p1;
	char *str="shonyeajin";
	p1.age++;
	p1.name=str;
}
