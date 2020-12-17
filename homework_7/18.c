//struct member reference
typedef struct person{
		char *name;
		int age;
}p;


int main(){
	p p1;
	char *pname="shonyeajin";
	p1.age++;
	p1.name=pname;
}
