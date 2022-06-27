//
//  ViewController.swift
//  Map
//
//  Created by Hyein on 2022/06/27.
//

import UIKit
import MapKit

class ViewController: UIViewController, CLLocationManagerDelegate {

    @IBOutlet var myMap: MKMapView!
    @IBOutlet var lblLocationInfo1: UILabel!
    @IBOutlet var lblLocationInfo2: UILabel!
    
    let locationManager = CLLocationManager()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        lblLocationInfo1.text = ""
        lblLocationInfo2.text = ""
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        locationManager.requestWhenInUseAuthorization()
        locationManager.startUpdatingLocation()
        myMap.showsUserLocation = true
    }
    
    @IBAction func sgChangeLocation(_ sender: UISegmentedControl) {
        if sender.selectedSegmentIndex == 0 {
            
        } else if sender.selectedSegmentIndex == 1 {
            setAnnotation(latitudeValue: 37.3677345, longtitudeValue: 127.1083617, delta: 1, title: "정자역", subtitle: "정자역 신분당선")
            self.lblLocationInfo1.text = "보고 계신 위치"
            self.lblLocationInfo2.text = "정자역 신분당선"
            
        } else if sender.selectedSegmentIndex == 2 {
            setAnnotation(latitudeValue: 37.34919, longtitudeValue: 127.1142351, delta: 0.01, title: "우리집", subtitle: "미금로 177")
            self.lblLocationInfo1.text = "보고 계신 위치"
            self.lblLocationInfo2.text = "미금로 177"
        }
    }
    
    func goLocation(latitudeValue: CLLocationDegrees,
                    longtitudeValue: CLLocationDegrees, delta span: Double) -> CLLocationCoordinate2D {
        let pLocation = CLLocationCoordinate2DMake(latitudeValue, longtitudeValue)
        let spanValue = MKCoordinateSpan(latitudeDelta: span, longitudeDelta: span)
        let pRegion = MKCoordinateRegion(center: pLocation, span: spanValue)
        myMap.setRegion(pRegion, animated: true)
        return pLocation
    }
    
    func setAnnotation(latitudeValue: CLLocationDegrees, longtitudeValue: CLLocationDegrees, delta span:Double, title strTitle: String, subtitle strSubtitle:String) {
        let annotation = MKPointAnnotation()
        annotation.coordinate = goLocation(latitudeValue: latitudeValue, longtitudeValue: longtitudeValue, delta: span)
        annotation.title = strTitle
        annotation.subtitle = strSubtitle
        myMap.addAnnotation(annotation)
    }
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        let pLocation = locations.last
        goLocation(latitudeValue: (pLocation?.coordinate.latitude)!, longtitudeValue: (pLocation?.coordinate.longitude)!, delta: 0.01)
        CLGeocoder().reverseGeocodeLocation(pLocation!, completionHandler: {
            (placemarks, error) -> Void in
            let pm = placemarks!.first
            let country = pm!.country
            var address:String = country!
            if pm!.locality != nil {
                address += " "
                address += pm!.locality!
            }
            if pm!.thoroughfare != nil {
                address += " "
                address += pm!.thoroughfare!
            }
            
            self.lblLocationInfo1.text = "현재 위치"
            self.lblLocationInfo2.text = address
        })
        
        locationManager.stopUpdatingLocation()
    }
    

}

