#include "offlinemessagemodel.h"
#include "mysql.h"
using namespace ChatRoom;
    // 查询用户的离线消息
    std::vector<std::string> OfflineMsgModel::query(int userid){
        // 1.组装sql语句
        char sql[1024] = {0};
        sprintf(sql, "SELECT message FROM offlinemessage WHERE userid = %d", userid);
        MySQL mysql;
        if(mysql.Connect()){
            MYSQL_RES *res = mysql.Query(sql);
            if(res != nullptr){
                MYSQL_ROW row;
                std::vector<std::string> messages;
                while((row = mysql_fetch_row(res)) != nullptr){
                    messages.push_back(row[0]);
                }
                mysql_free_result(res);
                return messages;
            }else{
                return {}; // 查询失败
            }
        }else{
            return {}; // 连接失败
        }
    }
    // 存储用户的离线消息
    bool OfflineMsgModel::insert(int userid, const std::string &msg){
        // 1.组装sql语句
        char sql[1024] = {0};
        sprintf(sql, "INSERT INTO offlinemessage (userid, message) values(%d, '%s')", userid, msg.c_str());
        
        MySQL mysql;
        if (mysql.Connect())
        {
            if (mysql.Update(sql))
            {
                return true;
            }
        }
        return false;
    }
    
    // 删除用户的离线消息
    bool OfflineMsgModel::remove(int userid){
        // 1.组装sql语句
        char sql[1024] = {0};
        sprintf(sql, "DELETE FROM offlinemessage WHERE userid = %d", userid);
        
        MySQL mysql;
        if (mysql.Connect())
        {
            if (mysql.Update(sql))
            {
                return true;
            }
        }
        return false;
    }

    // 更新用户的离线消息
    bool OfflineMsgModel::update(int userid, const std::string &msg) {
    char sql[1024] = {0};
    sprintf(sql, "UPDATE offlinemessage SET message = '%s' WHERE userid = %d", msg.c_str(), userid);
    
    MySQL mysql;
    if (mysql.Connect()) {
        if (mysql.Update(sql)) {
            return true;
        }
    }
    return false;
    }
    // 统计离线消息
    int OfflineMsgModel::count(int userid){
        // 1.组装sql语句
        char sql[1024] = {0};
        sprintf(sql, "SELECT COUNT(*) FROM offlinemessage WHERE userid = %d", userid);
        MySQL mysql;
        if(mysql.Connect()){
            MYSQL_RES *res = mysql.Query(sql);
            if(res != nullptr){
                MYSQL_ROW row;
                int count = 0;
                if((row = mysql_fetch_row(res)) != nullptr){
                    count = atoi(row[0]);
                }
                mysql_free_result(res);
                return count;
            }else{
                return -1; // 查询失败
            }
        }else{
            return -1; // 连接失败
        }
    }
    std::vector<std::pair<int, std::string>> OfflineMsgModel::getAll() {
    std::vector<std::pair<int, std::string>> results;
    char sql[1024] = {0};
    sprintf(sql, "SELECT userid, message FROM offlinemessage");
    MySQL mysql;
    if(mysql.Connect()){
        MYSQL_RES *res = mysql.Query(sql);
        if(res != nullptr){
            MYSQL_ROW row;
            while((row = mysql_fetch_row(res)) != nullptr){
                int uid = atoi(row[0]);
                std::string msg = row[1];
                results.emplace_back(uid, msg);
            }
            mysql_free_result(res);
        }
    }
    return results;
}