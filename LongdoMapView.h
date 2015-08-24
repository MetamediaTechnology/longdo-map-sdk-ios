//
//  LongdoMapView.h
//  MapGL
//
//  Created 9/21/12.
//  Copyright (c) 2013 Metamedia Technology Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LongdoMapViewDelegate.h"

// Start Lat/Lon/Zoom
#define DEFAULT_LAT 13.722439
#define DEFAULT_LON 100.529451
#define DEFAULT_ZOOM 14
#define DEFAULT_MIN_ZOOM 4
#define DEFAULT_MAX_ZOOM 18

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

// Longdo Map SDK config
// Please do not change if you do not know what you are doing.
#define TILE_CACHE_POOL_SIZE 4
#define TILE_DOWNLOAD_POOL_SIZE 4
#define TAG_POOL_SIZE 2
#define OUT_SCREEN_TILE_MARGIN 0
#define OUT_SCREEN_TILE_REMOVE_MARGIN 0
#define ZOOM_PERIOD 15
#define MOVE_PERIOD 15
#define TAG_EXTRA_SIZE 0
#define ONLY_DRAW_OVERLAY_LAYER_ON_BASE_IS_READY YES
#define FADE_IN_BASE_LAYER YES

// Layer classes
@class LongdoMapView;
@class Layer;
@class MapLayers;

// Overlay Marker Classes
@class Marker;
@class Popup;

// Search Class
@class Search;

// Geometric Classes
@class Polyline;

// Layer Class
@class Layer;

@class Tile;


// Struct
//typedef struct {
//  double latitude;
//  double longitude;
//} MapLocation;


@interface LongdoMapView : UIView {
}

@property(retain) id<LongdoMapViewDelegate> longdoMapViewDelegate;

// Initialization
- (void)initMap; // without key, you need your own map server
- (void)initMapWithKey:(NSString *)accessKey;
- (void)closeMap;

// Map control
- (void)refresh;

// Map parameters
- (void)setMaxZoomLevel:(short)maxZoom;
- (void)setMinZoomLevel:(short)minZoom;
- (void)setMapBackgroundColor:(UIColor *)backgroundColor;

- (void)enablePan:(bool)isEnable;
- (void)enablePinch:(bool)isEnable;
- (void)enableTilt:(bool)isEnable;
- (void)enableRotate:(bool)isEnable;
- (void)enableCenterZooming:(bool)isEnable;
- (void)enableCrossMark:(bool)isEnable;

// Location
- (double)latitude;
- (double)longitude;
- (CLLocationCoordinate2D)coordinate;
- (CLLocationCoordinate2D)location;
- (void)setLocation:(CLLocationCoordinate2D)coordinate; // Without animation
- (void)setLocation:(CLLocationCoordinate2D)coordinate
      withAnimation:(bool)isAnimate;

// Zoom
- (int)zoom;
- (void)zoomIn;
- (void)zoomOut;
- (void)setZoom:(int)targetZoom; // Without animation
- (void)setZoom:(int)targetZoom withAnimation:(bool)isAnimate;

// Bound
- (CGRect)getCoordinateBoundaryForZoom:(int)zoom
                              atCenter:(CLLocationCoordinate2D)coordinate;
- (void)setMapBoundaryFor:(CGRect)boundary;
- (void)setBoundBetween:(CLLocationCoordinate2D)coordinate1
                    and:(CLLocationCoordinate2D)coordinate2
          withExtraZoom:(int)extraZoom; // deprecate
- (void)setBoundBetween:(CLLocationCoordinate2D)coordinate1
                    and:(CLLocationCoordinate2D)coordinate2
             withCenter:(CLLocationCoordinate2D)center
           andExtraZoom:(int)extraZoom; // deprecate

// Marker
- (NSArray *)markers;
- (void)addMarker:(Marker *)marker;
- (void)removeMarker:(Marker *)marker;
- (void)removeMarkerWithTag:(NSString *)tag;
- (void)removeAllMarkers;

// Geometric Object
- (void)removeGeometricObjectWithTag:(NSString *)tag;
- (void)removeAllGeometricObjects;

// Longdo Tag
- (void)showLongdoTags:(NSArray *)longdoTags;
- (void)hideLongdoTags;

