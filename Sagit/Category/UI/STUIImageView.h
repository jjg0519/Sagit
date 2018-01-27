//
//  开源：https://github.com/cyq1162/Sagit
//  作者：陈裕强 create on 2017/12/12.
//  博客：(昵称：路过秋天） http://www.cnblogs.com/cyq1162/
//  起源：IT恋、IT连 创业App http://www.itlinks.cn
//  Copyright © 2017-2027年. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImageView(ST)<UIImagePickerControllerDelegate>

typedef void (^OnPick)(NSData *data,UIImagePickerController *picker,NSDictionary<NSString *,id> *info);
typedef void (^AfterSetImageUrl)(UIImageView* img);
//!长按时提示用户保存图片
-(UIImageView*)longPressSave:(BOOL)yesNo;
//!执行保存图片事件
-(UIImageView*)save;
//!设置图片是否圆角
-(UIImageView*)corner:(BOOL)yesNo;
//!获取图片的地址
-(NSString*)url;
//!为图片设置一个网络地址 （默认超过256K时会进行压缩）
-(UIImageView*)url:(NSString*)url;
//!为图片设置一个网络地址 （默认超过256K时会进行压缩）afterSet为设置后的回调函数
-(UIImageView *)url:(NSString *)url after:(AfterSetImageUrl)block;
//!为图片设置一个网络地址 （默认超过256K时会进行压缩）default:设置一张默认图片
-(UIImageView *)url:(NSString *)url default:(id)imgOrName;
//!为图片设置一个网络地址 maxKb 指定超过大小时压缩显示（设置为0不压缩）
-(UIImageView *)url:(NSString *)url maxKb:(NSInteger)compress;
//!为图片设置一个网络地址 （默认超过256K时会进行压缩） maxKb 指定超过大小时压缩显示（设置为0不压缩） default:设置一张默认图片
-(UIImageView *)url:(NSString *)url maxKb:(NSInteger)compress default:(id)imgOrName;
//!为图片设置一个网络地址 （默认超过256K时会进行压缩） maxKb 指定超过大小时压缩显示（设置为0不压缩） default:设置一张默认图片 afterSet为设置后的回调函数
-(UIImageView *)url:(NSString *)url maxKb:(NSInteger)compress default:(id)imgOrName after:(AfterSetImageUrl)block;
//!图片选择 edit:是否出现裁剪框
-(UIImageView*)pick:(OnPick)pick edit:(BOOL)yesNo;
//!图片选择 edit:是否出现裁剪框 maxKb:指定压缩的大小
-(UIImageView*)pick:(OnPick)pick edit:(BOOL)yesNo maxKb:(NSInteger)maxKb;

//!将图片压缩到指定的宽高，当前图片受变化
-(UIImageView*)reSize:(CGSize)maxSize;
#pragma mark 扩展属性
-(UIImageView*)image:(id)imgOrName;
@end

@interface UIImage(ST)
typedef void (^AfterImageSave)(NSError *err);
@property (nonatomic,copy) AfterImageSave afterImageSaveBlock;
//!获取图片压缩后的字节数据，当前图片不受变化
-(NSData*)compress:(NSInteger)maxKb;
-(void)save:(AfterImageSave)afterSave;
//!检测最大宽高的等比缩放
-(UIImage *)reSize:(CGSize)maxSize;
@end
