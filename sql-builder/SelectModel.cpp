//
// Created by yhy on 2017/8/15.
//

#include "SelectModel.h"


namespace sql {

    SelectModel &SelectModel::select() {
        return *this;
    }

    SelectModel &SelectModel::where(const std::string &condition) {
        _where_condition.push_back(condition);
        return *this;
    }

    SelectModel &SelectModel::where(Column &condition) {
        _where_condition.push_back(condition.str());
        return *this;
    }

    SelectModel &SelectModel::having(Column &condition) {
        _having_condition.push_back(condition.str());
        return *this;
    }

    SelectModel &SelectModel::from() {
        return *this;
    }

    SelectModel &SelectModel::group_by() {
        return *this;
    }

    SelectModel &SelectModel::having(const std::string &condition) {
        _having_condition.push_back(condition);
        return *this;
    }

    SelectModel &SelectModel::order_by(const std::string &order_by) {
        _order_by = order_by;
        return *this;
    }


    const std::string &SelectModel::str() {
        _sql.clear();
        _sql.append("select ");
        size_t size = _select_columns.size();
        for (size_t i = 0; i < size; ++i) {
            if (i < size - 1) {
                _sql.append(_select_columns[i]);
                _sql.append(", ");
            } else {
                _sql.append(_select_columns[i]);
            }
        }
        _sql.append(" from ");
        _sql.append(_table_name);
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
        size = _groupby_columns.size();
        if (!_groupby_columns.empty()) {
            _sql.append(" group by ");
            for (size_t i = 0; i < size; ++i) {
                if (i < size - 1) {
                    _sql.append(_groupby_columns[i]);
                    _sql.append(", ");
                } else {
                    _sql.append(_groupby_columns[i]);
                }
            }
        }
        size = _having_condition.size();
        if (size > 0) {
            _sql.append(" having ");
            for (size_t i = 0; i < size; ++i) {
                if (i < size - 1) {
                    _sql.append(_having_condition[i]);
                    _sql.append(" ");
                } else {
                    _sql.append(_having_condition[i]);
                }
            }
        }
        if (!_order_by.empty()) {
            _sql.append(" order by ");
            _sql.append(_order_by);
        }
        if (!_limit.empty()) {
            _sql.append(" limit ");
            _sql.append(_limit);
        }
        if (!_offset.empty()) {
            _sql.append(" offset ");
            _sql.append(_offset);
        }
        return _sql;
    }

    SelectModel &SelectModel::reset() {
        _table_name.clear();
        _select_columns.clear();
        _groupby_columns.clear();
        _where_condition.clear();
        _having_condition.clear();
        _order_by.clear();
        _limit.clear();
        _offset.clear();
        return *this;
    }

    std::ostream &operator<<(std::ostream &out, SelectModel &mod) {
        out << mod.str();
        return out;
    }


}