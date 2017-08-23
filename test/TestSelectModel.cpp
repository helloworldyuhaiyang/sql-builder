//
// Created by yhy on 2017/8/15.
//

#include <iostream>
#include "TestSelectModel.h"

void TestSelectModel::SetUpTestCase() {
    std::cout << "begin test SelectModel" << std::endl;
}

void TestSelectModel::TearDownTestCase() {
    std::cout << "end test SelectModel" << std::endl;
}


TEST_F(TestSelectModel, select) {
    sql.select("id", "age", "name", "address")
            .from("user")
            .where(Column("score") > 60 && (Column("age") >= 20 || Column("address").is_not_null()))
            .group_by("age")
            .having(Column("age") > 10)
            .order_by("age desc")
            .limit(10)
            .offset(1);

    std::cout << sql << std::endl;

    ASSERT_EQ(
            "select id, age, name, address from user where (score > 60) and ((age >= 20) or (address is not null)) group by age having age > 10 order by age desc limit 10 offset 1",
            sql.str());
}
