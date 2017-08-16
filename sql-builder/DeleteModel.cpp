//
// Created by yhy on 2017/8/15.
//

#include "DeleteModel.h"

namespace sql {

    DeleteModel &DeleteModel::where(Column &condition) {
        _where_condition.push_back(condition.str());
        return *this;
    }

    const std::string &DeleteModel::str() {
        _sql.clear();
        _sql.append("delete from ");
        _sql.append(_table_name);
        size_t size = _where_condition.size();
        if (size > 0) {
            _sql.append(" where ");
            for (size_t i = 0; i < size; ++i) {
                if (i < size - 1) {
                    _sql.append(_where_condition[i]);
                    _sql.append(" ");
                } else {
                    _sql.append(_where_condition[i]);
                }
            }
        }
        return _sql;
    }

    DeleteModel &DeleteModel::_delete() {
        return *this;
    }

    DeleteModel &DeleteModel::from() {
        return *this;
    }

    DeleteModel &DeleteModel::where(const std::string &condition) {
        _where_condition.push_back(condition);
        return *this;
    }

    DeleteModel &DeleteModel::reset() {
        _table_name.clear();
        _where_condition.clear();
        return *this;
    }

    std::ostream &operator<<(std::ostream &out, DeleteModel &mod) {
        out << mod.str();
        return out;
    }


}

