#include <stdio.h>


void teste(int i){
	int r;
	if (i > 10)
		return;
		
	printf("%d\n",i++);
	teste(i);
	r = i * 10;
	printf("%d\n", r);
}





int main(int argc, char **argv)
{
	
	teste(1);
	return 0;
}

