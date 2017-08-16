//
// Created by yhy on 2017/8/16.
//

#ifndef SQL_BUILDER_TESTDELETEMODEL_H
#define SQL_BUILDER_TESTDELETEMODEL_H

#include "sql-builder/DeleteModel.h"
#include "gtest/gtest.h"

using namespace sql;

class TestDeleteModel : public testing::Test {
public:
    TestDeleteModel() = default;

    ~TestDeleteModel() = default;

    static void SetUpTestCase();

    static void TearDownTestCase();

    DeleteModel deleteModel;
};


#endif //SQL_BUILDER_TESTDELETEMODEL_H
