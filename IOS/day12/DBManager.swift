//
//  DBManager.swift
//  DBtest
//
//  Created by Dongduk1 on 2022/07/08.
//

import Foundation
import SQLite3

class DBManager {
    
    let DB_NAME = "my_db.sqlite"
    let TABLE_NAME = "my_table"
    let COL_ID = "id"
    let COL_NAME = "name"
    
    var db: OpaquePointer? = nil // 데이터베이스를 가리키는 포인터
    
    func openDatabase() {
        // DB 열기
        let dbFile = try! FileManager.default.url(for: .documentDirectory, in: .userDomainMask, appropriateFor: nil, create: false).appendingPathComponent(DB_NAME)
        
        if sqlite3_open(dbFile.path, &db) == SQLITE_OK {
            print("Sucessfully Opened")
            print(dbFile)
        } else {
            print("Unable to open DB")
        }
    }

    func createTable() {
        // 데이터를 저장할 테이블 생성
        // 테이블이 없을때 실행
        let createTableString = """
            CREATE TABLE IF NOT EXISTS \(TABLE_NAME) ( \(COL_ID) INTEGER PRIMARY KEY AUTOINCREMENT, \(COL_NAME) TEXT);
        """
        
        var createTableStmt: OpaquePointer?
        
        print("TABLE SQL: \(createTableString)")
        
        if sqlite3_prepare(db, createTableString, -1, &createTableStmt, nil) == SQLITE_OK {
            if sqlite3_step(createTableStmt) == SQLITE_DONE { // 정상적으로 실행되면 DONE 반환
                print("Successfully created.")
            }
            sqlite3_finalize(createTableStmt)
        } else {
            let error = String(cString: sqlite3_errmsg(db)!)
            print("Table Error: \(error)")
        }
        
    }
    
    func insert(_ name: String) {
        // 샘플 데이터 추가
        var insertStmt: OpaquePointer?
        
        if sqlite3_prepare_v2(db, "insert into \(TABLE_NAME) values (null, ?)", -1, &insertStmt, nil) == SQLITE_OK {
            let SQLITE_TRANSIENT = unsafeBitCast(-1, to: sqlite3_destructor_type.self)
            
            if sqlite3_bind_text(insertStmt, 1, name, -1, SQLITE_TRANSIENT) != SQLITE_OK {
                let errmsg = String(cString: sqlite3_errmsg(db)!)
                print("Text Binding Failure: \(errmsg)")
                return
            }
            
            if sqlite3_step(insertStmt) == SQLITE_DONE {
                print("Successfully inserted.")
            } else {
                print("insert error")
            }
            
            sqlite3_finalize(insertStmt)
        } else {
            print("Insert statement is not prepared.")
        }
    }
    
    func selectAll(_ name: String) {
        // 전체 데이터 확인
        let sql = "select * from \(TABLE_NAME) " //where \(COL_NAME) = 'test1'"
        
        var queryStmt: OpaquePointer?
        
        if sqlite3_prepare(db, sql, -1, &queryStmt, nil) != SQLITE_OK {
            let errmsg = String(cString: sqlite3_errmsg(db)!)
            print("Reading Error: \(errmsg)")
            return
        }
        
        while(sqlite3_step(queryStmt) == SQLITE_ROW) {
            let id = sqlite3_column_int(queryStmt, 0)
            let name = String(cString: sqlite3_column_text(queryStmt, 1))
            print("id: \(id) name: \(name)")
        }
        
        sqlite3_finalize(queryStmt)
    }
    
    func update(_ name: String) {
            // id 1인 항목 이름을 수정
            let query = "update \(TABLE_NAME) set \(COL_NAME) = ? where \(COL_ID) = ?"
            
            var updateStmt: OpaquePointer?
            
            if sqlite3_prepare(db, query, -1, &updateStmt, nil) != SQLITE_OK {
                let errmsg = String(cString: sqlite3_errmsg(db)!)
                print("error preparing update: \(errmsg)")
                return
            }
            
            let SQLITE_TRANSIENT = unsafeBitCast(-1, to: sqlite3_destructor_type.self)
            
            //prepared statement 매개변수 연결(binding)
            if sqlite3_bind_text(updateStmt, 1, "my_id", -1, SQLITE_TRANSIENT) != SQLITE_OK {
                let errmsg = String(cString: sqlite3_errmsg(db)!)
                print("Text Binding Failure: \(errmsg)")
                return
            }
            
            if sqlite3_bind_int(updateStmt, 2, 1) != SQLITE_OK {
                let errmsg = String(cString: sqlite3_errmsg(db)!)
                print("Integer Binding Failure: \(errmsg)")
                return
            }
            
            if sqlite3_step(updateStmt) != SQLITE_DONE {
                let errmsg = String(cString: sqlite3_errmsg(db)!)
                print("Update Failure: \(errmsg)")
                return
            }
            
            sqlite3_finalize(updateStmt)
    }
    
    func delete(_ name: String) {
        // id 1인 항목 이름을 삭제
        let query = "delete from \(TABLE_NAME) where \(COL_ID) = ?"
        var deleteStmt: OpaquePointer?
        
        if sqlite3_prepare(db, query, -1, &deleteStmt, nil) != SQLITE_OK {
            let errmsg = String(cString: sqlite3_errmsg(db)!)
            print("error preparing stmt: \(errmsg)")
            return
        }
        
        bindIntParams(deleteStmt!, no: 1, param: 1)
        
        if sqlite3_step(deleteStmt) != SQLITE_DONE {
            let errmsg = String(cString: sqlite3_errmsg(db)!)
            print("Delete Failure: \(errmsg)")
            return
        }
        
        sqlite3_finalize(deleteStmt)
    }
    
    func drop() {
        // 테이블 삭제
        if sqlite3_exec(db, "drop table if exists \(TABLE_NAME)", nil, nil, nil) != SQLITE_OK {
            let errmsg = String(cString: sqlite3_errmsg(db)!)
            print("Drop Error: \(errmsg)")
            return
        }
    }
    
    func close() {
        // DB 닫기
        if sqlite3_close(db) != SQLITE_OK {
            let errmsg = String(cString: sqlite3_errmsg(db)!)
            print("Database Close Error: \(errmsg)")
            return
        }
    }
    
    
    func bindIntParams(_ stmt: OpaquePointer, no: Int, param: Int) {
        if sqlite3_bind_int(stmt, Int32(no), Int32(param)) != SQLITE_OK {
            let errmsg = String(cString: sqlite3_errmsg(db)!)
            print("Integer Binding Failure: \(errmsg)")
            return
        }
    }
    
    func bindTextParams(_ stmt: OpaquePointer, no: Int, param: String) {
        let SQLITE_TRANSIENT = unsafeBitCast(-1, to: sqlite3_destructor_type.self)
        
        if sqlite3_bind_text(stmt, Int32(no), param, -1, SQLITE_TRANSIENT) != SQLITE_OK {
            let errmsg = String(cString: sqlite3_errmsg(db)!)
            print("Text Binding Failure: \(errmsg)")
            return
        }
    }
}
