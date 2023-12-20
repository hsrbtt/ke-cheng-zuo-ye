#include "head.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	struct node*head=malloc(sizeof(struct node));//创建头节点 
	head->next=NULL;
	node*p;
	int n;
	n=login();
	readstudent(head);//读取存储的学生信息 
	while(n!=0){	
	output();
	char c=getch();//能避免使用getchar时吞回车 
	switch(c){
	case'1':inputstudent(head);
	break;
	case'2':
	p=readstudent(head);// 在输出时能同时输出上一次储存的数据 
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
	default:printf("请重新输入！\n"); 
	system("pause");
	break;
	}}
	return 0;
}
void output(){//打印主菜单 
    system("cls");
    printf("\t ============================\n");
	printf("\t ｜\t1.录入学生信息     ｜\n");
	printf("\t ｜\t2.打印学生信息     ｜\n");
	printf("\t ｜\t3.统计学生人数     ｜\n");
	printf("\t ｜\t4.查找学生信息     ｜\n");
	printf("\t ｜\t5.修改学生信息     ｜\n");
	printf("\t ｜\t6.删除学生信息     ｜\n");
	printf("\t ｜\t7.按成绩排序       ｜\n");
	printf("\t ｜\t8.退出系统         ｜\n");	
	printf("\t ============================\n");
}  
void inputstudent(node*head){
	system("cls");//清空屏幕 
	struct node *move,*p;
	int n;
		move=head;//move记录头节点 
	printf("请输入学生的学号，姓名，成绩,输入0结束\n");
	scanf("%d",&n);//输入学号 
    while(n!=0){
    	p=malloc(sizeof(struct node));//开辟新节点 
    	p->student.stunum=n;
    	scanf("%s %d",p->student.name,&p->student.score);
    	p->next=NULL;//让下一个指针域为空 
		move->next=p;//让move的指针指向为新节点，也就是链接 
		move=p;//让move往后移  
		printf("请输入学生的学号，姓名，成绩,输入0结束\n");
		scanf("%d",&n);
		}
	    savestudent(head); //把每个学生信息存储起来 
		printf("输入任意数返回主页面\n");
		getch();	
	}
void putoutstudent(node*p){
	system("cls");
	if(p->next==NULL){
		printf("请先创建学生信息\n");
		printf("输入任意数返回主页面\n");
		getch();	
		return; 
	}
	node*move=p->next;//让move指向第一个存放数据的节点 
	while(move!=NULL){
    printf("学号%d 姓名%s 得分%d\n",move->student.stunum,move->student.name,move->student.score);
	move=move->next; //move后移 
	}
		printf("输入任意数返回主页面\n");
		getch();
}
void countstudent(node*head){
	system("cls");
	node*move=head->next;
	int count;
    count=0;
	while(move!=NULL){
	move=move->next;
	count++;//每往后移动一次 加一 
	}
	printf("学生人数为%d\n",count);
	printf("输入任意数返回主页面\n");
		getch(); 
} 
void findstudent(node*head){
	system("cls");
	printf("请输入需要查找的学生姓名\n");
	char a[20];
	scanf("%s",a);
	node* move=head->next;
	while(move!=NULL){
		if(strcmp(a,move->student.name)==0){//判断所在结点的姓名是否与需要查找姓名相同 
			printf("学号%d 姓名%s 得分%d\n",move->student.stunum,move->student.name,move->student.score);	
		break;//成功跳出循环 
		}
		move=move->next;
	}
	if(move==NULL)
	printf("没有找到学生信息\n"); 
	printf("输入任意数返回主页面\n");
	getch(); 
	}
void modstudent(node*head){
	system("cls");
	node*move=head->next;
	char name[20];
	printf("请输入需要修改的学生名字\n");
	scanf("%s",name);
	while(move!=NULL){
	if(strcmp(name,move->student.name)==0){
	printf("请输入需要修改的学生成绩\n");
	scanf("%d",&move->student.score);
	remove("./stu.info");// 删除现有的信息文件 
	savestudent(head); //在修改完信息后将全部信息重新储存，避免造成重复储存 
	printf("修改成功\n");
	break;
	} 
	move=move->next;
	}
	if(move==NULL)
	printf("没有找到学生信息\n"); 
	printf("输入任意数返回主页面\n");
		getch();  
	}

