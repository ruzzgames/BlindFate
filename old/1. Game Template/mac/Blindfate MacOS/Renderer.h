//
//  Renderer.h
//  Blindfate MacOS
//
//  Created by Robert Ruzbacky on 26/4/20.
//  Copyright © 2020 RuzzGames. All rights reserved.
//

#import <MetalKit/MetalKit.h>

// Our platform independent renderer class.   Implements the MTKViewDelegate protocol which
//   allows it to accept per-frame update and drawable resize callbacks.
@interface Renderer : NSObject <MTKViewDelegate>

-(nonnull instancetype)initWithMetalKitView:(nonnull MTKView *)view;

@end

