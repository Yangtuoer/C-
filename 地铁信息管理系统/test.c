#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>
#define N 100 
#pragma warning (disable:4996)
struct subway//定义一个结构体 
{
	char num[N];
	char line[N];//地铁线路 
	char sstation[N];//起始站 
	char ostation[N];//终点站 
	char wstation[N];//途径站数 
	char charge[N];//票价 	
}sub[N];//给结构体起别名sub; 
int k = 1, n, m;
char readfile();//文件读取 
void save();//将信息保存至文件 
void insert();//增加地铁信息 
void Delete();//删除地铁信息 
void Search();//查询地铁信息 
void Print();//浏览地铁信息 
void Update();//更新地铁信息 
void menu();//主菜单调用其他函数 
int main()
{
	while (k)
		menu();
	system("pause");
	return 0;
}
char readfile()
{
	FILE *fp;//要读取的文件指针 
	int i = 0;//数组移动 
	if ((fp = fopen("subway.txt", "r")) == NULL)//打开操作不成功 
	{
		printf("Open file is error!");
		system("pause");
		exit(0);
	}
	//原txt文档的数据之间是空格隔开的，fscanf用来格式化读取文件中的数据 
	while (fscanf(fp, "%s %s %s %s %s %s", sub[i].num, sub[i].line, sub[i].sstation, sub[i].ostation, sub[i].charge, sub[i].wstation) == 6)
	{
		i++;
	}
	fclose(fp);//关闭文件 
	n = i;
	printf("录入完毕！\n");
}
void save()
{
	int i;
	FILE *fp;//要读取的文件指针 
	fp = fopen("subway.txt", "w"); //打开文件进行写入操作 
	for (i = 0; i<n; i++)
	{
		//原txt文档的数据之间是空格隔开的，fprintf用来向文件写格式化数据 
		fprintf(fp, "%s %s %s %s %s %s\n", sub[i].num, sub[i].line, sub[i].sstation, sub[i].ostation, sub[i].charge, sub[i].wstation);
	}
	fclose(fp);//关闭文件 
}
void insert() /*插入函数*/
{
	FILE *fp;//要读取的文件指针 
	int i = 0;//数组移动 
	if ((fp = fopen("subway.txt", "r")) == NULL)//打开操作不成功
	{
		printf("Open file is error!");
		system("pause");
		exit(0);
	}
	//原txt文档的数据之间是空格隔开的，fscanf用来格式化读取文件中的数据 
	while (fscanf(fp, "%s %s %s %s %s %s", sub[i].num, sub[i].line, sub[i].sstation, sub[i].ostation, sub[i].charge, sub[i].wstation) != EOF)
	{
		i++;
	}
	n = i;
	int j, flag;
	printf("请输入待增加的地铁线路数量:\n");
	scanf("%d", &m);
	do
	{
		flag = 1;
		while (flag)
		{
			flag = 0;
			printf("请输入第 %d 个地铁的编号:\n", i + 1);
			scanf("%s", sub[i].num);
			for (j = 0; j<i; j++)
				if (strcmp(sub[i].num, sub[j].num) == 0)
				{
				printf("已有该地铁编号,请检查后重新录入!\n");
				flag = 1;
				break; /*如有重复立即退出该层循环,提高判断速度*/
				}
		}
		printf("请输入第 %d 个地铁线路:\n", i + 1);
		scanf("%s", sub[i].line);
		printf("请输入第 %d 个地铁的起始站:\n", i + 1);
		scanf("%s", sub[i].sstation);
		printf("请输入第 %d 个地铁的终点站\n", i + 1);
		scanf("%s", sub[i].ostation);
		printf("请输入第 %d 个地铁的票价:\n", i + 1);
		scanf("%s", sub[i].charge);
		printf("请输入第 %d 个地铁的途经站数\n", i + 1);
		scanf("%s", sub[i].wstation);
		if (flag == 0)
		{
			i++;
		}
	} while (i<n + m);
	n += m;
	printf("录入完毕！\n\n");
	fclose(fp);//关闭文件 
	system("pause");
	save();//调用函数在增加信息后进行保存 
	return;
}
void Delete()
{
	FILE *fp;//要读取的文件指针 
	int i = 0;//数组移动
	if ((fp = fopen("subway.txt", "r")) == NULL)//打开操作不成功 
	{
		printf("Open file is error!");
		system("pause");
		exit(0);
	}
	//原txt文档的数据之间是空格隔开的，fscanf用来格式化读取文件中的数据
	while (fscanf(fp, "%s %s %s %s %s %s", sub[i].num, sub[i].line, sub[i].sstation, sub[i].ostation, sub[i].charge, sub[i].wstation) != EOF)
	{
		i++;
	}
	n = i;
	int t, j, flag = 0;
	char s1[30];
	printf("请输入要删除的地铁编号:\n");
	scanf("%s", s1);
	for (t = 0; t<n; t++)
		if (strcmp(sub[t].num, s1) == 0)
		{
		flag = 1;
		for (j = t; j<n - 1; j++)
			sub[t] = sub[t + 1];
		}
	if (flag == 0)
		printf("该编号不存在！\n");
	if (flag == 1)
	{
		printf("删除成功\n");
		n--;
	}
	save();//调用函数删除信息后进行保存 
}
void Search()//查找 
{
	FILE *fp;//要读取的文件指针 
	int i = 0;//数组移动
	if ((fp = fopen("subway.txt", "r")) == NULL)//打开操作不成功 
	{
		printf("Open file is error!");
		system("pause");
		exit(0);
	}
	//原txt文档的数据之间是空格隔开的，fscanf用来格式化读取文件中的数据
	while (fscanf(fp, "%s %s %s %s %s %s", sub[i].num, sub[i].line, sub[i].sstation, sub[i].ostation, sub[i].charge, sub[i].wstation) != EOF)
	{
		i++;
	}
	n = i;
	int j, item, flag = 0;
	char s1[10];
	printf("----------------------------------------------------------\n");
	printf("------------------◎ 1.按线路查询   ◎--------------------\n");
	printf("------------------◎ 2.按起始站查询 ◎--------------------\n");
	printf("------------------◎ 3.按终点站查询 ◎--------------------\n");
	printf("------------------◎ 4.退出本菜单   ◎--------------------\n");
	printf("----------------------------------------------------------\n");
	while (1)
	{
		printf("请选择子菜单编号:");
		scanf("%d", &item);
		flag = 0;
		switch (item)
		{
		case 1:
			printf("请输入要查询的地铁线路：");//通过地铁线路查找 
			scanf("%s", s1);
			for (j = 0; j<n; j++)
				if (strcmp(sub[j].line, s1) == 0)
				{
				flag = 1;
				printf("地铁编号  地铁线路   起始站    终点站    票价     途经站数\n");
				printf("----------------------------------------------------------\n");
				printf("%4s %10s %11s %11s %3s %10s\n", sub[j].num, sub[j].line, sub[j].sstation, sub[j].ostation, sub[j].charge, sub[j].wstation);
				printf("查询完毕!\n\n");
				}
			if (flag == 0)
				printf("查询错误，无该信息!\n"); break;
		case 2:
			printf("请输入查询的地铁起始站：");//通过地铁起始站查找 
			scanf("%s", s1);
			for (j = 0; j<n; j++)
				if (strcmp(sub[j].sstation, s1) == 0)
				{
				flag = 1;
				printf("地铁编号  地铁线路   起始站    终点站    票价     途经站数\n");
				printf("----------------------------------------------------------\n");
				printf("%4s %10s %11s %11s %3s %10s\n", sub[j].num, sub[j].line, sub[j].sstation, sub[j].ostation, sub[j].charge, sub[j].wstation);
				printf("查询完毕!\n\n");
				}
			if (flag == 0)
				printf("查询错误，无该信息!\n"); break;
		case 3:
			printf("请输入查询的地铁终点站：");//通过地铁终点站查找 
			scanf("%s", s1);
			for (j = 0; j<n; j++)
				if (strcmp(sub[j].ostation, s1) == 0)
				{
				flag = 1;
				printf("地铁编号  地铁线路   起始站    终点站    票价     途经站数\n");
				printf("----------------------------------------------------------\n");
				printf("%4s %10s %11s %11s %3s %10s\n", sub[j].num, sub[j].line, sub[j].sstation, sub[j].ostation, sub[j].charge, sub[j].wstation);
				printf("查询完毕！\n\n");
				}
			if (flag == 0)
				printf("查询错误，无该信息\n"); break;
		case 4: return;
		default:printf("请在1-4之间选择\n");//提示用户在有效范围中选择 
		}
	}
}
void Print()//存储信息的浏览 
{
	int i;
	printf("欢迎查询地铁线路!所有信息为:\n");
	printf("地铁编号  地铁线路   起始站    终点站    票价     途经站数\n");
	printf("----------------------------------------------------------\n");
	save();//调用函数 
	for (i = 0; i<n; i++)
	{
		printf("%4s %10s %11s %11s %3s %10s\n", sub[i].num, sub[i].line, sub[i].sstation, sub[i].ostation, sub[i].charge, sub[i].wstation);
	}

}
void Update()//信息的更新 
{
	FILE *fp;//要读取的文件指针 
	int i = 0;//数组移动
	if ((fp = fopen("subway.txt", "r")) == NULL)//打开操作不成功 
	{
		printf("Open file is error!");
		system("pause");
		exit(0);
	}
	//原txt文档的数据之间是空格隔开的，fscanf用来格式化读取文件中的数据
	while (fscanf(fp, "%s %s %s %s %s %s", sub[i].num, sub[i].line, sub[i].sstation, sub[i].ostation, sub[i].charge, sub[i].wstation) != EOF)
	{
		i++;
	}
	n = i;
	int j, item;
	char s1[N], s2[N];
	printf("请输入要更新的地铁编号：");
	scanf("%s", s1);
	for (j = 0; j<n; j++)
		if (strcmp(sub[j].num, s1) == 0)
		{
		printf("----------------------------------------------------------\n");
		printf("---------------◎ 1.修改地铁线路    ◎--------------------\n");
		printf("---------------◎ 2.修改地铁起始站  ◎--------------------\n");
		printf("---------------◎ 3.修改地铁终点站  ◎--------------------\n");
		printf("---------------◎ 4.修改票价        ◎--------------------\n");
		printf("---------------◎ 5.修改地铁途经站数◎--------------------\n");
		printf("---------------◎ 6.退出本菜单      ◎--------------------\n");
		printf("----------------------------------------------------------\n");
		while (1)
		{
			printf("请选择子菜单编号:");
			scanf("%d", &item);
			switch (item)
			{
			case 1:
				printf("请输入新的地铁线路:\n");
				scanf("%s", s2);
				strcpy(sub[j].line, s2); break;
			case 2:
				printf("请输入新的起始站:\n");
				scanf("%s", s2);
				strcpy(sub[j].sstation, s2); break;
			case 3:
				printf("请输入新的终点站:\n");
				scanf("%s", s2);
				strcpy(sub[j].ostation, s2); break;
			case 4:
				printf("请输入新的票价:\n");
				scanf("%s", s2);
				strcpy(sub[j].charge, s2); break;
			case 5:
				printf("请输入新的途经站数:\n");
				scanf("%s", s2);
				strcpy(sub[j].wstation, s2); break;
			case 6:return;
			default:printf("请在0-6之间选择\n");
			}
		}
		save();//调用函数更新信息后进行保存 
		}
	if (strcmp(sub[j].num, s1) != 0)
		printf("无此编号，请输入正确的编号!\n");
}
void menu()//主菜单 
{
	int num;
	system("color 75");//更改界面颜色为灰色背景浅紫色字体 
	printf("********************************地铁信息管理系统********************************\n");
	printf("***********************友情提示：浏览和更新前请先刷新系统***********************\n");
	printf("                       **********************************                       \n");
	printf("                       *     0     刷新地铁信息         *                       \n");
	printf("                       *     1     地铁信息的增加       *                       \n");
	printf("                       *     2     地铁信息的浏览       *                       \n");
	printf("                       *     3     地铁信息的查询       *                       \n");
	printf("                       *     4     地铁信息的更新       *                       \n");
	printf("                       *     5     地铁信息的删除       *                       \n");
	printf("                       *     6          退出            *                       \n");
	printf("                       **********************************                       \n");
	printf("请输入选择序号:\n");
	scanf("%d", &num);
	switch (num)
	{
	case 0:readfile(); break;
	case 1:insert(); break;
	case 2:Print(); break;
	case 3:Search(); break;
	case 4:Update(); break;
	case 5:Delete(); break;
	case 6:k = 0; printf("Bye!\n"); break;
	default:printf("请在0-6之间选择\n");
	}
}

