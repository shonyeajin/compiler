//scope rule test

int global=0;

int main(){
		int local;
		for(local=0;local<10;local++){
				global++;
				if(global==9){
						int p=1;
				}
		}
}
