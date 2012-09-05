//使用namespace防止命名冲突

namespace ConvexHull//一定要多于三个点
{
	int sz;
	point array[SIZE];
	point stack[SIZE];
	point *p;
	inline void push(point n){*p=n;	p++;}
	inline void pop(){p--;}
	inline void init(int isz)
	{
		sz=isz;
		memset(stack,0,sizeof(stack));
		p=stack;
	}

	int cmp(point p1,point p2)
	{
		if(xmult(p1,p2,array[0])>0) return 1;
		else if(xmult(p1,p2,array[0])==0 && pntDis(p1,array[0])<pntDis(p2,array[0])) return 1;
		else return 0;
	}
	int findtop()
	{
		int res=0;
		for(int i=1;i<sz;i++)
		{
			if(array[i].y<array[res].y) res=i;
			else if(array[i].y==array[res].y && array[i].x<array[res].x) res=i;
		}
		return res;
	}

	int graham()
	{
		int top=findtop();
		push(array[top]);
		swap(array[0],array[top]);
		sort(array+1,array+sz,cmp);
		
		push(array[1]);
		push(array[2]);
		for(int i=3;i<sz;i++)
		{
			while(xmult(array[i],*(p-1),*(p-2))>0) pop();//有等号时，不包括点都在一条直线的情况
			push(array[i]);
		}
		return p-stack;
	}
};
