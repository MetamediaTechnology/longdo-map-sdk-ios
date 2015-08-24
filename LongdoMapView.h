//
//  LongdoMapView.h
//  MapGL
//
//  Created 9/21/12.
//  Copyright (c) 2013 Metamedia Technology Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LongdoMapViewDelegate.h"


// Layer classes
@class LongdoMapView;
@class Layer;
@class LayerCollection;

// Overlay Marker Classes
@class Marker;
@class Popup;

// Search Class
@class Search;

// Geometric Classes
@class Polyline;

// Layer Class
@class Layer;

// STATUS CODE
#define STATUS_OK 200
#define STATUS_INCORRECT_API_KEY 451
#define STATUS_UNABLE_TO_CHECK_API_KEY 452



// Base layer names
#define LAYER_NAME_BASE @"BASE"
#define LAYER_NAME_GISTDA_SPOT5 @"GISTDA_SPOT5"
#define LAYER_NAME_GRAY @"GRAY"
#define LAYER_NAME_GRAY_EN @"GRAY_EN"
#define LAYER_NAME_HYDRO @"HYDRO"
#define LAYER_NAME_MAPQUEST @"MAPQUEST"
#define LAYER_NAME_NORMAL @"NORMAL"
#define LAYER_NAME_NORMAL_EN @"NORMAL_EN"
#define LAYER_NAME_OPENCYCLE @"OPENCYCLE"
#define LAYER_NAME_OSM @"OSM"
#define LAYER_NAME_POI @"POI"
#define LAYER_NAME_POI_EN @"POI_EN"
#define LAYER_NAME_POLITICAL @"POLITICAL"
#define LAYER_NAME_POLITICAL_EN @"POLITICAL_EN"
#define LAYER_NAME_POLITICAL_NOLABEL @"POLITICAL_NOLABEL"
#define LAYER_NAME_TERRAIN @"TERRAIN"
#define LAYER_NAME_THAICHOTE @"THAICHOTE"

// Overlay layer names
#define LAYER_NAME_GOOGLE_ROAD @"GOOGLE_ROAD"
#define LAYER_NAME_GOOGLE_ROAD_EN @"GOOGLE_ROAD_EN"
#define LAYER_NAME_POI_TRANSPARENT @"POI_TRANSPARENT"
#define LAYER_NAME_POI_TRANSPARENT_EN @"POI_TRANSPARENT_EN"
#define LAYER_NAME_TRAFFIC @"TRAFFIC"

// Layer types
#define LAYER_TYPE_CUSTOM 0
#define LAYER_TYPE_LONGDO 1
#define LAYER_TYPE_TMS 2
#define LAYER_TYPE_WMS 3
#define LAYER_TYPE_WMTS 4

// Projections
#define PROJECTION_EPSG4326 @"EPSG:3857"
#define PROJECTION_EPSG3857 @"EPSG:4326"


@interface LongdoMapView : UIView <LongdoMapViewDelegate> {
    
}


@property (retain) id <LongdoMapViewDelegate> delegate;

// public

- (void)initMapWithKey:(NSString *)accessKey;

- (void)setAccessKey:(NSString *)accessKey;

- (void)setMapBackgroundColor:(UIColor *)backgroundColor;

- (void)enableTilt:(bool)isEnable;
- (void)enableRotate:(bool)isEnable;
- (void)enableCenterZooming:(bool)isEnable;
- (void)enableCrossMark:(bool)isEnable;


- (void)animateScaleBarAlphaTo:(float)alpha withAnimationDuration:(float)seconds;
- (void)enableScaleBar:(bool)isEnable;
- (void)setScaleBarMarginX:(int)x andMarginY:(int)y;
- (void)setScaleBarUpSideDown:(bool)isInvert;
- (void)setScaleBarRightToLeft:(bool)isInvert;
- (void)setScaleBarAlpha:(float)alpha;
- (void)setScaleBarColorRed:(float)red Green:(float)green Blue:(float)blue;


- (void)refresh;

- (double)cX;
- (double)cY;
- (CGPoint)cXY;
- (void)gotoXY:(CGPoint)newXY;
- (void)setXY:(CGPoint)newXY;


- (double)latitude;
- (double)longitude;
- (CLLocationCoordinate2D)coordinate;
- (CLLocationCoordinate2D)location;
- (void)setLocation:(CLLocationCoordinate2D)coordinate withAnimation:(bool)isAnimate;
- (void)setLocation:(CLLocationCoordinate2D)coordinate;  // Without animation
- (void)gotoLocation:(CLLocationCoordinate2D)coordinate; // With animation

- (void)trackUserLocation;
- (void)stopTrackUserLocation;


