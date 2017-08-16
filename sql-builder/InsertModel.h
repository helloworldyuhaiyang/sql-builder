//
// Created by yhy on 2017/8/15.
//

#ifndef SQL_BUILDER_INSERTMODEL_H
#define SQL_BUILDER_INSERTMODEL_H

#include <vector>
#include "SqlModel.h"
#include "Util.h"


namespace sql {

    class InsertModel : public SqlModel {
    public:
        InsertModel() = default;

        virtual ~InsertModel() = default;

        template<typename T>
        InsertModel &insert(const std::string &c, const T &data) {
            _columns.push_back(c);
            _values.push_back(to_value(data));
            return *this;
        }

        template<typename T>
        InsertModel &operator()(const std::string &c, const T &data) {
            return insert(c, data);
        }

        void into(const std::string &table_name);

        const std::string &str() override;

        InsertModel &reset();

        friend std::ostream &operator<<(std::ostream &out, InsertModel &mod);

    protected:
        std::string _table_name;
        std::vector<std::string> _columns;
        std::vector<std::string> _values;
    };

}


#endif //SQL_BUILDER_INSERTMODEL_H
