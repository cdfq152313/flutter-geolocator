//
//  GeolocatorHandler.h
//  Pods
//
//  Created by Maurits van Beusekom on 23/06/2020.
//

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>

typedef void (^GeolocatorError)(NSString *_Nonnull errorCode, NSString *_Nonnull  errorDescription);
typedef void (^GeolocatorResult)(CLLocation *_Nullable location);
typedef void (^DelegateResult)(NSString *message);

@interface GeolocationHandler : NSObject

@property (strong, nonatomic) DelegateResult delegateHandler;

- (CLLocation *_Nullable)getLastKnownPosition;

- (void)startListeningWithDesiredAccuracy:(CLLocationAccuracy)desiredAccuracy
                           distanceFilter:(CLLocationDistance)distanceFilter
                           pausesLocationUpdatesAutomatically:(BOOL)pausesLocationUpdatesAutomatically
                            resultHandler:(GeolocatorResult _Nonnull)resultHandler
                             errorHandler:(GeolocatorError _Nonnull)errorHandler;

- (void)stopListening;

- (void)changeAccuracy:(CLLocationAccuracy)desiredAccuracy;

@end
