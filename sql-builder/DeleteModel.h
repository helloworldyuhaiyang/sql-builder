//
// Created by yhy on 2017/8/15.
//

#ifndef SQL_BUILDER_DELETEMODEL_H
#define SQL_BUILDER_DELETEMODEL_H


#include <vector>
#include "SqlModel.h"
#include "Column.h"

namespace sql {


    class DeleteModel : public SqlModel {
    public:
        DeleteModel() = default;

        virtual ~DeleteModel() = default;

        DeleteModel &_delete();

        template<typename... Args>
        DeleteModel &from(const std::string &table_name, Args &&... tables) {
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
        DeleteModel &from();

        DeleteModel &where(const std::string &condition);

        DeleteModel &where(Column &condition);

        const std::string &str() override;

        DeleteModel &reset();


        friend std::ostream &operator<<(std::ostream &out, DeleteModel &mod);

    protected:
        std::string _table_name;
        std::vector<std::string> _where_condition;
    };
}


#endif //SQL_BUILDER_DELETEMODEL_H
