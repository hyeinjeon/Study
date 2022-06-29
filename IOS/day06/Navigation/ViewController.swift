//
//  ViewController.swift
//  Navigation
//
//  Created by Hyein on 2022/06/29.
//

import UIKit

class ViewController: UIViewController, EditDelegate, DateDelegate {
    
    let imgOn = UIImage(named: "lamp-on.png")
    let imgOff = UIImage(named: "lamp-off.png")
    
    var isOn = true
    var isZoom = true
    var isZoomOut = false

    @IBOutlet var txtMessage: UITextField!
    @IBOutlet var imgView: UIImageView!
    @IBOutlet var txtDate: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        imgView.image = imgOn
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if(segue.identifier == "dateBtn") {
            let dateViewController = segue.destination as!
            DateViewController
            
            dateViewController.delegate = self
            
        } else {
            let editViewController = segue.destination as!
                EditViewController
        
            if segue.identifier == "editBtn" {
                editViewController.textWayValue = "segue: use button"
            } else if segue.identifier == "editBarBtn" {
                editViewController.textWayValue = "segue: use Bar button"
            }
        
            editViewController.textMessage = txtMessage.text!
            editViewController.isOn = isOn
            editViewController.isZoom = isZoom
            editViewController.isZoomOut = isZoomOut
            editViewController.delegate = self
        }
    }
    
    
    func didDateDone(_ controller: DateViewController, message: String) {
        txtDate.text = message
    }

    
    func didMessageEditDone(_ controller: EditViewController, message: String) {
        txtMessage.text = message
    }
    
    func didImageOnOffDone(_ controller: EditViewController, isOn: Bool) {
        if isOn {
            imgView.image = imgOn
            self.isOn = true
        } else {
            imgView.image = imgOff
            self.isOn = false
        }
    }
    
    func didImageZoomDone(_ controller: EditViewController, isZoom: Bool) {
        if isZoom {
            imgView.frame = CGRect(x: 10, y: 300, width: 400, height: 500)
        }
    }
    
    func didImageZoomOutDone(_ controller: EditViewController, isZoomOut: Bool) {
        if isZoomOut {
            imgView.frame = CGRect(x: 50, y: 300, width: 100, height: 150)
        }
    }
    
    

}

