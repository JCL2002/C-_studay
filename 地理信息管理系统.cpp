#include<bits/stdc++.h>
using namespace std;

struct node //��-��Ϣ�ṹ��
{
    string name;//����
    int name_size;//���ƵĴ�С�����ṹ�����ļ��Ĵ���Ͷ�ȡ
    double altitude;//�߶�
    pair<double,double> pos;//λ����Ϣ�����ȡ�γ��
};

struct road // ·-��Ϣ�ṹ��
{
    string name;//��·����
    int name_size;//���ƵĴ�С�����ṹ�����ļ��Ĵ���Ͷ�ȡ
    pair<string,string> edge;//��·������
    pair<int,int> Size;//�������ֵĴ�С
    double cost;//��·��ʱ
};

map<string,node> map_of_node;//��-����
map<string,road> map_of_road;//·-����

class Node //�� ������
{
    /*
    ���к����ķ���ֵ��Ϊint����
    FindSpot��������0�����Ҳ�������㣬����ֵ����ǰ���еĵ�����ֵĴ�С
    ʣ�����к�������-1����ʧ�ܣ�����ֵ����ǰ���е������
    */
public:
    static int FindSpot(string name)
    {
        if(map_of_node.find(name)==map_of_node.end()) return 0;
        return name.length();
    }

    static int AddSpot(string name,double longitude,double latitude,double altitude)//���ơ����ȡ�γ�ȡ��߶�  ���ӵ�
    {
        if(FindSpot(name)) return -1;//���Ѿ�������
        map_of_node[name]= {name,(int)name.length(),longitude,{latitude,altitude} };
        return map_of_node.size();
    }

    static int DeleteSpot(string name)//ɾ����
    {
        if(!FindSpot(name)) return -1;//�㲻����
        map_of_node.erase(name);//ɾ��ԭ�еĵ�
        return map_of_node.size();
    }

    static int UpdateSpot(string name,double longitude,double latitude,double altitude)//���ơ����ȡ�γ�ȡ��߶� �޸ĵ�
    {
        if(DeleteSpot(name)==-1) return -1;//ɾ��ԭ�еĵ�,ԭ���ĵ㲻���ھͷ���-1
        return AddSpot(name,longitude,latitude,altitude);//�����µĵ�
    }

    static int UpdateSpotName(string name,string Newname)
    {
        if(FindSpot(name)) return -1;
        map_of_node[Newname]={Newname,(int)Newname.length(),map_of_node[name].altitude,{map_of_node[name].pos.first,map_of_node[name].pos.second} };//�����µĵ�
        DeleteSpot(name);//ɾ��ԭ���ĵ�
        return map_of_node.size();
    }
};

int FindRoad(string name)
{
    if(map_of_road.find(name)==map_of_road.end()) return 0;
    return name.length();
}

int AddRoad(string name,string name1,string name2,double cost)
{
    int s=Node::FindSpot(name1),t=Node::FindSpot(name2);
    if(s && t)
    {
        if(FindRoad(name)) return -2;//��·�����ظ�
        map_of_road[name]={name,(int)name.length(),{name1,name2},{s,t},cost};
        return map_of_road.size();
    }
    return -1;
}

int DeleteRoad(string name)
{
    if(!FindRoad(name)) return -1;
    map_of_road.erase(name);
    return map_of_road.size();
}

int UpdateRpad(string name,string Newname,double cost)
{
    if(!FindRoad(name)) return -1;
    int s=Node::FindSpot(map_of_road[name].edge.first),t=Node::FindSpot(map_of_road[name].edge.second);
    if(s&&t) map_of_road[Newname]={Newname,(int)Newname.length(),{map_of_road[name].edge.first,map_of_road[name].edge.second},{s,t},cost};
    DeleteRoad(name);
    return -2;//�������Ѿ���Ч
}

int main()
{
    cout << sizeof(node) << endl;
    cout << sizeof(road) ;
    return 0;
}
