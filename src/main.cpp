#include"mysql.h"
#include<iostream>
#include"user.h"
#include"group.h"
#include"groupuser.h"
#include"friendmodel.h"
#include"groupmodel.h"
#include"usermodel.h"
#include"offlinemessagemodel.h"
#include<map>
#include<vector>
#include<string>
using namespace ChatRoom;
// using namespace std;
// 定义ANSI转义码的颜色
const std::string RED = "\033[31m";      // 红色
const std::string GREEN = "\033[32m";    // 绿色
const std::string YELLOW = "\033[33m";   // 黄色
const std::string BLUE = "\033[34m";     // 蓝色
const std::string YRED = "\033[35m";     // 洋红色
const std::string QING = "\033[36m";     // 青色
const std::string WHITE = "\033[37m";     // 白色
const std::string RESET = "\033[0m";     // 重置颜色
enum Managetype{
    BACK = 0,
    QUERY = 1,
    ADD,
    DELETE,
    UPDATE,
    STATISTIC ,  //统计

};
void print_UserDataManage_menu(){
    std::cout << "============欢迎来带东软校友通数据管理系统=================" << std::endl;
    std::cout << WHITE <<"请选择您的操作:"<< RESET <<std::endl;
    std::cout << YELLOW <<"1.用户信息查询" << RESET << std::endl;
    std::cout << YELLOW <<"2.用户信息添加" << RESET << std::endl;
    std::cout << YELLOW <<"3.用户信息删除" << RESET << std::endl;
    std::cout << YELLOW <<"4.用户信息更新" << RESET << std::endl;
    std::cout << YELLOW <<"5.用户信息统计" << RESET << std::endl;
    std::cout << YELLOW <<"0.返回上一级菜单" << RESET << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << BLUE <<"请输入:"<<RESET;
};
void UserDataManage(){
    UserModel userModel;
    while(1){
        print_UserDataManage_menu();
        int choice = 0;
        std::cin >> choice;
        if(choice == BACK){
            std::cout<<YELLOW<<"返回上一级菜单"<<RESET<<std::endl;
            break;
        }
        switch(choice){
            case QUERY:
            {
                std::cout << WHITE <<"请输入待查询的用户信息(用户名,输入all为查询全部):"<< RESET <<std::endl;
                std::string name;
                std::cin>>name;
                std::cout<<YELLOW<<"查询结果为:"<<RESET<<std::endl;
                std::vector<User> vec;
                vec = userModel.query(name);
                if(!vec.empty()){
                    for(auto& user:vec){
                        if(user.getId() != -1){
                            std::cout<<GREEN<<"user id:"<<user.getId()<<" ";
                            std::cout<<GREEN<<"user name:"<<user.getName()<<" ";
                            std::cout<<GREEN<<"user State:"<<user.getState()<<RESET<<std::endl;
                        }else{
                            std::cout<<RED<<"用户未找到,请检查!"<<RESET<<std::endl;
                        }
                    }
                }else{
                    std::cout<<RED<<"用户未找到,请检查！"<<RESET<<std::endl;
                }
            }
            break;
            case ADD:
            {
                std::string name,password;
                std::cout<<YELLOW<<"应输入用户名:"<<std::endl;
                std::cin>>name;
                std::cout<<"请输入用户密码:"<<RESET<<std::endl;
                std::cin>>password;
                User user;
                user.setName(name);
                user.setPwd(password);
                bool res = userModel.insert(user);
                if(res){
                    std::cout<<GREEN<<"用户插入成功！"<<RESET<<std::endl;
                }else{
                    std::cout<<RED<<"用户插入失败!"<<RESET<<std::endl;
                }    
            }
            break;
            case DELETE:
            {
                int user_id = 0;
                std::cout<<YELLOW<<"请输入待删除的用户id:"<<RESET<<std::endl;
                std::cin>>user_id;  
                bool res = userModel.deleteUser(user_id);
                if(res){
                    std::cout<<GREEN<<"用户删除成功"<<RESET<<std::endl;
                }else{
                    std::cout<<RED<<"用户删除失败!"<<RESET<<std::endl;
                }    
            }
            break;
            case UPDATE:
            {
                int user_id = 0,chioce = 0;
                std::string info;
                bool res;
                User user;
                std::cout<<YELLOW<<"请输入待更新的用户id:"<<std::endl;
                std::cin>>user_id;
                user.setId(user_id);
                std::cin.get();
                std::cout<<WHITE<<"请选择您要更新的内容:"<<RESET<<std::endl;
                std::cout << YELLOW <<"1.更新用户名" << RESET << std::endl;
                std::cout << YELLOW <<"2.更新状态" << RESET << std::endl;
                std::cin>>chioce;
                std::cin.get(); //吸收换行符
                if(1 == chioce){
                    std::cout<<WHITE<<"请输入新的用户名:"<<RESET<<std::endl;
                    std::cin>>info;
                    user.setName(info);
                    res = userModel.updateName(user);
                }
                else if(2 == chioce){
                    std::cout<<WHITE<<"请输入新的用户状态:"<<RESET<<std::endl;
                    std::cin>>info;
                    user.setState(info);
                    res = userModel.updateState(user);
                }else{
                    std::cout<<RED<<"输入有误"<<std::endl;
                    break;
                }
                if(res){
                    std::cout<<GREEN<<"信息更新成功"<<RESET<<std::endl;
                }else{
                    std::cout<<RED<<"信息更细失败!"<<RESET<<std::endl;
                }    
            }
            break;
            case STATISTIC:
            {
                int count = userModel.userCount();
                if(count == -1){
                    std::cout<<RED<<"查询出错"<<RESET<<std::endl;
                }else{
                    std::cout<<GREEN<<"当前系统用户数量为:"<<count<<RESET<<std::endl;
                }
            }
            break;
            default:
            std::cout<<RED<<"输入有误！"<<RESET<<std::endl;
            break;
        }
    }std::cout << "已退出用户数据管理" << std::endl;

}
void print_FriendDataManage_menu(){
    std::cout << "============欢迎来带东软校友通数据管理系统=================" << std::endl;
    std::cout << WHITE  <<"请选择您的操作:"<< RESET <<std::endl;
    std::cout << YELLOW <<"1.好友信息查询" << RESET << std::endl;
    std::cout << YELLOW <<"2.好友信息添加" << RESET << std::endl;
    std::cout << YELLOW <<"3.好友信息删除" << RESET << std::endl;
    std::cout << YELLOW <<"4.好友信息更新" << RESET << std::endl;
    std::cout << YELLOW <<"5.好友信息统计" << RESET << std::endl;
    std::cout << YELLOW <<"0.返回上一级菜单" << RESET << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << BLUE <<"请输入:"<<RESET;
};
void FriendDataManage() {
    FriendModel friendModel;
    int op;
    while(1){
        print_FriendDataManage_menu();
        std::cin >> op;
        if(op == BACK){
            std::cout<<YELLOW<<"返回上一级菜单"<<RESET<<std::endl;
            break;
        }
        int userid, friendid;
        switch(op) {
            case QUERY: {
                std::cout << YELLOW << "请输入用户ID: " << RESET;
                std::cin >> userid;
                auto vec = friendModel.query(userid);
                if (vec.empty()) {
                    std::cout << RED << "无好友记录" << RESET << std::endl;
                } else {
                    std::cout << GREEN << "好友列表如下：" << RESET << std::endl;
                    for (auto &u : vec) {
                        std::cout << "  ID:" << u.getId()
                            << " 名称:" << u.getName()
                            << " 状态:" << u.getState() << std::endl;
                    }   
                }
            } break;
            case ADD: {
                std::cout << YELLOW << "请输入用户ID: " << RESET;
                std::cin >> userid;
                std::cout << YELLOW << "请输入要添加的好友ID: " << RESET;
                std::cin >> friendid;
                bool r = friendModel.insert(userid, friendid);
                std::cout << (r ? GREEN + "添加成功" : RED + "添加失败") << RESET << std::endl;
            } break;
            case DELETE: {
                std::cout << YELLOW << "请输入用户ID: " << RESET;
                std::cin >> userid;
                std::cout << YELLOW << "请输入要删除的好友ID: " << RESET;
                std::cin >> friendid;
                bool r = friendModel.remove(userid, friendid);
                std::cout << (r ? GREEN + "删除成功" : RED + "删除失败") << RESET << std::endl;
            } break;
            case UPDATE:
                std::cout << YRED << "好友信息不支持更新操作" << RESET << std::endl;
                break;
            case STATISTIC: {
                std::cout << YELLOW << "请输入用户ID: " << RESET;
                std::cin >> userid;
                int cnt = friendModel.count(userid);
                if (cnt < 0) {
                    std::cout << RED << "统计失败" << RESET << std::endl;
                } else {
                    std::cout << GREEN << "好友总数：" << cnt << RESET << std::endl;
                }
            } break;

            default:
                std::cout << RED << "输入错误，请重试" << RESET << std::endl;
                break;
        }
    }
}
void print_GroupDataManage_menu(){
    std::cout << "============欢迎来带东软校友通数据管理系统=================" << std::endl;
    std::cout << WHITE <<"请选择您的操作:"<< RESET <<std::endl;
    std::cout << YELLOW <<"1.查询群组信息" << RESET << std::endl;
    std::cout << YELLOW <<"2.创建全新群组" << RESET << std::endl;
    std::cout << YELLOW <<"3.添加群组成员" << RESET << std::endl;
    std::cout << YELLOW <<"4.删除指定群组" << RESET << std::endl;
    std::cout << YELLOW <<"0.群组信息统计" << RESET << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << BLUE <<"请输入:"<<RESET;
};
void GroupDataManage(){
    GroupModel groupModel;
    print_GroupDataManage_menu();
    int op;
    std::cin >> op;
    int groupid, userid;
}
void print_OfflineDataManage_menu(){
    std::cout << "============欢迎来带东软校友通数据管理系统=================" << std::endl;
    std::cout << WHITE <<"请选择您的操作:"<< RESET <<std::endl;
    std::cout << YELLOW <<"1.查询用户离线消息" << RESET << std::endl;
    std::cout << YELLOW <<"2.存储用户离线消息" << RESET << std::endl;
    std::cout << YELLOW <<"3.删除用户离线消息" << RESET << std::endl;
    std::cout << YELLOW <<"4.更新用户离线消息" << RESET << std::endl;
    std::cout << YELLOW <<"5.统计用户离线消息" << RESET << std::endl;
    std::cout << YELLOW <<"0.返回上一级菜单" << RESET << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << BLUE <<"请输入:"<<RESET;
};

