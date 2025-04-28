#ifndef OFFLINEMESSAGEMODEL_H
#define OFFLINEMESSAGEMODEL_H

#include <string>
#include <vector>

namespace ChatRoom {

// 提供离线消息表的操作接口方法
class OfflineMsgModel {
public:
    // 查询用户的离线消息
    std::vector<std::string> query(int userid);
    // 存储用户的离线消息
    bool insert(int userid, const std::string &msg);
    // 删除用户的离线消息
    bool remove(int userid);
    //更新用户的离线消息
    bool update(int userid, const std::string &msg);
    // 统计离线消息 
    int count(int userid);
    // 统计所有离线消息
    std::vector<std::pair<int, std::string>> getAll();
};

} // namespace ChatRoom

#endif // OFFLINEMESSAGEMODEL_H