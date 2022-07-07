//
//  ViewController.swift
//  MissionPinch
//
//  Created by Dongduk1 on 2022/07/07.
//

import UIKit

class ViewController: UIViewController {
    
    var images = ["01.png", "02.png", "03.png", "04.png", "05.png", "06.png"]

    @IBOutlet var imgView: UIImageView!
    @IBOutlet var pageControl: UIPageControl!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        // page Control
        pageControl.numberOfPages = images.count
        pageControl.currentPage = 0
        
        pageControl.pageIndicatorTintColor = UIColor.blue
        pageControl.currentPageIndicatorTintColor = UIColor.red
        
        imgView.image = UIImage(named: images[0])
        
        // 핀치
        let pinch = UIPinchGestureRecognizer(target: self, action: #selector(ViewController.doPinch(_:)))
        self.view.addGestureRecognizer(pinch)
        
        // 스와이프
        let swipeLeft = UISwipeGestureRecognizer(target: self, action: #selector(ViewController.respondToSwipeGesture(_:)))
        swipeLeft.direction = UISwipeGestureRecognizer.Direction.left
        self.view.addGestureRecognizer(swipeLeft)
              
        let swipeRight = UISwipeGestureRecognizer(target: self, action: #selector(ViewController.respondToSwipeGesture(_:)))
        swipeRight.direction = UISwipeGestureRecognizer.Direction.right
        self.view.addGestureRecognizer(swipeRight)
        
        
    }
    
    // page Control
    @IBAction func pageChange(_ sender: UIPageControl) {
        imgView.image = UIImage(named: images[pageControl.currentPage])
    }
    
    
    // 핀치
    @objc func doPinch(_ pinch: UIPinchGestureRecognizer) {
        imgView.transform = imgView.transform.scaledBy(x: pinch.scale, y: pinch.scale)
           pinch.scale = 1
      
       }
    
    // 스와이프
    @objc func respondToSwipeGesture(_ gesture: UIGestureRecognizer) {
        
            if let swipeGesture = gesture as? UISwipeGestureRecognizer {
            
                switch swipeGesture.direction {
                case UISwipeGestureRecognizer.Direction.left:
                    if(pageControl.currentPage < images.count-1) {
                        imgView.image = UIImage(named: images[pageControl.currentPage + 1])
                        pageControl.currentPage = pageControl.currentPage + 1
                    }
                case UISwipeGestureRecognizer.Direction.right:
                    if(pageControl.currentPage > 0) {
                        imgView.image = UIImage(named: images[pageControl.currentPage - 1])
                        pageControl.currentPage = pageControl.currentPage - 1
                    }
                default:
                    break
                }
                
            }
        
    }
}

