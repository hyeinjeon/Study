//
//  ViewController.swift
//  DatePicker
//
//  Created by Hyein on 2022/06/22.
//  알람시계 만들기
//  + 현재 시간 읽는 함수
//

import UIKit

class ViewController: UIViewController {
    let timeSelector: Selector = #selector(ViewController.updateTime)
    let interval = 1.0
    var count = 0
    var alarmTime = ""
    var currentTime = ""

    @IBOutlet var backgroundView: UIView!
    @IBOutlet var lblCurrentTime: UILabel!
    @IBOutlet var lblPickerTime: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        Timer.scheduledTimer(timeInterval: interval, target: self, selector: timeSelector, userInfo: nil, repeats: true)
    }

    @IBAction func changeDatePicker(_ sender: UIDatePicker) {
        let datePickerView = sender
        
        let formatter = DateFormatter()
        formatter.dateFormat = "yyyy-MM-dd HH:mm aaa"
        lblPickerTime.text = "선택시간:" + formatter.string(from: datePickerView.date)
        
        alarmTime = formatter.string(from: datePickerView.date)
    }
    
    @objc func updateTime() {
//        lblCurrentTime.text = String(count)
//        count = count + 1
        
        let date = NSDate()
        
        let formatter = DateFormatter()
        formatter.dateFormat = "yyyy-MM-dd HH:mm aaa"
        lblCurrentTime.text =  "현재시간:" + formatter.string(from: date as Date)
        
        currentTime = formatter.string(from: date as Date)
        
        if(alarmTime == currentTime) {
            backgroundView.backgroundColor = UIColor.red
            
            let timeAlert = UIAlertController(title: "알림", message: "설정된 시간입니다", preferredStyle: UIAlertController.Style.alert)
                    
            let onAction = UIAlertAction(title: "네, 알겠습니다", style: UIAlertAction.Style.default, handler: {
                ACTION in
                self.present(timeAlert, animated: false, completion: nil)
            })
                    
            timeAlert.addAction(onAction)
            present(timeAlert, animated: true, completion: nil)

        }
        else {
            backgroundView.backgroundColor = UIColor.white
        }
    }
}

