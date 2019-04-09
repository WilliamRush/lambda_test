#include<iostream>
#include <vector>
#include<algorithm>
#include <functional>
using namespace std;


int foo(int n,function<int (int)>process)
{
	cout<<"OK"<<endl;
	return process(n);
}	

class CClassLambda
{
	public:
		CClassLambda();
		~CClassLambda();
		int global_int;
	private:
		int priv_int;
};
CClassLambda::CClassLambda()
{
	priv_int =4;
	global_int = 21;
	int x = 12;
	int y = 16;

	cout<<"before my x dstis "<<&x<<","<<x<<endl;
	cout<<"before my y dstis "<<&y<<","<<y<<endl;
	cout<<"before my global"<<&global_int<<","<<global_int<<endl;
	int result = foo(5,[=,x,&y](int n)->int{
			cout<<"inside my x dstis "<<&x<<","<<x<<endl;
			x+=x;	
			cout<<"inside my y dstis "<<&y<<","<<y<<endl;
	                cout<<"inside my global"<<&global_int<<","<<global_int<<endl;
			});

	cout<<"after my x dstis "<<&x<<","<<x<<endl;
	cout<<"after my y dstis "<<&y<<","<<y<<endl;
	
	cout<<"after my global"<<&global_int<<","<<global_int<<endl;

}
CClassLambda::~CClassLambda()
{
	;
}
int main ()
{
	vector<int> some_list;
	int total = 0;
	for (int i = 0 ;i< 5;++i)
		some_list.push_back(i);
	for_each(begin(some_list),end(some_list),[&total](int x)
			{
				total += x;
				cout<<x<<"teewio"<<endl;
			}
			);
	cout<<total<<endl;

	CClassLambda *mptrlambda = new CClassLambda();
	mptrlambda->global_int = 12;

	int x = 12;
	int y = 16;

	cout<<"before my x dstis "<<&x<<","<<x<<endl;
	cout<<"before my y dstis "<<&y<<","<<y<<endl;
	int result = foo(5,[=,x,&y](int n)->int{
			cout<<"inside my x dstis "<<&x<<","<<x<<endl;
			
			cout<<"inside my y dstis "<<&y<<","<<y<<endl;
			});

	cout<<"after my x dstis "<<&x<<","<<x<<endl;
	cout<<"after my y dstis "<<&y<<","<<y<<endl;
	delete(mptrlambda);
	mptrlambda = NULL;
	return 0;

}