// Scale bar
- (void)animateScaleBarAlphaTo:(float)alpha
         withAnimationDuration:(float)seconds;
- (void)enableScaleBar:(bool)isEnable;
- (void)setScaleBarMarginX:(int)x andMarginY:(int)y;
- (void)setScaleBarUpSideDown:(bool)isInvert;
- (void)setScaleBarRightToLeft:(bool)isInvert;
- (void)setScaleBarAlpha:(float)alpha;
- (void)setScaleBarColorRed:(float)red green:(float)green blue:(float)blue;

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

// Gesture control
- (void)disableGestureZoomIn;
- (void)disableGestureZoomOut;

// Overlay object
- (void)addGeometicObject:(id)object;

// Debuger
- (void)setDebugLabel:(UILabel *)label;

@end

// Class Marker
@interface Marker : NSObject

- (id)initWithImage:(UIImage *)image andCoordinate:(CLLocationCoordinate2D)coordinate;
- (id)initWithImageUrl:(NSString *)url andCoordinate:(CLLocationCoordinate2D)coordinate;


- (NSString *)tag;
- (UIImage *)image;
- (CLLocationCoordinate2D)coordinate;
- (CGPoint)offset;
- (int)weight;
- (int)minZoom;
- (int)maxZoom;
- (bool)isClickable;
- (bool)isPersistent;



- (Marker *)setTag:(NSString *)tag;
- (Marker *)setImage:(UIImage *)image;
- (Marker *)setCoordinate:(CLLocationCoordinate2D)coordinate;
- (Marker *)setOffset:(CGPoint)offset;
- (Marker *)setWeight:(int)weight;
- (Marker *)setMaxZoom:(int)maxZoom;
- (Marker *)setMinZoom:(int)minZoom;
- (Marker *)setIsClickable:(bool)isClickable;
- (Marker *)setIsPersistent:(bool)isPersistent;



@end

// Class Popup
@interface Popup : NSObject

@property CLLocationCoordinate2D coordinate;
@property(retain) NSString *title;
@property(retain) NSString *detail;
@property(retain) NSString *tag;
@property CGPoint offset;
@property int weight;
@property float opacity;

- (id)initWithSimplePopupAt:(CLLocationCoordinate2D)coordinate;

@end

// Class Polyline
@interface Polyline : NSObject

@property(retain) NSMutableArray *coordinates;
@property(retain) NSString *tag;
@property int weight;
@property float opacity;
@property(retain) UIColor *lineColor;
@property int lineWidth;

- (id)initWithCoordinates:(NSArray *)coordinates;
- (void)addCoordinate:(CLLocationCoordinate2D)coordinate;

@end

// Class Search
@interface Search : NSObject

@property(retain) NSString *keyword;
@property CLLocationCoordinate2D coordinate;
@property(retain) NSString *area;
@property(retain) NSString *tag;
@property(retain) NSString *language;
@property int limit;
@property int offset;
@property int span;

- (id)initWithKeyword:(NSString *)keyword;

@end

// Class Layer
@interface Layer : NSObject

@property(retain) NSString *name;
@property(retain) NSString *url;
@property(retain) NSString *key;
@property(retain) NSString *format;
@property(retain) NSString *srs;
@property(retain) NSString *transparent;
@property(retain) NSString *styles;
@property(retain) NSString *extraQuery;
@property int type;
@property int refresh;
@property float opacity;
@property int weight;
@property int minZoom;
@property int maxZoom;
@property int maxAge;

- (id)initWithUrl:(NSString *)url andType:(int)type;
- (NSString *)tileUrlForZoom:(int)zoom
                    atColumn:(int)columnNumber
                      andRow:(int)rowNumber;

@end

// Class Longdo Tag
@interface LongdoTag : NSObject

@property(retain) NSString *name;
@property int minZoomRange;
@property int maxZoomRange;

- (id)initWithName:(NSString *)name;
- (id)initWithName:(NSString *)name
    betweenMinZoom:(int)minZoom
        andMaxZoom:(int)maxZoom;

@end

// Class Tag data
@interface TagData : NSObject

@property(retain) NSString *ID;
@property(retain) NSString *name;
@property(retain) NSString *icon;
@property CLLocationCoordinate2D coordinate;

@end
