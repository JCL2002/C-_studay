#include<bits/stdc++.h>
using namespace std;
#define Linux true
#define Windows false

#define env Windows  //运行环境Linux/Windows   !!!---请正确切换linux和windows，这关系到内容的显示---!!!

//全局变量定义
int size_book;
int size_reader;
int size_info;
FILE* file=NULL;
char passwd=0;
char password[17];//储存密码字符串
bool show[9]={1,1,1,1,1,1,1,1,1};//自定义显示选项
char file_name[513];
//全局变量定义结束

struct Book{//图书信息结构体
	char book_name[257];//书名
	char book_ISBN[24];//ISBN
	unsigned long long book_id;//图书编号
	char book_writer[33];//作者
	char book_publisher[127];//出版社
	unsigned int book_date;// 出版日期
	char book_edition[33];//版次
	float book_val;//价格
	int number;//剩余数量
};

struct Reader{//读者信息结构体
	char name[33];//姓名
	int age;//年龄
	bool sex;//性别，true-男;false-女
	unsigned long long id;//读者编号
	char address[65];//读者地址
};

struct Info{//借阅信息结构体
	unsigned long long id;//读者编号
	char book_ISBN[24];//ISBN
	unsigned int rent_date;//始租日期
	unsigned int return_date;//终租日期
};

struct Book_l{//方便图书的增删而采用链表结构
	Book book;
	Book_l* next;
};

struct Reader_l{//方便读者的增删而采用的链表结构
	Reader reader;
	Reader_l* next;
};

struct Info_l{//方便借阅信息的增删而采用的链表结构
	Info info;
	Info_l* next;
};

