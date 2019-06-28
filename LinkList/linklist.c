#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"

//��˳�򴴽�N���ڵ������
LinkList create(int n)
{
	int i;
	LinkList head,node,end;
	head = (LinkList)malloc(sizeof(Node));
	if(head == NULL)
	{
		printf("malloc head memory failed\n");
		exit(0);
	}
	end = head;
	for(i=0;i<n;i++)
	{
		node = (LinkList)malloc(sizeof(Node));
		if(node == NULL)
		{
			printf("malloc node memory failed\n");
			exit(0);
		}
		scanf("%d",&node->data);
		end->next = node;
		end = node;
	}
	end->next = NULL;
	return head;
}

//����������ĳһλ�õ�����
int search_linklist_L(LinkList head,int location)
{
	int i=1;
	LinkList ptr = head;
	ptr = ptr->next;   //ȥ��ͷ�ڵ�
	while(i!=location && ptr)
	{
		ptr = ptr->next;	
		i++;
	}
	if(ptr!=NULL)
	{
		printf("search linklist location %d data:%d\n",location,ptr->data);
		return (ptr->data);
	}
	else
	{
		goto error;	
	}
	error:
		 printf("search linklist failed\n");
		 return -1;
}

//����������ĳ�����������е�λ��
int search_linklist_D(LinkList head,int data)
{
	int i = 0,j=1;
	int sum = 0;
	LinkList ptr = head;
	ptr = ptr->next;
	while(ptr)
	{
		if(ptr->data == data)
		{
			printf("%d.search linklist data %d location:%d\n",++i,data,j);
			sum++;
		}
		j++;
		ptr = ptr->next;
	}
	if(!sum)
	{
		printf("not search data from linklist\n");
	}
	return sum;
}

//��˳���ӡ�������
void print_linklist(LinkList head)
{
	LinkList p = head;
	int j = 1;
	p = p->next;
	while(p != NULL)
	{
		printf("%d.\t%d\n",j,p->data);
		p = p->next;
		j++;
	}
}

//ɾ��������ָ��λ�õĽڵ�
void delete_node(LinkList head,int n)
{
	int i = 0;
	LinkList p,ptr;
	p = head;         //����ָ��ָ��ͬһ����ַ
	ptr = head;
	while(i<n&&p!=NULL)
	{
		ptr = p;            //����whileʱ��ptrָ��ָ��ָ��P��ǰһ����ַ          
		p = p->next;
		i++;
	}
	if(p!=NULL)
	{
		ptr->next = p->next;
		free(p);	
		p = NULL;      	  //�ͷ�ָ���ָ����ձ����Ұָ��
	}
	else
	{
		printf("delete node not exist\n");
	}
	
}
//�ڶ�Ӧλ�ò�����Ӧ�Ľڵ�
void insert_node(LinkList head,int n)
{
	int i=0;
	LinkList p,ptr;
	p = head;
	ptr = (LinkList)malloc(sizeof(Node));
	if(ptr == NULL)
	{
		printf("insert fun malloc node failed\n");
		exit(0);
	}
	printf("input data:");
	scanf("%d",&ptr->data);
	while(i<n&&p!=NULL)
	{
		p = p->next;
		i++;
	}
	if(p != NULL)      
	{
		ptr->next = p->next;
		p->next = ptr;
	}
	else
	{
		printf("insert node location is failed\n");
	}
}
//��˳���ͷ����������ַ
void free_linklist(LinkList head)
{
	LinkList p;
	while(head!=NULL)
	{
		p = head;
		head = head->next;
		free(p);
	}
	p = NULL;  //�ͷ����ָ����գ������Ұָ��,�����Ҫ�ɲ�Ҫ����������ϰ��ÿ���ͷ�ָ���ʱ��ָ��ָΪ�յ�ַ��
}

//������
int main(int argc,char *argv[])
{
	int lnum = 0,location = 0,data1 = 0;
	char c;
	LinkList mylist = NULL;  			  //ָ����ʹ��ʱһ���ó�ʼ����Ҫôָ���Ҫôֻ����ڵ��ڴ��ַ
	printf("you want to create linklist len:");
	scanf("%d",&lnum);
	mylist = create(lnum);                //��������
	print_linklist(mylist);
	
	printf("you want insert node location:");
	scanf("%d",&location);
	insert_node(mylist,location);         //����ڵ㵽������
	print_linklist(mylist);
	
	
	printf("you want delete node location:");
	scanf("%d",&location);
	delete_node(mylist,location);         //��������ɾ���ڵ�
	print_linklist(mylist);
	
	printf("you want search node location:");
	scanf("%d",&location);
	search_linklist_L(mylist,location);  //��ѯ����ĳλ�ýڵ������
	
	printf("you want search node data:");
	scanf("%d",&data1);
	search_linklist_D(mylist,data1);     //��ѯ������ĳ�������������е�λ��

	free_linklist(mylist);
	return 0;
}

