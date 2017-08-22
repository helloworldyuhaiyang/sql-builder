# 帮助简单的写 sql 语句。
        #demo 在 test 目录下。单元测试依赖 gtest

# 安装
1.mkdir build
2.cd build
3.cmake ..
4.make
5.make install



# 使用

## 增
```
 InsertModel i;
    i.insert("score", 100)
            ("name", std::string("yu"))
            ("age", 28)
            ("address", nullptr)
            ("create_time", "2016-03-25 10:15:59")
    into("user");
 std::cout << i.str() << std::endl;
```

## 删
```
  DeleteModel d;
    d._delete()
            .from("user")
            .where(Column("id") == 1);
  std::cout << d << std::endl;
```

## 改
```
 updateModel.update("user")
            .set("name", "yu")
                    ("age", 18)
                    ("score", 50)
                    ("address", nullptr)
            .where(Column("id").in(a));
 std::cout << updateModel << std::endl;
```

## 查
```
 sql.select("id", "age", "name", "address")
            .from("user")
            .where(Column("score") > 60 and (Column("age") >= 20 or Column("address").is_not_null()))
            .group_by("age")
            .having(Column("age") > 10)
            .order_by("age desc")
            .limit(10)
            .offset(1);

    std::cout << sql << std::endl;
```

