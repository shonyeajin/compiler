//함수 재귀호출
int func(int a){
		a--;
		if(a>10)
				func(a);
}
int main(){
		func(20);
}
