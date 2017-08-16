//
// Created by yhy on 2017/8/16.
//

#ifndef SQL_BUILDER_TESTUPDATEMODEL_H
#define SQL_BUILDER_TESTUPDATEMODEL_H

#include <sql-builder/UpdateModel.h>
#include "gtest/gtest.h"

using namespace sql;

class TestUpdateModel : public testing::Test {
public:
    TestUpdateModel() = default;

    ~TestUpdateModel() = default;

    static void SetUpTestCase();

    static void TearDownTestCase();

    UpdateModel updateModel;
};


#endif //SQL_BUILDER_TESTUPDATEMODEL_H
