#include<iostream>
#include <vector>

using namespace std;

template <typename T>
class Heap
{
private:
	vector<T> vec;
public:
	Heap() { };
	
	void Add(T n);
	void Remove();
	size_t Getsize();
	T GetParent(int index);
	int GetParentIndex(int index);

	T GetLeft(int index);
	int GetLeftIndex(int index);

	T GetRight(int index);
	int GetRightIndex(int index);
	void Siftup(int index);
	void Display();
};



template<typename T>
void Heap<T>::Add(T n)
{
	vec.push_back(n);
	Siftup(vec.size() - 1);
}

template<typename T>
T Heap<T>::GetParent(int index)
{
	if (index < 0 && index >= vec.size()) {
		return T();
	}
	int pi = GetParentIndex(index);
	return vec.at(pi);
}

template<typename T>
int Heap<T>::GetParentIndex(int index)
{
	return (index - 1) / 2;
}

template<typename T>
T Heap<T>::GetLeft(int index)
{

	if (index < 0 && index >= vec.size()) {
		return T();
	}

	int li = GetLeftIndex(index);
	if (li >= vec.size())
	{
		return T();
	}

	return vec.at(li);
}

template<typename T>
int Heap<T>::GetLeftIndex(int index)
{
	return 2 * index + 1;
}

template<typename T>
T Heap<T>::GetRight(int index)
{
	if (index < 0 && index >= vec.size())
	{
		return T();
	}

	int ri = GetRightIndex(index);
	if (ri >= vec.size())
	{
		return T();
	}
	return vec.at(ri);
}

template<typename T>
int Heap<T>::GetRightIndex(int index)
{
	return 2 * i + 2;
}

template<typename T>
void Heap<T>::Siftup(int index)
{
	if (index < 0 && index >= vec.size())
	{
		return;
	}

	auto p = GetParent(index);
	auto pi = GetParentIndex(index);
	if (pi >= vec.size())
	{
		return;
	}

	if (vec.at(index) > vec.at(pi))
	{
		auto temp = vec[pi];
		vec[pi] = vec[index];
		vec[index] = temp;

		Siftup(pi);
	}

}

template<typename T>
void Heap<T>::Display()
{
	for (auto e : vec)
	{
		cout << e <<": ";
	}
	cout << endl;
}

int main()
{
	Heap<int> h;
	for (auto i = 0; i < 10; i++)
	{
		h.Add(i+10);
	}
	h.Display();
	return 0;
}
