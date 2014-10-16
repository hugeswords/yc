/*************************************************************************
    > File Name: 2.1.1.cpp
    > Author: Ye Anda
    > Company: Lemote Loongson 
    > Created Time: 2014年09月09日 星期二 19时29分53秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution
{
public:
	int removeDuplicates(int A[],int n)
	{
		if(n == 0) 
			return 0;
		int index = 0;
		for(int i = 0; i < n; i++)
			{
				if(A[index] != A[i])
					A[++index] = A[i];
			}
		return (++index);
	}
};
int main()
{
int A[]={1,1,1,2,2,2};

Solution s1;
cout<<s1.removeDuplicates(A,6)<<endl;
return 0;
}
