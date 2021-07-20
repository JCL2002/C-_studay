#include<bits/stdc++.h>
using namespace std;
#define Linux true
#define Windows false

#define env Windows  //���л���Linux/Windows   !!!---����ȷ�л�linux��windows�����ϵ�����ݵ���ʾ---!!!

//ȫ�ֱ�������
int size_book;
int size_reader;
int size_info;
FILE* file=NULL;
char passwd=0;
char password[17];//���������ַ���
bool show[9]={1,1,1,1,1,1,1,1,1};//�Զ�����ʾѡ��
char file_name[513];
//ȫ�ֱ����������

struct Book{//ͼ����Ϣ�ṹ��
	char book_name[257];//����
	char book_ISBN[24];//ISBN
	unsigned long long book_id;//ͼ����
	char book_writer[33];//����
	char book_publisher[127];//������
	unsigned int book_date;// ��������
	char book_edition[33];//���
	float book_val;//�۸�
	int number;//ʣ������
};

struct Reader{//������Ϣ�ṹ��
	char name[33];//����
	int age;//����
	bool sex;//�Ա�true-��;false-Ů
	unsigned long long id;//���߱��
	char address[65];//���ߵ�ַ
};

struct Info{//������Ϣ�ṹ��
	unsigned long long id;//���߱��
	char book_ISBN[24];//ISBN
	unsigned int rent_date;//ʼ������
	unsigned int return_date;//��������
};

struct Book_l{//����ͼ�����ɾ����������ṹ
	Book book;
	Book_l* next;
};

struct Reader_l{//������ߵ���ɾ�����õ�����ṹ
	Reader reader;
	Reader_l* next;
};

struct Info_l{//���������Ϣ����ɾ�����õ�����ṹ
	Info info;
	Info_l* next;
};

