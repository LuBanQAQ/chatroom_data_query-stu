#include "groupmodel.h"
#include "mysql.h"
using namespace ChatRoom;
// 创建群组
bool GroupModel::createGroup(Group &group)
{
    // 1.组装sql语句
    char sql[1024] = {0};
    sprintf(sql, "insert into allgroup(groupname, groupdesc) values('%s', '%s')",
            group.getName().c_str(), group.getDesc().c_str());

    MySQL mysql;
    if (mysql.Connect())
    {
        if (mysql.Update(sql))
        {
            group.setId(mysql_insert_id(mysql.GetConnection()));
            return true;
        }
    }

    return false;
}

// 加入群组
void GroupModel::addGroup(int userid, int groupid, string role)
{
    // 1.组装sql语句
    char sql[1024] = {0};
    sprintf(sql, "insert into groupuser values(%d, %d, '%s')",
            groupid, userid, role.c_str());

    MySQL mysql;
    if (mysql.Connect())
    {
        mysql.Update(sql);
    }
}

// 查询用户所在群组信息
vector<Group> GroupModel::queryGroups(int userid)
{
    /*
    1. 先根据userid在groupuser表中查询出该用户所属的群组信息
    2. 在根据群组信息，查询属于该群组的所有用户的userid，并且和user表进行多表联合查询，查出用户的详细信息
    */
    char sql[1024] = {0};
    sprintf(sql, "select a.id,a.groupname,a.groupdesc from allgroup a inner join \
         groupuser b on a.id = b.groupid where b.userid=%d",
            userid);

    vector<Group> groupVec;

    MySQL mysql;
    if (mysql.Connect())
    {
        MYSQL_RES *res = mysql.Query(sql);
        if (res != nullptr)
        {
            MYSQL_ROW row;
            // 查出userid所有的群组信息
            while ((row = mysql_fetch_row(res)) != nullptr)
            {
                Group group;
                group.setId(atoi(row[0]));
                group.setName(row[1]);
                group.setDesc(row[2]);
                groupVec.push_back(group);
            }
            mysql_free_result(res);
        }
    }

    // 查询群组的用户信息
    for (Group &group : groupVec)
    {
        sprintf(sql, "select a.id,a.name,a.state,b.grouprole from user a \
            inner join groupuser b on b.userid = a.id where b.groupid=%d",
                group.getId());

        MYSQL_RES *res = mysql.Query(sql);
        if (res != nullptr)
        {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res)) != nullptr)
            {
                GroupUser user;
                user.setId(atoi(row[0]));
                user.setName(row[1]);
                user.setState(row[2]);
                user.setRole(row[3]);
                group.getUsers().push_back(user);
            }
            mysql_free_result(res);
        }
    }
    return groupVec;
}

// 根据指定的groupid查询群组用户id列表，除userid自己，主要用户群聊业务给群组其它成员群发消息
vector<int> GroupModel::queryGroupUsers(int userid, int groupid)
{
    char sql[1024] = {0};
    sprintf(sql, "select userid from groupuser where groupid = %d and userid != %d", groupid, userid);

    vector<int> idVec;
    MySQL mysql;
    if (mysql.Connect())
    {
        MYSQL_RES *res = mysql.Query(sql);
        if (res != nullptr)
        {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res)) != nullptr)
            {
                idVec.push_back(atoi(row[0]));
            }
            mysql_free_result(res);
        }
    }
    return idVec;
}



/**
 * @brief 从数据库中删除一个群组及其关联的成员。
 * 
 * 此函数会先从 `groupuser` 表中删除指定群组的所有成员关系，
 * 然后从 `allgroup` 表中删除该群组本身。
 * 
 * @param groupid 要删除的群组的 ID。
 * @return 如果群组及其成员成功删除则返回 true，
 *         否则返回 false
 */
bool GroupModel::removeGroup(int groupid)
{
    MySQL mysql;
    if (!mysql.Connect())
        return false;

    // 先删除 groupuser 表中该群组的所有成员关系
    char sql1[256] = {0};


    sprintf(sql1, "DELETE FROM groupuser WHERE groupid=%d", groupid);
    if (!mysql.Delete(sql1))
        return false;

    // 再删除 allgroup 表中的群组本身
    char sql2[256] = {0};
    sprintf(sql2, "DELETE FROM allgroup WHERE id=%d", groupid);
    if (!mysql.Delete(sql2))
        return false;

    return true;
}


/**
 * @brief 统计指定群组中用户的数量。
 * 
 * @param groupid 群组的唯一标识符。
 * @return int 返回群组中的用户数量。如果查询失败，返回 -1。
 * 
 * 此函数通过执行 SQL 查询从数据库中获取指定群组的用户数量。
 * 如果数据库连接失败或查询结果为空，则返回 -1。
 */
int GroupModel::countGroup(int groupid)
{
    char sql[256] = {0};
    sprintf(sql, "SELECT COUNT(*) FROM groupuser WHERE groupid=%d", groupid);
    MySQL mysql;
    if (!mysql.Connect())
        return -1;
    MYSQL_RES* res = mysql.Query(sql);
    if (!res){
        return -1;
    }
        
    MYSQL_ROW row = mysql_fetch_row(res);
    int cnt = row ? atoi(row[0]) : -1;
    mysql_free_result(res);
    return cnt;
}




