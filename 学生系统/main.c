#include "head.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	struct node*head=malloc(sizeof(struct node));//����ͷ�ڵ� 
	head->next=NULL;
	node*p;
	int n;
	n=login();
	readstudent(head);//��ȡ�洢��ѧ����Ϣ 
	while(n!=0){	
	output();
	char c=getch();//�ܱ���ʹ��getcharʱ�̻س� 
	switch(c){
	case'1':inputstudent(head);
	break;
	case'2':
	p=readstudent(head);// �����ʱ��ͬʱ�����һ�δ�������� 
	putoutstudent(p);
	break;
	case'3':countstudent(head);
	break;
	case'4':findstudent(head);
	break;
	case'5':modstudent(head);
	break;
	case'6':delstudent(head);
	break;
	case'7':sortstudent(head);
	break;
	case'8':system("cls");
	printf("bye!");
	return;
	default:printf("���������룡\n"); 
	system("pause");
	break;
	}}
	return 0;
}
void output(){//��ӡ���˵� 
    system("cls");
    printf("\t ============================\n");
	printf("\t ��\t1.¼��ѧ����Ϣ     ��\n");
	printf("\t ��\t2.��ӡѧ����Ϣ     ��\n");
	printf("\t ��\t3.ͳ��ѧ������     ��\n");
	printf("\t ��\t4.����ѧ����Ϣ     ��\n");
	printf("\t ��\t5.�޸�ѧ����Ϣ     ��\n");
	printf("\t ��\t6.ɾ��ѧ����Ϣ     ��\n");
	printf("\t ��\t7.���ɼ�����       ��\n");
	printf("\t ��\t8.�˳�ϵͳ         ��\n");	
	printf("\t ============================\n");
}  
void inputstudent(node*head){
	system("cls");//�����Ļ 
	struct node *move,*p;
	int n;
		move=head;//move��¼ͷ�ڵ� 
	printf("������ѧ����ѧ�ţ��������ɼ�,����0����\n");
	scanf("%d",&n);//����ѧ�� 
    while(n!=0){
    	p=malloc(sizeof(struct node));//�����½ڵ� 
    	p->student.stunum=n;
    	scanf("%s %d",p->student.name,&p->student.score);
    	p->next=NULL;//����һ��ָ����Ϊ�� 
		move->next=p;//��move��ָ��ָ��Ϊ�½ڵ㣬Ҳ�������� 
		move=p;//��move������  
		printf("������ѧ����ѧ�ţ��������ɼ�,����0����\n");
		scanf("%d",&n);
		}
	    savestudent(head); //��ÿ��ѧ����Ϣ�洢���� 
		printf("����������������ҳ��\n");
		getch();	
	}
void putoutstudent(node*p){
	system("cls");
	if(p->next==NULL){
		printf("���ȴ���ѧ����Ϣ\n");
		printf("����������������ҳ��\n");
		getch();	
		return; 
	}
	node*move=p->next;//��moveָ���һ��������ݵĽڵ� 
	while(move!=NULL){
    printf("ѧ��%d ����%s �÷�%d\n",move->student.stunum,move->student.name,move->student.score);
	move=move->next; //move���� 
	}
		printf("����������������ҳ��\n");
		getch();
}
void countstudent(node*head){
	system("cls");
	node*move=head->next;
	int count;
    count=0;
	while(move!=NULL){
	move=move->next;
	count++;//ÿ�����ƶ�һ�� ��һ 
	}
	printf("ѧ������Ϊ%d\n",count);
	printf("����������������ҳ��\n");
		getch(); 
} 
void findstudent(node*head){
	system("cls");
	printf("��������Ҫ���ҵ�ѧ������\n");
	char a[20];
	scanf("%s",a);
	node* move=head->next;
	while(move!=NULL){
		if(strcmp(a,move->student.name)==0){//�ж����ڽ��������Ƿ�����Ҫ����������ͬ 
			printf("ѧ��%d ����%s �÷�%d\n",move->student.stunum,move->student.name,move->student.score);	
		break;//�ɹ�����ѭ�� 
		}
		move=move->next;
	}
	if(move==NULL)
	printf("û���ҵ�ѧ����Ϣ\n"); 
	printf("����������������ҳ��\n");
	getch(); 
	}
void modstudent(node*head){
	system("cls");
	node*move=head->next;
	char name[20];
	printf("��������Ҫ�޸ĵ�ѧ������\n");
	scanf("%s",name);
	while(move!=NULL){
	if(strcmp(name,move->student.name)==0){
	printf("��������Ҫ�޸ĵ�ѧ���ɼ�\n");
	scanf("%d",&move->student.score);
	remove("./stu.info");// ɾ�����е���Ϣ�ļ� 
	savestudent(head); //���޸�����Ϣ��ȫ����Ϣ���´��棬��������ظ����� 
	printf("�޸ĳɹ�\n");
	break;
	} 
	move=move->next;
	}
	if(move==NULL)
	printf("û���ҵ�ѧ����Ϣ\n"); 
	printf("����������������ҳ��\n");
		getch();  
	}

