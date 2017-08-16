//
// Created by yhy on 2017/8/15.
//

#include "Column.h"

sql::Column::Column(const std::string &column) {
    _cond = column;
}

sql::Column &sql::Column::as(const std::string &s) {
    _cond.append(" as ");
    _cond.append(s);
    return *this;
}

sql::Column &sql::Column::is_null() {
    _cond.append(" is null");
    return *this;
}

sql::Column &sql::Column::is_not_null() {
    _cond.append(" is not null");
    return *this;
}

sql::Column &sql::Column::operator&&(sql::Column &condition) {
    std::string str("(");
    str.append(_cond);
    str.append(") and (");
    str.append(condition._cond);
    str.append(")");
    condition._cond = str;
    return condition;
}

sql::Column &sql::Column::operator||(sql::Column &condition) {
    std::string str("(");
    str.append(_cond);
    str.append(") or (");
    str.append(condition._cond);
    str.append(")");
    condition._cond = str;
    return condition;
}

sql::Column &sql::Column::operator&&(const std::string &condition) {
    _cond.append(" and ");
    _cond.append(condition);
    return *this;
}

sql::Column &sql::Column::operator||(const std::string &condition) {
    _cond.append(" or ");
    _cond.append(condition);
    return *this;
}

sql::Column &sql::Column::operator&&(const char *condition) {
    _cond.append(" and ");
    _cond.append(condition);
    return *this;
}

sql::Column &sql::Column::operator||(const char *condition) {
    _cond.append(" or ");
    _cond.append(condition);
    return *this;
}
