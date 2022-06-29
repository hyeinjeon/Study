//
//  DateViewController.swift
//  Navigation
//
//  Created by Dongduk1 on 2022/06/29.
//

import UIKit

protocol DateDelegate {
    func didDateDone(_ controller: DateViewController, message: String)
}

class DateViewController: UIViewController {
    
    var txtPickerTime: String = ""
    var delegate: DateDelegate?

    @IBOutlet var lblWay: UILabel!
    @IBOutlet var lblPickerTime: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }
    
    @IBAction func btnDone(_ sender: UIButton) {
        if delegate != nil {
            delegate?.didDateDone(self, message: lblPickerTime.text!)
        }
    
        _ = navigationController?.popViewController(animated: true)
    }
    
    @IBAction func changeDatePicker(_ sender: UIDatePicker) {
        let datePickerView = sender
        let formatter = DateFormatter()
        
        formatter.dateFormat = "yyyy-MM-dd HH:mm:ss aaa"
        lblPickerTime.text = "선택시간:" + formatter.string(from: datePickerView.date)
    }
    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

}
