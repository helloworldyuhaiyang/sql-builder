//
// Created by yhy on 2017/8/16.
//

#include "TestUpdateModel.h"

void TestUpdateModel::SetUpTestCase() {
    std::cout << "begin test UpdateModel" << std::endl;
}

void TestUpdateModel::TearDownTestCase() {
    std::cout << "end test UpdateModel" << std::endl;
}

TEST_F(TestUpdateModel, update) {
    std::vector<int> a = {1, 2};
    updateModel.update("user")
            .set("name", "yu")
                    ("age", 18)
                    ("score", 50)
                    ("address", nullptr)
            .where(Column("id").in(a));
    std::cout << updateModel << std::endl;

    ASSERT_EQ(updateModel.str(),
              "update user set name = 'yu', age = 18, score = 50, address = null where id in (1, 2)");
}
