// Copyright © Microsoft Open Technologies, Inc.
//
// All Rights Reserved
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// THIS CODE IS PROVIDED *AS IS* BASIS, WITHOUT WARRANTIES OR CONDITIONS
// OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION
// ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS FOR A
// PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
//
// See the Apache License, Version 2.0 for the specific language
// governing permissions and limitations under the License.

@class ADWebRequest;
@class ADWebResponse;

extern NSString *const HTTPGet;
extern NSString *const HTTPPost;

@interface HTTPWebRequest : NSObject <NSURLConnectionDelegate>
{
// OSX Universal Compatibility
@private
    NSURLConnection     *_connection;
    
    NSURL               *_requestURL;
    NSString            *_requestMethod;
    NSMutableDictionary *_requestHeaders;
    NSData              *_requestData;
    
    NSHTTPURLResponse   *_response;
    NSMutableData       *_responseData;
    NSUUID              *_correlationId;
    
    NSUInteger           _timeout;
    
    void (^_completionHandler)( NSError *, ADWebResponse *);
}

@property (strong, readonly, nonatomic) NSURL               *URL;
@property (strong)                      NSString            *method;
@property (strong, readonly, nonatomic) NSMutableDictionary *headers;
@property (strong)                      NSData              *body;
@property (nonatomic)                   NSUInteger           timeout;

- (id)initWithURL: (NSURL*)url
    correlationId: (NSUUID*) correlationId;

- (void)send:( void (^)( NSError *, ADWebResponse *) )completionHandler;

@end

