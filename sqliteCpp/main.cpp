#include <stdio.h>
#include <ios>
#include <iostream>
#include "sqlite3.h"

using namespace std;

// http://www.adp-gmbh.ch/sqlite/bind_insert.html
int main(int argc, char **argv){

	int rc;
	char *error;

	// Open database
	sqlite3 *db;
	rc = sqlite3_open("library.db", &db);

	if(rc){
		cerr << "Error opening SQLite3 database: " << sqlite3_errmsg(db) << endl << endl;
		sqlite3_close(db);
		return 1;
	}

	// Eecute SQL
	const char *sqlDropTable = "DROP TABLE IF EXISTS CATEGORY";
	rc = sqlite3_exec(db, sqlDropTable, NULL, NULL, &error);
	if (rc){
      cerr << "Error executing SQLite3 statement: " << sqlite3_errmsg(db) << endl << endl;
      sqlite3_free(error);
	  return 1;
	}

	// Execute SQL
	const char *sqlCreateTable = "CREATE TABLE CATEGORY (CID VARCHAR2(1) PRIMARY KEY, MAX_BOOKS INT, LOAN_PERIOD INT, CHECK(MAX_BOOKS BETWEEN 1 AND 99), CHECK(LOAN_PERIOD BETWEEN 1 AND 99))";
	rc = sqlite3_exec(db, sqlCreateTable, NULL, NULL, &error);
	if (rc){
      cerr << "Error executing SQLite3 statement: " << sqlite3_errmsg(db) << endl << endl;
      sqlite3_free(error);
	   return 1;
	}

	// Eecute SQL
	//const char *sqlInsert = "INSERT INTO CATEGORY VALUES(1, 5, 3)";
	//rc = sqlite3_exec(db, sqlInsert, NULL, NULL, &error);

	const char *sqlInsert = "INSERT INTO CATEGORY VALUES(?, ?, ?)";

	sqlite3_stmt *stmt;

	if (sqlite3_prepare(
			db, 
			sqlInsert,  // stmt
			-1, // If than zero, then stmt is read up to the first nul terminator
			&stmt,
			 0  // Pointer to unused portion of stmt
       )
       != SQLITE_OK) {
		printf("\nCould not prepare statement.");
		return 1;
	}

	if (sqlite3_bind_text(
        stmt,
        1,  // Index of wildcard
        "2",
        1,  // length of text
        SQLITE_STATIC
        )
      != SQLITE_OK) {
		printf("\nCould not bind text.\n");
		return 1;
	}

	if (sqlite3_bind_int(
        stmt,
        2,  // Index of wildcard
        8
        )
      != SQLITE_OK) {
		printf("\nCould not bind int.\n");
		return 1;
	}

	if (sqlite3_bind_int(
        stmt,
        3,  // Index of wildcard
        7
        )
      != SQLITE_OK) {
		printf("\nCould not bind int.\n");
		return 1;
	}

	if (sqlite3_step(stmt) != SQLITE_DONE) {
		printf("\nCould not step (execute) stmt.\n");
		return 1;
	}

	sqlite3_close(db);
	//system("PAUSE");
	return 0;
}
