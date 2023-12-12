#include <stdio.h>
#include <sqlite3.h>
#include <unistd.h>

int callback(void *unused, int argc, char **argv, char **col_name) {
    for (int i = 0; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    const char *data_file = "data.db";
    if (access(data_file, F_OK) == 0) {
        remove(data_file);
    }
    sqlite3_open(data_file, &db);

    char *sql_stmt = "CREATE TABLE person(name, age);";
    sqlite3_exec(db, sql_stmt, callback, NULL, NULL);
    sql_stmt = "INSERT INTO person VALUES('John', 18);";
    sqlite3_exec(db, sql_stmt, callback, NULL, NULL);
    sql_stmt = "SELECT * FROM person;";
    sqlite3_exec(db, sql_stmt, callback, NULL, NULL);

    sqlite3_close(db);
    return 0;
}
