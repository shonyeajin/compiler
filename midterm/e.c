
int forFunc(int i){
		int x=0;
		int y=20;
		while (x<10) x++;
		for(i;i<10;i++){
				y--;
				if(y==5)
						continue;
		}

		return x+y;
}

