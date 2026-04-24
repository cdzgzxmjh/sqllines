# SQLines SQL Converter

SQLines SQL Converter is an open source tool (Apache License 2.0) that allows you to convert database schema (DDL), queries and DML statements, views, stored procedures, packages, functions and triggers between Microsoft SQL Server, Oracle, MariaDB, MySQL, PostgreSQL, IBM DB2, Sybase, Informix, Teradata, Greenplum and Netezza.

You can also try it online at http://www.sqlines.com/online

> [中文版](README_zh.md)

## Supported Conversions

Source dialects: `oracle`, `mysql`, `postgresql`, `sqlserver`, `db2`, `sybase`, `informix`, `teradata`, `greenplum`, `netezza`

Target dialects: `oracle`, `mysql`, `postgresql`, `sqlserver`, `db2`, `sybase`, `informix`, `teradata`, `greenplum`

## Usage

### Quick Start

Convert a single SQL file from Oracle to MySQL:

```cmd
sqlines.exe -s oracle -t mysql -in input.sql -out output.sql
```

Convert from Oracle to PostgreSQL:

```cmd
sqlines.exe -s oracle -t postgresql -in input.sql -out output.sql
```

Convert from SQL Server to Oracle:

```cmd
sqlines.exe -s sqlserver -t oracle -in input.sql -out output.sql
```

### Command Line Options

| Option | Description |
|--------|-------------|
| `-s <dialect>` | Source (input) database dialect |
| `-t <dialect>` | Target (output) database dialect |
| `-in <file>` | Input SQL file path |
| `-out <file>` | Output SQL file path |
| `-d` | Enable debug output (show detailed conversion process) |
| `-?` | Show help information |

### Batch Conversion (Windows CMD)

Convert all `.sql` files in a directory:

```cmd
for %f in (D:\scripts\*.sql) do sqlines.exe -s oracle -t mysql -in %f -out D:\mysql\%~nf.sql
```

### Examples

**DDL conversion (CREATE TABLE):**

Oracle:
```sql
CREATE TABLE t1 (
    id NUMBER(10) PRIMARY KEY,
    name VARCHAR2(100),
    created_date DATE DEFAULT SYSDATE
);
```

MySQL (after conversion):
```sql
CREATE TABLE t1 (
    id BIGINT PRIMARY KEY,
    name VARCHAR(100),
    created_date DATETIME DEFAULT SYSDATE()
);
```

**DML conversion (SELECT query):**

Oracle:
```sql
SELECT empno, ename, NVL(comm, 0), TO_CHAR(hiredate, 'YYYY-MM-DD')
  FROM emp
 WHERE ROWNUM <= 10;
```

MySQL (after conversion):
```sql
SELECT empno, ename, IFNULL(comm, 0), DATE_FORMAT(hiredate, '%Y-%m-%d')
  FROM emp
 LIMIT 10;
```

## Build from Source

### Prerequisites

- MinGW-w64 (GCC for Windows) with C++11 support
- Windows 10/11 or Windows Server 2016+ (for the pre-built binary)

### Build Steps

**1. Build SQLParser library:**

```cmd
cd sqlparser
g++ -m64 -fpermissive -c dllmain.cpp cobol.cpp file.cpp clauses.cpp datatypes.cpp db2.cpp functions.cpp greenplum.cpp guess.cpp java.cpp informix.cpp language.cpp mysql.cpp oracle.cpp postgresql.cpp select.cpp helpers.cpp patterns.cpp post.cpp procedures.cpp report.cpp storage.cpp sqlparser.cpp sqlserver.cpp statements.cpp stats.cpp str.cpp sybase.cpp teradata.cpp token.cpp
ar rcs sqlparser.a *.o
cd ..
```

**2. Build SQLines:**

```cmd
cd sqlines
g++ -m64 -fpermissive -c applog.cpp file.cpp filelist.cpp main.cpp os.cpp parameters.cpp sqlines.cpp
g++ -m64 -static -static-libgcc -static-libstdc++ applog.o file.o filelist.o main.o os.o parameters.o sqlines.o ../sqlparser/sqlparser.a -o sqlines.exe
cd ..
```

## Support

For technical support and custom development, please contact us at support@sqlines.com
