//
// Created by yhy on 2017/8/15.
//

#ifndef SQL_BUILDER_TESTINSERTMODEL_H
#define SQL_BUILDER_TESTINSERTMODEL_H

#include <sql-builder/InsertModel.h>
#include "gtest/gtest.h"

using namespace sql;

class TestInsertModel : public testing::Test {
public:
    TestInsertModel() = default;

    ~TestInsertModel() = default;

    static void SetUpTestCase();

    static void TearDownTestCase();

    InsertModel sql;
};


#endif //SQL_BUILDER_TESTINSERTMODEL_H
