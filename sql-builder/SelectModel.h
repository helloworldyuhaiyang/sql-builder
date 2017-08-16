//
// Created by yhy on 2017/8/15.
//

#ifndef SQL_BUILDER_SELECTMODEL_H
#define SQL_BUILDER_SELECTMODEL_H


#include <vector>
#include "SqlModel.h"
#include "Column.h"

namespace sql {


    class SelectModel : public SqlModel {
    public:
        SelectModel() = default;

        virtual ~SelectModel() = default;

        template<typename... Args>
        SelectModel &select(const std::string &str, Args &&... columns) {
            _select_columns.push_back(str);
            select(columns...);
            return *this;
        }

        // for recursion
        SelectModel &select();

        template<typename... Args>
        SelectModel &from(const std::string &table_name, Args &&... tables) {
            if (_table_name.empty()) {
                _table_name = table_name;
            } else {
                _table_name.append(", ");
                _table_name.append(table_name);
            }
            from(tables...);
            return *this;
        }

        // for recursion
        SelectModel &from();

        SelectModel &where(const std::string &condition);

        SelectModel &where(Column &condition);

        template<typename... Args>
        SelectModel &group_by(const std::string &str, Args &&...columns) {
            _groupby_columns.push_back(str);
            group_by(columns...);
            return *this;
        }

        // for recursion
        SelectModel &group_by();

        SelectModel &having(const std::string &condition);

        SelectModel &having(Column &condition);

        SelectModel &order_by(const std::string &order_by);

        template<typename T>
        SelectModel &limit(const T &limit) {
            _limit = std::to_string(limit);
            return *this;
        }

        template<typename T>
        SelectModel &limit(const T &offset, const T &limit) {
            _offset = std::to_string(offset);
            _limit = std::to_string(limit);
            return *this;
        }

        template<typename T>
        SelectModel &offset(const T &offset) {
            _offset = std::to_string(offset);
            return *this;
        }

        const std::string &str() override;

        SelectModel &reset();

        friend std::ostream &operator<<(std::ostream &out, SelectModel &mod);

    protected:
        std::vector<std::string> _select_columns;
        std::vector<std::string> _groupby_columns;
        std::string _table_name;
        std::vector<std::string> _where_condition;
        std::vector<std::string> _having_condition;
        std::string _order_by;
        std::string _limit;
        std::string _offset;
    };
}

#endif //SQL_BUILDER_SELECTMODEL_H
