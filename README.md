# cpp_db_conn

## c查询mysql方案和demo(mysql.h)
使用c语言和mysql的对接demo    
依赖安装包:    
```
sudo apt install mysql-server mysql-client
sudo apt install libmysqlclient-dev
```

验证安装ok:  
```
ubuntu@VM-16-5-ubuntu:~/cpp_db_conn$ mysql_config --cflags --libs
-I/usr/include/mysql 
-L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -lrt -lssl -lcrypto -ldl
```

创建数据库和测试表   
```
CREATE DATABASE IF NOT EXISTS test
DEFAULT CHARACTER SET utf8
DEFAULT COLLATE utf8_general_ci;

use test;

DROP TABLE IF EXISTS `dept`;

CREATE TABLE `dept` (
  `deptno` tinyint(2) NOT NULL,
  `dname` varchar(14) DEFAULT NULL,
  `loc` varchar(13) DEFAULT NULL,
  PRIMARY KEY (`deptno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `dept` VALUES (10,'部门ACCOUNTING','NEW YORK'),(20,'部门RESEARCH','DALLAS'),(30,'部门SALES','CHICAGO'),(40,'部门OPERATIONS','BOSTON ');
```
编译和运行  
```
mkdir build
cd build
cmake ..
make 

ubuntu@VM-16-5-ubuntu:~/cpp_db_conn/build$ ./c_mysql_conn 
connect success!
insert OK
查询到 6 行 
deptno	dname	loc	
10	部门ACCOUNTING	NEW YORK	
20	部门RESEARCH	DALLAS	
30	部门SALES	CHICAGO	
40	部门OPERATIONS	BOSTON 	
111	research	new york	
delete OK
```
## cpp查询mysql方案(cpp-mysql-conn)
依赖安装包:   
```
sudo apt-get install mysql-server mysql-client
sudo apt-get install libboost-dev
sudo apt-get install libcpprest-dev
sudo apt-get install libmysqlclient-dev -y
sudo apt-get install libmysqlcppconn-dev
```
编译命令:  
gcc编译  
```
cpp_mysql_conn.cpp  
g++ cpp_mysql_conn.cpp -o test -lmysqlcppconn
```

cmake编译和运行  
```
mkdir build
cd build
cmake ..
make  

ubuntu@VM-16-5-ubuntu:~/cpp_db_conn/build$ ./cpp_mysql_conn  
Running 'SELECT 'Hello World!'   AS _message'...
	... MySQL replies: Hello World!
	... MySQL says it again: Hello World!
```

## cpp查询sqlite方案cpp-sqlite-conn
依赖安装包:   
```
sudo apt-get install libsqlite3-dev
```
编译，执行同之前的(需要自己创建sqlitedb文件)  

