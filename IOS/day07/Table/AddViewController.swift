//
//  AddViewController.swift
//  Table
//
//  Created by Dongduk1 on 2022/06/30.
//

import UIKit

class AddViewController: UIViewController, UIPickerViewDelegate, UIPickerViewDataSource {
    
    let MAX_ARRAY_NUM = 3
    let PICKER_VIEW_COLUMN = 1
    let PICKER_VIEW_HEIGHT:CGFloat = 50
    
    var imageArray = [UIImage?]()
    var pickImageFileName = ""
    
    var imageFile = ["cart.png", "clock.png", "pencil.png"]
    var pos = 0
    
    @IBOutlet var tfAddItem: UITextField!
    @IBOutlet var imageView: UIImageView!
    @IBOutlet var imagePicker: UIPickerView!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        for i in 0..<MAX_ARRAY_NUM {
            let image = UIImage(named: imageFile[i])
            imageArray.append(image)
            print("ddddd")
        }
        
        imageView.image = UIImage(named: imageFile[0])
        pickImageFileName = imageFile[0]
    }
    
    @IBAction func btnAddItem(_ sender: UIButton) {
        items.append(tfAddItem.text!)
        itemsImageFile.append(imageFile[pos])
        tfAddItem.text = "" // text는 클리어
        _ = navigationController?.popViewController(animated: true)
    }
    
    func numberOfComponents(in pickerView: UIPickerView) -> Int {
           return PICKER_VIEW_COLUMN
    }
    
    func pickerView(_ pickerView: UIPickerView, rowHeightForComponent component: Int) -> CGFloat {
         return PICKER_VIEW_HEIGHT
     }
    
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
         return imageFile.count
     }
    
    // 파일명 대신 이미지 출력하기
    func pickerView(_ pickerView: UIPickerView, viewForRow row: Int, forComponent component: Int, reusing view: UIView?) -> UIView {
            print("3333:" + String(row))
            let imageView = UIImageView(image: imageArray[row])
        
            imageView.frame = CGRect(x: 0, y: 0, width: 30, height: 30)
            
            return imageView
    }
    
    func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
            imageView.image = imageArray[row]  //선택한 이미지를 이미지 뷰에 출력하기]
        self.pos = row
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
