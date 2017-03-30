const int global = 5;

int abcd();

int factorial(int x) {
	if(x==0)
		return 1;
	return x*factorial(x-1);
}

void swap(int *x,int *y) {
	int z=*y; int c;
	*y=*x;
	*x=z;
}

int main(){
	int i;
	for (i = 0; i < 100; ++i)
	{
		int z = factorial(i) % 20;
		swap(z,i);
		printf("%d\n",i );
	}
}