//
//  ViewController.swift
//  ImageView_Mission
//
//  Created by Hyein on 2022/06/23.
//

import UIKit

class ViewController: UIViewController {

    var imgMid: UIImage?
    var i = 3
    
    @IBOutlet var imgView: UIImageView!
    @IBOutlet var btnPrev: UIButton!
    @IBOutlet var btnNext: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        imgMid = UIImage(named: "3.png")
        
        imgView.image = imgMid
        
    }
    
    @IBAction func btnPrevImg(_ sender: UIButton) {
        let imgName = String(i) + ".png"
        
        if(i <= 1){
            i = 1
        } else {
            i -= 1
        }
        imgView.image = UIImage(named: imgName)
            
    
    }
    
    @IBAction func btnNextImg(_ sender: UIButton) {
        let imgName = String(i) + ".png"
        
        if(i >= 6){
            i = 6
        } else {
            i += 1
        }
        
        imgView.image = UIImage(named: imgName)
    
    }
    
}