void OfflineDataManage(){

    OfflineMsgModel offlineModel;
    int op;
    while(1){
        print_OfflineDataManage_menu();
        std::cin >> op;
        if(op == BACK){
            std::cout<<YELLOW<<"返回上一级菜单"<<RESET<<std::endl;
            break;
        }
        int userid;
        std::string s;
        switch (op) {
            case QUERY: {
            std::cout << YELLOW << "请输入用户ID: " << RESET;
            std::cin >> userid;
            auto vec = offlineModel.query(userid);
            if (vec.empty()) {
                std::cout << RED << "该用户没有离线消息" << RESET << std::endl;
            } else {
                std::cout << GREEN << "离线消息如下：" << RESET << std::endl;
                for (auto& msg : vec) {
                    std::cout << msg << std::endl;
                }
                }
            } break;
            case ADD: {
                std::cout << YELLOW << "请输入用户ID: " << RESET;
                std::cin >> userid;
                std::cin.ignore();
                std::cout << YELLOW << "请输入要存储的离线消息: " << RESET;
                getline(std::cin, s);
                bool res = offlineModel.insert(userid, s);
                if (res) {
                    std::cout << GREEN << "离线消息存储成功" << RESET << std::endl;
                } else {
                    std::cout << RED << "离线消息存储失败" << RESET << std::endl;
                }
            } break;

            case DELETE: {
                std::cout << YELLOW << "请输入用户ID: " << RESET;
                std::cin >> userid;
                bool res = offlineModel.remove(userid);
                if (res) {
                    std::cout << GREEN << "用户的离线消息删除成功" << RESET << std::endl;
                } else {
                    std::cout << RED << "用户的离线消息删除失败" << RESET << std::endl;
                }
            } break;
            case UPDATE:
                std::cout << YRED << "离线信息不支持更新操作" << RESET << std::endl;
                break;
            case STATISTIC: {
                OfflineMsgModel model;
                auto allMsgs = model.getAll();
                if(allMsgs.empty()){
                    std::cout << "没有记录" << std::endl;
                } else {
                    std::cout << "离线消息列表:" << std::endl;
                    for(auto &p : allMsgs){
                        std::cout << "user: " << p.first << ", msg: " << p.second << std::endl;
                    }
                }
            } break;    
            // case STATISTIC: {
            //     std::cout << YELLOW << "请输入用户ID（输入0统计所有离线消息）: " << RESET;
            //     std::cin >> userid;
            //     int count = offlineModel.count(userid);
            //     if (count < 0) {
            //         std::cout << RED << "统计失败" << RESET << std::endl;
            //     } else {
            //         std::cout << GREEN << "离线消息总数：" << count << RESET << std::endl;
            //     }
            // } break;

            default:
                std::cout << RED << "输入错误，请重试" << RESET << std::endl;
                break;
        }
    }
}

