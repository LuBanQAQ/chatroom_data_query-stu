#include "friendmodel.h"
#include "mysql.h"
using namespace ChatRoom;
// 辅助：检查用户是否存在
static bool userExists(int userid) {
    char sql[256] = {0};
    sprintf(sql, "SELECT id FROM user WHERE id=%d", userid);
    MySQL mysql;
    if (!mysql.Connect()) return false;
    MYSQL_RES* res = mysql.Query(sql);
    if (!res) return false;
    bool ok = (mysql_fetch_row(res) != nullptr);
    mysql_free_result(res);
    return ok;
}
// 添加好友关系（双向），先检查用户存在且未成为好友
bool FriendModel::insert(int userid, int friendid) {
    if (!userExists(userid) || !userExists(friendid) || userid==friendid) {
        return false;
    }
    // 检查是否已为好友
    char check[256] = {0};
    sprintf(check,
            "SELECT COUNT(*) FROM friend WHERE userid=%d AND friendid=%d",
            userid, friendid);
    MySQL mysql;
    if (!mysql.Connect()) return false;
    MYSQL_RES* cres = mysql.Query(check);
    if (cres) {
        MYSQL_ROW row = mysql_fetch_row(cres);
        int cnt = row ? atoi(row[0]) : 0;
        mysql_free_result(cres);
        if (cnt > 0) return false;
    }
    // 执行双向插入
    char sql1[512] = {0}, sql2[512] = {0};
    sprintf(sql1,
            "INSERT INTO friend(userid,friendid) VALUES(%d,%d)",
            userid, friendid);
    sprintf(sql2,
            "INSERT INTO friend(userid,friendid) VALUES(%d,%d)",
            friendid, userid);
    return mysql.Update(sql1) && mysql.Update(sql2);
}

// 返回用户好友列表
vector<User> FriendModel::query(int userid)
{
    // 1.组装sql语句
    char sql[1024] = {0};

    sprintf(sql, "select a.id,a.name,a.state from user a inner join friend b on b.friendid = a.id where b.userid=%d", userid);

    vector<User> vec;
    MySQL mysql;
    if (mysql.Connect())
    {
        MYSQL_RES *res = mysql.Query(sql);
        if (res != nullptr)
        {
            // 把userid用户的所有好友放入vec中返回
            MYSQL_ROW row;
            while((row = mysql_fetch_row(res)) != nullptr)
            {
                User user;
                user.setId(atoi(row[0]));
                user.setName(row[1]);
                user.setState(row[2]);
                vec.push_back(user);
            }
            mysql_free_result(res);
            return vec;
        }
    }
    return vec;
}

// 删除好友关系（双向），先检查是否为好友
bool FriendModel::remove(int userid, int friendid) {
    // 检查现有关系
    char check[256] = {0};
    sprintf(check,
            "SELECT COUNT(*) FROM friend WHERE userid=%d AND friendid=%d",
            userid, friendid);
    MySQL mysql;
    if (!mysql.Connect()) return false;
    MYSQL_RES* res = mysql.Query(check);
    if (res) {
        MYSQL_ROW row = mysql_fetch_row(res);
        int cnt = row ? atoi(row[0]) : 0;
        mysql_free_result(res);
        if (cnt == 0) return false;
    }
    // 执行双向删除
    char sql[512] = {0};
    sprintf(sql,
            "DELETE FROM friend WHERE "
            "(userid=%d AND friendid=%d) "
            "OR (userid=%d AND friendid=%d)",
            userid, friendid,
            friendid, userid);
    return mysql.Delete(sql);
}

// 统计好友个数
int FriendModel::count(int userid) {
    char sql[256] = {0};
    sprintf(sql,
            "SELECT COUNT(*) FROM friend WHERE userid=%d",
            userid);
    MySQL mysql;
    if (!mysql.Connect()) return -1;
    MYSQL_RES* res = mysql.Query(sql);
    if (!res) return -1;
    MYSQL_ROW row = mysql_fetch_row(res);
    int cnt = row ? atoi(row[0]) : -1;
    mysql_free_result(res);
    return cnt;
}