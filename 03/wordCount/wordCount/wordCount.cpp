#include<fstream>
#include<cstdlib>
#include<iostream>
#include<stdio.h>

#define _CRT_SECURE_NO_WARNINGS


using namespace std;

int CharCount(char path[]);
int WordCount(char path[]);
int LineCount(char path[]);
//void Muiltiple(char path[]);

int main()
{
	char buffer[50];
	cout << "输入你要查询的文件：";
	cin >> buffer;

	cout << "char count is:" << CharCount(buffer) << endl;
	cout << "word count is:" << WordCount(buffer) << endl;
	cout << "line count is:" << LineCount(buffer) << endl;
	return 0;
}

int CharCount(char path[])
{
	FILE *fp = NULL;          //文件指针
	int c = 0;                //计数
	char ch;                  //读取字符
	char *path_1 = path;
	if ((fp = fopen(path_1, "r")) == NULL)      //打开只读文件path_1
	{
		cout << "file read failure!" << endl;
		exit(0);
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch >= 'A' || ch <= 'z' || ch >= '0' || ch <= '9' || ch == 32 || ch == 44 || ch == 46 || ch == 10)
		{
			c++;
			ch = fgetc(fp);
		}
		else
		{

			ch = fgetc(fp);          //fgetc是读取字符函数，fgets是读取字符串函数
		}
	}
	
	c--;
	fclose(fp);
	return c;
}

int WordCount(char path[])
{
	FILE *fp;
	int w = 0;
	int temp = 0;
	char ch;
	char *path_2 = path;
	if ((fp = fopen(path_2, "r")) == NULL)
	{
		cout << "file read failure!" << endl;
		exit(0);
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		temp = 0;

		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		{
			while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')
				|| (ch >= '0' && ch <= '9'))
			{
				temp++;
				ch = fgetc(fp);
			}
			//当读取到以上字符时循环直到空字符，w开始计数，如果原本是空字符则继续往后读
			if (temp >= 4)
			{
				w++;
				ch = fgetc(fp);
			}
		}
		else
		{
			ch = fgetc(fp);
		}
	}
	fclose(fp);
	return w;
}

int LineCount(char path[])
{
	FILE *fp;
	int l = 1;
	char ch;
	char *path_3 = path;
	if ((fp = fopen(path_3, "r")) == NULL)
	{
		cout << "file read failure!" << endl;
		exit(0);
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch == '\n')
		{
			l++;
			ch = fgetc(fp);
		}
		else
		{
			ch = fgetc(fp);
		}
	}
	fclose(fp);
	return l;
}