// 在 main.cpp 中，替换原来的空实现：

int main(){
    int choice = 0;
    while(1){
        // 显示首页面菜单、查询、插入、删除、更新
        std::cout << "===========欢迎来到东软校友通数据管理系统===============" << std::endl;
        std::cout << WHITE <<"请选择您的操作："<< RESET <<std::endl;
        std::cout << YELLOW <<"1.用户信息管理" << RESET << std::endl;
        std::cout << YELLOW <<"2.好友信息管理" << RESET << std::endl;
        std::cout << YELLOW <<"3.群组信息管理" << RESET << std::endl;
        std::cout << YELLOW <<"4.离线信息管理" << RESET << std::endl;
        std::cout << YELLOW <<"0.退出系统" << RESET << std::endl;
        std::cout << "=====================================================" << std::endl;
        std::cout << BLUE <<"请输入:"<<RESET;
        std::cin >>choice;
        if(0 == choice){
            std::cout<<YELLOW<<"退出系统"<<RESET<<std::endl;
            break;
        }
        std::cin.get();// 读掉缓冲区的回车
        switch(choice)
        {
            case 1: //用户数据管理
                UserDataManage();
                break;
            case 2: //好友数据管理
                FriendDataManage();
                break;
            case 3: //群组数据管理
                GroupDataManage();
                break;
            case 4: //离线消息管理
                OfflineDataManage();
                break;
            default:
                std::cout<<RED<<"input error"<<RESET<<std::endl;
                std::cin.clear();  //异常输入时,std::cin会输出错误标记，通过clear将其清除
                std::cin.ignore(100,'\n'); //清空缓冲区
                break;
        }
        
    }
    return 0;
}
