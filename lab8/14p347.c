
#define N 10 				// no "="" 
#define INC(x) x+1
#define SUB(x,y) (x-y)		// no space after SUB
#define SQR(x)	((x)*(x))	
#define CUBE(x)	(SQR(x)*x)
#define M1(x,y)	x##y
#define M2(x,y) #x #y

int main(void)
{
	int a[N], i, j, k, m, jk;  //have to declare type for identifier jk
#ifdef N
	i = j;
#else
	j = i;
#endif
	i = 10*INC(j);
	i = SUB(j, k);
	i = SQR(SQR(j));
	i = M1(j, k);
	puts(M2(i, j));
#undef SQR
	//i = SQR(j);           //cant use SQR because SQR is undefined
#define SQR
	i = SQR(j);
	
	return 0;
}
