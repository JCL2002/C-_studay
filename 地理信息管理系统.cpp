#include<bits/stdc++.h>
using namespace std;

struct node //点-信息结构体
{
    string name;//名称
    int name_size;//名称的大小，方结构体向文件的储存和读取
    double altitude;//高度
    pair<double,double> pos;//位置信息：经度、纬度
};

struct road // 路-信息结构体
{
    string name;//道路名称
    int name_size;//名称的大小，方结构体向文件的储存和读取
    pair<string,string> edge;//道路的两边
    pair<int,int> Size;//两边名字的大小
    double cost;//道路耗时
};

map<string,node> map_of_node;//点-容器
map<string,road> map_of_road;//路-容器

class Node //点 方法类
{
    /*
    所有函数的返回值均为int类型
    FindSpot函数返回0代表找不到这个点，其他值代表当前已有的点的名字的大小
    剩余所有函数返回-1代表失败，其他值代表当前已有点的数量
    */
public:
    static int FindSpot(string name)
    {
        if(map_of_node.find(name)==map_of_node.end()) return 0;
        return name.length();
    }

    static int AddSpot(string name,double longitude,double latitude,double altitude)//名称、经度、纬度、高度  增加点
    {
        if(FindSpot(name)) return -1;//点已经存在了
        map_of_node[name]= {name,(int)name.length(),longitude,{latitude,altitude} };
        return map_of_node.size();
    }

    static int DeleteSpot(string name)//删除点
    {
        if(!FindSpot(name)) return -1;//点不存在
        map_of_node.erase(name);//删除原有的点
        return map_of_node.size();
    }

    static int UpdateSpot(string name,double longitude,double latitude,double altitude)//名称、经度、纬度、高度 修改点
    {
        if(DeleteSpot(name)==-1) return -1;//删除原有的点,原来的点不存在就返回-1
        return AddSpot(name,longitude,latitude,altitude);//加入新的点
    }

    static int UpdateSpotName(string name,string Newname)
    {
        if(FindSpot(name)) return -1;
        map_of_node[Newname]={Newname,(int)Newname.length(),map_of_node[name].altitude,{map_of_node[name].pos.first,map_of_node[name].pos.second} };//插入新的点
        DeleteSpot(name);//删除原来的点
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
        if(FindRoad(name)) return -2;//道路命名重复
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
    return -2;//这条边已经无效
}

int main()
{
    cout << sizeof(node) << endl;
    cout << sizeof(road) ;
    return 0;
}
