#include <stdio.h>
#include <sqlite3.h>

int main() {
    sqlite3* db;
    sqlite3_open("data.db", &db);
    sqlite3_close(db);
    return 0;
}