void delstudent(node*head){
	system("cls");
	node*move=head;
	char name[20];
	printf("��������Ҫɾ����ѧ������\n");
	scanf("%s",name);
	while(move->next!=NULL){
		if(strcmp(name,move->next->student.name)==0){
			node*p=move->next;//��һ����ָ������Ҫɾ���Ľڵ�ĵ�ַ 
			move->next=move->next->next;//����Ҫɾ���Ľڵ�ǰ������ 
			free(p);//�ͷ���Ҫɾ���ڵ�Ŀռ� 
			p=NULL;//��pΪ�շ�ֹ�ͷź�pΪҰָ��
			remove("./stu.info");
			savestudent(head);//��ɾ����Ϣ��ȫ����Ϣ���´��棬��ֹ������ظ�  
			printf("ɾ���ɹ�\n"); 
			printf("����������������ҳ��\n");
		    getch();
			return;
		}
		move=move->next;
	} 
	if(move->next==NULL)
	printf("û���ҵ�ѧ����Ϣ\n"); 
	printf("����������������ҳ��\n");
		getch(); 
}
void sortstudent(node*head){//ѡ������ 
    system("cls");
	node*pre,*p;
	for(pre=head->next;pre->next!=NULL;pre=pre->next){//��preָ���һ��������ݽڵ���ƱȽϴ��� 
		for(p=pre->next;p!=NULL;p=p->next){//��pָ��ڶ���������ݵĽڵ���pre��ָ�ڵ������ÿ���ڵ���бȽ� 
			if((pre->student.score)<(p->student.score)){//�������� 
				student temp=pre->student;
				pre->student=p->student;
				p->student=temp;	 
			}
		}
	}
	putoutstudent(head);
}
void savestudent(node*head){//�洢ÿ��ѧ����Ϣ 
	FILE*file=fopen("./stu.info","a");//���ļ� ���ڵ�ǰ�ļ��д���stu.info�ļ���a�Ǵ��ļ���д��,����ļ����ڣ���д������׷�ӵ��ļ�ĩβ������ļ������ڣ���ᴴ�����ļ��� 
	if(file==NULL){
		printf("��ʧ��");
		return; 
	} 
	node*move=head->next;
	while(move!=NULL){//��������д��ÿ��ѧ����Ϣ 
		fwrite(&move->student,sizeof(student),1,file);
		// fwriteд�룬&move->studentд��ط��ĵ�ַ ��sizeof(student)д�����ݴ�С��1д�����ݵĸ������������� fileĿ���ļ��ĵ�ַ ������д�����ݵĸ��� 
		move=move->next;
	} 
	fclose(file);//�ر��ļ� 
}
node *readstudent(node*head){//��ȡѧ����Ϣ 
	FILE*file=fopen("./stu.info","r");//��stu.info�ļ�����ȡ 
	if(file==NULL){
		printf("��ʧ��");
		return; 
	} 
	node*new_,*move;
	new_=malloc(sizeof(node));//��Ҫ�Ѷ�ȡ�����ݴ������һ���ط� 
	new_->next=NULL;
	move=head;
	 while((fread(&new_->student,sizeof(student),1,file))==1){//������������Ŷ�ȡ��ѧ����Ϣ 
	 // fread��ȡ��&new_->student������Ŷ�ȡ������Ϣ�ĵ�ַ��sizeof(student)��ȡ������Ϣ��С��1��ȡ�����ݸ�����fileĿ���ļ��ĵ�ַ�����ض�ȡ�����ݸ��� 
	 	move->next=new_;
	 	move=new_;
		new_=malloc(sizeof(node));//�����½ڵ�����һ��ѧ������Ϣ ������ഴ��һ���սڵ� 
	    new_->next=NULL; 	
	 }
	 free(new_);//�ͷŶ���Ľڵ�ռ� 
	 fclose(file);
	 return head;//����Ŷ�ȡ�����ݵĵ�ַ���� 
} 
 int login(){//ʵ�ּ򵥵�¼ 
    struct account user;
	char id[20];
	char an[20];
	int n;
	n=0;
	strcpy(user.id,"yuanshen");
	strcpy(user.an,"qidong!");//��ʼ���˺����� 
	while(n==0){
	printf("�����˺�\n");
	gets(id);
	printf("��������\n");
	gets(an); 
	if(strcmp(id,user.id)==0&&strcmp(an,user.an)==0){//�ж������˺��Ƿ���ȷ 
		n=1;
		return n;
	}
	if(n==0){
		printf("ʧ��\n");
		printf("����������\n");
	}}
 }