class Book_manager{//图书管理-功能类
	public:
		static Book_l* head;
		static Book_l* current;
		static void book_find(){//图书查找
			char choose;
			if(env){
				system("clear");
			}
			else{
				system("cls");
			}
			cout <<"查找方式：\n1.书名(要加书名号)\n2.ISBN\n3.图书编号\n";
			cin >>choose;getchar();
			char book_name[257];//书名
			char book_ISBN[24];//ISBN
			unsigned long long book_id;//图书编号
			switch(choose){
				case '1':{
					cin >>book_name;
					break;
				}
				case '2':{
					cin >>book_ISBN;
					break;
				}
				case '3':{
					cin >>book_id;
					break;
				}
				default:{
					cout <<"输入有误!";return ;
					break;
				}
			}
			current=head;
			while(current!=NULL){
				if(choose=='1'){//书名
					if(strcmp((current->book).book_name,book_name)==0){
						book_browser(&(current->book));getchar();getchar();
						return ;
					}
				}
				else if(choose=='2'){//ISBN
					if(strcmp((current->book).book_ISBN,book_ISBN)==0){
						book_browser(&(current->book));getchar();getchar();
						return ;
					}
				}
				else{//编号
					if((current->book).book_id==book_id){
						book_browser(&(current->book));getchar();getchar();
						return ;
					}
				}
				current=current->next;
			}
			cout <<"找不到,按回车返回";getchar();getchar();
			return ;
		}
		static void book_add(){//图书上架
			cout <<"第"<<size_book+1<<"本书:"<<endl;
			if(!size_book){
				head=(Book_l*)malloc(sizeof(Book_l));
				head->next=NULL;
				cout <<"请输入书名: ";cin >>(head->book).book_name;
				cout <<"请输入ISBN: ";cin >>(head->book).book_ISBN;
				cout <<"请输入图书编号: ";cin>>(head->book).book_id;
				cout <<"请输入图书作者: ";cin>>(head->book).book_writer;
				cout <<"请输入图书出版社: ";cin>>(head->book).book_publisher;
				cout <<"请输入出版日期(转化成整数): ";cin>>(head->book).book_date;
				cout <<"请输入价格: ";cin>>(head->book).book_val;
				cout <<"请输入图书余量: ";cin>>(head->book).number;
				getchar();
				size_book++;
			}
			else{
				current=head;
				while(current->next!=NULL){//找到链表最后一个
					current=current->next;
				}
				current->next=(Book_l*)malloc(sizeof(Book_l));
				current=current->next;
				current->next=NULL;
				cout <<"请输入书名: ";cin >>(current->book).book_name;
				cout <<"请输入ISBN: ";cin >>(current->book).book_ISBN;
				cout <<"请输入图书编号: ";cin>>(current->book).book_id;
				cout <<"请输入图书作者: ";cin>>(current->book).book_writer;
				cout <<"请输入图书出版社: ";cin>>(current->book).book_publisher;
				cout <<"请输入出版日期(转化成整数): ";cin>>(current->book).book_date;
				cout <<"请输入价格: ";cin>>(current->book).book_val;
				cout <<"请输入图书余量: ";cin>>(current->book).number;
				getchar();
				size_book++;
			}
		}
		static void book_del(){//图书下架
			char choose;
			if(env){
				system("clear");
			}
			else{
				system("cls");
			}
			cout <<"查找方式：\n1.书名(要加书名号)\n2.ISBN\n3.图书编号\n";
			cin >>choose;getchar();
			char book_name[257];//书名
			char book_ISBN[24];//ISBN
			unsigned long long book_id;//图书编号
			switch(choose){
				case '1':{
					cin >>book_name;getchar();
					break;
				}
				case '2':{
					cin >>book_ISBN;getchar();
					break;
				}
				case '3':{
					cin >>book_id;getchar();
					break;
				}
				default:{
					cout <<"输入有误!";getchar();return ;
					break;
				}
			}
			current=head;
			Book_l* Free=NULL;
			if(choose=='1'){//name
				if(strcmp((head->book).book_name,book_name)==0){
					Free=head;
					head=head->next;
					free(Free);
					cout <<"删除成功"<<endl;getchar(); return ;
				}
				else{
					current=head;
					while(current->next!=NULL){
						if(strcmp((current->next->book).book_name,book_name)==0){
							Free=current->next;
							current->next=current->next->next;
							free(Free);
							size_book--;
							cout <<"删除成功"<<endl;getchar(); return ;
						}
						current=current->next;
					}
				}
			}
			else if(choose=='2'){//ISBN
				if(strcmp((head->book).book_ISBN,book_ISBN)==0){
					Free=head;
					head=head->next;
					free(Free);
					size_book--;
					cout <<"删除成功"<<endl;getchar(); return ;
				}
				else{
					current=head;
					while(current->next!=NULL){
						if(strcmp((current->next->book).book_ISBN,book_ISBN)==0){
							Free=current->next;
							current->next=current->next->next;
							free(Free);
							size_book--;
							cout <<"删除成功"<<endl;getchar(); return ;
						}
						current=current->next;
					}
				}
			}
			else{
				if((head->book).book_id==book_id){
					Free=head;
					head=head->next;
					free(Free);
					size_book--;
					cout <<"删除成功"<<endl;getchar(); return ;
				}
				else{
					current=head;
					while(current->next!=NULL){
						if((current->next->book).book_id==book_id){
							Free=current->next;
							current->next=current->next->next;
							free(Free);
							size_book--;
							cout <<"删除成功"<<endl;getchar(); return ;
						}
						current=current->next;
					}
				}
			}
			cout <<"找不到要删除的节点,按回车返回";getchar();getchar();
			return ;
		}
		static void book_change(){//图书修改
			Book* cache=NULL;
			char choose;
			if(env){
				system("clear");
			}
			else{
				system("cls");
			}
			cout <<"查找方式：\n1.书名(要加书名号)\n2.ISBN\n3.图书编号\n";
			cin >>choose;getchar();
			char book_name[257];//书名
			char book_ISBN[24];//ISBN
			unsigned long long book_id;//图书编号
			switch(choose){
				case '1':{
					cin >>book_name;
					break;
				}
				case '2':{
					cin >>book_ISBN;
					break;
				}
				case '3':{
					cin >>book_id;
					break;
				}
				default:{
					cout <<"输入有误!";return ;
					break;
				}
			}
			current=head;
			while(current!=NULL){
				if(choose=='1'){//书名
					if(strcmp((current->book).book_name,book_name)==0){
						cache=&(current->book);
					}
				}
				else if(choose=='2'){//ISBN
					if(strcmp((current->book).book_ISBN,book_ISBN)==0){
						cache=&(current->book);
					}
				}
				else{//编号
					if((current->book).book_id==book_id){
						cache=&(current->book);
					}
				}
				current=current->next;
			}
			if(cache==NULL){cout <<"找不到!\n按回车退出";getchar();getchar();return ;}
			cout <<"请输入书名: ";cin >>cache->book_name;
			cout <<"请输入ISBN: ";cin >>cache->book_ISBN;
			cout <<"请输入图书编号: ";cin>>cache->book_id;
			cout <<"请输入图书作者: ";cin>>cache->book_writer;
			cout <<"请输入图书出版社: ";cin>>cache->book_publisher;
			cout <<"请输入出版日期(转化成整数): ";cin>>cache->book_date;
			cout <<"请输入价格: ";cin>>cache->book_val;
			cout <<"请输入图书余量: ";cin>>cache->number;
			getchar();
		}
		static void book_browser(){//图书浏览-整体浏览
			int i=1;
			current=head;
			while(current!=NULL){
				if(env){
					system("clear");
				}
				else{
					system("cls");
				}
				cout <<"第"<<i<<"本书"<<endl;
				book_browser(&(current->book));
				cout <<"按回车键继续";
				getchar();
				current=current->next;
				i++;
			}
		}
		static void book_browser(Book* book){//图书浏览-单个浏览
			if(book==NULL) return;
			if(show[1]){cout <<"图书名称:";cout << book->book_name<<endl;}
			if(show[2]){cout<<"ISBN:";cout << book->book_ISBN<<endl;}
			if(show[3]){cout <<"图书作者";cout << book->book_writer<<endl;}
			if(show[4]){cout <<"出版社:";cout << book->book_publisher<<endl;}
			if(show[5]){cout <<"出版时间:";cout << book->book_date<<endl;}
			if(show[6]){cout <<"版次:";cout << book->book_edition<<endl;}
			if(show[7]){cout <<"定价:";cout << book->book_val<<endl;}
			if(show[8]){cout <<"数量:";cout << book->number<<endl;}
		}
};
Book_l* Book_manager::head=NULL;
Book_l* Book_manager::current=NULL;
class Reader_manager{//读者管理
	public:
		static Reader_l* head;
		static Reader_l* current;
		static Reader_l* reader_find(){//查找-返回节点指针-用于被调用
			char choose;
			char name[33];//姓名
			unsigned long long id;//读者编号
			if(env){
				system("clear");
			}
			else{
				system("cls");
			}
			cout <<"查找方式：\n1.姓名\n2.读者编号\n";
			cin >>choose;getchar();
			switch (choose){
				case '1':{
					cin >>name;getchar();
					break;
				}
				case '2':{
					cin >>id;getchar();
					break;
				}
				default:{
					cout <<"输入有误!";getchar();return NULL;
					break;
				}
			}
			current=head;
			while(current!=NULL){
				if(choose=='1'){
					if(strcmp((current->reader).name,name)==0){
						return current;
					}
				}
				else{
					if((current->reader).id==id){
						return current;
					}
				}
				current=current->next;
			}
			cout <<"查无此人，按回车继续";getchar();
			return NULL;
		}
		static void reader_search(){//查找并显示单个用户
			Reader_l* cache=NULL;
			cache=reader_find();
			if(cache==NULL) return ;
			cout <<"姓名:"<<(current->reader).name<<endl;
			cout <<"性别:";if((current->reader).sex){cout <<"男"<<endl;}else cout <<"女"<<endl;
			cout <<"年龄:"<<(current->reader).age<<endl;
			cout <<"读者编号:"<<(current->reader).id<<endl;
			cout <<"读者地址:"<<(current->reader).address<<endl;getchar();
		}
		static void reader_browser(){//读者浏览
			Reader_l* cache=head;
			while(cache!=NULL){
				cout <<"姓名:"<<(cache->reader).name<<endl;
				cout <<"性别:";if((cache->reader).sex){cout <<"男"<<endl;}else cout <<"女"<<endl;
				cout <<"年龄:"<<(cache->reader).age<<endl;
				cout <<"读者编号:"<<(cache->reader).id<<endl;
				cout <<"读者地址:"<<(cache->reader).address<<endl;
				cout <<"按回车键继续";getchar();
				cache=cache->next;
			}
		}
		static void reader_add(){//读者增加
			cout <<"第"<<size_reader+1<<"个读者:"<<endl;
			if(!size_reader){
				head=(Reader_l*)malloc(sizeof(Reader_l));
				head->next=NULL;
				cout <<"请输入读者姓名:";cin >>(head->reader).name;
				cout <<"请输入读者年龄:";cin >>(head->reader).age;
				char sex[3];
				cout <<"请输入读者性别(男/女)";cin>>sex;
				if(strcmp(sex,"男")){(head->reader).sex=false;} else{(head->reader).sex=true;}
				cout <<"请输入读者编号:";cin >>(head->reader).id;
				cout <<"请输入读者地址:";cin >>(head->reader).address;
				size_reader++;
				getchar();
			}
			else{
				current=head;
				while(current->next!=NULL){
					current=current->next;
				}
				current->next=(Reader_l*)malloc(sizeof(Reader_l));
				current=current->next;
				current->next=NULL;
				cout <<"请输入读者姓名:";cin >>(current->reader).name;
				cout <<"请输入读者年龄:";cin >>(current->reader).age;
				char sex[3];
				cout <<"请输入读者性别(男/女)";cin>>sex;
				if(strcmp(sex,"男")){(current->reader).sex=false;} else{(current->reader).sex=true;}
				cout <<"请输入读者编号:";cin >>(current->reader).id;
				cout <<"请输入读者地址:";cin >>(current->reader).address;
				size_reader++;
				getchar();
			}
		}
		static void reader_del(){//删除读者
			char choose;
			char name[33];//姓名
			unsigned long long id;//读者编号
			if(env){
				system("clear");
			}
			else{
				system("cls");
			}
			cout <<"查找方式：\n1.姓名\n2.读者编号\n";
			cin >>choose;getchar();
			switch (choose){
				case '1':{
					cin >>name;getchar();
					break;
				}
				case '2':{
					cin >>id;getchar();
					break;
				}
				default:{
					cout <<"输入有误!";getchar();return;
					break;
				}
			}
			if(choose=='1'){
				if(strcmp((head->reader).name,name)){
					head=head->next;
					size_reader--;
					cout <<"删除完毕，按回车键继续"<<endl; getchar();
					return ;
				}
			}
			if(choose=='2'){
				if((head->reader).id==id){
					head=head->next;
					size_reader--;
					cout <<"删除完毕，按回车键继续"<<endl; getchar();
					return ;
				}
			}
			current=head;
			while(current->next!=NULL){
				if(choose=='1'){
					if(strcmp((current->next->reader).name,name)==0){
						Reader_l* FREE=current->next;
						current->next=current->next->next;
						free(FREE);
						cout <<"删除完毕，按回车键继续"<<endl; getchar();
						return ;
					}
				}
				else{
					if((current->next->reader).id==id){
						Reader_l* FREE=current->next;
						current->next=current->next->next;
						free(FREE);
						cout <<"删除完毕，按回车键继续"<<endl; getchar();
						return ;
					}
				}
				current=current->next;
			}
			cout <<"没有这个人，删除失败，按回车键继续"<<endl;getchar();
			return ;
		}
		static void reader_change(){//修改读者信息
			Reader_l* cache=NULL;
			cache=reader_find();
			if(cache==NULL) return ;
			cout <<"前请输入读者姓名:";cin >>(cache->reader).name;
			cout <<"请输入读者年龄:";cin >>(cache->reader).age;
			char sex[3];
			cout <<"请输入读者性别(男/女)";cin>>sex;
			if(strcmp(sex,"男")){(current->reader).sex=false;} else{(current->reader).sex=true;}
			cout <<"请输入读者编号:";cin >>(current->reader).id;
			cout <<"请输入读者地址:";cin >>(current->reader).address;
			cout <<"修改完毕，按回车继续";
			getchar();getchar();
		}
};
Reader_l* Reader_manager::head=NULL;
Reader_l* Reader_manager::current=NULL;
class Info_manager{
	public:
		static Info_l* head;
		static Info_l* current;
		static void book_rent(){//借书
			//限于篇幅，只提供根据ISBN和读者id来借阅的功能
			unsigned long long id;//读者id
			char book_ISBN[24];//图书ISBN
			if(env){
				system("clear");
			}
			else{
				system("cls");
			}
			cout <<"请分别输入借阅者id和图书的ISBN，空格隔开"<<endl;
			cin >>id >>book_ISBN;getchar();
			//检查读者是否存在
			Reader_l* reader_c;
			reader_c=Reader_manager::head;
			while(reader_c!=NULL){
				if((reader_c->reader).id==id){//找到读者，进一步操作
					//检查图书是否存在
					Book_l* book_c;
					book_c=Book_manager::head;
					while(book_c!=NULL){
						if((book_c->book).book_ISBN==book_ISBN){//图书找到，操作条件达到
							//添加一条借阅信息
							if((book_c->book).number==0){
								cout <<"借完了！！！"<<endl;getchar();
							}
							unsigned int rent_date,return_date;//租还日期
							cout <<"请输入当前日期、归还日期，空格隔开，日期化为正整数"<<endl;
							cin >>rent_date >>return_date;getchar();
							if(head==NULL){//一个也没有时
								head=(Info_l*)malloc(sizeof(Info_l));
								(head->info).id=id;
								strcpy((head->info).book_ISBN,book_ISBN);
								(head->info).rent_date=rent_date;
								(head->info).return_date=return_date;
								(book_c->book).number--;//图书余量减一
							}
							else{
								current=head->next;
								while(current->next!=NULL){
									current=current->next;
								}
								current->next=(Info_l*)malloc(sizeof(Info_l));
								((current->next)->info).id=id;
								strcpy(((current->next)->info).book_ISBN,book_ISBN);
								((current->next)->info).rent_date=rent_date;
								((current->next)->info).return_date=return_date;
							}
							return;
						}
						book_c=book_c->next;
					}
					cout <<"图书找不到，借阅失败"<<endl;getchar();
				}
				reader_c=reader_c->next;
			}
			cout <<"找不到读者，借阅失败"<<endl; getchar();
		}
		static void book_return(){//还书
			unsigned long long id;//读者id
			char book_ISBN[24];//图书ISBN
			cout << "请分别输入读者id、图书ISBN，空格隔开"<<endl;
			cin >> id >> book_ISBN;getchar();
			if((head->info).id==id&&strcmp((head->info).book_ISBN,book_ISBN)==0){//头部特判
				head=head->next;
			}
			current=head;
			while(current->next!=NULL){
				if((current->next->info).id==id&&strcmp((current->next->info).book_ISBN,book_ISBN)==0){
					current->next=current->next->next;
				}
			}
			cout <<"没有这一条的借阅记录"<<endl;
		}
};
Info_l* Info_manager::head=NULL;
Info_l* Info_manager::current=NULL;
class File_manager{
	public:
	/*
	 * 归档数据结构定义：
	 * 前4字节代表 全局变量：size_book――结构体Book_l的数量
	 * 第5-8字节代表 全局变量：size_reader――结构体Reader_l的数量
	 * 第9-12字节代表 全局变量：size_info――结构体Info_l的数量
	 * 第13字节：密码表示，为0代表没有密码，不为0代表有密码
	 * 第14-30字节：储存加密后的密码
	 * 第14-sizeof(Book)*"结构体Book_l的数量"-1字节存储
	 * 以此类推
	 * 
	 * 密码定义准则：
	 * 若密码存在，则从14字节开始，每一位都与密码有关，即加密
	 * 恺撒密码：加密时每一位都加上密码位，解码时每一位都减去密码位即可
	 * */
		static void file_creat(){//归档创建
			if(file!=NULL){
				if(env){
					system("clear");
				}
				else{
					system("cls");
				}
				cout <<"已经有打开的文件了!";getchar();
				return ;
			}
			int a[3]={0,0,0};
			char c=0;
			cout <<"请输入文件名（不要用绝对路径的方式）：";cin >>file_name;
			file=fopen(file_name,"wb+");
			if(file==NULL){
				if(env){
					system("clear");
				}
				else{
					system("cls");
				}
				cout <<"!!!归档创建失败，请检查对目标目录有无读写权限!!!";
				getchar();getchar();
			}
			else{
				cout <<"名为："<<file_name<<"的文件创建成功,按回车键继续"<<endl;
				fwrite(a,4,3,file);
				fwrite(&c,1,1,file);
				for(int i=0;i<17;i++){
					fwrite(&c,1,1,file);
				}
				fclose(file);file=NULL;
				getchar();getchar();
			}
		}
		
		
		static void file_open(){//归档打开
			if(file!=NULL){
				if(env){
					system("clear");
				}
				else{
					system("cls");
				}
				cout <<"已经有打开的文件了"<<endl;
				getchar();
				return ;
			}
			else{
				cout <<"请输入要打开的归档的名字：";cin >>file_name;
				file=fopen(file_name,"rb+");
				if(file==NULL){
					if(env){
					system("clear");
					}
					else{
						system("cls");
					}
					cout <<"!!!归档打开失败，请检查对目标目录有无读写权限或者文件不存在!!!";
					getchar();getchar();
				}
				else{
					fread(&size_book,4,1,file);
					fread(&size_reader,4,1,file);
					fread(&size_info,4,1,file);
					fread(&passwd,1,1,file);
					fread(password,1,17,file);
					Book_l* before=NULL;
					Book_manager::current=NULL;//指针复位
					for(int i=0;i<size_book;i++){//Book_l的读取建立
						before=Book_manager::current;
						Book_manager::current=(Book_l*)malloc(sizeof(Book_l));
						if(Book_manager::head==NULL){Book_manager::head=Book_manager::current;}
						fread(&(Book_manager::current->book),sizeof(Book),1,file);
						if(before!=NULL) before->next=Book_manager::current;
						
					}
					if(Book_manager::current!=NULL) Book_manager::current->next=NULL;
					Reader_l* Before=NULL;
					Reader_manager::current=NULL;//指针复位
					for(int i=0;i<size_reader;i++){
						Before=Reader_manager::current;
						Reader_manager::current=(Reader_l*)malloc(sizeof(Reader_l));
						if(Reader_manager::head==NULL){Reader_manager::head=Reader_manager::current;}
						fread(&(Reader_manager::current->reader),sizeof(Reader),1,file);
						Reader_manager::current->next=Before;
						if(Before) Before->next=Reader_manager::current;
					}
					if(Reader_manager::current!=NULL) Reader_manager::current->next=NULL;
					Info_l* BEfore=NULL;
					Info_manager::current=NULL;//指针复位
					for(int i=0;i<size_info;i++){
						BEfore=Info_manager::current;
						Info_manager::current=(Info_l*)malloc(sizeof(Info_l));
						if(Info_manager::head==NULL){Info_manager::head=Info_manager::current;}
						fread(&(Info_manager::current->info),sizeof(Info),1,file);
						Info_manager::current->next=BEfore;
						if(BEfore)BEfore->next=Info_manager::current;
					}
					if(Info_manager::current!=NULL)Info_manager::current->next=NULL;
					if(passwd){//归档有密码保护
						//密码还原
						for(int i=0;i<17;i++){
							password[i]+=passwd;
						}
						cout <<"有密码保护的归档"<<endl;
						for(int i=3;i>0;i--){
							char P[17];
							cout <<"还有"<<i<<"次机会: ";cin >>P;
							if(strcmp(P,password)){
								cout <<"密码错误!"<<endl;
							}
							else{//解码
								Book_manager::current=Book_manager::head;
								while(Book_manager::current!=NULL){
									char* turn=(char*)&(Book_manager::current->book);
									for(int i=0;i<(int)sizeof(Book);i++){
										turn[i]+=passwd;
									}
									Book_manager::current=Book_manager::current->next;
								}
								Reader_manager::current=Reader_manager::head;
								while(Reader_manager::current!=NULL){
									char* turn=(char*)&(Reader_manager::current->reader);
									for(int i=0;i<(int)sizeof(Reader);i++){
										turn[i]+=passwd;
									}
									Reader_manager::current=Reader_manager::current->next;
								}
								Info_manager::current=Info_manager::head;
								while(Info_manager::current!=NULL){
									char* turn=(char*)&(Info_manager::current->info);
									for(int i=0;i<(int)sizeof(Info);i++){
										turn[i]+=passwd;
									}
									Info_manager::current=Info_manager::current->next;
								}
								//解码完毕
								//fclose(file);
								cout <<"归档加载成功,按回车键继续";
								getchar();getchar();
								return ;
							}
						}
						//密码验证失败
						fclose(file);
						exit(0);
					}
					else{//没有密码保护
						//fclose(file);
						cout <<"归档加载成功,按回车键继续";
						getchar();getchar();
						return ;
					}
				}
			}
		}
		
