//
// Created by yhy on 2017/8/15.
//

#ifndef SQL_BUILDER_COLUMN_H
#define SQL_BUILDER_COLUMN_H


#include <string>
#include <vector>
#include "Util.h"

namespace sql {


    class Column {
    public:
        Column(const std::string &column);

        virtual ~Column() = default;

        Column &as(const std::string &s);

        Column &is_null();

        Column &is_not_null();

        template<typename T>
        Column &in(const std::vector<T> &args) {
            size_t size = args.size();
            if (size == 1) {
                _cond.append(" = ");
                _cond.append(to_value(args[0]));
            } else {
                _cond.append(" in (");
                for (size_t i = 0; i < size; ++i) {
                    if (i < size - 1) {
                        _cond.append(to_value(args[i]));
                        _cond.append(", ");
                    } else {
                        _cond.append(to_value(args[i]));
                    }
                }
                _cond.append(")");
            }
            return *this;
        }

        template<typename T>
        Column &not_in(const std::vector<T> &args) {
            size_t size = args.size();
            if (size == 1) {
                _cond.append(" != ");
                _cond.append(to_value(args[0]));
            } else {
                _cond.append(" not in (");
                for (size_t i = 0; i < size; ++i) {
                    if (i < size - 1) {
                        _cond.append(to_value(args[i]));
                        _cond.append(", ");
                    } else {
                        _cond.append(to_value(args[i]));
                    }
                }
                _cond.append(")");
            }
            return *this;
        }

        Column &operator&&(Column &condition);

        Column &operator||(Column &condition);

        Column &operator&&(const std::string &condition);

        Column &operator||(const std::string &condition);

        Column &operator&&(const char *condition);

        Column &operator||(const char *condition);

        template<typename T>
        Column &operator==(const T &data) {
            _cond.append(" = ");
            _cond.append(to_value(data));
            return *this;
        }

        template<typename T>
        Column &operator!=(const T &data) {
            _cond.append(" != ");
            _cond.append(to_value(data));
            return *this;
        }

        template<typename T>
        Column &operator>=(const T &data) {
            _cond.append(" >= ");
            _cond.append(to_value(data));
            return *this;
        }

        template<typename T>
        Column &operator<=(const T &data) {
            _cond.append(" <= ");
            _cond.append(to_value(data));
            return *this;
        }

        template<typename T>
        Column &operator>(const T &data) {
            _cond.append(" > ");
            _cond.append(to_value(data));
            return *this;
        }

        template<typename T>
        Column &operator<(const T &data) {
            _cond.append(" < ");
            _cond.append(to_value(data));
            return *this;
        }

        const std::string &str() const {
            return _cond;
        }

        operator bool() {
            return true;
        }

    private:
        std::string _cond;
    };


}

#endif //SQL_BUILDER_COLUMN_H
