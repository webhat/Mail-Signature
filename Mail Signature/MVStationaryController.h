//
//  MVStationaryController.h
//  Mail Signature
//
//  Created by Daniël W. Crompton on 18/10/15.
//  Copyright (c) 2015 Daniël W. Crompton. All rights reserved.
//

#ifndef Mail_Signature_MVStationaryController_h
#define Mail_Signature_MVStationaryController_h

@interface StationeryController : NSObject
{
    Stationery *_stationery;
    BOOL _isStationeryLoaded;
    NSString *_currentColor;
    double _letterTopMargin;
    double _letterWidth;
    id _savedResourceLoadDelegate;
    id _savedFrameLoadDelegate;
    long long _numberOfResourcesNotYetLoaded;
    BOOL _isLoadingStationery;
    BOOL _isChangingStationeryColor;
    BOOL _isLoadingResources;
    BOOL _shouldAnimateTransitions;
    WebView *_webView;
    ComposeBackEnd *_composeBackEnd;
    EditableWebMessageDocument *_messageDocument;
    NSMutableDictionary *_fontElementsWithColors;
    NSMutableArray *_colorsThatHaveBeenDisplayed;
    NSTimer *_flushWindowTimer;
}

- (id)stationeryFromCurrentMessageError:(id *)arg1;
- (void)changeStationeryColor:(id)arg1;
- (void)userClickedOnStationeryBackground:(id)arg1;
- (void)_webViewDidFinishLoadingAllResources;
- (void)_timerDidFire:(id)arg1;
- (void)webView:(id)arg1 didLoadResourceFromMemoryCache:(id)arg2 response:(id)arg3 length:(long long)arg4 fromDataSource:(id)arg5;
- (void)webView:(id)arg1 resource:(id)arg2 didFinishLoadingFromDataSource:(id)arg3;
- (id)webView:(id)arg1 identifierForInitialRequest:(id)arg2 fromDataSource:(id)arg3;
- (void)webView:(id)arg1 didFailLoadWithError:(id)arg2 forFrame:(id)arg3;
- (void)_finishLoadingStationery;
- (void)webView:(id)arg1 didFinishLoadForFrame:(id)arg2;
- (void)loadStationery:(id)arg1;
- (void)showColorOptions;
- (void)setColor:(id)arg1;
- (id)color;
- (void)setStationeryIsLoaded:(BOOL)arg1;
- (BOOL)isStationeryLoaded;
- (void)setStationery:(id)arg1;
- (id)stationery;
- (void)setWebView:(id)arg1;
- (void)setComposeBackEnd:(id)arg1;
- (BOOL)isUpdatingWebView;
- (void)dealloc;

@end


#endif
