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


#import <objc/runtime.h>
#import "MailSignature.h"
#import "MVMailBundle.h"

@implementation MailSignature
+ (void)initialize {
    NSLog(@"Loading MailSignature plugin...");
    
    // since 64-bit objective-c runtimes, you apparently can't load
    // symbols directly (i.e. through class inheritance) and have to
    // resort to NSClassFromString
    Class mvMailBundleClass = NSClassFromString(@"MVMailBundle");
    
    // If this class is not available that means Mail.app
    // doesn't allow plugins anymore or has changed the API
    if (!mvMailBundleClass)
        return;
    
    // dynamically change super class hierarchy
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated"
    class_setSuperclass([self class], mvMailBundleClass);
#pragma GCC diagnostic pop
    
    // register our plugin bundle in mail
    [[((MailSignature *)self) class] registerBundle];
    NSLog(@"Done registering MailSignature plugin.");
}
@end
