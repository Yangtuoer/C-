#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>
#define N 100 
#pragma warning (disable:4996)
struct subway//����һ���ṹ�� 
{
	char num[N];
	char line[N];//������· 
	char sstation[N];//��ʼվ 
	char ostation[N];//�յ�վ 
	char wstation[N];//;��վ�� 
	char charge[N];//Ʊ�� 	
}sub[N];//���ṹ�������sub; 
int k = 1, n, m;
char readfile();//�ļ���ȡ 
void save();//����Ϣ�������ļ� 
void insert();//���ӵ�����Ϣ 
void Delete();//ɾ��������Ϣ 
void Search();//��ѯ������Ϣ 
void Print();//���������Ϣ 
void Update();//���µ�����Ϣ 
void menu();//���˵������������� 
int main()
{
	while (k)
		menu();
	system("pause");
	return 0;
}
char readfile()
{
	FILE *fp;//Ҫ��ȡ���ļ�ָ�� 
	int i = 0;//�����ƶ� 
	if ((fp = fopen("subway.txt", "r")) == NULL)//�򿪲������ɹ� 
	{
		printf("Open file is error!");
		system("pause");
		exit(0);
	}
	//ԭtxt�ĵ�������֮���ǿո�����ģ�fscanf������ʽ����ȡ�ļ��е����� 
	while (fscanf(fp, "%s %s %s %s %s %s", sub[i].num, sub[i].line, sub[i].sstation, sub[i].ostation, sub[i].charge, sub[i].wstation) == 6)
	{
		i++;
	}
	fclose(fp);//�ر��ļ� 
	n = i;
	printf("¼����ϣ�\n");
}
void save()
{
	int i;
	FILE *fp;//Ҫ��ȡ���ļ�ָ�� 
	fp = fopen("subway.txt", "w"); //���ļ�����д����� 
	for (i = 0; i<n; i++)
	{
		//ԭtxt�ĵ�������֮���ǿո�����ģ�fprintf�������ļ�д��ʽ������ 
		fprintf(fp, "%s %s %s %s %s %s\n", sub[i].num, sub[i].line, sub[i].sstation, sub[i].ostation, sub[i].charge, sub[i].wstation);
	}
	fclose(fp);//�ر��ļ� 
}
void insert() /*���뺯��*/
{
	FILE *fp;//Ҫ��ȡ���ļ�ָ�� 
	int i = 0;//�����ƶ� 
	if ((fp = fopen("subway.txt", "r")) == NULL)//�򿪲������ɹ�
	{
		printf("Open file is error!");
		system("pause");
		exit(0);
	}
	//ԭtxt�ĵ�������֮���ǿո�����ģ�fscanf������ʽ����ȡ�ļ��е����� 
	while (fscanf(fp, "%s %s %s %s %s %s", sub[i].num, sub[i].line, sub[i].sstation, sub[i].ostation, sub[i].charge, sub[i].wstation) != EOF)
	{
		i++;
	}
	n = i;
	int j, flag;
	printf("����������ӵĵ�����·����:\n");
	scanf("%d", &m);
	do
	{
		flag = 1;
		while (flag)
		{
			flag = 0;
			printf("������� %d �������ı��:\n", i + 1);
			scanf("%s", sub[i].num);
			for (j = 0; j<i; j++)
				if (strcmp(sub[i].num, sub[j].num) == 0)
				{
				printf("���иõ������,���������¼��!\n");
				flag = 1;
				break; /*�����ظ������˳��ò�ѭ��,����ж��ٶ�*/
				}
		}
		printf("������� %d ��������·:\n", i + 1);
		scanf("%s", sub[i].line);
		printf("������� %d ����������ʼվ:\n", i + 1);
		scanf("%s", sub[i].sstation);
		printf("������� %d ���������յ�վ\n", i + 1);
		scanf("%s", sub[i].ostation);
		printf("������� %d ��������Ʊ��:\n", i + 1);
		scanf("%s", sub[i].charge);
		printf("������� %d ��������;��վ��\n", i + 1);
		scanf("%s", sub[i].wstation);
		if (flag == 0)
		{
			i++;
		}
	} while (i<n + m);
	n += m;
	printf("¼����ϣ�\n\n");
	fclose(fp);//�ر��ļ� 
	system("pause");
	save();//���ú�����������Ϣ����б��� 
	return;
}
void Delete()
{
	FILE *fp;//Ҫ��ȡ���ļ�ָ�� 
	int i = 0;//�����ƶ�
	if ((fp = fopen("subway.txt", "r")) == NULL)//�򿪲������ɹ� 
	{
		printf("Open file is error!");
		system("pause");
		exit(0);
	}
	//ԭtxt�ĵ�������֮���ǿո�����ģ�fscanf������ʽ����ȡ�ļ��е�����
	while (fscanf(fp, "%s %s %s %s %s %s", sub[i].num, sub[i].line, sub[i].sstation, sub[i].ostation, sub[i].charge, sub[i].wstation) != EOF)
	{
		i++;
	}
	n = i;
	int t, j, flag = 0;
	char s1[30];
	printf("������Ҫɾ���ĵ������:\n");
	scanf("%s", s1);
	for (t = 0; t<n; t++)
		if (strcmp(sub[t].num, s1) == 0)
		{
		flag = 1;
		for (j = t; j<n - 1; j++)
			sub[t] = sub[t + 1];
		}
	if (flag == 0)
		printf("�ñ�Ų����ڣ�\n");
	if (flag == 1)
	{
		printf("ɾ���ɹ�\n");
		n--;
	}
	save();//���ú���ɾ����Ϣ����б��� 
}
void Search()//���� 
{
	FILE *fp;//Ҫ��ȡ���ļ�ָ�� 
	int i = 0;//�����ƶ�
	if ((fp = fopen("subway.txt", "r")) == NULL)//�򿪲������ɹ� 
	{
		printf("Open file is error!");
		system("pause");
		exit(0);
	}
	//ԭtxt�ĵ�������֮���ǿո�����ģ�fscanf������ʽ����ȡ�ļ��е�����
	while (fscanf(fp, "%s %s %s %s %s %s", sub[i].num, sub[i].line, sub[i].sstation, sub[i].ostation, sub[i].charge, sub[i].wstation) != EOF)
	{
		i++;
	}
	n = i;
	int j, item, flag = 0;
	char s1[10];
	printf("----------------------------------------------------------\n");
	printf("------------------�� 1.����·��ѯ   ��--------------------\n");
	printf("------------------�� 2.����ʼվ��ѯ ��--------------------\n");
	printf("------------------�� 3.���յ�վ��ѯ ��--------------------\n");
	printf("------------------�� 4.�˳����˵�   ��--------------------\n");
	printf("----------------------------------------------------------\n");
	while (1)
	{
		printf("��ѡ���Ӳ˵����:");
		scanf("%d", &item);
		flag = 0;
		switch (item)
		{
		case 1:
			printf("������Ҫ��ѯ�ĵ�����·��");//ͨ��������·���� 
			scanf("%s", s1);
			for (j = 0; j<n; j++)
				if (strcmp(sub[j].line, s1) == 0)
				{
				flag = 1;
				printf("�������  ������·   ��ʼվ    �յ�վ    Ʊ��     ;��վ��\n");
				printf("----------------------------------------------------------\n");
				printf("%4s %10s %11s %11s %3s %10s\n", sub[j].num, sub[j].line, sub[j].sstation, sub[j].ostation, sub[j].charge, sub[j].wstation);
				printf("��ѯ���!\n\n");
				}
			if (flag == 0)
				printf("��ѯ�����޸���Ϣ!\n"); break;
		case 2:
			printf("�������ѯ�ĵ�����ʼվ��");//ͨ��������ʼվ���� 
			scanf("%s", s1);
			for (j = 0; j<n; j++)
				if (strcmp(sub[j].sstation, s1) == 0)
				{
				flag = 1;
				printf("�������  ������·   ��ʼվ    �յ�վ    Ʊ��     ;��վ��\n");
				printf("----------------------------------------------------------\n");
				printf("%4s %10s %11s %11s %3s %10s\n", sub[j].num, sub[j].line, sub[j].sstation, sub[j].ostation, sub[j].charge, sub[j].wstation);
				printf("��ѯ���!\n\n");
				}
			if (flag == 0)
				printf("��ѯ�����޸���Ϣ!\n"); break;
		case 3:
			printf("�������ѯ�ĵ����յ�վ��");//ͨ�������յ�վ���� 
			scanf("%s", s1);
			for (j = 0; j<n; j++)
				if (strcmp(sub[j].ostation, s1) == 0)
				{
				flag = 1;
				printf("�������  ������·   ��ʼվ    �յ�վ    Ʊ��     ;��վ��\n");
				printf("----------------------------------------------------------\n");
				printf("%4s %10s %11s %11s %3s %10s\n", sub[j].num, sub[j].line, sub[j].sstation, sub[j].ostation, sub[j].charge, sub[j].wstation);
				printf("��ѯ��ϣ�\n\n");
				}
			if (flag == 0)
				printf("��ѯ�����޸���Ϣ\n"); break;
		case 4: return;
		default:printf("����1-4֮��ѡ��\n");//��ʾ�û�����Ч��Χ��ѡ�� 
		}
	}
}
void Print()//�洢��Ϣ����� 
{
	int i;
	printf("��ӭ��ѯ������·!������ϢΪ:\n");
	printf("�������  ������·   ��ʼվ    �յ�վ    Ʊ��     ;��վ��\n");
	printf("----------------------------------------------------------\n");
	save();//���ú��� 
	for (i = 0; i<n; i++)
	{
		printf("%4s %10s %11s %11s %3s %10s\n", sub[i].num, sub[i].line, sub[i].sstation, sub[i].ostation, sub[i].charge, sub[i].wstation);
	}

}
void Update()//��Ϣ�ĸ��� 
{
	FILE *fp;//Ҫ��ȡ���ļ�ָ�� 
	int i = 0;//�����ƶ�
	if ((fp = fopen("subway.txt", "r")) == NULL)//�򿪲������ɹ� 
	{
		printf("Open file is error!");
		system("pause");
		exit(0);
	}
	//ԭtxt�ĵ�������֮���ǿո�����ģ�fscanf������ʽ����ȡ�ļ��е�����
	while (fscanf(fp, "%s %s %s %s %s %s", sub[i].num, sub[i].line, sub[i].sstation, sub[i].ostation, sub[i].charge, sub[i].wstation) != EOF)
	{
		i++;
	}
	n = i;
	int j, item;
	char s1[N], s2[N];
	printf("������Ҫ���µĵ�����ţ�");
	scanf("%s", s1);
	for (j = 0; j<n; j++)
		if (strcmp(sub[j].num, s1) == 0)
		{
		printf("----------------------------------------------------------\n");
		printf("---------------�� 1.�޸ĵ�����·    ��--------------------\n");
		printf("---------------�� 2.�޸ĵ�����ʼվ  ��--------------------\n");
		printf("---------------�� 3.�޸ĵ����յ�վ  ��--------------------\n");
		printf("---------------�� 4.�޸�Ʊ��        ��--------------------\n");
		printf("---------------�� 5.�޸ĵ���;��վ����--------------------\n");
		printf("---------------�� 6.�˳����˵�      ��--------------------\n");
		printf("----------------------------------------------------------\n");
		while (1)
		{
			printf("��ѡ���Ӳ˵����:");
			scanf("%d", &item);
			switch (item)
			{
			case 1:
				printf("�������µĵ�����·:\n");
				scanf("%s", s2);
				strcpy(sub[j].line, s2); break;
			case 2:
				printf("�������µ���ʼվ:\n");
				scanf("%s", s2);
				strcpy(sub[j].sstation, s2); break;
			case 3:
				printf("�������µ��յ�վ:\n");
				scanf("%s", s2);
				strcpy(sub[j].ostation, s2); break;
			case 4:
				printf("�������µ�Ʊ��:\n");
				scanf("%s", s2);
				strcpy(sub[j].charge, s2); break;
			case 5:
				printf("�������µ�;��վ��:\n");
				scanf("%s", s2);
				strcpy(sub[j].wstation, s2); break;
			case 6:return;
			default:printf("����0-6֮��ѡ��\n");
			}
		}
		save();//���ú���������Ϣ����б��� 
		}
	if (strcmp(sub[j].num, s1) != 0)
		printf("�޴˱�ţ���������ȷ�ı��!\n");
}
void menu()//���˵� 
{
	int num;
	system("color 75");//���Ľ�����ɫΪ��ɫ����ǳ��ɫ���� 
	printf("********************************������Ϣ����ϵͳ********************************\n");
	printf("***********************������ʾ������͸���ǰ����ˢ��ϵͳ***********************\n");
	printf("                       **********************************                       \n");
	printf("                       *     0     ˢ�µ�����Ϣ         *                       \n");
	printf("                       *     1     ������Ϣ������       *                       \n");
	printf("                       *     2     ������Ϣ�����       *                       \n");
	printf("                       *     3     ������Ϣ�Ĳ�ѯ       *                       \n");
	printf("                       *     4     ������Ϣ�ĸ���       *                       \n");
	printf("                       *     5     ������Ϣ��ɾ��       *                       \n");
	printf("                       *     6          �˳�            *                       \n");
	printf("                       **********************************                       \n");
	printf("������ѡ�����:\n");
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
	default:printf("����0-6֮��ѡ��\n");
	}
}

