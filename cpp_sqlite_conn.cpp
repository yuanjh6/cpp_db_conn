#include <iostream>
#include <string>
#include "sqlite3.h"
using namespace std;
static int callback(void *data,int args_num,char **argv,char **argc){
   for(int i=0;i<args_num;i++){
      cout<<argc[i]<<" = " <<(argv[i]?argv[i]:"NULL")<<"\t";
   }
   cout<<endl;
   return 0;
}
 
int main(){
  sqlite3 *db;
  char *errMsg;
  string sql = "insert into user (name,age,mobile) values ('xxx',20,'15011186301')";
  int rc = sqlite3_open("/data/testsqlite3.db",&db);
  if(rc!=SQLITE_OK){
    cout<<"open sqlite3 fail."<<endl;
    return -1;
  }
  cout<<"open sqlite3 ok."<<endl;
  int rs = sqlite3_exec(db,sql.c_str(),0,0,&errMsg);
  if(rs!=SQLITE_OK){
     cout<<"insert fail"<<endl;
  }else{
     cout<<"insert data ok."<<endl;
  }
  sql = "select * from user"; 
  int first = 0;
  sqlite3_exec(db,sql.c_str(),callback,(void *)&first,&errMsg);
  sqlite3_close(db);
  return 0;
}