		static void file_save(){//归档保存
			if(file!=NULL){
				fclose(file);
				file=fopen(file_name,"wb+");
				fwrite(&size_book,4,1,file);
				fwrite(&size_reader,4,1,file);
				fwrite(&size_info,4,1,file);
				fwrite(&passwd,1,1,file);
				for(int i=0;i<17;i++){//存入密码
					char cache=password[i]-passwd;
					fwrite(&cache,1,1,file);
				}
				Book_manager::current=Book_manager::head;
				Reader_manager::current=Reader_manager::head;
				Info_manager::current=Info_manager::head;
				Book_l* cache;
				Reader_l* Cache;
				Info_l* CAche;
				while(Book_manager::current!=NULL){
					cache=Book_manager::current->next;
					char* turn=(char*)&(Book_manager::current->book);
					for(int i=0;i<(int)sizeof(Book);i++){
						turn[i]-=passwd;
					}
					fwrite(&(Book_manager::current->book),sizeof(Book),1,file);
					free(Book_manager::current);//释放内存
					Book_manager::current=cache;
				}
				while(Reader_manager::current!=NULL){
					Cache=Reader_manager::current->next;
					char* turn=(char*)&(Reader_manager::current->reader);
					for(int i=0;i<(int)sizeof(Reader);i++){
						turn[i]-=passwd;
					}
					fwrite(&(Reader_manager::current->reader),sizeof(Reader),1,file);
					free(Reader_manager::current);//释放内存
					Reader_manager::current=Cache;
				}
				while(Info_manager::current!=NULL){
					CAche=Info_manager::current->next;
					char* turn=(char*)&(Info_manager::current->info);
					for(int i=0;i<(int)sizeof(Info);i++){
						turn[i]-=passwd;
					}
					fwrite(&(Info_manager::current->info),sizeof(Info),1,file);
					free(Info_manager::current);
					Info_manager::current=CAche;
				}
				fclose(file);file=NULL;
				//指针复位
				Book_manager::current=NULL;
				Book_manager::head=NULL;
				Reader_manager::current=NULL;
				Reader_manager::head=NULL;
				Info_manager::current=NULL;
				Info_manager::head=NULL;
				//复位完毕
				cout <<"归档保存成功,按回车键继续";
				getchar();
			}
			else{
				if(env){
					system("clear");
				}
				else{
					system("cls");
				}
				cout <<"还没有打开的文件!";getchar();
			}
		}
		static void file_close(){//归档关闭（不保存）
			if(file==NULL){
				if(env){
					system("clear");
				}
				else{
					system("cls");
				}
				cout <<"!!!没有已经打开的文件，请用归档管理打开!!!"<<endl;
				getchar();
				return ;
			}
			char makesure;//执行之前的确认
			cout <<"这将放弃所有的改动，但不会修改储存于磁盘上的文件，确认继续吗？ Y/N"<<endl;
			cin >>makesure;
			if(makesure!='Y') return ;
			Book_manager::current=Book_manager::head;
			Reader_manager::current=Reader_manager::head;
			Info_manager::current=Info_manager::head;
			Book_l* cache;
			Reader_l* Cache;
			Info_l* CAche;
			while(Book_manager::current!=NULL){
				cache=Book_manager::current->next;
				free(Book_manager::current);//释放内存
				Book_manager::current=cache;
			}
			while(Reader_manager::current!=NULL){
				Cache=Reader_manager::current->next;
				free(Reader_manager::current);//释放内存
				Reader_manager::current=Cache;
			}
			while(Info_manager::current!=NULL){
				CAche=Info_manager::current->next;
				free(Info_manager::current);//释放内存
				Info_manager::current=CAche;
			}
			//销毁head指针
			Book_manager::head=NULL;
			Reader_manager::head=NULL;
			Info_manager::head=NULL;
			//关闭文件
			fclose(file);file=NULL;getchar();
		}
		
		
		static void file_passwd(){//归档加密
			char origion[17];
			char first[17];
			char second[17];
			if(passwd){//原本有密码
				cout <<"请输入原有密码:";cin >>origion;
				if(strcmp(origion,password)){
					if(env){
						system("clear");
					}
					else{
						system("cls");
					}
					cout <<"密码错误!"<<endl;
					getchar();getchar();
					return ;
				}
				else{
					cout <<"请输入新密码:";cin >>first;
					cout <<"请再次输入以确认:";cin >>second;
					if(strcmp(first,second)){
						if(env){
							system("clear");
						}
						else{
							system("cls");
						}
						cout <<"两次密码不相同，更改失败!";getchar();getchar();
						return ;
					}
					else{
						strcpy(password,first);
						cout <<"加密成功!";getchar();getchar();
						return ;
					}
				}
			}
			else{//原本无密码
				passwd=1+rand()%63;//随机产生密码原值
				cout <<"请输入密码:";cin >>first;
				cout <<"请再次输入以确认:";cin >>second;
				if(strcmp(first,second)){
					if(env){
						system("clear");
					}
					else{
						system("cls");
					}
					cout <<"两次密码不同，加密失败!";
					passwd=0;
					getchar();getchar();
				}
				else{
					cout <<"加密成功!";getchar();getchar();
					strcpy(password,first);
				}
			}
		}
};
void Book_manager_interface(){
	if(file==NULL){
		if(env){
			system("clear");
		}
		else{
			system("cls");
		}
		cout <<"!!!没有已经打开的文件，请用归档管理打开!!!"<<endl;
		getchar();
		return ;
	}
	char choose;
	while(true){
		if(env){
			system("clear");
		}
		else{
			system("cls");
		}
		cout <<"------------------图书管理--------------------"<<endl;
		cout <<"---             1.图书浏览                 ---"<<endl;
		cout <<"---             2.图书查找                 ---"<<endl;
		cout <<"---             3.图书上架                 ---"<<endl;
		cout <<"---             4.图书下架                 ---"<<endl;
		cout <<"---             5.图书修改                 ---"<<endl;
		cout <<"---             6.个性化显示               ---"<<endl;
		cout <<"---             7.返回上一级               ---"<<endl;
		cout <<"----------------------------------------------"<<endl;
		choose=getchar();getchar();
		switch(choose){
			case '1':{
				Book_manager::book_browser();
				getchar();//暂停&显示
				break;
			}
			case '2':{
				Book_manager::book_find();
				break;
			}
			case '3':{
				Book_manager::book_add();
				break;
			}
			case '4':{
				Book_manager::book_del();
				break;
			}
			case '5':{
				Book_manager::book_change();
				break;
			}
			case '6':{
				bool flag=true;
				while(flag){
					if(env){
						system("clear");
					}
					else{
						system("cls");
					}
					cout <<"------------------个性化显示------------------"<<endl;
					cout <<"---请输入对应项目前面的编号来打开/关闭其显示---"<<endl;
					cout <<"---             1.图书名称(";if(show[1]){cout <<"show)            ---"<<endl;}else{cout <<"unshow)          ---"<<endl;}
					cout <<"---             2.ISBN    (";if(show[2]){cout <<"show)            ---"<<endl;}else{cout <<"unshow)          ---"<<endl;}
					cout <<"---             3.图书作者(";if(show[3]){cout <<"show)            ---"<<endl;}else{cout <<"unshow)          ---"<<endl;}
					cout <<"---             4.出版社  (";if(show[4]){cout <<"show)            ---"<<endl;}else{cout <<"unshow)          ---"<<endl;}
					cout <<"---             5.出版时间(";if(show[5]){cout <<"show)            ---"<<endl;}else{cout <<"unshow)          ---"<<endl;}
					cout <<"---             6.版次    (";if(show[6]){cout <<"show)            ---"<<endl;}else{cout <<"unshow)          ---"<<endl;}
					cout <<"---             7.定价    (";if(show[7]){cout <<"show)            ---"<<endl;}else{cout <<"unshow)          ---"<<endl;}
					cout <<"---             8.数量    (";if(show[8]){cout <<"show)            ---"<<endl;}else{cout <<"unshow)          ---"<<endl;}
					cout <<"---             9.返回                      ---"<<endl;
					choose=getchar();getchar();
					switch(choose){
						case '1':{
							if(show[1]){show[1]=false;}
							else{show[1]=true;}
							break;
						}
						case '2':{
							if(show[2]){show[2]=false;}
							else{show[2]=true;}
							break;
						}
						case '3':{
							if(show[3]){show[3]=false;}
							else{show[3]=true;}
							break;
						}
						case '4':{
							if(show[4]){show[4]=false;}
							else{show[4]=true;}
							break;
						}
						case '5':{
							if(show[5]){show[5]=false;}
							else{show[5]=true;}
							break;
						}
						case '6':{
							if(show[6]){show[6]=false;}
							else{show[6]=true;}
							break;
						}
						case '7':{
							if(show[7]){show[7]=false;}
							else{show[7]=true;}
							break;
						}
						case '8':{
							if(show[8]){show[8]=false;}
							else{show[8]=true;}
							break;
						}
						case '9':{
							flag=false;
							break;
						}
						default:{
							if(env){
								system("clear");
							}
							else{
								system("cls");
							}
							cout <<"!!!输入有误，请重新输入!!!\n按回车返回上一级"<<endl;getchar();
						}
					}
				}
				break;
			}
			case '7':{
				return ;
				break;
			}
			default:{
				if(env){
					system("clear");
					cout <<"!!!输入有误，请重新输入!!!\n按回车返回上一级"<<endl;getchar();
				}
				else{
					system("cls");
					cout <<"!!!输入有误，请重新输入!!!\n按回车返回上一级"<<endl;getchar();
				}
				break;
			}
		}
	}
}

