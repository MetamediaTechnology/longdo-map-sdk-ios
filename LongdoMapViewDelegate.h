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
@class TagData;
@class Marker;

@protocol LongdoMapViewDelegate

@optional

@required


// Map Status
- (void)longdoMapView:(LongdoMapView *)mapView SDKStatus:(int)status;
- (void)longdoMapView:(LongdoMapView *)mapView mapIsReady:(bool)isMapReady;
- (void)longdoMapView:(LongdoMapView *)mapView
      statusChangedTo:(LongdoMapInfo *)mapStatus;

// Click
- (void)longdoMapView:(LongdoMapView *)mapView
      clickedOnMarker:(Marker *)marker;
- (void)longdoMapView:(LongdoMapView *)mapView
         clickedOnTag:(TagData *)tagData;
- (void)longdoMapView:(LongdoMapView *)mapView
  clickedOnCoordinate:(CLLocationCoordinate2D)coordinate;

// Long Click
- (void)longdoMapView:(LongdoMapView *)mapView
    longPressedStartAtCoordinate:(CLLocationCoordinate2D)coordinate;
- (void)longdoMapView:(LongdoMapView *)mapView
    longPressedFinishAtCoordinate:(CLLocationCoordinate2D)coordinate;

// Zooming
- (void)longdoMapView:(LongdoMapView *)mapView startZoomFrom:(int)zoom;
- (void)longdoMapView:(LongdoMapView *)mapView finishZoomTo:(int)zoom;

// Moving
- (void)longdoMapView:(LongdoMapView *)mapView
      startMovingFrom:(CLLocationCoordinate2D)coordinate;
- (void)longdoMapView:(LongdoMapView *)mapView
       finishMovingTo:(CLLocationCoordinate2D)coordinate;

// User Action
- (void)onUserPanning:(LongdoMapView *)mapView;
- (void)onUserZooming:(LongdoMapView *)mapView;

@end
