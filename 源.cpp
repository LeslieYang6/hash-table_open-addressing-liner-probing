#include<iostream>

using namespace std;

//对于数组，-1代表空，-2代表被删除//
int Hash(int x)
{
	return x % 7;
}

void Insert(int arr[], int key,int size)
{
	int i = Hash(key);
	if (arr[i] == -1)
	{
		arr[i] = key;
		return;
	}
	i++;
	for (; i < size; i++)
	{
		if (arr[i] != -1)
			;
		else
		{
			arr[i] = key;
			return;
		}
	}
	cout << "memory is full"<<endl;
}

void Delete(int arr[], int key, int size)
{
	int i = Hash(key);
	if (arr[i] == -1)
	{
		cout << "not found";
		return;
	}
	i++;
	for (; i < size; i++)
	{
		if (arr[i] == -1)
		{
			cout << "not found";
			return;
		}
		else
		{
			if (arr[i] == key)
			{
				arr[i] = -2;
				return;
			}
		}
	}
	cout << "not found";
}

void Search(int arr[], int key, int size)
{
	int i = Hash(key);
	if (arr[i] == -1)
	{
		cout << "not found";
		return;
	}
	i++;
	for (; i < size; i++)
	{
		if (arr[i] == -1)
		{
			cout << "not found";
			return;
		}
		else
		{
			if (arr[i] == key)
			{
				cout << "key is found at " << i;
				return;
			}
		}
	}
	cout << "not found";
}

int main()
{
	int arr[] = { 50,700,76,85,92,73,101 };
	int hash_table[7];
	memset(hash_table, -1, sizeof(hash_table));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		Insert(hash_table, arr[i], sizeof(arr) / sizeof(arr[0]));
	Delete(hash_table, 85, sizeof(arr) / sizeof(arr[0]));
	system("pause");
}