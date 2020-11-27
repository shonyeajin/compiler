int kim=10+20;
float *park[3];
typedef struct s1 {
		char *name;
		int value;
} STR;
STR chang[5];
enum e1 {red=10,green,blue} song;
int fun(int x, int y){
		int z;
		z=0;
		while(y>0){
				if(y%2)
						z=z+x;
				x=x*2;
				y=y/2;
				if(x==1)
						continue;
		}
		return z;
}

void main(){
		int result;
		result=fun(kim,7);
}

