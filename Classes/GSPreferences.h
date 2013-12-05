//
//  GSPreferences.h
//  gfxCardStatus
//
//  Created by Cody Krieger on 9/26/10.
//  Copyright 2010 Cody Krieger. All rights reserved.
//

#import <Cocoa/Cocoa.h>

typedef enum {
    GSPowerSourceBasedSwitchingModeIntegrated = 0,
    GSPowerSourceBasedSwitchingModeDiscrete = 1,
    GSPowerSourceBasedSwitchingModeDynamic = 2
} GSPowerSourceBasedSwitchingMode;

@interface GSPreferences : NSObject <NSWindowDelegate> {
    NSMutableDictionary *_prefsDict;
    
    NSNumber *yesNumber;
    NSNumber *noNumber;
}

@property (strong) NSMutableDictionary *prefsDict;

- (void)setUpPreferences;
- (void)setDefaults;
- (void)savePreferences;

- (BOOL)shouldCheckForUpdatesOnStartup;
- (BOOL)shouldStartAtLogin;
- (BOOL)shouldDisplayNotifications;
- (BOOL)shouldUsePowerSourceBasedSwitching;
- (BOOL)shouldUseImageIcons;
- (BOOL)shouldUseSmartMenuBarIcons;

- (BOOL)shouldUseLastExplicitModeOnLaunch;
- (void)setLastExplicitMode:(GSPowerSourceBasedSwitchingMode)mode;
- (GSPowerSourceBasedSwitchingMode)lastExplicitMode;

- (GSPowerSourceBasedSwitchingMode)modeForACAdapter;
- (GSPowerSourceBasedSwitchingMode)modeForBattery;

- (void)setBool:(BOOL)value forKey:(NSString *)key;
- (BOOL)boolForKey:(NSString *)key;

- (void)savePreferences;

+ (GSPreferences *)sharedInstance;

@end
