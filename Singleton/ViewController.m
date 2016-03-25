//
//  ViewController.m
//  Singleton
//
//  Created by 吴青 on 15/12/25.
//  Copyright © 2015年 com.weiqi.www. All rights reserved.
//

#import "ViewController.h"
#import "MySingletonView.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    /**
     *  单例创建的对象在项目中有且只有一个实例对象,如果通过alooc,copy,mutableCopy产生的实例对象都还是只有一个,对其操作是改变了它的属性而已,不能改变他本身在项目中的个数.
     */
    MySingletonView* view = [MySingletonView sharedCreatView];
    view.frame = CGRectMake(100, 100, 100, 100);
    view.backgroundColor = [UIColor redColor];
    [self.view addSubview:view];
    NSLog(@"%@",view);
    MySingletonView* aView = [[MySingletonView alloc] initWithFrame:CGRectMake(120, 120, 120, 120)];
    view.backgroundColor = [UIColor greenColor];
    [self.view addSubview:aView];
     NSLog(@"%@",aView);
    
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
