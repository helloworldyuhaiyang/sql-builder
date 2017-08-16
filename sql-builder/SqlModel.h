//
// Created by yhy on 2017/8/15.
//

#ifndef SQL_BUILDER_SQLMODEL_H
#define SQL_BUILDER_SQLMODEL_H


#include <string>


namespace sql {


    class SqlModel {
    public:
        SqlModel() = default;

        virtual ~SqlModel() = default;

        virtual const std::string &str() = 0;

        const std::string &last_sql();

        SqlModel(const SqlModel &m) = delete;

        SqlModel &operator=(const SqlModel &data) = delete;

    protected:
        std::string _sql;
    };


}
#endif //SQL_BUILDER_SQLMODEL_H
