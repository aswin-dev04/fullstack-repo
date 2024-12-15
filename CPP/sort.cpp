#include <cmath>
#include <iostream>
#include <vector>

template <class T>
void bubble(std::vector<T> &v)
{
	T temp{};
	int flag{0};
	for(int i=0;i<v.size()-1;i++)
	{
		for(int j=0;j<v.size()-1-i;++j)
		{
			if(v.at(j)>v.at(j+1))
			{
				temp=v.at(j);
				v.at(j)=v.at(j+1);
				v.at(j+1)=temp;
				flag=1;
			}
		}
		if(flag==0)return;
	}
}

template<class T>
void insertSort(std::vector<T> &v)
{
	T temp{};
	int j{0};
	for(int i=1;i<v.size();++i)
	{
		j=i-1;
		temp=v.at(i);
		while(j>-1&&v.at(j)>temp)
		{
			v.at(j+1)=v.at(j);
			j--;
		}
		v.at(j+1)=temp;
	}
}

template<class T>
void merge(std::vector<T> &v, int low, int mid, int high)
{
	int i=low;
	int j=mid+1;
	int k=low;
	std::vector<T> temp(high+1);
	while(i<=mid && j<=high)
	{
		if(v.at(i)<v.at(j)) temp.at(k++)=v.at(i++);
		else temp.at(k++)=v.at(j++);
	}
	for(;i<=mid;++i) temp.at(k++)=v.at(i);
	for(;j<=high;++j) temp.at(k++)=v.at(j);
	for(int x=low;x<=high;++x) v.at(x)=temp.at(x);
}

template<class T>
void mergeSort(std::vector<T> &v,int low, int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergeSort(v,low,mid);
		mergeSort(v,mid+1,high);
		merge(v,low,mid,high);
	}
}





int main()
{
	std::vector<int> v = {3,6,2,13,5,2,6,8,12,34};
	mergeSort(v,0,9);
	for(int i=0;i<v.size();++i) std::cout<<v.at(i)<<" ";
	std::cout<<"\n";

	return 0;
}

