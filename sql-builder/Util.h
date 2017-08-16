//
// Created by yhy on 2017/8/16.
//

#ifndef SQL_BUILDER_UTIL_H
#define SQL_BUILDER_UTIL_H


#include <string>

namespace sql {
    template<typename T>
    static std::string to_value(const T &data) {
        return std::to_string(data);
    }

    template<>
    inline std::string to_value<const char *>(const char *const &data) {
        std::string str("'");
        str.append(data);
        str.append("'");
        return str;
    }

    template<>
    inline std::string to_value<std::string>(const std::string &data) {
        std::string str("'");
        str.append(data);
        str.append("'");
        return str;
    }

    template<>
    inline std::string to_value<std::nullptr_t>(const std::nullptr_t &data) {
        //sql 里的 null 加单引号就是 null 字符串值了，不是真正的 NULL
        std::string str;
        str.append("null");
        return str;
    }

    template<size_t N>
    std::string to_value(char const(&data)[N]) {
        std::string str("'");
        str.append(data);
        str.append("'");
        return str;
    }

/*
template <>
static std::string sql::to_value<time_t>(const time_t& data) {
    char buff[128] = {0};
    struct tm* ttime = localtime(&data);
    strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", ttime);
    std::string str("'");
    str.append(buff);
    str.append("'");
    return str;
}
*/
}

#endif //SQL_BUILDER_UTIL_H
