int func(int a){
		a--;
		printf("%d\n",a);
		if(a>10)
				func(a);
}
int main(){
		func(20);
}
