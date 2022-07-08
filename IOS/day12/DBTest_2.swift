//
//  ViewController.swift
//  DBtest
//
//  Created by Dongduk1 on 2022/07/08.
//

import UIKit
import SQLite3

class ViewController: UIViewController {
    
    let DB_NAME = "my_db.sqlite"
    let TABLE_NAME = "my_table"
    let COL_ID = "id"
    let COL_NAME = "name"
    
    var db: OpaquePointer? = nil // 데이터베이스를 가리키는 포인터
    
    let manager = DBManager()

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func btnOpenDatabase(_ sender: UIButton) {
        // DB 열기
        manager.openDatabase()
    }
    
    @IBAction func btnCreateTable(_ sender: UIButton) {
        // 데이터를 저장할 테이블 생성
        manager.createTable()
    }
    
    
    @IBAction func btnInsert(_ sender: UIButton) {
        // 샘플 데이터 추가
        manager.insert("test1")
    }
    
    @IBAction func btnSelectAll(_ sender: UIButton) {
        // 전체 데이터 확인
        manager.selectAll("test1")
    }
    
    @IBAction func btnUpdate(_ sender: UIButton) {
        // id 1인 항목 이름을 수정
        manager.update("test1")
    }
    
    @IBAction func btnDelete(_ sender: UIButton) {
        // id 1인 항목 이름을 삭제
        manager.delete("test1")
    }
    
    @IBAction func btnDropTable(_ sender: UIButton) {
        // 테이블 삭제
        manager.drop()
    }
    
    @IBAction func btnCloseDatabase(_ sender: UIButton) {
        // DB 닫기
        manager.close()
    }
    
    
    
}

