//
//  Singleton.h
//  Singleton
//
//  Created by 吴青 on 15/12/25.
//  Copyright © 2015年 com.weiqi.www. All rights reserved.
//

#ifndef Singleton_h
#define Singleton_h
//.h实现
#define singleton_h(name) + (instancetype)shared##name
//.m实现

#if __has_feature(objc_arc)//ARC
#define singleton_m(name) \
static id instance;\
+ (instancetype)allocWithZone:(struct _NSZone*)zone{\
    if(instance == nil){\
        static dispatch_once_t onceToken;\
        dispatch_once(&onceToken,^{\
        instance = [super allocWithZone:zone];\
        });\
    }\
    return instance;\
}\
- (instancetype)init{\
    static dispatch_once_t onceToken;\
    dispatch_once(&onceToken,^{\
    instance = [super init];\
    });\
    return instance;\
}\
+ (instancetype)shared##name{\
    return [[self alloc] init];\
}\
- (id)copyWithZone:(nullable NSZone*)zone{\
    return instance;\
}\
- (id)mutableCopyWithZone:(nullable NSZone*)zone{\
    return instance;\
}

#else 

#define singleton_m(name) \
static id instance;\
+ (instancetype)allocWithZone:(struct _NSZone*)zone{\
if (instance == nil){\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken,^{\
instance = [super allocWithZone:zone];\
});\
}\
return instance;\
}\
- (instancetype)init{\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken,^{\
instance = [super init];\
});\
return instance;\
}\
+ (instancetype)shared##name{\
return [[self alloc] init];\
}\
- (id)copyWithZone:(nullable NSZone*)zone{\
return instance;\
}\
- (id)mutableCopyWithZone:(nullable NSZone*)zone{\
return instance;\
}\
- (oneway void)release{\
    \
}\
- (instancetype)retain{\
return instance;\
}\
- (NSUInteger)retainCount{\
return 1;\
}
#endif

#endif /* Singleton_h */
