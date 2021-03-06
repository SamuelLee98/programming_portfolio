//
//  Event.swift
//  FOMO_V2
//
//  Created by Samuel Kyu-Seo Lee on 12/25/18.
//  Copyright © 2018 Samuel Kyu-Seo Lee. All rights reserved.
//

import UIKit

class Event: NSObject {
    
    var thumbNailImageName: String?
    var title: String?
    var numCompanies: NSNumber = 0.0 //get rid of it for now
    var descript: String?
    var date: String?
    var time: String?
    var building: String?
    var address: String?
    
    var channel: Channel? 
}

class Channel: NSObject {
    var name: String?
    var profileImageName: String?
}
