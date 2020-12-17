int gcd(int x, int y){
		int a,b;
		a=x;
		b=y;
		while(a!=b){
				if(a<b)
						b=b-a;
				if(a>b)
						a=a-b;
		}
		return (a);
}
void main(){
		int i;
		i=gcd(84,36);
}
