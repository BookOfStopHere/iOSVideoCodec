//
//  AVCCodec.cpp
//  iOSCodecDemo
//
//  Created by yang on 2018/2/6.
//  Copyright © 2018年 BookOfStopHere. All rights reserved.
//

#include "AVCCodec.hpp"
#include <VideoToolbox/VideoToolbox.h>
#include <AudioToolbox/AudioToolbox.h>
#include <AudioToolbox/AudioFormat.h>

#include <TargetConditionals.h>
#if TARGET_RT_BIG_ENDIAN
#   define FourCC2Str(fourcc) (const char[]){*((char*)&fourcc), *(((char*)&fourcc)+1), *(((char*)&fourcc)+2), *(((char*)&fourcc)+3),0}
#else
#   define FourCC2Str(fourcc) (const char[]){*(((char*)&fourcc)+3), *(((char*)&fourcc)+2), *(((char*)&fourcc)+1), *(((char*)&fourcc)+0),0}
#endif


namespace Codec{
    
    AVCCodec:: ~AVCCodec()
    {
    };
    
    AVCCodec::AVCCodec(void)
    {
        
    };
    
    bool AVCCodec::hardwareCodecCapabilities()
    {
//        AudioClassDescription requestedCodecs[2] = {
//            {
//                kAudioEncoderComponentType,
//                kAudioFormatMPEG4AAC,
//                kAppleHardwareAudioCodecManufacturer
//            },
//            {
//                kAudioDecoderComponentType,
//                kAudioFormatMPEG4AAC,
//                kAppleHardwareAudioCodecManufacturer
//            }
//        };
//
//        UInt32 successfulCodecs = 0;
//        int size = sizeof (successfulCodecs);
//
////
////        OSStatus result = AudioFormatGetPropertyInfo( kAudioFormatProperty_Encoders,
////                                   sizeof(requestedCodecs),
////                                   requestedCodecs,
////                                   &successfulCodecs);
//
//
////        AudioFormatGetProperty(32,
////                              sizeof(requestedCodecs),
////                               requestedCodecs,
////                               &size,
////                               &successfulCodecs);
//OSStatus result = AudioFormatGetProperty(kAudioFormatProperty_Encoders,sizeof(requestedCodecs),requestedCodecs,&size,&successfulCodecs);
//        switch (successfulCodecs) {
//            case 0:
//                printf("");
//                break;
//                // aac hardware encoder is unavailable. aac hardware decoder availability
//                // is unknown; could ask again for only aac hardware decoding
//            case 1:
//                printf("");
//                break;
//                // aac hardware encoder is available but, while using it, no hardware
//                // decoder is available.
//            case 2:
//                printf("");
//                break;
//                // hardware encoder and decoder are available simultaneously
//        }
//
//        return successfulCodecs == 2;
        
        bool isAvailable = false;
        OSStatus error;
        
        // get an array of AudioClassDescriptions for all installed encoders for the given format
        // the specifier is the format that we are interested in - this is 'aac ' in our case
        UInt32 encoderSpecifier = kAudioFormatMPEG4AAC;
        //    UInt32 encoderSpecifier = kAudioFormatMPEG4AAC_HE;
        //    UInt32 encoderSpecifier = kAudioFormatMPEG4AAC_HE_V2;
        UInt32 size;
        
        error = AudioFormatGetPropertyInfo(kAudioFormatProperty_Encoders, sizeof(encoderSpecifier),
                                           &encoderSpecifier, &size);
        if (error) { printf("AudioFormatGetPropertyInfo kAudioFormatProperty_Encoders error %d %4.4s\n", (int)error, (char*)&error); return false; }
        
        UInt32 numEncoders = size / sizeof(AudioClassDescription);
        AudioClassDescription encoderDescriptions[numEncoders];
        
        error = AudioFormatGetProperty(kAudioFormatProperty_Encoders, sizeof(encoderSpecifier),
                                       &encoderSpecifier, &size, encoderDescriptions);
        if (error) { printf("AudioFormatGetProperty kAudioFormatProperty_Encoders error %d %4.4s\n",
                            (int)error, (char*)&error); return false; }
        
        for (UInt32 i=0; i < numEncoders; ++i) {
            if (encoderDescriptions[i].mSubType == kAudioFormatMPEG4AAC &&
                encoderDescriptions[i].mManufacturer == kAppleHardwareAudioCodecManufacturer) isAvailable = true;
            
            printf("\n\n list %s %s %s \n", FourCC2Str(encoderDescriptions[i].mType), FourCC2Str(encoderDescriptions[i].mSubType), FourCC2Str(encoderDescriptions[i].mManufacturer));
        }
        
        return isAvailable;
    }
    
};
