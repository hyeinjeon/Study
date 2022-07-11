
import UIKit

class AddViewController: UIViewController {
    @IBOutlet var dpPicker: UIDatePicker!
    @IBOutlet var tfTitle: UITextField!
    @IBOutlet var tfDetail: UITextField!
    
    var currentTime = ""
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        // DatePicker 에 현재 시간 설정
        let date = NSDate() 
        dpPicker.setDate(date as Date, animated: true)
        
    }

    @IBAction func btnSave(_ sender: UIButton) {
        // 뷰에 입력한 값을 사용하여 DB에 추가
        let today = Int32(dpPicker.date.timeIntervalSince1970)
        print("today int: \(today)")
        
        manager.insertItems(tfTitle.text!, detail: tfDetail.text!, date: today)
        
        _ = navigationController?.popViewController(animated: true)
    }
    

}

