//
// Created by yhy on 2017/8/15.
//

#include "TestInsertModel.h"

void TestInsertModel::SetUpTestCase() {
    std::cout << "begin test InsertModel" << std::endl;
}

void TestInsertModel::TearDownTestCase() {
    std::cout << "end test InsertModel" << std::endl;
}


TEST_F(TestInsertModel, insert) {
    InsertModel i;
    i.insert("score", 100)
                    ("name", std::string("yu"))
                    ("age", 28)
                    ("address", nullptr)
                    ("create_time", "2016-03-25 10:15:59")
            .into("user");
    std::cout << i.str() << std::endl;
    ASSERT_EQ(i.str(),
              "insert into user(score, name, age, address, create_time) values(100, 'yu', 28, null, '2016-03-25 10:15:59')");
}

