
http://ja.stackoverflow.com/questions/2170/デバイスの判定方法-objective-c

モデル番号から判別する

英語版の記事に詳しくありますが、モデル番号を uname で取得して判断するのが手っ取り早いです。 今回は iPhone 5, 6, Plusの判別がされたいとのことなのでそのサンプルコードを示します。

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.

    NSString* deviceName = getDeviceName();

    bool is_Simulator =  ([deviceName isEqualToString:@"i386"] || [deviceName isEqualToString:@"x86_64"]);
    bool is_iPhone5 = ([deviceName hasPrefix:@"iPhone5,"] || [deviceName hasPrefix:@"iPhone6,"]);
    bool is_iPhone6 =  ([deviceName isEqualToString:@"iPhone7,2"]);
    bool is_iPhone6Plus =  ([deviceName isEqualToString:@"iPhone7,1"]);

    NSLog(@"Device Name: %@",deviceName);
    NSLog(@"Is Simulator? => %@", is_Simulator ? @"YES":@"NO");
    NSLog(@"Is iPhone5? => %@", is_iPhone5 ? @"YES":@"NO");
    NSLog(@"Is iPhone6? => %@", is_iPhone6 ? @"YES":@"NO");
    NSLog(@"Is iPhone6Plus? => %@", is_iPhone6Plus ? @"YES":@"NO");

}

// モデル名を取得する
NSString* getDeviceName()
{
    struct utsname systemInfo;
    uname(&systemInfo);

    return [NSString stringWithCString:systemInfo.machine
                              encoding:NSUTF8StringEncoding];
}

実行結果

DeviceTest[####:##x] hardware: iPhone7,2
DeviceTest[####:##x] Is Simulator? => NO
DeviceTest[####:##x] Is iPhone5? => NO
DeviceTest[####:##x] Is iPhone6? => YES
DeviceTest[####:##x] Is iPhone6Plus? => NO

UIDevice ライブラリを使用する

iOS7 Cookbook のレポジトリに、小さなライブラリと良いサンプルがあります。

ただ、このライブラリだと iPhone6 はラベルが Unknown デバイスとして 認識されるので注意してください。モデル番号で判別するならば問題ないですが、 ラベルが必要な場合は、自分で少し更新する必要があります。

UIDevice *device = [UIDevice currentDevice];
NSLog(@"Platform: %@", device.platform);
NSLog(@"HWModel: %@", device.hwmodel);
NSLog(@"Platform type: %d", device.platformType);
NSLog(@"Platform string: %@", device.platformString);
NSLog(@"Bus Freq: %d", device.busFrequency);
NSLog(@"CPU Count: %d", device.cpuCount);
NSLog(@"Total memory: %ud", device.totalMemory);
NSLog(@"Mac address: %@", device.macaddress);
NSLog(@"Retina display: %d", device.hasRetinaDisplay);

モデル番号のリスト

Wikipedia 項目 "List of iOS devices" の、"Hardware Strings"の行を参考にしてください。

i386      , iPhone Simulator  
iPhone1,1 , iPhone  
iPhone1,2 , iPhone 3G  
iPhone2,1 , iPhone 3GS  
iPhone3,1 , iPhone 4  
iPhone3,2 , iPhone 4 GSM Rev A  
iPhone3,3 , iPhone 4 CDMA  
iPhone4,1 , iPhone 4S  
iPhone5,1 , iPhone 5 (GSM)  
iPhone5,2 , iPhone 5 (GSM+CDMA)  
iPhone5,3 , iPhone 5C (GSM)  
iPhone5,4 , iPhone 5C (Global)  
iPhone6,1 , iPhone 5S (GSM)  
iPhone6,2 , iPhone 5S (Global)  
iPhone7,1 , iPhone 6 Plus  
iPhone7,2 , iPhone 6  
iPod1,1   , 1st Gen iPod  
iPod2,1   , 2nd Gen iPod  
iPod3,1   , 3rd Gen iPod  
iPod4,1   , 4th Gen iPod  
iPod5,1   , 5th Gen iPod  
iPad1,1   , iPad  
iPad1,2   , iPad 3G  
iPad2,1   , 2nd Gen iPad  
iPad2,2   , 2nd Gen iPad GSM  
iPad2,3   , 2nd Gen iPad CDMA  
iPad2,4   , 2nd Gen iPad New Revision  
iPad3,1   , 3rd Gen iPad  
iPad3,2   , 3rd Gen iPad CDMA  
iPad3,3   , 3rd Gen iPad GSM  
iPhone5,1 , iPhone 5 GSM+LTE  
iPhone5,2 , iPhone 5 CDMA+LTE  
iPod5,1   , 5th Gen iPod  
iPad2,5   , iPad mini  
iPad2,6   , iPad mini GSM+LTE  
iPad2,7   , iPad mini CDMA+LTE  
iPad3,4   , 4th Gen iPad  
iPad3,5   , 4th Gen iPad GSM+LTE  
iPad3,6   , 4th Gen iPad CDMA+LTE  
iPad4,1   , iPad Air (WiFi)  
iPad4,2   , iPad Air (GSM+CDMA)  
iPad4,4   , iPad mini Retina (WiFi)  
iPad4,5   , iPad mini Retina (GSM+CDMA)  
iPad4,6   , iPad mini Retina (China)  
iPad5,3   , iPad Air 2 (WiFi)  
iPad5,4   , iPad Air 2 (GSM+CDMA)  
iPad4,7   , iPad mini 3 (WiFi)  
iPad4,8   , iPad mini 3 (GSM+CDMA)  






