//
//  ViewController.swift
//  MissionPageControl
//
//  Created by Hyein on 2022/06/28.
//

import UIKit

class ViewController: UIViewController {
    
    let pageCount = 10
    
    @IBOutlet var lblView: UILabel!
    @IBOutlet var pageControl: UIPageControl!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        pageControl.numberOfPages = pageCount
        pageControl.currentPage = 0
        
        pageControl.pageIndicatorTintColor = UIColor.green
        pageControl.currentPageIndicatorTintColor = UIColor.red
        
        lblView.text = String(1)
    }
    
    @IBAction func pageChange(_ sender: UIPageControl) {
        lblView.text = String(pageControl.currentPage + 1)
    }
    
}

