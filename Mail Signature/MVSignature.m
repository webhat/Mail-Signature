/*
 * Copyright (c) 2015 Daniël W. Crompton. All rights reserved.
 *
 *     This file is part of Mail Signature.
 *
 * Mail Signature is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 
 * Mail Signature is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License
 * along with Mail Signature.  If not, see <http://www.gnu.org/licenses/>.
 */

#import "MailSignature.h"

@implementation Signature

+ (void)load {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        NSLog(@"swizzle: %@", self);
        Class class = [self class];
        
        SEL originalSelector = @selector(setSignatureContents:);
        SEL swizzledSelector = @selector(xxx_setSignatureContents:);
        
        Method originalMethod = class_getInstanceMethod(class, originalSelector);
        Method swizzledMethod = class_getInstanceMethod(class, swizzledSelector);
        
        BOOL didAddMethod =
        class_addMethod(class,
                        originalSelector,
                        method_getImplementation(swizzledMethod),
                        method_getTypeEncoding(swizzledMethod));
        
        if (didAddMethod) {
            class_replaceMethod(class,
                                swizzledSelector,
                                method_getImplementation(originalMethod),
                                method_getTypeEncoding(originalMethod));
        } else {
            method_exchangeImplementations(originalMethod, swizzledMethod);
        }
    });
}


#pragma mark - Method Swizzling

- (void)xxx_setSignatureContents:(id)arg1 {
    [self xxx_setSignatureContents:arg1];
    
    NSLog(@"setSignatureContents: %@", self);
}
@end
