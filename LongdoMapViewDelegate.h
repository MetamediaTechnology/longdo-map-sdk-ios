//
//  LongdoMapViewDelegate.h
//  MapGL
//
//  Created 9/24/12.
//  Copyright (c) 2013 Metamedia Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LongdoMapView.h"
#import <CoreLocation/CoreLocation.h>


@class LongdoMapView;
@class LongdoMapInfo;

@protocol LongdoMapViewDelegate

@optional

@required

- (void)longdoMapView:(LongdoMapView *)mapView SDKStatus:(int)status;
- (void)longdoMapView:(LongdoMapView *)mapView mapIsReady:(bool)isMapReady;
- (void)longdoMapView:(LongdoMapView *)mapView statusChangedTo:(LongdoMapInfo *)mapStatus;
- (void)longdoMapView:(LongdoMapView *)mapView tappedAtIconTag:(NSString *)tag;
- (void)longdoMapView:(LongdoMapView *)mapView tappedAtCoordinate:(CLLocationCoordinate2D)coordinate;
- (void)longdoMapView:(LongdoMapView *)mapView longPressedStartAtCoordinate:(CLLocationCoordinate2D)coordinate;
- (void)longdoMapView:(LongdoMapView *)mapView longPressedFinishAtCoordinate:(CLLocationCoordinate2D)coordinate;
- (void)longdoMapView:(LongdoMapView *)mapView currentUserCoordinate:(CLLocationCoordinate2D)userCoordinate;

- (void)longdoMapView:(LongdoMapView *)mapView startZoomFrom:(int)zoom;
- (void)longdoMapView:(LongdoMapView *)mapView finishZoomTo:(int)zoom;

- (void)longdoMapView:(LongdoMapView *)mapView startMovingFrom:(CLLocationCoordinate2D)coordinate;
- (void)longdoMapView:(LongdoMapView *)mapView finishMovingTo:(CLLocationCoordinate2D)coordinate;


- (void)onUserPanning:(LongdoMapView *)mapView;
- (void)onUserZooming:(LongdoMapView *)mapView;
- (void)onUserClickPOI:(LongdoMapView *)mapView ID:(NSString*)ID name:(NSString*)name icon:(NSString*)icon atCoordinate:(CLLocationCoordinate2D)coordinate;
- (void)onUserClickCamera:(LongdoMapView *)mapView
                 cameraID:(NSString*)camid
             atCoordinate:(CLLocationCoordinate2D)coordinate
                    title:(NSString*)title
                     link:(NSString*)link
               lastUpdate:(NSString*)lastupdate
                   incity:(NSString*)incity
             organization:(NSString*)organization
              sponsertext:(NSString*)sponsertext
                   motion:(bool)isMotion
                   vdoURL:(NSString*)vdourl
                   imgURL:(NSString*)imgurl
           imgurlSpecific:(NSString*)imgurlSpecific;

- (void)onUserClickEvent:(LongdoMapView *)mapView
                 eventID:(NSString*)eventID
            atCoordinate:(CLLocationCoordinate2D)coordinate
                   title:(NSString*)title
            description:(NSString*)description
                    icon:(NSString*)icon
                   start:(NSString*)start
                    stop:(NSString*)stop
             contributor:(NSString*)contributor;

@end