void Reader_manager_interface(){
	if(file==NULL){
		if(env){
			system("clear");
		}
		else{
			system("cls");
		}
		cout <<"!!!没有已经打开的文件，请用归档管理打开!!!"<<endl;
		getchar();
		return ;
	}
	char choose;
	while(true){
		if(env){
			system("clear");
		}
		else{
			system("cls");
		}
		cout <<"------------------读者管理--------------------"<<endl;
		cout <<"---             1.读者浏览                 ---"<<endl;
		cout <<"---             2.读者查找                 ---"<<endl;
		cout <<"---             3.读者增加                 ---"<<endl;
		cout <<"---             4.读者删除                 ---"<<endl;
		cout <<"---             5.读者修改                 ---"<<endl;
		cout <<"---             6.返回上级                 ---"<<endl;
		cout <<"----------------------------------------------"<<endl;
		choose=getchar();getchar();
		switch(choose){
			case '1':{
				Reader_manager::reader_browser();
				break;
			}
			case '2':{
				Reader_manager::reader_search();
				break;
			}
			case '3':{
				Reader_manager::reader_add();
				break;
			}
			case '4':{
				Reader_manager::reader_del();
				break;
			}
			case '5':{
				Reader_manager::reader_change();
				break;
			}
			case '6':{
				return ;
				break;
			}
			default:{
				if(env){
					system("clear");
				}
				else{
					system("cls");
				}
				cout <<"!!!输入有误，请重新输入!!!\n按回车返回上一级"<<endl;getchar();
				break;
			}
		}
	}
}

