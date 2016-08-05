//
//  MySingleton.h
//  Singleton
//
//  Created by 魏琦 on 15/12/25.
//  Copyright © 2015年 com.weiqi.www. All rights reserved.
//

#ifndef MySingleton_h
#define MySingleton_h
//.h实现
#define MySingletonH(methodName) + (instancetype)shared##methodName
//.m实现

#if __has_feature(objc_arc)//ARC
#define MySingletonM(methodName) \
static id _instance = nil;\
+ (instancetype)allocWithZone:(struct _NSZone*)zone{\
    if(_instance == nil){\
    static dispatch_once_t onceToken;\
    dispatch_once(&onceToken,^{\
    _instance = [super allocWithZone];\
        });\
    }\
    return _instance;\
}\
- (instancetype)init{\
    static dispatch_once_t onceToken;\
    dispatch_once(^onceToken,^{\
    _instance = [super init];\
});\
}\
+ (instancetype)shared##methodName{\
return [self alloc] init];\
}\
- (id)copyWithZone:(nullable NSZone*)zone{\
return _instance;\
}\
- (id)mutableCopyWithZone:(nullable NSZone*)zone{\
return _instance;\
}
#else

#define MySingletonM(methodName) \
static id _instance == nil;\
+(instancetype)allocWithZone:(struct _NSZone*)zone{\
if (_instance == nil){\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken,^{\
instance = [super allocWithZone:zone];\
});\
}\
return _instance;\
}\
- (instancetype)init{\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken,^{\
instance = [super init];\
});\
return _instance;\
}\
+ (instancetype)shared##methodName{\
return[[self alloc] init];\
}\
- (id)copyWithZone:(nullable NSZone*)zone{\
return _instance;\
}\
- (id)mutableCopyWithZone:(nullable NSZone*)zone{\
return _instance;\
}\
- (oneway void)release{\
\
}\
- (instancetype)retain{\
return _instance;\
}\
- (NSUInteger)retainCount{\
return 1;\
}
#endif

#endif /* MySingleton_h */
