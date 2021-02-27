//
//  CCCDevice.h
//  CardConnectConsumerSDK_IDTech
//
//  Created by Nick Rimer on 12/28/18.
//  Copyright © 2018 iMobile3 LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 A device returned when finding BLE devices.
 
 Contains the device's name and its unique identifier that can be used with [CCCSwiperController connectToDevice:].
 */
@interface CCCDevice : NSObject

/**
 The name of the device
 */
@property (nonatomic, strong, readonly) NSString *name;

/**
 The unique identifier of the device.
 */
@property (nonatomic, strong, readonly) NSUUID *uuid;

@end
