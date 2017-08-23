//
// Created by yhy on 2017/8/15.
//

#ifndef SQL_BUILDER_UPDATEMODEL_H
#define SQL_BUILDER_UPDATEMODEL_H

#include "SqlModel.h"
#include "Column.h"
#include "Util.h"


namespace sql {


    class UpdateModel : public SqlModel {
    public:
        UpdateModel() = default;

        virtual ~UpdateModel() = default;

        UpdateModel &update(const std::string &table_name);

        template<typename T>
        UpdateModel &set(const std::string &c, const T &data) {
            std::string str(c);
            str.append(" = ");
            str.append(to_value(data));
            _set_columns.push_back(str);
            return *this;
        }

		//************************************
		// Method:    set
		// FullName:  sql::UpdateModel::set
		// Access:    public 
		// Returns:   sql::UpdateModel &
		// Qualifier: no have value 
		// Parameter: const std::string & c
		// Parameter: const std::nullptr_t &
		//************************************
		UpdateModel &set(const std::string &c, const std::nullptr_t &) {
			std::string str(c);
			str.append(" = null");
			_set_columns.push_back(str);
			return *this;
		}
        template<typename T>
        UpdateModel &operator()(const std::string &c, const T &data) {
            return set(c, data);
        }

        UpdateModel &where(const std::string &condition);

        UpdateModel &where(Column &condition);

        UpdateModel &reset();

        const std::string &str() override;

        friend std::ostream &operator<<(std::ostream &out, UpdateModel &mod);

    protected:
        std::vector<std::string> _set_columns;
        std::string _table_name;
        std::vector<std::string> _where_condition;
    };


}

#endif //SQL_BUILDER_UPDATEMODEL_H
