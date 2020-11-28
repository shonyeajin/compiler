//for-continue
int main(){
		int i;
		for(i=0;i<100;i++){
				if(i%5==0)
						continue;
				printf("printf number except multiple of 5:%d\n",i);
		}
		return 0;
}
