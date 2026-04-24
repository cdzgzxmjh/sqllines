# SQLines SQL 转换工具

SQLines SQL 转换工具是一款开源工具（Apache License 2.0），可帮助您在 Microsoft SQL Server、Oracle、MariaDB、MySQL、PostgreSQL、IBM DB2、Sybase、Informix、Teradata、Greenplum 和 Netezza 之间转换数据库结构（DDL）、查询和 DML 语句、视图、存储过程、包、函数和触发器。

在线体验：http://www.sqlines.com/online

> [English](README.md)

## 支持的转换方向

**源方言：** `oracle`, `mysql`, `postgresql`, `sqlserver`, `db2`, `sybase`, `informix`, `teradata`, `greenplum`, `netezza`

**目标方言：** `oracle`, `mysql`, `postgresql`, `sqlserver`, `db2`, `sybase`, `informix`, `teradata`, `greenplum`

## 使用方法

### 快速上手

将单个 SQL 文件从 Oracle 转换为 MySQL：

```cmd
sqlines.exe -s oracle -t mysql -in input.sql -out output.sql
```

将 Oracle 转换为 PostgreSQL：

```cmd
sqlines.exe -s oracle -t postgresql -in input.sql -out output.sql
```

将 SQL Server 转换为 Oracle：

```cmd
sqlines.exe -s sqlserver -t oracle -in input.sql -out output.sql
```

### 命令行参数

| 参数 | 说明 |
|------|------|
| `-s <方言>` | 源数据库方言 |
| `-t <方言>` | 目标数据库方言 |
| `-in <文件>` | 输入的 SQL 文件路径 |
| `-out <文件>` | 输出的 SQL 文件路径 |
| `-d` | 开启调试输出（显示详细转换过程） |
| `-?` | 显示帮助信息 |

### 批量转换（Windows CMD）

转换目录下所有 `.sql` 文件：

```cmd
for %f in (D:\scripts\*.sql) do sqlines.exe -s oracle -t mysql -in %f -out D:\mysql\%~nf.sql
```

### 转换示例

**DDL 转换（CREATE TABLE）：**

Oracle 源：
```sql
CREATE TABLE t1 (
    id NUMBER(10) PRIMARY KEY,
    name VARCHAR2(100),
    created_date DATE DEFAULT SYSDATE
);
```

MySQL 目标（转换后）：
```sql
CREATE TABLE t1 (
    id BIGINT PRIMARY KEY,
    name VARCHAR(100),
    created_date DATETIME DEFAULT SYSDATE()
);
```

**DML 转换（SELECT 查询）：**

Oracle 源：
```sql
SELECT empno, ename, NVL(comm, 0), TO_CHAR(hiredate, 'YYYY-MM-DD')
  FROM emp
 WHERE ROWNUM <= 10;
```

MySQL 目标（转换后）：
```sql
SELECT empno, ename, IFNULL(comm, 0), DATE_FORMAT(hiredate, '%Y-%m-%d')
  FROM emp
 LIMIT 10;
```

## 从源码编译

### 环境要求

- MinGW-w64（GCC for Windows），支持 C++11
- 预编译版本适用于 Windows 10/11 或 Windows Server 2016+

### 编译步骤

**1. 编译 SQLParser 库：**

```cmd
cd sqlparser
g++ -m64 -fpermissive -c dllmain.cpp cobol.cpp file.cpp clauses.cpp datatypes.cpp db2.cpp functions.cpp greenplum.cpp guess.cpp java.cpp informix.cpp language.cpp mysql.cpp oracle.cpp postgresql.cpp select.cpp helpers.cpp patterns.cpp post.cpp procedures.cpp report.cpp storage.cpp sqlparser.cpp sqlserver.cpp statements.cpp stats.cpp str.cpp sybase.cpp teradata.cpp token.cpp
ar rcs sqlparser.a *.o
cd ..
```

**2. 编译 SQLines：**

```cmd
cd sqlines
g++ -m64 -fpermissive -c applog.cpp file.cpp filelist.cpp main.cpp os.cpp parameters.cpp sqlines.cpp
g++ -m64 -static -static-libgcc -static-libstdc++ applog.o file.o filelist.o main.o os.o parameters.o sqlines.o ../sqlparser/sqlparser.a -o sqlines.exe
cd ..
```

## 技术支持

如需技术支持或定制开发，请联系我们：support@sqlines.com
