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

@import WebKit;

#import "MailSignature.h"

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
    
    

    Signature *signature = [[Signature alloc]init];
    

    WebView *webView = [[WebView alloc] init];
    WebFrame *webFrame = [webView mainFrame];
    
    NSURLRequest *urlRequest = [NSURLRequest requestWithURL:[NSURL URLWithString:@"https://enroll.oplerno.com/404.html"]];
    [webFrame loadRequest:urlRequest];
    
    WebDataSource *webDataSource = webFrame.dataSource;
    WebArchive *webArchive = webDataSource.webArchive;
    //    [signature setWebArchive:webArchive];
    NSString *someString = [NSString stringWithFormat:@"%@", webArchive.data];
    NSLog(@"%s", someString);
}
@end

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
    NSLog(@"setSignatureContents: %@", self);
    id arg2 = nil;
    
    [self xxx_setSignatureContents:arg1];
}
@end


