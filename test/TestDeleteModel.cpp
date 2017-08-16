//
// Created by yhy on 2017/8/16.
//

#include "TestDeleteModel.h"

void TestDeleteModel::SetUpTestCase() {
    std::cout << "begin test DeleteModel" << std::endl;
}

void TestDeleteModel::TearDownTestCase() {
    std::cout << "end test DeleteModel" << std::endl;
}

TEST_F(TestDeleteModel, deleteTest) {
    DeleteModel d;
    d._delete()
            .from("user")
            .where(Column("id") == 1);
    std::cout << d << std::endl;

    ASSERT_EQ(d.str(), "delete from user where id = 1");
}