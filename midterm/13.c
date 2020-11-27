//do-while-break
int main(){
		int i=0;

		do{
				printf("current i value:%d\n",i);
				i++;
				if(i%11==0)
						break;
		}while(i<100);

		return 0;
}
