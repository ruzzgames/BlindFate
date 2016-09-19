//
//  main.m
//  BlindFate
//
//  Created by Robert Ruzbacky on 18/09/2016.
//  Copyright © 2016 Robert Ruzbacky. All rights reserved.
//

// uncomment below if compiling for Windows using Visual Studio Community
// #define _WIN32

// uncomment below if compiling for Mac OS/X using Xcode
#define TARGET_OS_MAC

#ifdef TARGET_OS_MAC


#import <Cocoa/Cocoa.h>

int main(int argc, const char * argv[]) {
    return NSApplicationMain(argc, argv);
}


#endif