- (int)zoom;
- (void)zoomIn;
- (void)zoomOut;
- (void)gotoZoom:(int)targetZoom; // Without animation
- (void)setZoom:(int)targetZoom;  // Without animation
- (void)setZoom:(int)targetZoom withAnimation:(bool)isAnimate;
- (void)setMaxZoomLevel:(short)maxZoom;
- (void)setMinZoomLevel:(short)minZoom;
- (void)setBoundBetween:(CLLocationCoordinate2D)coordinate1 and:(CLLocationCoordinate2D)coordinate2;
- (void)setBoundBetween:(CLLocationCoordinate2D)coordinate1 and:(CLLocationCoordinate2D)coordinate2 withCenter:(CLLocationCoordinate2D)center;

- (NSArray *)getAllOverlayObjects;
- (void)removeOverlayObjectWithTag:(NSString*)tag;
- (void)removeAllOverlayObjects;

- (void)removeGeometricObjectWithTag:(NSString *)tag;
- (void)removeAllGeometricObjects;

- (void)disableGestureZoomIn;
- (void)disableGestureZoomOut;

- (void)showPOIs:(NSArray *)poiTags;

- (NSArray *)search:(Search *)query;
- (NSArray *)suggest:(NSString *)keyword;

- (void)addOverlayObject:(id)object;
- (void)addGeometicObject:(id)object;


// Traffic Features
- (void)showTrafficCamera;
- (void)showTrafficCameraBetweenMinZoom:(int)minZoom andMaxZoom:(int)maxZoom;
- (void)hideTrafficCamera;

- (void)showTrafficEvents;
- (void)showTrafficEventsBetweenMinZoom:(int)minZoom andMaxZoom:(int)maxZoom;
- (void)hideTrafficEvents;


// Map Layer
- (Layer *)layerName:(NSString *)name;
- (void)addLayer:(Layer *)layer name:(NSString *)name;


// Layer Collection
- (Layer *)baseLayer;
- (NSArray *)overlayLayers;
- (void)setBaseLayer:(Layer *)layer;
- (void)addOverlayLayer:(Layer *)layer;
- (void)removeOverlayLayer:(Layer *)layer;
- (void)removeAllOverlayLayers;


// For engine
- (void)playAnimation;
- (void)onCameraUpdate:(NSDictionary*)camera;
- (void)onEventUpdate:(NSDictionary*)events;

@end





// Class Marker
@interface Marker : NSObject

@property CLLocationCoordinate2D coordinate;
@property (retain) NSString *tag;
@property (retain) UIImage *icon;
@property CGPoint offset;
@property int weight;
@property float opacity;
@property bool tapable;
@property bool persistent;
@property int minZoom;
@property int maxZoom;

- (id)initWithUrlMarker:(NSString *)url atCoordinate:(CLLocationCoordinate2D)coordinate;
- (id)initWithIconMarker:(UIImage *)icon atCoordinate:(CLLocationCoordinate2D)coordinate;
@end



// Class Popup
@interface Popup : NSObject

@property CLLocationCoordinate2D coordinate;
@property (retain) NSString *title;
@property (retain) NSString *detail;
@property (retain) NSString *tag;
@property CGPoint offset;
@property int weight;
@property float opacity;

- (id)initWithSimplePopupAt:(CLLocationCoordinate2D)coordinate;

@end



// Class Polyline
@interface Polyline : NSObject


@property (retain) NSMutableArray *coordinates;
@property (retain) NSString *tag;
@property int weight;
@property float opacity;
@property (retain) UIColor *lineColor;
@property int lineWidth;


- (id)initWithCoordinates:(NSArray*)coordinates;
- (void)addCoordinate:(CLLocationCoordinate2D)coordinate;

@end


// Class Search
@interface Search : NSObject

@property (retain) NSString *keyword;
@property CLLocationCoordinate2D coordinate;
@property (retain) NSString *area;
@property (retain) NSString *tag;
@property (retain) NSString *language;
@property int limit;
@property int offset;
@property int span;

- (id)initWithKeyword:(NSString*)keyword;

@end



// Class Layer
@interface Layer : NSObject

@property (retain) NSString *name;
@property (retain) NSString *url;
@property (retain) NSString *key;
@property (retain) NSString *format;
@property (retain) NSString *srs;
@property (retain) NSString *transparent;
@property (retain) NSString *styles;
@property (retain) NSString *extraQuery;
@property int type;
@property int refresh;
@property float opacity;
@property int weight;
@property int minZoomRange;
@property int maxZoomRange;

- (id)initWithUrl:(NSString *)url andType:(int)type;
- (NSString *)tileUrlForZoom:(int)zoom atColumn:(int)columnNumber andRow:(int)rowNumber;


@end




// Class Longdo Tag
@interface LongdoTag : NSObject

@property (retain) NSString *name;
@property int minZoomRange;
@property int maxZoomRange;

- (id)initWithName:(NSString *)name;
- (id)initWithName:(NSString *)name betweenMinZoom:(int)minZoom andMaxZoom:(int)maxZoom;

@end
