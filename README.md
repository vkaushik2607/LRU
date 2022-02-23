# LRU
lru implementation

The main program creates an object of the LRUCache class.
Sqlite implementation is not implemented yet, but can be done in a following way.

The db conection can be made in LRU cache constructor and 


    sqlite3* DB;
    sqlite3_stmt * st;
    std::string sql = "CREATE TABLE KEYTABLE("
                      "ID INT PRIMARY KEY     NOT NULL, "                                           
                      "KEY_DELETED         INT );";
    int exit = 0;
    exit = sqlite3_open("mydb.db", &DB);
    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
  
    if (exit != SQLITE_OK) {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Table created Successfully" << std::endl;
       
    sqlite3_close(DB);
    
    
    //Now when the value from get is mutated, we can run a insert query like below:
    insertIntoDB(int myKey)
    {
        if (sqlite3_open("mydb.db", &db) == SQLITE_OK)
        {
            string sql = "INSERT INTO KEYTABLE (KEY_DELETED) VALUES (?);";
            int rc = sqlite3_prepare(db, sql.c_str(), -1, &st, NULL);
            if (rc == SQLITE_OK)
            {
                sqlite3_bind_int(st, 1, myKey, myKey.size() , SQLITE_TRANSIENT);
                sqlite3_step(st);
                sqlite3_finalize(st);
            }
        }
    }