void delstudent(node*head){
	system("cls");
	node*move=head;
	char name[20];
	printf("请输入需要删除的学生名字\n");
	scanf("%s",name);
	while(move->next!=NULL){
		if(strcmp(name,move->next->student.name)==0){
			node*p=move->next;//用一个新指针存放需要删除的节点的地址 
			move->next=move->next->next;//让需要删除的节点前后相连 
			free(p);//释放需要删除节点的空间 
			p=NULL;//让p为空防止释放后p为野指针
			remove("./stu.info");
			savestudent(head);//在删除信息后将全部信息重新储存，防止储存的重复  
			printf("删除成功\n"); 
			printf("输入任意数返回主页面\n");
		    getch();
			return;
		}
		move=move->next;
	} 
	if(move->next==NULL)
	printf("没有找到学生信息\n"); 
	printf("输入任意数返回主页面\n");
		getch(); 
}
void sortstudent(node*head){//选择排序 
    system("cls");
	node*pre,*p;
	for(pre=head->next;pre->next!=NULL;pre=pre->next){//让pre指向第一个存放数据节点控制比较次数 
		for(p=pre->next;p!=NULL;p=p->next){//让p指向第二个存放数据的节点让pre所指节点与后面每个节点进行比较 
			if((pre->student.score)<(p->student.score)){//交换数据 
				student temp=pre->student;
				pre->student=p->student;
				p->student=temp;	 
			}
		}
	}
	putoutstudent(head);
}
void savestudent(node*head){//存储每个学生信息 
	FILE*file=fopen("./stu.info","a");//打开文件 ，在当前文件夹创建stu.info文件，a是打开文件来写入,如果文件存在，则写入内容追加到文件末尾；如果文件不存在，则会创建新文件。 
	if(file==NULL){
		printf("打开失败");
		return; 
	} 
	node*move=head->next;
	while(move!=NULL){//遍历链表写入每个学生信息 
		fwrite(&move->student,sizeof(student),1,file);
		// fwrite写入，&move->student写入地方的地址 ，sizeof(student)写入内容大小，1写入数据的个数（次数）， file目标文件的地址 ，返回写入数据的个数 
		move=move->next;
	} 
	fclose(file);//关闭文件 
}
node *readstudent(node*head){//读取学生信息 
	FILE*file=fopen("./stu.info","r");//打开stu.info文件来读取 
	if(file==NULL){
		printf("打开失败");
		return; 
	} 
	node*new_,*move;
	new_=malloc(sizeof(node));//需要把读取的数据存放在另一个地方 
	new_->next=NULL;
	move=head;
	 while((fread(&new_->student,sizeof(student),1,file))==1){//创建链表来存放读取的学生信息 
	 // fread读取，&new_->student用来存放读取到的信息的地址，sizeof(student)读取到的信息大小，1读取的数据个数，file目标文件的地址，返回读取的数据个数 
	 	move->next=new_;
	 	move=new_;
		new_=malloc(sizeof(node));//创建新节点存放下一个学生的信息 ，但会多创建一个空节点 
	    new_->next=NULL; 	
	 }
	 free(new_);//释放多余的节点空间 
	 fclose(file);
	 return head;//将存放读取的数据的地址返回 
} 
 int login(){//实现简单登录 
    struct account user;
	char id[20];
	char an[20];
	int n;
	n=0;
	strcpy(user.id,"yuanshen");
	strcpy(user.an,"qidong!");//初始化账号密码 
	while(n==0){
	printf("输入账号\n");
	gets(id);
	printf("输入密码\n");
	gets(an); 
	if(strcmp(id,user.id)==0&&strcmp(an,user.an)==0){//判断密码账号是否正确 
		n=1;
		return n;
	}
	if(n==0){
		printf("失败\n");
		printf("请重新输入\n");
	}}
 }
