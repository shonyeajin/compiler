void main(){
		int n,x,i,k,lim,prim;
		int p[300];
		p[1]=2;
		printf("%d ",2);
		n=100;
		x=1;
		lim=1;
		for(i=2;i<=n;i++){
				do{
						x=x+1;
						x++;
						if(p[lim]*p[lim]<=x)
								lim++;
						k=2;
						prim=1;
						while(prim && (k<lim)){
								prim=x%p[k];
								k++;
						}
				}
				while(!prim);
				p[i]=x;
				printf("%d ",x);
				if(i%10==0)
						printf("\n");
		}
}