void Info_manager_interface(){
	if(file==NULL){
		if(env){
			system("clear");
		}
		else{
			system("cls");
		}
		cout <<"!!!没有已经打开的文件，请用归档管理打开!!!"<<endl;
		getchar();
		return ;
	}
	char choose;
	while(true){
		if(env){
			system("clear");
		}
		else{
			system("cls");
		}
		cout <<"------------------借阅管理--------------------"<<endl;
		cout <<"---             1.图书借阅                 ---"<<endl;
		cout <<"---             2.图书归还                 ---"<<endl;
		cout <<"---             3.返回上级                 ---"<<endl;
		cout <<"----------------------------------------------"<<endl;
		choose=getchar();getchar();
		switch(choose){
			case '1':{
				Info_manager::book_rent();
				break;
			}
			case '2':{
				Info_manager::book_return();
				break;
			}
			case '3':{
				return ;
				break;
			}
			default:{
				if(env){
					system("clear");
				}
				else{
					system("cls");
				}
				cout <<"!!!输入有误，请重新输入!!!\n按回车返回上一级"<<endl;getchar();
				break;
			}
		}
	}
}

void File_manager_interface(){
	char choose;
	while(true){
		if(env){
			system("clear");
		}
		else{
			system("cls");
		}
		cout <<"------------------归档管理--------------------"<<endl;
		cout <<"---             1.归档创建                 ---"<<endl;
		cout <<"---             2.归档打开                 ---"<<endl;
		cout <<"---             3.归档保存并关闭           ---"<<endl;
		cout <<"---             4.归档不保存并关闭         ---"<<endl;
		cout <<"---             5.归档加密                 ---"<<endl;
		cout <<"---             6.返回上级                 ---"<<endl;
		cout <<"----------------------------------------------"<<endl;
		choose=getchar();getchar();
		switch(choose){
			case '1':{
				File_manager::file_creat();
				break;
			}
			case '2':{
				File_manager::file_open();
				break;
			}
			case '3':{
				File_manager::file_save();
				break;
			}
			case '4':{
				File_manager::file_close();
				break;
			}
			case '5':{
				File_manager::file_passwd();
				break;
			}
			case '6':{
				return ;
				break;
			}
			default:{
				if(env){
					system("clear");
				}
				else{
					system("cls");
				}
				cout <<"!!!输入有误，请重新输入!!!\n按回车返回上一级"<<endl;getchar();
				break;
				break;
			}
		}
	}
}

