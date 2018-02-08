//
//  HEVCCodec.hpp
//  iOSCodecDemo
//
//  Created by yang on 2018/2/6.
//  Copyright © 2018年 BookOfStopHere. All rights reserved.
//

#ifndef HEVCCodec_hpp
#define HEVCCodec_hpp

#include <stdio.h>
#include "BaseCodec.hpp"

namespace Codec{
    class HEVCCodec : public BaseCodec{
    public:
        virtual ~HEVCCodec();
        explicit HEVCCodec(void);
    };
};
#endif /* HEVCCodec_hpp */
