//
// Created by yhy on 2017/8/15.
//

#ifndef SQL_BUILDER_TESTSELECTMODEL_H
#define SQL_BUILDER_TESTSELECTMODEL_H

#include <sql-builder/SelectModel.h>
#include "gtest/gtest.h"

using namespace sql;

class TestSelectModel : public testing::Test {
public:
    TestSelectModel() = default;

    ~TestSelectModel() = default;

    static void SetUpTestCase();

    static void TearDownTestCase();

    SelectModel sql;
};


#endif //SQL_BUILDER_TESTSELECTMODEL_H
