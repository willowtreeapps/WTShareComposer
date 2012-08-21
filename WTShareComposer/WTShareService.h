//
//  WTShareService.h
//  WTShareComposer
//
//  Created by Joel Garrett on 8/2/12.
//  Copyright (c) 2012 WillowTree Apps, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@protocol WTShareService <NSObject>

// Returns if service is accessible and at least one account has been setup.
+ (BOOL)canShare;

- (NSString *)title;

- (void)postText:(NSString *)text withImages:(NSArray *)images;

@optional

- (NSUInteger)imageAttachmentsLimit;
- (NSUInteger)URLAttachmentsLimit;

- (void)postText:(NSString *)text withImages:(NSArray *)images location:(CLLocation *)location;

@end

@protocol WTShareServiceDelegate <NSObject>

@optional
- (void)postSucceeded:(id<WTShareService>)service;
- (void)postFailed:(id<WTShareService>)service;
- (void)postFailedAuthentication:(id<WTShareService>)service;

@end

@protocol WTShareServiceCharacterLimit <WTShareService>

- (NSUInteger)characterLimit;
- (NSUInteger)characterCountForImages:(NSArray *)images;
- (NSUInteger)characterCountForURLs:(NSArray *)urls;

@end
