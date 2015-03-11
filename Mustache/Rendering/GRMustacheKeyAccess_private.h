// The MIT License
//
// Copyright (c) 2015 Gwendal Roué
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

// This code comes from Objective-C GRMustache.
//
// It is still written in Objective-C because
// +[GRMustacheKeyAccess isSafeMustacheKey:forObject:] needs to call
// [[object class] safeMustacheKeys] if [object class] conforms to the
// GRMustacheSafeKeyAccess protocol.
//
// But Swift won't let do that (see example below):
//
// ::
//
//   @objc protocol P {
//       class func f() -> String
//   }
//   
//   class C : NSObject, P {
//       class func f() -> String { return "C" }
//   }
//   
//   let c: NSObject = C()
//   if let p = c as? P {
//       // error: accessing members of protocol type value 'P.Type' is unimplemented
//       p.dynamicType.f()
//   }
@interface GRMustacheKeyAccess : NSObject
+ (BOOL)isSafeMustacheKey:(NSString *)key forObject:(id)object;

@end
