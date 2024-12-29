int find(int A[],int X)
{
       if(X == A[X]) return X;
       return find(A,A[X]);
}
void unionSet(int A[],int X,int Z)
{
	int parentX = find(A,X);
	int parentZ = find(A,Z);
	if(parentX == parentZ) return;
	A[parentX] = parentZ;
}
