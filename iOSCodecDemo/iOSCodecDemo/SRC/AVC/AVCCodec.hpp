//
//  AVCCodec.hpp
//  iOSCodecDemo
//
//  Created by yang on 2018/2/6.
//  Copyright © 2018年 BookOfStopHere. All rights reserved.
//

#ifndef AVCCodec_hpp
#define AVCCodec_hpp

#include <stdio.h>
#include "BaseCodec.hpp"

namespace Codec{
    class AVCCodec : public BaseCodec{
    public:
        virtual ~AVCCodec();
        AVCCodec(void);
        static bool hardwareCodecCapabilities();
    };
};
#endif /* AVCCodec_hpp */
