
int calFunc(int a, int b, int c){

		if(c!=0&&a>0)
				return ((1+a)*(b%3)/c)-2;
		else if(c=0||b>0)
				return (c+b);
		else{
				return --b;
		}

}

