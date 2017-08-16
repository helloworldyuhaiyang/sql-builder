//
// Created by yhy on 2017/8/15.
//

#include "InsertModel.h"


namespace sql {

    void InsertModel::into(const std::string &table_name) {
        _table_name = table_name;
    }

    const std::string &InsertModel::str() {
        _sql.clear();
        std::string v_ss;
        _sql.append("insert into ");
        _sql.append(_table_name);
        _sql.append("(");
        v_ss.append(" values(");
        size_t size = _columns.size();
        for (size_t i = 0; i < size; ++i) {
            if (i < size - 1) {
                _sql.append(_columns[i]);
                _sql.append(", ");
                v_ss.append(_values[i]);
                v_ss.append(", ");
            } else {
                _sql.append(_columns[i]);
                _sql.append(")");
                v_ss.append(_values[i]);
                v_ss.append(")");
            }
        }
        _sql.append(v_ss);
        return _sql;
    }

    InsertModel &InsertModel::reset() {
        _table_name.clear();
        _columns.clear();
        _values.clear();
        return *this;
    }


    std::ostream &operator<<(std::ostream &out, InsertModel &mod) {
        out << mod.str();
        return out;
    }
}