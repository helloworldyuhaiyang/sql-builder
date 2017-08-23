//
// Created by yhy on 2017/8/15.
//

#include "UpdateModel.h"
#include <iostream>

namespace sql {

    UpdateModel &UpdateModel::update(const std::string &table_name) {
        _table_name = table_name;
        return *this;
    }

    UpdateModel &UpdateModel::where(const std::string &condition) {
        _where_condition.push_back(condition);
        return *this;
    }

    UpdateModel &UpdateModel::where(Column &condition) {
        _where_condition.push_back(condition.str());
        return *this;
    }
	template<>
	UpdateModel &UpdateModel::set<const std::nullptr_t&>(const std::string &c, const std::nullptr_t &) {
		std::string str(c);
		str.append(" = null");
		_set_columns.push_back(str);
		return *this;
	}
    const std::string &UpdateModel::str() {
        _sql.clear();
        _sql.append("update ");
        _sql.append(_table_name);
        _sql.append(" set ");
        size_t size = _set_columns.size();
        for (size_t i = 0; i < size; ++i) {
            if (i < size - 1) {
                _sql.append(_set_columns[i]);
                _sql.append(", ");
            } else {
                _sql.append(_set_columns[i]);
            }
        }
        size = _where_condition.size();
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

    UpdateModel &UpdateModel::reset() {
        _table_name.clear();
        _set_columns.clear();
        _where_condition.clear();
        return *this;
    }

    std::ostream &operator<<(std::ostream &out, UpdateModel &mod) {
        out << mod.str();
        return out;
    }


}