class Book_manager{//ͼ�����-������
	public:
		static Book_l* head;
		static Book_l* current;
		static void book_find(){//ͼ�����
			char choose;
			if(env){
				system("clear");
			}
			else{
				system("cls");
			}
			cout <<"���ҷ�ʽ��\n1.����(Ҫ��������)\n2.ISBN\n3.ͼ����\n";
			cin >>choose;getchar();
			char book_name[257];//����
			char book_ISBN[24];//ISBN
			unsigned long long book_id;//ͼ����
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
					cout <<"��������!";return ;
					break;
				}
			}
			current=head;
			while(current!=NULL){
				if(choose=='1'){//����
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
				else{//���
					if((current->book).book_id==book_id){
						book_browser(&(current->book));getchar();getchar();
						return ;
					}
				}
				current=current->next;
			}
			cout <<"�Ҳ���,���س�����";getchar();getchar();
			return ;
		}
		static void book_add(){//ͼ���ϼ�
			cout <<"��"<<size_book+1<<"����:"<<endl;
			if(!size_book){
				head=(Book_l*)malloc(sizeof(Book_l));
				head->next=NULL;
				cout <<"����������: ";cin >>(head->book).book_name;
				cout <<"������ISBN: ";cin >>(head->book).book_ISBN;
				cout <<"������ͼ����: ";cin>>(head->book).book_id;
				cout <<"������ͼ������: ";cin>>(head->book).book_writer;
				cout <<"������ͼ�������: ";cin>>(head->book).book_publisher;
				cout <<"�������������(ת��������): ";cin>>(head->book).book_date;
				cout <<"������۸�: ";cin>>(head->book).book_val;
				cout <<"������ͼ������: ";cin>>(head->book).number;
				getchar();
				size_book++;
			}
			else{
				current=head;
				while(current->next!=NULL){//�ҵ��������һ��
					current=current->next;
				}
				current->next=(Book_l*)malloc(sizeof(Book_l));
				current=current->next;
				current->next=NULL;
				cout <<"����������: ";cin >>(current->book).book_name;
				cout <<"������ISBN: ";cin >>(current->book).book_ISBN;
				cout <<"������ͼ����: ";cin>>(current->book).book_id;
				cout <<"������ͼ������: ";cin>>(current->book).book_writer;
				cout <<"������ͼ�������: ";cin>>(current->book).book_publisher;
				cout <<"�������������(ת��������): ";cin>>(current->book).book_date;
				cout <<"������۸�: ";cin>>(current->book).book_val;
				cout <<"������ͼ������: ";cin>>(current->book).number;
				getchar();
				size_book++;
			}
		}
		static void book_del(){//ͼ���¼�
			char choose;
			if(env){
				system("clear");
			}
			else{
				system("cls");
			}
			cout <<"���ҷ�ʽ��\n1.����(Ҫ��������)\n2.ISBN\n3.ͼ����\n";
			cin >>choose;getchar();
			char book_name[257];//����
			char book_ISBN[24];//ISBN
			unsigned long long book_id;//ͼ����
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
					cout <<"��������!";getchar();return ;
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
					cout <<"ɾ���ɹ�"<<endl;getchar(); return ;
				}
				else{
					current=head;
					while(current->next!=NULL){
						if(strcmp((current->next->book).book_name,book_name)==0){
							Free=current->next;
							current->next=current->next->next;
							free(Free);
							size_book--;
							cout <<"ɾ���ɹ�"<<endl;getchar(); return ;
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
					cout <<"ɾ���ɹ�"<<endl;getchar(); return ;
				}
				else{
					current=head;
					while(current->next!=NULL){
						if(strcmp((current->next->book).book_ISBN,book_ISBN)==0){
							Free=current->next;
							current->next=current->next->next;
							free(Free);
							size_book--;
							cout <<"ɾ���ɹ�"<<endl;getchar(); return ;
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
					cout <<"ɾ���ɹ�"<<endl;getchar(); return ;
				}
				else{
					current=head;
					while(current->next!=NULL){
						if((current->next->book).book_id==book_id){
							Free=current->next;
							current->next=current->next->next;
							free(Free);
							size_book--;
							cout <<"ɾ���ɹ�"<<endl;getchar(); return ;
						}
						current=current->next;
					}
				}
			}
			cout <<"�Ҳ���Ҫɾ���Ľڵ�,���س�����";getchar();getchar();
			return ;
		}
		static void book_change(){//ͼ���޸�
			Book* cache=NULL;
			char choose;
			if(env){
				system("clear");
			}
			else{
				system("cls");
			}
			cout <<"���ҷ�ʽ��\n1.����(Ҫ��������)\n2.ISBN\n3.ͼ����\n";
			cin >>choose;getchar();
			char book_name[257];//����
			char book_ISBN[24];//ISBN
			unsigned long long book_id;//ͼ����
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
					cout <<"��������!";return ;
					break;
				}
			}
			current=head;
			while(current!=NULL){
				if(choose=='1'){//����
					if(strcmp((current->book).book_name,book_name)==0){
						cache=&(current->book);
					}
				}
				else if(choose=='2'){//ISBN
					if(strcmp((current->book).book_ISBN,book_ISBN)==0){
						cache=&(current->book);
					}
				}
				else{//���
					if((current->book).book_id==book_id){
						cache=&(current->book);
					}
				}
				current=current->next;
			}
			if(cache==NULL){cout <<"�Ҳ���!\n���س��˳�";getchar();getchar();return ;}
			cout <<"����������: ";cin >>cache->book_name;
			cout <<"������ISBN: ";cin >>cache->book_ISBN;
			cout <<"������ͼ����: ";cin>>cache->book_id;
			cout <<"������ͼ������: ";cin>>cache->book_writer;
			cout <<"������ͼ�������: ";cin>>cache->book_publisher;
			cout <<"�������������(ת��������): ";cin>>cache->book_date;
			cout <<"������۸�: ";cin>>cache->book_val;
			cout <<"������ͼ������: ";cin>>cache->number;
			getchar();
		}
		static void book_browser(){//ͼ�����-�������
			int i=1;
			current=head;
			while(current!=NULL){
				if(env){
					system("clear");
				}
				else{
					system("cls");
				}
				cout <<"��"<<i<<"����"<<endl;
				book_browser(&(current->book));
				cout <<"���س�������";
				getchar();
				current=current->next;
				i++;
			}
		}
		static void book_browser(Book* book){//ͼ�����-�������
			if(book==NULL) return;
			if(show[1]){cout <<"ͼ������:";cout << book->book_name<<endl;}
			if(show[2]){cout<<"ISBN:";cout << book->book_ISBN<<endl;}
			if(show[3]){cout <<"ͼ������";cout << book->book_writer<<endl;}
			if(show[4]){cout <<"������:";cout << book->book_publisher<<endl;}
			if(show[5]){cout <<"����ʱ��:";cout << book->book_date<<endl;}
			if(show[6]){cout <<"���:";cout << book->book_edition<<endl;}
			if(show[7]){cout <<"����:";cout << book->book_val<<endl;}
			if(show[8]){cout <<"����:";cout << book->number<<endl;}
		}
};
Book_l* Book_manager::head=NULL;
Book_l* Book_manager::current=NULL;
class Reader_manager{//���߹���
	public:
		static Reader_l* head;
		static Reader_l* current;
		static Reader_l* reader_find(){//����-���ؽڵ�ָ��-���ڱ�����
			char choose;
			char name[33];//����
			unsigned long long id;//���߱��
			if(env){
				system("clear");
			}
			else{
				system("cls");
			}
			cout <<"���ҷ�ʽ��\n1.����\n2.���߱��\n";
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
					cout <<"��������!";getchar();return NULL;
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
			cout <<"���޴��ˣ����س�����";getchar();
			return NULL;
		}
		static void reader_search(){//���Ҳ���ʾ�����û�
			Reader_l* cache=NULL;
			cache=reader_find();
			if(cache==NULL) return ;
			cout <<"����:"<<(current->reader).name<<endl;
			cout <<"�Ա�:";if((current->reader).sex){cout <<"��"<<endl;}else cout <<"Ů"<<endl;
			cout <<"����:"<<(current->reader).age<<endl;
			cout <<"���߱��:"<<(current->reader).id<<endl;
			cout <<"���ߵ�ַ:"<<(current->reader).address<<endl;getchar();
		}
		static void reader_browser(){//�������
			Reader_l* cache=head;
			while(cache!=NULL){
				cout <<"����:"<<(cache->reader).name<<endl;
				cout <<"�Ա�:";if((cache->reader).sex){cout <<"��"<<endl;}else cout <<"Ů"<<endl;
				cout <<"����:"<<(cache->reader).age<<endl;
				cout <<"���߱��:"<<(cache->reader).id<<endl;
				cout <<"���ߵ�ַ:"<<(cache->reader).address<<endl;
				cout <<"���س�������";getchar();
				cache=cache->next;
			}
		}
		static void reader_add(){//��������
			cout <<"��"<<size_reader+1<<"������:"<<endl;
			if(!size_reader){
				head=(Reader_l*)malloc(sizeof(Reader_l));
				head->next=NULL;
				cout <<"�������������:";cin >>(head->reader).name;
				cout <<"�������������:";cin >>(head->reader).age;
				char sex[3];
				cout <<"����������Ա�(��/Ů)";cin>>sex;
				if(strcmp(sex,"��")){(head->reader).sex=false;} else{(head->reader).sex=true;}
				cout <<"��������߱��:";cin >>(head->reader).id;
				cout <<"��������ߵ�ַ:";cin >>(head->reader).address;
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
				cout <<"�������������:";cin >>(current->reader).name;
				cout <<"�������������:";cin >>(current->reader).age;
				char sex[3];
				cout <<"����������Ա�(��/Ů)";cin>>sex;
				if(strcmp(sex,"��")){(current->reader).sex=false;} else{(current->reader).sex=true;}
				cout <<"��������߱��:";cin >>(current->reader).id;
				cout <<"��������ߵ�ַ:";cin >>(current->reader).address;
				size_reader++;
				getchar();
			}
		}
		static void reader_del(){//ɾ������
			char choose;
			char name[33];//����
			unsigned long long id;//���߱��
			if(env){
				system("clear");
			}
			else{
				system("cls");
			}
			cout <<"���ҷ�ʽ��\n1.����\n2.���߱��\n";
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
					cout <<"��������!";getchar();return;
					break;
				}
			}
			if(choose=='1'){
				if(strcmp((head->reader).name,name)){
					head=head->next;
					size_reader--;
					cout <<"ɾ����ϣ����س�������"<<endl; getchar();
					return ;
				}
			}
			if(choose=='2'){
				if((head->reader).id==id){
					head=head->next;
					size_reader--;
					cout <<"ɾ����ϣ����س�������"<<endl; getchar();
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
						cout <<"ɾ����ϣ����س�������"<<endl; getchar();
						return ;
					}
				}
				else{
					if((current->next->reader).id==id){
						Reader_l* FREE=current->next;
						current->next=current->next->next;
						free(FREE);
						cout <<"ɾ����ϣ����س�������"<<endl; getchar();
						return ;
					}
				}
				current=current->next;
			}
			cout <<"û������ˣ�ɾ��ʧ�ܣ����س�������"<<endl;getchar();
			return ;
		}
		static void reader_change(){//�޸Ķ�����Ϣ
			Reader_l* cache=NULL;
			cache=reader_find();
			if(cache==NULL) return ;
			cout <<"ǰ�������������:";cin >>(cache->reader).name;
			cout <<"�������������:";cin >>(cache->reader).age;
			char sex[3];
			cout <<"����������Ա�(��/Ů)";cin>>sex;
			if(strcmp(sex,"��")){(current->reader).sex=false;} else{(current->reader).sex=true;}
			cout <<"��������߱��:";cin >>(current->reader).id;
			cout <<"��������ߵ�ַ:";cin >>(current->reader).address;
			cout <<"�޸���ϣ����س�����";
			getchar();getchar();
		}
};
Reader_l* Reader_manager::head=NULL;
Reader_l* Reader_manager::current=NULL;
class Info_manager{
	public:
		static Info_l* head;
		static Info_l* current;
		static void book_rent(){//����
			//����ƪ����ֻ�ṩ����ISBN�Ͷ���id�����ĵĹ���
			unsigned long long id;//����id
			char book_ISBN[24];//ͼ��ISBN
			if(env){
				system("clear");
			}
			else{
				system("cls");
			}
			cout <<"��ֱ����������id��ͼ���ISBN���ո����"<<endl;
			cin >>id >>book_ISBN;getchar();
			//�������Ƿ����
			Reader_l* reader_c;
			reader_c=Reader_manager::head;
			while(reader_c!=NULL){
				if((reader_c->reader).id==id){//�ҵ����ߣ���һ������
					//���ͼ���Ƿ����
					Book_l* book_c;
					book_c=Book_manager::head;
					while(book_c!=NULL){
						if((book_c->book).book_ISBN==book_ISBN){//ͼ���ҵ������������ﵽ
							//���һ��������Ϣ
							if((book_c->book).number==0){
								cout <<"�����ˣ�����"<<endl;getchar();
							}
							unsigned int rent_date,return_date;//�⻹����
							cout <<"�����뵱ǰ���ڡ��黹���ڣ��ո���������ڻ�Ϊ������"<<endl;
							cin >>rent_date >>return_date;getchar();
							if(head==NULL){//һ��Ҳû��ʱ
								head=(Info_l*)malloc(sizeof(Info_l));
								(head->info).id=id;
								strcpy((head->info).book_ISBN,book_ISBN);
								(head->info).rent_date=rent_date;
								(head->info).return_date=return_date;
								(book_c->book).number--;//ͼ��������һ
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
					cout <<"ͼ���Ҳ���������ʧ��"<<endl;getchar();
				}
				reader_c=reader_c->next;
			}
			cout <<"�Ҳ������ߣ�����ʧ��"<<endl; getchar();
		}
		static void book_return(){//����
			unsigned long long id;//����id
			char book_ISBN[24];//ͼ��ISBN
			cout << "��ֱ��������id��ͼ��ISBN���ո����"<<endl;
			cin >> id >> book_ISBN;getchar();
			if((head->info).id==id&&strcmp((head->info).book_ISBN,book_ISBN)==0){//ͷ������
				head=head->next;
			}
			current=head;
			while(current->next!=NULL){
				if((current->next->info).id==id&&strcmp((current->next->info).book_ISBN,book_ISBN)==0){
					current->next=current->next->next;
				}
			}
			cout <<"û����һ���Ľ��ļ�¼"<<endl;
		}
};
Info_l* Info_manager::head=NULL;
Info_l* Info_manager::current=NULL;
class File_manager{
	public:
	/*
	 * �鵵���ݽṹ���壺
	 * ǰ4�ֽڴ��� ȫ�ֱ�����size_book�D�D�ṹ��Book_l������
	 * ��5-8�ֽڴ��� ȫ�ֱ�����size_reader�D�D�ṹ��Reader_l������
	 * ��9-12�ֽڴ��� ȫ�ֱ�����size_info�D�D�ṹ��Info_l������
	 * ��13�ֽڣ������ʾ��Ϊ0����û�����룬��Ϊ0����������
	 * ��14-30�ֽڣ�������ܺ������
	 * ��14-sizeof(Book)*"�ṹ��Book_l������"-1�ֽڴ洢
	 * �Դ�����
	 * 
	 * ���붨��׼��
	 * ��������ڣ����14�ֽڿ�ʼ��ÿһλ���������йأ�������
	 * �������룺����ʱÿһλ����������λ������ʱÿһλ����ȥ����λ����
	 * */
		static void file_creat(){//�鵵����
			if(file!=NULL){
				if(env){
					system("clear");
				}
				else{
					system("cls");
				}
				cout <<"�Ѿ��д򿪵��ļ���!";getchar();
				return ;
			}
			int a[3]={0,0,0};
			char c=0;
			cout <<"�������ļ�������Ҫ�þ���·���ķ�ʽ����";cin >>file_name;
			file=fopen(file_name,"wb+");
			if(file==NULL){
				if(env){
					system("clear");
				}
				else{
					system("cls");
				}
				cout <<"!!!�鵵����ʧ�ܣ������Ŀ��Ŀ¼���޶�дȨ��!!!";
				getchar();getchar();
			}
			else{
				cout <<"��Ϊ��"<<file_name<<"���ļ������ɹ�,���س�������"<<endl;
				fwrite(a,4,3,file);
				fwrite(&c,1,1,file);
				for(int i=0;i<17;i++){
					fwrite(&c,1,1,file);
				}
				fclose(file);file=NULL;
				getchar();getchar();
			}
		}
		
		
		static void file_open(){//�鵵��
			if(file!=NULL){
				if(env){
					system("clear");
				}
				else{
					system("cls");
				}
				cout <<"�Ѿ��д򿪵��ļ���"<<endl;
				getchar();
				return ;
			}
			else{
				cout <<"������Ҫ�򿪵Ĺ鵵�����֣�";cin >>file_name;
				file=fopen(file_name,"rb+");
				if(file==NULL){
					if(env){
					system("clear");
					}
					else{
						system("cls");
					}
					cout <<"!!!�鵵��ʧ�ܣ������Ŀ��Ŀ¼���޶�дȨ�޻����ļ�������!!!";
					getchar();getchar();
				}
				else{
					fread(&size_book,4,1,file);
					fread(&size_reader,4,1,file);
					fread(&size_info,4,1,file);
					fread(&passwd,1,1,file);
					fread(password,1,17,file);
					Book_l* before=NULL;
					Book_manager::current=NULL;//ָ�븴λ
					for(int i=0;i<size_book;i++){//Book_l�Ķ�ȡ����
						before=Book_manager::current;
						Book_manager::current=(Book_l*)malloc(sizeof(Book_l));
						if(Book_manager::head==NULL){Book_manager::head=Book_manager::current;}
						fread(&(Book_manager::current->book),sizeof(Book),1,file);
						if(before!=NULL) before->next=Book_manager::current;
						
					}
					if(Book_manager::current!=NULL) Book_manager::current->next=NULL;
					Reader_l* Before=NULL;
					Reader_manager::current=NULL;//ָ�븴λ
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
					Info_manager::current=NULL;//ָ�븴λ
					for(int i=0;i<size_info;i++){
						BEfore=Info_manager::current;
						Info_manager::current=(Info_l*)malloc(sizeof(Info_l));
						if(Info_manager::head==NULL){Info_manager::head=Info_manager::current;}
						fread(&(Info_manager::current->info),sizeof(Info),1,file);
						Info_manager::current->next=BEfore;
						if(BEfore)BEfore->next=Info_manager::current;
					}
					if(Info_manager::current!=NULL)Info_manager::current->next=NULL;
					if(passwd){//�鵵�����뱣��
						//���뻹ԭ
						for(int i=0;i<17;i++){
							password[i]+=passwd;
						}
						cout <<"�����뱣���Ĺ鵵"<<endl;
						for(int i=3;i>0;i--){
							char P[17];
							cout <<"����"<<i<<"�λ���: ";cin >>P;
							if(strcmp(P,password)){
								cout <<"�������!"<<endl;
							}
							else{//����
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
								//�������
								//fclose(file);
								cout <<"�鵵���سɹ�,���س�������";
								getchar();getchar();
								return ;
							}
						}
						//������֤ʧ��
						fclose(file);
						exit(0);
					}
					else{//û�����뱣��
						//fclose(file);
						cout <<"�鵵���سɹ�,���س�������";
						getchar();getchar();
						return ;
					}
				}
			}
		}
		
		static void file_save(){//�鵵����
			if(file!=NULL){
				fclose(file);
				file=fopen(file_name,"wb+");
				fwrite(&size_book,4,1,file);
				fwrite(&size_reader,4,1,file);
				fwrite(&size_info,4,1,file);
				fwrite(&passwd,1,1,file);
				for(int i=0;i<17;i++){//��������
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
					free(Book_manager::current);//�ͷ��ڴ�
					Book_manager::current=cache;
				}
				while(Reader_manager::current!=NULL){
					Cache=Reader_manager::current->next;
					char* turn=(char*)&(Reader_manager::current->reader);
					for(int i=0;i<(int)sizeof(Reader);i++){
						turn[i]-=passwd;
					}
					fwrite(&(Reader_manager::current->reader),sizeof(Reader),1,file);
					free(Reader_manager::current);//�ͷ��ڴ�
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
				//ָ�븴λ
				Book_manager::current=NULL;
				Book_manager::head=NULL;
				Reader_manager::current=NULL;
				Reader_manager::head=NULL;
				Info_manager::current=NULL;
				Info_manager::head=NULL;
				//��λ���
				cout <<"�鵵����ɹ�,���س�������";
				getchar();
			}
			else{
				if(env){
					system("clear");
				}
				else{
					system("cls");
				}
				cout <<"��û�д򿪵��ļ�!";getchar();
			}
		}
		static void file_close(){//�鵵�رգ������棩
			if(file==NULL){
				if(env){
					system("clear");
				}
				else{
					system("cls");
				}
				cout <<"!!!û���Ѿ��򿪵��ļ������ù鵵�����!!!"<<endl;
				getchar();
				return ;
			}
			char makesure;//ִ��֮ǰ��ȷ��
			cout <<"�⽫�������еĸĶ����������޸Ĵ����ڴ����ϵ��ļ���ȷ�ϼ����� Y/N"<<endl;
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
				free(Book_manager::current);//�ͷ��ڴ�
				Book_manager::current=cache;
			}
			while(Reader_manager::current!=NULL){
				Cache=Reader_manager::current->next;
				free(Reader_manager::current);//�ͷ��ڴ�
				Reader_manager::current=Cache;
			}
			while(Info_manager::current!=NULL){
				CAche=Info_manager::current->next;
				free(Info_manager::current);//�ͷ��ڴ�
				Info_manager::current=CAche;
			}
			//����headָ��
			Book_manager::head=NULL;
			Reader_manager::head=NULL;
			Info_manager::head=NULL;
			//�ر��ļ�
			fclose(file);file=NULL;getchar();
		}
		
		
		static void file_passwd(){//�鵵����
			char origion[17];
			char first[17];
			char second[17];
			if(passwd){//ԭ��������
				cout <<"������ԭ������:";cin >>origion;
				if(strcmp(origion,password)){
					if(env){
						system("clear");
					}
					else{
						system("cls");
					}
					cout <<"�������!"<<endl;
					getchar();getchar();
					return ;
				}
				else{
					cout <<"������������:";cin >>first;
					cout <<"���ٴ�������ȷ��:";cin >>second;
					if(strcmp(first,second)){
						if(env){
							system("clear");
						}
						else{
							system("cls");
						}
						cout <<"�������벻��ͬ������ʧ��!";getchar();getchar();
						return ;
					}
					else{
						strcpy(password,first);
						cout <<"���ܳɹ�!";getchar();getchar();
						return ;
					}
				}
			}
			else{//ԭ��������
				passwd=1+rand()%63;//�����������ԭֵ
				cout <<"����������:";cin >>first;
				cout <<"���ٴ�������ȷ��:";cin >>second;
				if(strcmp(first,second)){
					if(env){
						system("clear");
					}
					else{
						system("cls");
					}
					cout <<"�������벻ͬ������ʧ��!";
					passwd=0;
					getchar();getchar();
				}
				else{
					cout <<"���ܳɹ�!";getchar();getchar();
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
		cout <<"!!!û���Ѿ��򿪵��ļ������ù鵵�����!!!"<<endl;
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
		cout <<"------------------ͼ�����--------------------"<<endl;
		cout <<"---             1.ͼ�����                 ---"<<endl;
		cout <<"---             2.ͼ�����                 ---"<<endl;
		cout <<"---             3.ͼ���ϼ�                 ---"<<endl;
		cout <<"---             4.ͼ���¼�                 ---"<<endl;
		cout <<"---             5.ͼ���޸�                 ---"<<endl;
		cout <<"---             6.���Ի���ʾ               ---"<<endl;
		cout <<"---             7.������һ��               ---"<<endl;
		cout <<"----------------------------------------------"<<endl;
		choose=getchar();getchar();
		switch(choose){
			case '1':{
				Book_manager::book_browser();
				getchar();//��ͣ&��ʾ
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
					cout <<"------------------���Ի���ʾ------------------"<<endl;
					cout <<"---�������Ӧ��Ŀǰ��ı������/�ر�����ʾ---"<<endl;
					cout <<"---             1.ͼ������(";if(show[1]){cout <<"show)            ---"<<endl;}else{cout <<"unshow)          ---"<<endl;}
					cout <<"---             2.ISBN    (";if(show[2]){cout <<"show)            ---"<<endl;}else{cout <<"unshow)          ---"<<endl;}
					cout <<"---             3.ͼ������(";if(show[3]){cout <<"show)            ---"<<endl;}else{cout <<"unshow)          ---"<<endl;}
					cout <<"---             4.������  (";if(show[4]){cout <<"show)            ---"<<endl;}else{cout <<"unshow)          ---"<<endl;}
					cout <<"---             5.����ʱ��(";if(show[5]){cout <<"show)            ---"<<endl;}else{cout <<"unshow)          ---"<<endl;}
					cout <<"---             6.���    (";if(show[6]){cout <<"show)            ---"<<endl;}else{cout <<"unshow)          ---"<<endl;}
					cout <<"---             7.����    (";if(show[7]){cout <<"show)            ---"<<endl;}else{cout <<"unshow)          ---"<<endl;}
					cout <<"---             8.����    (";if(show[8]){cout <<"show)            ---"<<endl;}else{cout <<"unshow)          ---"<<endl;}
					cout <<"---             9.����                      ---"<<endl;
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
							cout <<"!!!������������������!!!\n���س�������һ��"<<endl;getchar();
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
					cout <<"!!!������������������!!!\n���س�������һ��"<<endl;getchar();
				}
				else{
					system("cls");
					cout <<"!!!������������������!!!\n���س�������һ��"<<endl;getchar();
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
		cout <<"!!!û���Ѿ��򿪵��ļ������ù鵵�����!!!"<<endl;
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
		cout <<"------------------���߹���--------------------"<<endl;
		cout <<"---             1.�������                 ---"<<endl;
		cout <<"---             2.���߲���                 ---"<<endl;
		cout <<"---             3.��������                 ---"<<endl;
		cout <<"---             4.����ɾ��                 ---"<<endl;
		cout <<"---             5.�����޸�                 ---"<<endl;
		cout <<"---             6.�����ϼ�                 ---"<<endl;
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
				cout <<"!!!������������������!!!\n���س�������һ��"<<endl;getchar();
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
		cout <<"!!!û���Ѿ��򿪵��ļ������ù鵵�����!!!"<<endl;
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
		cout <<"------------------���Ĺ���--------------------"<<endl;
		cout <<"---             1.ͼ�����                 ---"<<endl;
		cout <<"---             2.ͼ��黹                 ---"<<endl;
		cout <<"---             3.�����ϼ�                 ---"<<endl;
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
				cout <<"!!!������������������!!!\n���س�������һ��"<<endl;getchar();
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
		cout <<"------------------�鵵����--------------------"<<endl;
		cout <<"---             1.�鵵����                 ---"<<endl;
		cout <<"---             2.�鵵��                 ---"<<endl;
		cout <<"---             3.�鵵���沢�ر�           ---"<<endl;
		cout <<"---             4.�鵵�����沢�ر�         ---"<<endl;
		cout <<"---             5.�鵵����                 ---"<<endl;
		cout <<"---             6.�����ϼ�                 ---"<<endl;
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
				cout <<"!!!������������������!!!\n���س�������һ��"<<endl;getchar();
				break;
				break;
			}
		}
	}
}

void function_choose(){//�ṩ�������棬ѡ����
	while(true){
		if(env){
			system("clear");
		}
		else{
			system("cls");
		}
		cout <<"-----------ͼ�������Ϣ�������v1.0----------"<<endl;
		cout <<"---             1.ͼ�����                ---"<<endl;
		cout <<"---             2.���߹���                ---"<<endl;
		cout <<"---             3.ͼ�����                ---"<<endl;
		cout <<"---             4.�鵵����                ---"<<endl;
		cout <<"---             5.�˳�����                ---"<<endl;
		cout <<"------------------����ѡ��-------------------"<<endl;
		if(file==NULL){
		cout <<"------------------�ļ�״̬-------------------"<<endl;
		cout <<"--- û���ļ������أ���ʹ�ù鵵��������ļ� --"<<endl;
		cout <<"---------------------------------------------"<<endl;
		}
		else{
		cout <<"------------------�ļ�״̬-------------------"<<endl;
		cout <<"---   ����״̬:";
		if(passwd){
								cout <<"�Ѿ�����"<<"                ---"<<endl;
		}
		else{
								cout <<"δ����"<<"                     ---"<<endl;
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
					cout <<"!!!�����ļ�δ���棬��ʹ�ù鵵��������!!!\n���س�������һ��"<<endl;getchar();
				}
				else{
					exit(0);
				}
				break;
			}
			default:{
				if(env){
					system("clear");
					cout <<"!!!������������������!!!\n���س�������һ��"<<endl;getchar();
				}
				else{
					system("cls");
					cout <<"!!!������������������!!!\n���س�������һ��"<<endl;getchar();
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
 �������ߣ�������
 ѧ�ţ�2000170131
 �༶���ƿ�2005/�ƿ�201
 ���ڣ�2021/06/21-2021/07/18
 ���뻷����kubuntu 20.02.2LTS/Windows10 1903
 �ں˰汾��5.8.0-48-generic
 ��������g++
 �������汾��g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
 */