void function_choose(){//提供交互界面，选择功能
	while(true){
		if(env){
			system("clear");
		}
		else{
			system("cls");
		}
		cout <<"-----------图书借阅信息管理程序v1.0----------"<<endl;
		cout <<"---             1.图书管理                ---"<<endl;
		cout <<"---             2.读者管理                ---"<<endl;
		cout <<"---             3.图书借阅                ---"<<endl;
		cout <<"---             4.归档管理                ---"<<endl;
		cout <<"---             5.退出程序                ---"<<endl;
		cout <<"------------------功能选择-------------------"<<endl;
		if(file==NULL){
		cout <<"------------------文件状态-------------------"<<endl;
		cout <<"--- 没有文件被加载，请使用归档管理加载文件 --"<<endl;
		cout <<"---------------------------------------------"<<endl;
		}
		else{
		cout <<"------------------文件状态-------------------"<<endl;
		cout <<"---   加密状态:";
		if(passwd){
								cout <<"已经加密"<<"                ---"<<endl;
		}
		else{
								cout <<"未加密"<<"                     ---"<<endl;
		}
		cout <<"---------------------------------------------"<<endl;
		}
		char choose;scanf("%c",&choose);getchar();
		switch(choose){
			
			case '1':{
				Book_manager_interface();
				break;
			}
			case '2':{
				Reader_manager_interface();
				break;
			}
			case '3':{
				Info_manager_interface();
				break;
			}
			case '4':{
				File_manager_interface();
				break;
			}
			case '5':{
				if(file!=NULL){
					if(env){
						system("clear");
					}
					else{
						system("cls");
					}
					cout <<"!!!还有文件未保存，请使用归档管理保存它!!!\n按回车返回上一级"<<endl;getchar();
				}
				else{
					exit(0);
				}
				break;
			}
			default:{
				if(env){
					system("clear");
					cout <<"!!!输入有误，请重新输入!!!\n按回车返回上一级"<<endl;getchar();
				}
				else{
					system("cls");
					cout <<"!!!输入有误，请重新输入!!!\n按回车返回上一级"<<endl;getchar();
				}
				break;
			}
		}
	}
}
int main(){
	if(env){
		system("clear");
	}
	else{
		system("cls");
	}
	srand(time(NULL));
	function_choose();
	return 0;
}

/*
 程序作者：姜春磊
 学号：2000170131
 班级：计科2005/计科201
 日期：2021/06/21-2021/07/18
 编译环境：kubuntu 20.02.2LTS/Windows10 1903
 内核版本：5.8.0-48-generic
 编译器：g++
 编译器版本：g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
 */
