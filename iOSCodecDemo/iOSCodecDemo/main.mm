//
//  main.m
//  iOSCodecDemo
//
//  Created by yang on 2018/2/5.
//  Copyright © 2018年 yang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#include "AVCCodec.hpp"
int main(int argc, char * argv[]) {
    @autoreleasepool {
        bool isyes = Codec::AVCCodec::hardwareCodecCapabilities();
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
